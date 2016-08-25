#Tyler Forrester
#Makefile for Assignment 2 makes 5 object Critter, Doodlebug, InputValid, Ant and Main files into a program
#July 10, 2016
CXX = g++ 
OBJSSUM = Critter.o
SRCSSUM = Critter.cpp
OBJSAVG = Doodlebug.o
SRCSAVG = Doodlebug.cpp
OBJSL1 = InputValid.o
SRCSL1 = InputValid.cpp
OBJSL3 = Ant.o
SRCSL3 = Ant.cpp
OBJSL2 = main.o
SRCSL2 = main.cpp
HEADERS = Critter.hpp
HEADERA = Doodlebug.hpp
HEADERI = InputValid.hpp
HEADER3 = Ant.hpp
PROG = Assignment2
#PROGT = Test

all: $(PROG) 

$(PROG): $(OBJSL2) $(OBJSSUM) $(OBJSAVG) $(OBJSL1) $(OBJSL3)
	$(CXX) $(OBJSAVG) $(OBJSL2) $(OBJSSUM) $(OBJSL1) $(OBJSL3) -o $(PROG)
$(OBJSL2): $(SRCSL2) $(HEADERS) $(HEADERA) $(HEADERI) $(HEADER3)
	$(CXX) -c $(SRCSL2)
$(OBJSAVG): $(SCRSAVG) $(HEADERA) 
	$(CXX) -c $(SRCSAVG)
$(OBJSL1): $(SRCSL1) $(HEADERI)
	$(CXX) -c $(SRCSL1)
$(OBJSSUM): $(SRCSSUM) $(HEADERS)
	$(CXX) -c $(SRCSSUM)
$(OBJSL3): $(SRCSL3) $(HEADER3)
	$(CXX) -c $(SRCSL3)
clean:
	rm -rf $(PROG) *.o  *~
