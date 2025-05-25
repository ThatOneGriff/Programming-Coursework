#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>	    // strings (TRY <string>?)
#include <time.h>		// random
using namespace System; // all things CLR


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


std::string to_cpp_string(System::String^ target)
{
	// copied code
	std::string result;
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(target)).ToPointer();
	result = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return result;
}


std::string transliterate(const std::string& target)
{
	// WARNING: may break without <wstring>



	return "-1";
}

#pragma endregion


#endif