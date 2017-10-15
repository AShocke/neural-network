/* network.cc
 * Implementation for the network class
 * Aisosa Efemwonkieke
 * aisosaefemwonkieke@gmail.com
 */
#include "network.h"
/* Recursively runs through network, using the
 * previous layers of perceptrons' stimulate() as input 
 */
int Network::process(Input input, size_t max_depth, size_t curr_depth) {
	if (curr_depth > max_depth) {
		Perceptron output(weights_, bias_);
		return output.stimulate(input);
	}
	Input new_inputs;
	Layer l = net_[curr_depth];
	for (std::size_t i = 0; i < l.size(); i++) {
		double out = l[i].stimulate(input);
		new_inputs.push_back(out);
	}
	return process(new_inputs, curr_depth++, max_depth);
}

Input Network::get_inputs_at(Input input, size_t i) {
	Input output;
	Layer l = net_[i];
	for (std::size_t x = 0; x < l.size(); x++) {
		double out = l[i].stimulate(input);
		output.push_back(out);
	}
	return output;
}





