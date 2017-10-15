/* A nand gate with a simple perceptron
 * Author: Aisosa Efemwonkieke
 * Uses (C++ 11)
 */
#include "perceptron.h"
#include <cstdio>
#include <iostream>
const int INPUT_SIZE = 2;

int main() {
	Input weights = {-2, -2};
	Input inputs(INPUT_SIZE);
	int bias = 3;
	printf("Enter %d inputs (0 for false, 1 for true)\n",
		   INPUT_SIZE);
	for (int i = 0; i < INPUT_SIZE; i++) {
		int input;
		scanf("%d", &input);
		inputs[i] = input;
	}
	Perceptron nand(weights, bias);
	bool nand_result = nand.stimulate(inputs) == 1;
	std::cout << nand_result << "\n";
}
