#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <time.h>


int _seed = time(NULL);

// [min, max]
int randint(const unsigned int min, const unsigned int max)
{
	srand(++_seed);
	return rand() % (max+1 - min) + min;
}

// [1, max]
int randint(const unsigned int max)
{
	srand(++_seed);
	return rand() % (max) + 1;
}


#endif