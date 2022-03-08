#include <iostream>
#include <random>

// As of C++20, the Mersenne Twister algorithm is the only PRNG (psuedo-random number generator)
// that ships with C++ that has both decent performance and quality.

int main() {
	// The random library has support for two Mersenne Twister types:
	//
	//    mt19937 is a Mersenne Twister that generates 32-bit unsigned integers
	//    mt19937_64 is a Mersenne Twister that generates 64-bit unsigned integers

	std::mt19937 mt; // Instantiate a 32-bit Mersenne Twister

	// Print a bunch of random numbers
	for (int count{1}; count <= 40; ++count) {
		std::cout << mt() << '\t'; // generate a random number

		// If we've printed 5 numbers, start a new row
		if (count % 5 == 0)
			std::cout << '\n';
	}

	return 0;
}
