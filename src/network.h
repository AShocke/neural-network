/* network.h
 * A feedforward neural network class using the Perceptron class
 * 
 * Author: Aisosa Efemwonkieke
 * aisosaefemwonkieke@gmail.com
 */
#ifndef NETWORK
#define NETWORK

#include "perceptron.h"
#include <cstdio>
typedef std::vector<Perceptron> Layer;
typedef std::vector<Layer> Net;
/* 
 * Does not include input perceptron which are really just 
 * Net indexing starts at zero
 */
class Network {
public:
	/* Constructors */
	Network(Net n) {
		net_ = n;
		depth_ = n.size();
		bias_ = 0;
		if (depth_  != 0) {
			Input w(n[depth_-1].size(), 0);
			weights_ = w;
		}
	}
	Network(Net n, Input weights, double bias) {
		net_ = n;
		depth_ = n.size();
		weights_ = weights;
		bias_ = bias;
	}
	/* Create more constructors as needed */
	/* 
	 * Runs the network outputing a single value 1 or 0 to simulate a
	 * response of some kind.
	 * Optionally, you can start at a different layer other than the first in the Network
	 * or end at a different layer other than the first 
	 * Note that input is a typdef in perceptron.h meaning std::vector<double> 
	 */
	Input process(Input inputs, size_t max_depth, size_t i = 0);
	/*
	 * Get functions
	 */
	/*
	 * Condition: 0 <= i < depth_
	 */
	Input get_inputs_at(Input inputs, size_t i);
	
private:
	// The layers in the network
	std::size_t depth_;
	Net net_;
	// This networks bias is its process bias
	double bias_;
	// This networks weights are the weights of the final depths output channels
	Input weights_;
};
#endif
