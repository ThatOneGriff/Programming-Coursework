#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <time.h>

using namespace System;


#pragma region = Random =

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

#pragma endregion


#pragma region = Strings =

System::String^ to_dotnet_string(const std::string& target)
{
	System::String^ result = "";
	for (const char& c : target)
		result += System::Convert::ToChar(c);
	return result;
}


std::string transliterate(const std::string& target)
{
	/*for (int i = 0; i < target.size(); i+=2)
	{
		std::string letter = std::string() + target[i-1] + target[i];
		std::cout << letter;
	}*/

	return "-1";
}

#pragma endregion


#endif