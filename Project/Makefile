# -*- MakeFile -*-

#target: dependencies
#       action

include source.mk

INCLUDE= ./Header
SOURCE = main.c project1.c memory.c   
PRE = main.i project1.i memory.i  
ASM = main.s project1.s memory.s  
OBJ = main.o project1.o memory.o 
CC= gcc
CFLAG= -Wall -g -O0
COPY = scp
BB8 = root@192.168.7.2:Project1
ifeq ($(ARCH),BBB)
CC=arm-linux-gnueabihf-gcc
else ifeq ($(ARCH), HOST)
CC = gcc 
else ifeq ($(ARCH),FRDM)
CC=arm-none-eabi-gcc
endif

PREPROCESS:$(PRE)
%.i: %.c
	$(CC) $(CFLAG) -I $(INCLUDE) -E $< -o $@
ASMFILE:$(ASM)
%.s: %.i
	$(CC) $(CFLAG) -S $< -o $@
OBJECT:$(OBJ)
%.o: %.c
	$(CC) $(CFLAG) -I $(INCLUDE) -c $< -o $@
compile:$(OBJ)
	$(CC) $(CFLAG) -I $(INCLUDE) -c $< 
Build:$(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o final
	size -A final
	objdump -a $(OBJ)
Build-lib: $(SOURCE)
	ar rU libproject1.a ./Source/*.c
	ranlib libproject1.a
	tar -cvf libproject1.tar ./Source/*.c   
UPLOAD: final
	scp final $(BB8)
clear:
	rm -rf *.i *.s *.o final


