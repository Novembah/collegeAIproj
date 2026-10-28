#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <functional>
#include <numeric>
#include <cmath>

std::vector<double> Zscale(std::vector<double>& data)
{
	// Scaling algorithm for data, using Standardization
	std::vector<double> result(data.size());
	if (data.empty()) { return result; }

	// Getting data set mean (greek letter Mu)
	double dataSum = std::accumulate(data.begin(), data.end(), 0.0);
	double Mu = dataSum / (double)data.size();

	// Getting population standard deviation(greek letter sigma)
	double Sigma_SIGMA = 0.0;
	for (double x : data)
	{
		Sigma_SIGMA += (x - Mu) * (x - Mu);
	}
	double Sigma = sqrt(Sigma_SIGMA / (double)data.size());

	// Division by zero guard
	if (Sigma == 0) { return result; }

	// Applying the Zscaling formula to the data and putting it in the result vector
	for (int i = 0; i < data.size(); i++)
	{
		result[i] = (data[i] - Mu) / Sigma;
	}
	return result;
}

double random() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(-2, 2);
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
	// a value for easy training, not to be set manually.
	double lastOutputtedValue = 0;

	Perceptron(double weight, double Dbias, int inputnum) : esteem(weight), bias(Dbias) {
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
		double summation = bias;
		for (int i : weights) {
			summation += weights[i] * inputs[i];
		}
		lastOutputtedValue = summation;
		return summation;
	}

};

class MLP
{
public:
	size_t layerSize;
	size_t layerCount;
	size_t P_icount;
	double P_DefaultBias;
	// matrix of perceptrons
	std::vector<std::vector<Perceptron>> Neuron_M;

	MLP(size_t S, size_t C) 
		: layerSize(S), 
		layerCount(C), 
		Neuron_M(layerCount, std::vector<Perceptron>(layerSize, Perceptron(random(), P_DefaultBias, P_icount))) 
	{}

	/*
		activation function goes here. activation function needs to be specific to the model.
	*/

};

int main() {
	return 0;
}

