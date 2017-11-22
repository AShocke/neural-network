/* perceptron.cc
 * Author: Aisosa Efemwonkieke
 * aisosaefemwonkieke@gmail.com
 * Descriptions of functions are present in perceptron.h
 */
#include "perceptron.h"
#include <cmath>
int Perceptron::stimulate(Input inputs) {
	int sum = 0; 
		for (std::size_t i = 0; i < inputs.size(); i++) {
			sum += inputs[i] * weights_[i];
		}
		sum += bias_;
		return (sum > 0)? 1 : 0;
}
double Perceptron::sigmoid_stimulate(Input inputs) {
	int sum = stimulate(inputs);
	return 1 / (1 + exp(-sum));
}
