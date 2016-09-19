# Mounika
###This project is a part of Coursework

###This is a free library to be used for teaching ECEN5013. 

###Class:  ECEN5013 - Embedded Software Essentials
###Current Year: 2016
###Current Semester: Fall

Introduction:
This project is for creating the Makefile which is for automatic building.The functions written are for Manipulating the memory and Data Sources are for manipulating the data.

Making targets:

#target: dependencies
#       action

Syntax is that for creating Target the files required are dependencies and action is the command to be performed on the dependencies for creating the target
1) Move to the directory of Project
2)Change the source Preprocess Assembly Object file names to the required
3)
Creating Preprocess:
Make Preprocess
with this command all the preprocessed outputs will be created
and if you want an individual file input then 
Make sourcefile.i
Creating Assembly Outputs:
Make ASMFILE
with this command all the Assembly outputs will be created
and if you want an individual file input then 
Make sourcefile.s
Creating Objects:
Make OBJECT
with this command all the Object files are created but not linked with each other
and if you want an individual file input then 
Make sourcefile.o
Linking the Objectfiles:
Make Compile
with this command all the Object files are linked with each other but headers are not included
Executable File:
Make Build
This command gives the executable file final and also the size of the executable file created and even converts the executable files into assembly language
Make Build-all:
It creates all the sourcefiles into the library
For Other Compilers
1)make clear- removes all the files created before for your host machine
all object assembly preprocessed and final executable files
2)make Build arch=BBB for BeagleBone which compiles the program for Beaglebone
3)make UPLOAD this will push the final executable file into your host machine
