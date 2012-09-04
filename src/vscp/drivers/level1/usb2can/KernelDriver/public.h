/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

Module Name:

    BulkUsr.h

Abstract:

Environment:

    User & Kernel mode

--*/

#ifndef _USER_H
#define _USER_H

#include <initguid.h>

// {6068EB61-98E7-4c98-9E20-1F068295909A}
//DEFINE_GUID(GUID_CLASS_USBSAMP_USB,0x873fdf, 0x61a8, 0x11d1, 0xaa, 0x5e, 0x0, 0xc0, 0x4f, 0xb1, 0x72, 0x8b);
// {3EA03B52-C71A-433c-A626-E8AD96F2578B}
DEFINE_GUID(GUID_CLASS_USB2CAN,0x3ea03b52, 0xc71a, 0x433c, 0xa6, 0x26, 0xe8, 0xad, 0x96, 0xf2, 0x57, 0x8b);



#define IOCTL_INDEX             0x0000


#define IOCTL_USBSAMP_GET_CONFIG_DESCRIPTOR CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX,     \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)
                                                   
#define IOCTL_USBSAMP_RESET_DEVICE          CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 1, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)

#define IOCTL_USBSAMP_RESET_PIPE            CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 2, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)


#define IOCTL_USBSAMP_GET_SERIALNUMBER_STRING        CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 3, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)

#endif

