/* network.cc
 * Implementation for the network class
 * Aisosa Efemwonkieke
 * aisosaefemwonkieke@gmail.com
 */
#include "network.h"
#include<fstream>
#include<cstdio>
/* Recursively runs through network, using the
 * previous layers of perceptrons' stimulate() as input 
 */
Input Network::process(Input input, size_t max_depth, size_t curr_depth) {
	if (curr_depth > max_depth) {
		return input;
	}
	Input new_inputs;
	Layer l = net_[curr_depth];
	for (std::size_t i = 0; i < l.size(); i++) {
		double out = l[i].sigmoid_stimulate(input);
		new_inputs.push_back(out);
	}
	return process(new_inputs, curr_depth+1, max_depth);
}

Input Network::get_inputs_at(Input input, size_t i) {
	Input output;
	Layer l = net_[i];
	for (std::size_t x = 0; x < l.size(); x++) {
		double out = l[i].sigmoid_stimulate(input);
		output.push_back(out);
	}
	return output;
}
/*
 * Loads a neural network from a file.
 * View the comments above save_to() for more information on
 * what a *.Net file looks like. The format is very straightforward. 
 */
Network::Network(const char* filename) {
	Net n;
	std::ifstream reader(filename);
	if(reader.is_open()) {
		int net_size;
		reader >> net_size;
		for (int i = 0; i < net_size; i++) {
			int layer_size;
			reader >> layer_size;
			Layer l;
			for (int j = 0; j < layer_size; j++) {
				double bias;
				reader >> bias;
				double weight_size;
				reader >> weight_size;
				Input weights;
				for (int w = 0; w < weight_size; w++) {
					double x;
					reader >> x;
					weights.push_back(x);
				}
				Perceptron p(weights, bias);
				l.push_back(p);
			}
			n.push_back(l);
		}
		printf("Network loaded successfully\n");
	}
	else {
		fprintf(stderr, "ERROR: Could not open ' %s '\n", filename);
	}
	net_ = n;
}

/*Contributed by PancakeReaper
 *Edited By Aisosa Efemwonkieke
 *
 * Saves the neural newtork to a specified *.NET file
 * The folowing commments are an example of how a neural
 * netowrk would be saved
 * 
 * --------------------------
 *       example.NET
 * --------------------------
 * (number of layers)
 * (number of perceptron in first layer)
 * (bias) (weight size) (weights) ... (bias)_n (weights)_n
 * .
 * .
 * .
 * (number of perceptrons in last layer)
 * (bias) (weight size) (weights)  ...  (bias) (weights) 
 * ---------------------------
 */
void Network::save_to(const char* filename) {
	// Save weights, and biases
	std::ofstream writer(filename);
	if(writer.is_open()){
		// Writes Neural Net size (amount of layers)
		writer << net_.size() << "\n"; 

		// Iterate through the layers, hopefully
		for (std::size_t i = 0; i < net_.size(); i++) {
			Layer l = net_[i];
			// Writes layer size (amount of perceptrons)
			writer << l.size() << "\n";

			// Iterate through biases and weights, hopefully
			for (std::size_t p = 0; p < l.size(); p++) {
				writer << l[p].get_bias() << " ";
				Input weights = l[p].get_weights();
				writer <<  weights.size() << " ";
				for (std::size_t w = 0; w < weights.size(); w++) {
					writer << weights[w] << " ";
				}
				writer << " ";
			}
			writer << "\n";
		}
	}
	else {
		fprintf(stderr, "ERROR: Could not open ' %s '\n", filename);
	}
	writer.close();
}
/*
 * Calls save_to with the parameter DEFAULT_FILE
 */
void Network::save(){
	save_to(DEFAULT_FILE);
}

/*------------------------------------------------------------
 *                    BACKPROPOGATION
 *               The Heart of Neural Networks
 *------------------------------------------------------------
 *
 * More info on backpropogation will be in
 * backpropogation.pdf or backpropogation.md (TODO for both)
 * 
 */



