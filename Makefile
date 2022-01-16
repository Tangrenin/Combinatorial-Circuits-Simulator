CPP=g++ --std=c++11
CFLAGS= -Wall

all : main

main : main.o Gate.o BinaryGate.o InputGate.o OutputGate.o UnaryGate.o NegateGate.o AndGate.o NandGate.o NorGate.o NxorGate.o OrGate.o XorGate.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

Gate.o : Gates/Gate.cpp Gates/Gate.h
	$(CPP) $(CFLAGS) -c $<

BinaryGate.o : Gates/BinaryGate.cpp Gates/BinaryGate.h
	$(CPP) $(CFLAGS) -c $<

InputGate.o : Gates/InputGate.cpp Gates/InputGate.h
	$(CPP) $(CFLAGS) -c $<

OutputGate.o : Gates/OutputGate.cpp Gates/OutputGate.h
	$(CPP) $(CFLAGS) -c $<

UnaryGate.o : Gates/UnaryGate.cpp Gates/UnaryGate.h
	$(CPP) $(CFLAGS) -c $<

NegateGate.o : Gates/UnaryGates/NegateGate.cpp Gates/UnaryGates/NegateGate.h
	$(CPP) $(CFLAGS) -c $<

AndGate.o : Gates/BinaryGates/AndGate.cpp Gates/BinaryGates/AndGate.h
	$(CPP) $(CFLAGS) -c $<

NandGate.o : Gates/BinaryGates/NandGate.cpp Gates/BinaryGates/NandGate.h
	$(CPP) $(CFLAGS) -c $<

NorGate.o : Gates/BinaryGates/NorGate.cpp Gates/BinaryGates/NorGate.h
	$(CPP) $(CFLAGS) -c $<

NxorGate.o : Gates/BinaryGates/NxorGate.cpp Gates/BinaryGates/NxorGate.h
	$(CPP) $(CFLAGS) -c $<

OrGate.o : Gates/BinaryGates/OrGate.cpp Gates/BinaryGates/OrGate.h
	$(CPP) $(CFLAGS) -c $<

XorGate.o : Gates/BinaryGates/XorGate.cpp Gates/BinaryGates/XorGate.h
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o

test: all
	./main