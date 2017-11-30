CC:=g++
FLAGS:= -Wall
TESTS:= networktests.cc

bitwisesum: bitwisesum.cc network
	$(CC) $(FLAGS) perceptron.cc network.cc bitwisesum.cc -o $@
nand: nand.cc perceptron
	$(CC) $(FLAGS) perceptron.cc nand.cc -o $@

perceptron: perceptron.h perceptron.cc
	g++ -c $(FLAGS) perceptron.cc

network: perceptron network.cc
	g++ -c $(FLAGS) perceptron.cc
test: $(TESTS) network
	$(CC) $(FLAGS) perceptron.cc network.cc $(TESTS) -o $@
