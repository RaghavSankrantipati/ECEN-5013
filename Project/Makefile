# -*- MakeFile -*-

#target: dependencies
#       action
#including the path of the source files and header from source.mk
include source.mk

INCLUDE= ./Header # including the Header path variable
SOURCE = main.c project1.c memory.c #all the sources required are given   
PRE = main.i project1.i memory.i  #all the preprocessed outputs
ASM = main.s project1.s memory.s  #all the assembly outputs
OBJ = main.o project1.o memory.o #all the object files
CC= gcc -std=c99 #host compiler
CFLAG= -Wall -g -O0 #error flags
COPY = scp #for uploading to Beaglebone
BB8 = root@192.168.7.2:Project1 #the ip address of Beaglebone
#the if loop for selecting the compiler required
ifeq ($(ARCH),BBB)
CC=arm-linux-gnueabihf-gcc
else ifeq ($(ARCH), HOST)
CC = gcc 
else ifeq ($(ARCH),FRDM)
CC=arm-none-eabi-gcc
endif
#for all PREPROCESSED outputs at the same time
PREPROCESS:$(PRE)
#for individual file
%.i: %.c
	$(CC) $(CFLAG) -I $(INCLUDE) -E $< -o $@
#for all assembly files at a time
ASMFILE:$(ASM)
#for individual assembly files
%.s: %.i
	$(CC) $(CFLAG) -S $< -o $@
#for all Object files at a time
OBJECT:$(OBJ)
#for individual files
%.o: %.c
	$(CC) $(CFLAG) -I $(INCLUDE) -c $< -o $@
#for compiling the object files and no linking
compile:$(OBJ)
	$(CC) $(CFLAG) -I $(INCLUDE) -c $< 
#for linking the object files
Build:$(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o final
	$(CC) $(CFLAG) -I $(INCLUDE) -M ./Source/*.c > final.dep	
	size -A final
	objdump -a $(OBJ)
#for creating a library
Build-lib: $(SOURCE)
	ar rU libproject1.a ./Source/*.c
	ranlib libproject1.a
	tar -cvf libproject1.tar ./Source/*.c
#for uploading to different compilers   
UPLOAD: final
	scp final $(BB8)
#for clearing the files 
clear:
	rm -rf *.i *.s *.o final

