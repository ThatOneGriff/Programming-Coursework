#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

int _seed = time(NULL);
int randint(const unsigned int min, const unsigned int max)
{
	srand(++_seed);
	return rand() % (max+1 - min) + min;
}

int randint(const unsigned int max)
{
	srand(++_seed);
	return rand() % (max+1);
}

#endif