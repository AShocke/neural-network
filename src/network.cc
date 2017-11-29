/* network.cc
 * Implementation for the network class
 * Aisosa Efemwonkieke
 * aisosaefemwonkieke@gmail.com
 */
#include "network.h"
#include<fstream>
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
<<<<<<< HEAD

Network::Network(const char* filename) {
	//TODO
}
void Network::save_to(char* filename) {
	// Save weights, and biases
	ofstream writer(filename);
	if(writer!=NULL){
		// Writes Neural Net size (amount of layers)
		writer << net_.size() << "\n" << endl; 

		// Iterate through the layers, hopefully
		for (std::size_t i = 0; i < net_.size(); i++) {
			Layer l = net_[i];
			// Writes layer size (amount of perceptrons)
			writer << l.size() << "\n" << endl;

			// Iterate through biases and weights, hopefully
			for (std::size_t p = 0; p < l.size(); p++) {
				writer << l[p].get_bias() << ":" << endl;
				wei = l[p].get_weights()
				for (std::size_t w = 0; w < wei.size(); w++) {
					writer << wei[w] << ":" << endl;
				}
			}
			writer << "\n" << endl;
		}
	}
	writer.close()
}

void Network::save(){
	save_to(DEFAULT_FILE)
}





=======
>>>>>>> origin/master
