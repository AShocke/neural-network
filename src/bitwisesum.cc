/* A nand gate with a simple perceptron
 * Author: Aisosa Efemwonkieke
 * Uses (C++ 11)
 */
#include "perceptron.h"
#include "network.h"
#include <cstdio>
#include <iostream>
const int INPUT_SIZE = 2;

int main() {
	Input weights = {-2, -2};
	Input inputs(INPUT_SIZE);
	int bias = 3;
	printf("Enter %d inputs representing bits (1 or 0)\n",
		   INPUT_SIZE);
	for (int i = 0; i < INPUT_SIZE; i++) {
		int input;
		scanf("%d", &input);
		inputs[i] = input;
	}
	Perceptron nand(weights, bias);
	Layer l1;
	l1.push_back(nand);
	Layer l2;
	l2.push_back(nand);
	l2.push_back(nand);
	Perceptron output(weights, bias);
	double l1_output = l1[0].stimulate(inputs);
	Input l2_input_r = {l1_output, inputs[0]};
	Input l2_input_l = {l1_output, inputs[1]};
	Input final_inputs = {(double) l2[0].stimulate(l2_input_r), (double) l2[1].stimulate(l2_input_l)};
	Input carry_input = {(double) l1_output};
	Input carry_weights = {-4};
	Perceptron carry_bit(carry_weights, bias);
	int carry = carry_bit.stimulate(carry_input);
	printf("%d%d\n", carry, nand.stimulate(final_inputs));
}
