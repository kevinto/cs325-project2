#########################################################
# File: Makefile
# # Description: A makefile for CS325 Project 2.
# #########################################################

CXX = gcc -std=c99 

SRC1 = changedp.c
SRC2 = changegreedy.c
SRC3 = changeslow.c
SRC4 = filefunctions.c
SRC5 = changeslowkevin.c

PROG1 = changedp 
PROG2 = changegreedy 
PROG3 = changeslow
PROG4 = changeslowkevin
PROGS = ${PROG1} ${PROG2} ${PROG3} ${PROG4}

# Not hooked up yet
HEADER1 = filefunctions.h
HEADERS = ${HEADER1}

all: program1 program2 program3 program4

program1: ${SRC1}
	${CXX} ${SRC1} ${SRC4} ${HEADERS} -o ${PROG1}  

program2: ${SRC2}
	${CXX} ${SRC2} ${SRC4} ${HEADERS} -o ${PROG2}  

program3: ${SRC3}
	${CXX} ${SRC3} ${SRC4} ${HEADERS} -o ${PROG3}  

program4: ${SRC5}
	${CXX} ${SRC5} ${SRC4} ${HEADERS} -o ${PROG4}  

clean:
	rm -rf ${PROGS} *Amount.txt
