#include "network.h"
#include "perceptron.h"
#include <cstdio>
const char* TEST = "TEST.NET";
/* Test save_to function
 * After test check 'TEST.NET' to make sure
 * it is running properly
 */
void save_to_test(Network n) {
	n.save_to(TEST);
	printf("Test complete. Check %s to be sure thatnetworwork::save_to(const char*) is working properly\n",
		   TEST);
}
void Network_test(Net expected) {
	Network test(TEST);
	Net t = test.get_net();
  	for (unsigned i = 0; i < expected.size(); i++) {
		Layer l = t[i];
		Layer l_e = expected[i];
		for (unsigned j = 0; j < l.size(); j++) {
			Perceptron p = l[j];
			Perceptron p_e = l_e[j];
			if(p.get_bias() != p_e.get_bias()) {
				printf("Failure! Biases do not match. Something is not working correctly\n");
				return;
			}
			Input w = p.get_weights();
			Input w_e = p_e.get_weights();
			for (unsigned x = 0; x < p.get_weights().size(); x++) {
				if (w[x] != w_e[x]) {
					printf("Failure! Weights do not match. Something is not working correctly\n");
					return;
				}
			}
		}
	}
	printf("Test complete. No errors. Rejoice!\n");
}
int main() {
	int net_size = 4;
	// Each perceptron in test has the same weights
	Input weights = {1, 2, 3, 4, 5};
	// Create all layers
	Net n;
	for (int i = 0; i < net_size; i++) {
		Layer l;
		for (int j = 0; j < i + 1; j++) {
			double bias = j;
			Perceptron p(weights, bias);
			l.push_back(p);
		}
		n.push_back(l);
	}
	Network net(n);
	// tests
	save_to_test(net);
	Network_test(n);
	
}
