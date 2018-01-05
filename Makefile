# MPLAB IDE generated this makefile for use with GNU make.
# Project: soundScode.mcp
# Date: Sat Dec 23 17:04:19 2017

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

soundScode.cof : main.o
	$(LD) /p18F452 /l"C:\Program Files (x86)\Microchip\mplabc18\v3.40\lib" "..\..\..\..\..\Program Files (x86)\Microchip\mplabc18\v3.40\bin\LKR\18f452_g.lkr" "main.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"soundScode.cof" /M"soundScode.map" /W

main.o : main.c Includes.h ../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.40/h/p18f452.h
	$(CC) -p=18F452 "main.c" -fo="main.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "main.o" "soundScode.cof" "soundScode.hex"

