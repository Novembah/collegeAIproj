#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <functional>

double random() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(-1, 1);
	return distr(gen);
}

class Perceptron 
{
public:
	// Perceptron Inherent wieght and bias
	double esteem;
	double bias;
	// input weights and inputs
	std::vector<double> weights;
	std::vector<double> inputs;

	Perceptron(double& weight, double& Dbias, int inputnum) : esteem(weight), bias(Dbias) {
		weights.resize(inputnum);
		inputs.resize(inputnum);
		for (size_t i : weights) {
			weights.at(i) = random();
		}
		for (size_t i : inputs) {
			inputs.at(i) = random();
		}
	}

	double fire() {
		double currentThreshold = bias;
		for (int i : weights) {
			currentThreshold += weights[i] * inputs[i];
		}
		if (currentThreshold < )
	}

};

class MLP 
{
private:
	
};

int main() {
	return 0;
}
