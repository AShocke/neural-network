CC:=g++
FLAGS:= -Wall

bitwisesum: bitwisesum.cc network
	$(CC) $(FLAGS) perceptron.cc network.cc bitwisesum.cc -o $@
nand: nand.cc perceptron
	$(CC) $(FLAGS) perceptron.cc nand.cc -o $@

perceptron: perceptron.h perceptron.cc
	g++ -c $(FLAGS) perceptron.cc

network: perceptron network.h network.cc
	g++ -c $(FLAGS) perceptron.cc
