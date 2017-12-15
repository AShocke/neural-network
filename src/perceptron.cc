/* perceptron.cc
 * Author: Aisosa Efemwonkieke
 * aisosaefemwonkieke@gmail.com
 * Descriptions of functions are present in perceptron.h
 */
#include "perceptron.h"
#include <cmath>
double Perceptron::weighted_sum(Input inputs) {
	double sum = 0;
	for (std::size_t i = 0; i < inputs.size(); i++) {
   		sum += inputs[i] * weights_[i];
	}
	return sum;
}
int Perceptron::stimulate(Input inputs) {
	int sum = 0; 
	sum = weighted_sum(inputs);
   	sum += bias_;
	return (sum > 0)? 1 : 0;
}
double Perceptron::sigmoid_stimulate(Input inputs) {
	int sum = weighted_sum(inputs);
	sum += bias_;
	return 1 / (1 + exp(-sum));
}
double Perceptron::sigmoid_derivative(Input inputs) {
	double s = sigmoid_stimulate(inputs);
	return s*(1-s); // This is actually so surprisingly simple
}

