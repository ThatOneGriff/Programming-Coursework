#pragma once
#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <time.h> // time-based seed generation

/// Here be:
int randint(const unsigned int min, const unsigned int max);
int randint(const unsigned int max);


int _seed = time(NULL);

// [min, max]
int randint(const unsigned int min, const unsigned int max)
{
	srand(++_seed);
	return rand() % (max+1 - min) + min;
}

// [0, max]
int randint(const unsigned int max)
{
	srand(++_seed);
	return rand() % (max+1);
}


#endif