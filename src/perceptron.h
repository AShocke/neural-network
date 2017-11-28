/* perceptron.h
 * An implementation of a perceptron in C++
 * Author: Aisosa Efemwonkieke 
 *
 */

#ifndef PERCEPTRON
#define PERCEPTRON
#include <vector>
typedef std::vector<double> Input; // Represents the type of the in channels and weights
class Perceptron {
public:
	/* Constructor takes in three vectors inputs, weights, bias
	 * inputs contains all the input channels of the perceptron
	 * weights contains all the weights of the corresponding channels
	 * bias is the perceptrons general bias towards firing
	 * The constructor sets the parameters to the class variables: 
	 *inputs_, weights_ and bias_ respectively
  	 */
	Perceptron(Input weights, double bias) {
		weights_ = weights;
		arg_size_ = weights.size();
		bias_ = bias;
	}
	/*
	 * Performs the weigted sum */
	double weighted_sum(Input inputs);
	/* Condition: inputs.size() == weights.size()
	 * "fires" the perceptron if Sigma(inputs[i] * weights_[i]) + bias > 0
	 * If a perceptrons fires succesfuly, it returns 1 else it returns 0
	 */
	int stimulate(Input inputs);
    double sigmoid_stimulate(Input inputs); // -- Uses the logistic curve for calcualtion */
	/* TODO stimulate(Function) -- Takes in a function if this is even possible */
	/*
	 * Set functions
	 * Mostly self explanatory
     */
	/*
	 * Get Functions
	 * Mostly self explanatory
	 */
	int get_bias() {
		return bias_;
	}
	Input get_weights(){
		return weights_;
	}
	
	
private:
	std::size_t arg_size_;
	Input weights_;
	double bias_;
};

#endif 
