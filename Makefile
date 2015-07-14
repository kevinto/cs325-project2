#########################################################
# File: Makefile
# # Description: A makefile for CS325 Project 2.
# #########################################################

CXX = gcc -std=c99 

SRC1 = changedp.c
SRC2 = changegreedy.c
SRC3 = changeslow.c

PROG1 = changedp 
PROG2 = changegreedy 
PROG3 = changeslow
PROGS = ${PROG1} ${PROG2} ${PROG3} 

# Not hooked up yet
# HEADER1 = filefunctions.h
# HEADERS = ${HEADER1}

all: program1 program2 program3 

program1: ${SRC1}
	${CXX} ${SRC1} -o ${PROG1}  

program2: ${SRC2}
	${CXX} ${SRC2} -o ${PROG2}  

program3: ${SRC3}
	${CXX} ${SRC3} -o ${PROG3}  

clean:
	rm -rf ${PROGS} *change.txt
