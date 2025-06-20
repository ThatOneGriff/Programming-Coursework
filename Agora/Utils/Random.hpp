#pragma once
#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <time.h> // time-based seed generation

/// Here be:
int randint(const unsigned int min, const unsigned int max);
int randint(const unsigned int max);


unsigned int _seed = time(NULL);

// [min, max]. DON'T THINK it supports negatives, maybe I'm wrong.
int randint(const unsigned int min, const unsigned int max)
{
	if (max < min) return -1;
	srand(++_seed);
	return rand() % (max+1 - min) + min;
}

// [0, max]. Does NOT support negatives!
int randint(const unsigned int max)
{
	if (max < 0) return -1;
	srand(++_seed);
	return rand() % (max+1);
}


#endif