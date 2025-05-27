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
	return (target >= L'À' && target <= L'ÿ')
		|| (target == L'¨' || target == L'¸')
		|| (target >= L'A' && target <= L'z');
}


wchar_t lower(wchar_t target)
{
	if (target < L'à')
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
	{L'à', L"a"},  {L'á', L"b"},  {L'â', L"v"},   {L'ã', L"g"}, {L'ä', L"d"}, {L'å', L"e"}, {L'¸', L"yo"}, {L'æ', L"zh"},
	{L'ç', L"z"},  {L'è', L"i"},  {L'é', L"y"},   {L'ê', L"k"}, {L'ë', L"l"}, {L'ì', L"m"}, {L'í', L"n"},  {L'î', L"o"},
	{L'ï', L"p"},  {L'ð', L"r"},  {L'ñ', L"s"},   {L'ò', L"t"}, {L'ó', L"u"}, {L'ô', L"f"}, {L'õ', L"kh"}, {L'ö', L"ts"},
	{L'÷', L"ch"}, {L'ø', L"sh"}, {L'ù', L"sch"}, {L'ú', L"y"}, {L'û', L"y"}, {L'ü', L""},  {L'ý', L"e"},  {L'þ', L"yu"},
	{L'ÿ', L"ya"}
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