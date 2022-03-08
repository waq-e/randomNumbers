#include <iostream>
#include <random>

// As of C++20, the Mersenne Twister algorithm is the only PRNG (psuedo-random number generator)
// that ships with C++ that has both decent performance and quality.

int main() {
	// The random library has support for two Mersenne Twister types:
	//
	//    mt19937 is a Mersenne Twister that generates 32-bit unsigned integers
	//    mt19937_64 is a Mersenne Twister that generates 64-bit unsigned integers

	std::mt19937 mt1; // Instantiate a 32-bit Mersenne Twister

	// Print a bunch of random numbers
	for (int count{1}; count <= 40; ++count) {
		std::cout << mt1() << '\t'; // generate a random number

		// If we've printed 5 numbers, start a new row
		if (count % 5 == 0)
			std::cout << '\n';
	}

	// Rolling a dice using Mersenne Twister

	// Unfortunately, PRNGs can’t do this. They can only generate numbers that use the full range.
	// What we need is some way to convert a number that is output from our PRNG into a value in
	// the smaller range we want (with an even probability of each value occurring).

	// Fortunately, the random library can help us here, in the form of random number distributions.
	// A random number distribution converts the output of a PRNG into some other distribution
	// of numbers.
	// seed the PRNG:
	std::mt19937 mt2{ std::random_device{}() };

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt2) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}
