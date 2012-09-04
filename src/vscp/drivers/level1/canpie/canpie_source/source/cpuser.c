/*****************************************************************************\
*  CANpie                                                                     *
*                                                                             *
*  File        : cpuser.c                                                     *
*  Description :                                                              *
*  Author      : Uwe Koppe                                                    *
*  e-mail      : koppe@microcontrol.net                                       *
*                                                                             *
* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *
*                                                                             *
*   This program is free software; you can redistribute it and/or modify      *
*   it under the terms of the GNU General Public License as published by      *
*   the Free Software Foundation; either version 2 of the License, or         *
*   (at your option) any later version.                                       *
*                                                                             *
* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *
*                                                                             *
*  History                                                                    *
*  Vers.    Date        Comment                                         Aut.  *
*  -----    ----------  ---------------------------------------------   ----  *
*  0.1      11.02.1999  Initial version                                 UK    *
*  0.2      29.04.1999  Changed structures, new data type definitions   UK    *
*  0.3      01.09.1999  Adaption to version 0.3 of the CANpie Doc.      UK    *
*  0.4      18.01.2000  added function calls in CpUserAppInit(), i.e.   UK    *
*                       CpUserBaudrate() and CpFilterAll(),                   *
*                       changed place of CpVar_InitFlag                       *
*  0.5                  - no changes -                                        *
*  0.6      15.06.2000  set to CANpie release 0.6                       UK    *
*  0.7                  - no changes -                                      	*
*  0.8      21.06.2001  init to default baudrate                        UK   	*
*                                                                             *
\*****************************************************************************/

#include "cpcore.h"
#include "cpfifo.h"
#include "cpfilter.h"
#include "cpuser.h"




/*------------------------------------------------------------------------
** CpUserAppInit()
**
*/
_U08 Cp_PREFIX CpUserAppInit( _U08 channel,
                              _U16 rcvFifoSize, _U16 trmFifoSize, _U16 timeout)
{
   _U16        initMask = 0;
   _U08        err_code;

#if   CP_SMALL_CODE == 0
   //--- test the channel number --------------------------
   if( (channel + 1) > CP_CHANNEL_MAX) return (CpErr_CHANNEL);

   //--- check if already initialized ---------------------
   if( (CpVar_InitFlag >> channel) & 0x0001) return (CpErr_INIT_READY);
#endif


   //--- set up the FIFOs ---------------------------------
   err_code = CpFifoSetup(channel,CP_FIFO_RCV, rcvFifoSize);
   if (err_code != CpErr_OK) return (err_code);

   err_code = CpFifoSetup(channel,CP_FIFO_TRM, trmFifoSize);
   if (err_code != CpErr_OK) return (err_code);
         
   //--- init the core driver -----------------------------
   err_code = CpCoreInitDriver(channel);
   if (err_code != CpErr_OK) return (err_code);

   //--- mark the channel as initialized ------------------
   initMask = (1 << channel);
   CpVar_InitFlag = CpVar_InitFlag | initMask;

   //--- init baudrate ------------------------------------
   err_code = CpUserBaudrate(channel, CP_DEFAULT_BAUDRATE);
   if (err_code != CpErr_OK) return (err_code);

   //--- setup filter -------------------------------------
   CpUserFilterAll(channel, TRUE);

   //--- clear pointer for callback functions -------------
   CpInt_ReceiveHandler[channel]    = 0;
   CpInt_TransmitHandler[channel]   = 0;
   CpInt_ErrorHandler[channel]      = 0;
   
   return (CpErr_OK);
}


/*------------------------------------------------------------------------
** CpUserAppDeInit()
**
*/
_U08 Cp_PREFIX CpUserAppDeInit(_U08 channel)
{
   _U08  err_code;
   _U16  initMask;

#if   CP_SMALL_CODE == 0
   //--- test the channel number --------------------------
   if( (channel + 1) > CP_CHANNEL_MAX) return (CpErr_CHANNEL);

   //--- check if already initialized ---------------------
   if( !( (CpVar_InitFlag >> channel) & 0x0001) ) return (CpErr_INIT_MISSING);
#endif


   //--- remove the core driver ---------------------------
   err_code = CpCoreDeInitDriver(channel);
   if (err_code != CpErr_OK) return (err_code);

   //--- remove the FIFOs ---------------------------------

   //--- remove initialization flag -----------------------
   initMask = (1 << channel);
   initMask = ~initMask;
   CpVar_InitFlag = CpVar_InitFlag & initMask;

   return(CpErr_OK);
}


/*------------------------------------------------------------------------
** CpUserBaudrate()
**
*/
_U08 Cp_PREFIX CpUserBaudrate(_U08 channel, _U08 baud)
{
   int   offset = 0;    /* Offset for Bit-Timing Table   */

#if   CP_SMALL_CODE == 0
   //--- test the channel number ------------------------------------
   if( (channel + 1) > CP_CHANNEL_MAX) return (CpErr_CHANNEL);

   //--- check if already initialized -------------------------------
   if( !( (CpVar_InitFlag >> channel) & 0x0001) ) return (CpErr_INIT_MISSING);
#endif

   //--- get the Bit-Timing values and call the core function -------
   offset = baud + (channel * CP_NUMBER_OF_BAUDRATES);
   return ( CpCoreBaudrate(channel,
                           CpStruct_BitTimingTable[offset].btr0,
                           CpStruct_BitTimingTable[offset].btr1,
                           CpStruct_BitTimingTable[offset].sjw)  );
}



/*------------------------------------------------------------------------
** CpUserFifoClear()
**
*/
_U08 Cp_PREFIX CpUserFifoClear(_U08 channel, _U08 buffer)
{
   _U08  err_code;

#if   CP_SMALL_CODE == 0
   //--- test the channel number ------------------------------------
   if( (channel + 1) > CP_CHANNEL_MAX) return (CpErr_CHANNEL);

   //--- check if already initialized -------------------------------
   if( !( (CpVar_InitFlag >> channel) & 0x0001) ) return (CpErr_INIT_MISSING);
#endif

   //--- clear the FIFO ---------------------------------------------
   err_code = CpFifoClear(channel, CP_FIFO_RCV);
   if (err_code) return (err_code);

   err_code = CpFifoClear(channel, CP_FIFO_TRM);
   if (err_code) return (err_code);

   return(CpErr_OK);   
}



/*------------------------------------------------------------------------
** CpUserFilterAll()
**
*/
_U08 Cp_PREFIX CpUserFilterAll(_U08 channel, _BIT enable)
{
#if   CP_SMALL_CODE == 0
   //--- test the channel number ------------------------------------
   if( (channel + 1) > CP_CHANNEL_MAX) return (CpErr_CHANNEL);

   //--- check if already initialized -------------------------------
   if( !( (CpVar_InitFlag >> channel) & 0x0001) ) return (CpErr_INIT_MISSING);
#endif


#if   CP_SW_FILTER == 0
   return ( CpErr_NOT_SUPPORTED );
#elif CP_SW_FILTER == 1
   return ( CpFilterAll(channel, enable) );
#elif CP_SW_FILTER == 2
   return ( CpCoreFilterAll(channel, enable) );
#else
#error   Wrong definition for symbol CP_SW_FILTER !
#endif

}


/*------------------------------------------------------------------------
** CpUserFilterMsg()
**
*/
_U08 Cp_PREFIX CpUserFilterMsg(_U08 channel, _U16 id, _BIT enable)
{
#if   CP_SMALL_CODE == 0
   //--- test the channel number ------------------------------------
   if( (channel + 1) > CP_CHANNEL_MAX) return (CpErr_CHANNEL);

   //--- check if already initialized -------------------------------
   if( !( (CpVar_InitFlag >> channel) & 0x0001) ) return (CpErr_INIT_MISSING);
#endif


#if   CP_SW_FILTER == 0
   return ( CpErr_NOT_SUPPORTED );
#elif CP_SW_FILTER == 1
   return ( CpFilterMsg(channel, id, enable) );
#elif CP_SW_FILTER == 2
   return ( CpCoreFilterMsg(channel, id, enable) );
#else
#error   Wrong definition for symbol CP_SW_FILTER !
#endif

}


/*------------------------------------------------------------------------
** CpUserIntFunctions()
**
*/
_U08 Cp_PREFIX CpUserIntFunctions(  _U08 channel,
                                    _U08 (* rx_handler)  (CpStruct_CAN *),
                                    _U08 (* tx_handler)  (CpStruct_CAN *),
                                    _U08 (* err_handler) (_U08) )
{
#if   CP_SMALL_CODE == 0
   //--- test the channel number ------------------------------------
   if( (channel + 1) > CP_CHANNEL_MAX) return (CpErr_CHANNEL);

   //--- check if already initialized -------------------------------
   if( !( (CpVar_InitFlag >> channel) & 0x0001) ) return (CpErr_INIT_MISSING);
#endif

   CpInt_ReceiveHandler[channel]    = rx_handler;
   CpInt_TransmitHandler[channel]   = tx_handler;
   CpInt_ErrorHandler[channel]      = err_handler;
   
   return(CpErr_OK);
}


/*------------------------------------------------------------------------
** CpUserMsgRead()
**
*/
_U08 Cp_PREFIX CpUserMsgRead(_U08 channel, CpStruct_CAN * msgPtr)
{
   _U08  err_code = 0;

#if   CP_SMALL_CODE == 0
   //--- test the channel number ------------------------------------
   if( (channel + 1) > CP_CHANNEL_MAX) return (CpErr_CHANNEL);

   //--- check if already initialized -------------------------------
   if( !( (CpVar_InitFlag >> channel) & 0x0001) ) return (CpErr_INIT_MISSING);
#endif


#if CP_INT_HANDLER == 0
   //--- use polling if there is no Interrupt-Handler ---------------
   CpCoreMsgReceive(channel);
#endif

   //--- get message from FIFO --------------------------------------
   err_code = CpFifoPop(channel, CP_FIFO_RCV, msgPtr);
   if (err_code) return (err_code); 


   return (CpErr_OK);
}


/*------------------------------------------------------------------------
** CpUserMsgWrite()
**
*/
_U08 Cp_PREFIX CpUserMsgWrite(_U08 channel, CpStruct_CAN * msgPtr)
{
   _U08  err_code = 0;

#if   CP_SMALL_CODE == 0
   //--- test the channel number ------------------------------------
   if( (channel + 1) > CP_CHANNEL_MAX) return (CpErr_CHANNEL);

   //--- check if already initialized -------------------------------
   if( !( (CpVar_InitFlag >> channel) & 0x0001) ) return (CpErr_INIT_MISSING);
#endif

   //--- put message into FIFO --------------------------------------
   err_code = CpFifoPush(channel, CP_FIFO_TRM, msgPtr);
   if (err_code) return (err_code);


   //--- transmit the message ---------------------------------------
   CpCoreMsgTransmit(channel);

   return (CpErr_OK);
}