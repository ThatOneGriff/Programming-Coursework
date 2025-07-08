#pragma once
#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <time.h> // time-based seed generation

/// Here be:
int randint(const unsigned int min, const unsigned int max);
int randint(const unsigned int max);
bool randint_percent(const unsigned int percent);


unsigned int _seed = time(NULL);

/// [min, max]. I DON'T THINK it supports negatives
int randint(const unsigned int min, const unsigned int max)
{
	if (max < min) return -1;
	srand(++_seed);
	return rand() % (max+1 - min) + min;
}

/// [0, max]. Does NOT support negatives!
int randint(const unsigned int max)
{
	if (max < 0) return -1;
	srand(++_seed);
	return rand() % (max+1);
}

/// Returns true if a percent% chance is hit
bool randint_percent(const unsigned int percent)
{
	if (percent > 100) return true;
	return randint(1, 100) <= percent;
}


#endif