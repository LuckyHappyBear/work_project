PWD=${shell pwd}
CROSS_COMP=${PWD}/../android_4_2_ndk_for_7300/bin/arm-linux-androideabi-
CC=${CROSS_COMP}gcc
LD=${CROSS_COMP}ld

#CFLAGS="-I${PWD}/../gcc-arm-none-eabi-4_6-2012q1/arm-none-eabi/include -L${PWD}/../gcc-arm-none-eabi-4_6-2012q1/arm-none-eabi/lib -lc ARCH=arm"
#LDFLAGS=-nostdlib ${PWD}/../gcc-arm-none-eabi-4_6-2012q1/lib/gcc/arm-none-eabi/4.6.2/crtbegin.o ${PWD}/../gcc-arm-none-eabi-4_6-2012q1/lib/gcc/arm-none-eabi/4.6.2/crtend.o

vpath %.h socket_h
vpath %.c socket_client
vpath %.c socket_public
vpath % main_func:cJSON:local_func

ObjClient = cgi_check.o cgi_getlist.o cgi_backup.o cgi_recover.o cgi_delete.o \
            public_handle.o
ObjLocal = cgic_local.o
ObjMain = cgic.o cgic_auxil.o

target: backup.cgi

backup.cgi: $(ObjClient) $(ObjLocal) $(ObjMain) cJSON.o
	${CC} $(ObjClient) $(ObjLocal) $(ObjMain) cJSON.o -lm ${CFLAGS} -o $@ ${LDFLAGS}

$(ObjClient):%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

$(ObjLocal):%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

$(ObjMain):%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

cJSON.o:cJSON.c
	${CC} -c ${CFLAGS} $< -o $@

.PHONY: clean
clean:
	rm -f *.o *~ *cgi
