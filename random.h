// ECE 209, Fall 2025 - Program 2
// random numbers

#ifndef RANDOM_H
#define RANDOM_H

// set starting value for LFSR-based random number generator
void seedRandom(unsigned int seed);

// return a random integer between 0 and limit-1
unsigned int getRandom(unsigned int limit);

#endif // RANDOM_H
