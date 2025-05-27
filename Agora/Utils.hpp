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
bool	is_digit(const System::Char target);
bool	is_letter(const wchar_t target);
bool	is_letter(const System::Char target);
wchar_t lower(wchar_t target);
System::String^ to_dotnet_string(const std::wstring& target);
std::wstring	to_std_wstring(System::String^ target);
std::wstring	transliterate_for_email(const std::wstring& target);


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


bool is_digit(const System::Char target)
{
	return (target >= L'0' && target <= L'9');
}


// I suppose 'System::Char' is just 'wchar' without directly stating it. Gods I hate .net
bool is_letter(const System::Char target)
{
	// Might get some additional chars btw
	return (target >= L'�' && target <= L'�')
		|| (target == L'�' || target == L'�')
		|| (target >= L'A' && target <= L'z');
}


wchar_t lower(wchar_t target)
{
	if (target < L'�')
		target -= (L'A' - L'a');
	return target;
}


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


// non-const to read from '[]'
std::unordered_map<wchar_t, std::wstring> _char_transliterations {
	{L'�', L"a"},  {L'�', L"b"},  {L'�', L"v"},   {L'�', L"g"}, {L'�', L"d"}, {L'�', L"e"}, {L'�', L"yo"}, {L'�', L"zh"},
	{L'�', L"z"},  {L'�', L"i"},  {L'�', L"y"},   {L'�', L"k"}, {L'�', L"l"}, {L'�', L"m"}, {L'�', L"n"},  {L'�', L"o"},
	{L'�', L"p"},  {L'�', L"r"},  {L'�', L"s"},   {L'�', L"t"}, {L'�', L"u"}, {L'�', L"f"}, {L'�', L"kh"}, {L'�', L"ts"},
	{L'�', L"ch"}, {L'�', L"sh"}, {L'�', L"sch"}, {L'�', L"y"}, {L'�', L"y"}, {L'�', L""},  {L'�', L"e"},  {L'�', L"yu"},
	{L'�', L"ya"}
};
std::wstring transliterate_for_email(const std::wstring& target)
{
	std::wstring result = L"";
	for (const wchar_t& c : target)
	{
		// Avoiding accidental insert
		if (_char_transliterations.find(lower(c)) == _char_transliterations.end())
			continue;
		result += _char_transliterations[lower(c)];
	}
	return result;
}

#pragma endregion


#endif