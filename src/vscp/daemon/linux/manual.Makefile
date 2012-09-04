# =========================================================================
#                      Autogenerated from Makefile.in         
# =========================================================================

prefix = /usr/local
exec_prefix = ${prefix}
INSTALL = /usr/bin/install -c
top_srcdir = ../../../..
top_wxsrcdir = @top_wxsrcdir@
top_builddir = ../../../..
top_wxbuilddir = @top_wxbuilddir@
CXX = g++
CXXFLAGS = -g -O2 
CPPFLAGS =  -I/usr/local/lib/wx/include/gtk2-unicode-release-2.8 -I/usr/local/include/wx-2.8 -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D_LARGEFILE_SOURCE=1 -D__WXGTK__ -DwxUSE_GUI=0
LDFLAGS = 
EXTRALIBS =  -lz -lm -lcrypto -lpthread -ldl  -L/usr/local/lib -pthread -lwx_baseu_xml-2.8 -lwx_baseu_net-2.8 -lwx_baseu-2.8  -W1,--version-script
STRIP = strip
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_DIR = /usr/bin/install -c -d
srcdir = .
top_srcdir = .
top_builddir =
bindir = ${exec_prefix}/bin
libdir = ${exec_prefix}/lib
datadir = ${prefix}/share
includedir = ${prefix}/include
DLLPREFIX = lib

### Variables: ###

DESTDIR = 
WX_RELEASE = 2.8
LIBDIRNAME = $(top_wxbuilddir)lib

CANALD_OBJECTS =  \
	vscpd.o \
        ../../common/daemonvscp.o \
        ../../common/clientlist.o ../../common/controlobject.o \
        ../../common/devicelist.o \
        ../../common/vscphelper.o \
        ../../common/tcpipclientthread.o \
	../../common/dm.o \
	../../common/vscpvariable.o \
	../../common/interfacelist.o \
	../../common/userlist.o \
        ../../common/udpthread.o \
        ../../common/devicethread.o \
	../../common/vscptcpif.o \
	../../common/guid.o \
	../../../common/dllist.o \
	../../../common/configfile.o \
	../../../common/crc.o \
	../../../common/md5.o \
	../../../common/randPassword.o       	


### Targets: ###

all: vscpd

install: all
	$(INSTALL_PROGRAM) vscpd $(bindir)

uninstall: 

install-strip: install

clean: 
	rm -rf ./.deps ./.pch
	rm -f ./*.o
	rm -f ../../common/*.o
	rm -f ../../../common/*.o
	rm -f ../../../vscp/common/*.o
	rm -f vscpd

distclean: clean
	rm -f config.cache config.log config.status bk-deps bk-make-pch shared-ld-sh Makefile

vscpd: $(CANALD_OBJECTS)
	$(CXX) -o $@ $(CANALD_OBJECTS) $(LDFLAGS) -L$(LIBDIRNAME) $(WXLIBS) $(EXTRALIBS)
	


# Include dependency info, if present:
-include .deps/*.d

.PHONY: all install uninstall clean distclean data

