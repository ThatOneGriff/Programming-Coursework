#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>	     // strings (try removing)
#include <time.h>		 // random
#include <string>		 // 'std::wstring'
#include <unordered_map> // mapping chars for transliteration
using namespace System;  // all things CLR

/// Here be:
int randint(const unsigned int min, const unsigned int max);
int randint(const unsigned int max);
System::String^ to_dotnet_string(const std::wstring& target);
std::wstring	to_std_wstring(System::String^ target);
std::wstring	transliterate(const std::wstring& target);



#pragma region = Random =

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

#pragma endregion


#pragma region = Strings =

System::String^ to_dotnet_string(const std::wstring& target)
{
	System::String^ result = "";
	for (const wchar_t& c : target)
		result += System::Convert::ToChar(c);
	return result;
}


std::wstring to_std_wstring(System::String^ target)
{
	/// copied code
	std::wstring result;
	using namespace Runtime::InteropServices;
	const wchar_t* chars = (const wchar_t*)(Marshal::StringToHGlobalAnsi(target)).ToPointer();
	result = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return result;
}

#pragma endregion


#endif