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
 * NOTE: The input typdef is taken from perceptron.h and
 * is equivalent to std::vector<double>
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
	Network(const char* filename);
	/* Create more constructors as needed */

	void save_to(const char* filename); 
	void save(); // Saves to DEFAULT_FILE
	/* 
	 * Runs the network outputing a single value to simulate a
	 * response of some kind.
	 * Optionally, you can start at a different layer other than the first in the Network
	 * or end at a different layer other than the first 
	 * Note that Input is a typdef in perceptron.h for std::vector<double> 
	 */
	Input process(Input inputs, size_t max_depth, size_t i = 0);
	/*************** BACKPROPOGATION *************/
	void backpropogation(Input ouput, Input expected);
    /**********************************************/
	/*
	 * Get functions
	 */
	/*
	 * Condition: 0 <= i < depth_
	 */
    Input get_inputs_at(Input inputs, size_t i);
    Net get_net() {
	   return net_;
	}
private:
    // The layers in the network
	std::size_t depth_;
	Net net_;
	// This network's bias is it's process bias
	double bias_;
	// This network's weights are the weights of the final depths output channels
	Input weights_;
    const char* DEFAULT_FILE = "network.NET";
};
#endif
