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


const std::unordered_map<wchar_t, std::wstring> _char_transliterations {
	{L'à', L"a"},  {L'á', L"b"},  {L'â', L"v"},   {L'ã', L"g"}, {L'ä', L"d"}, {L'å', L"e"}, {L'¸', L"yo"}, {L'æ', L"zh"},
	{L'ç', L"z"},  {L'è', L"i"},  {L'é', L"y"},   {L'ê', L"k"}, {L'ë', L"l"}, {L'ì', L"m"}, {L'í', L"n"},  {L'î', L"o"},
	{L'ï', L"p"},  {L'ð', L"r"},  {L'ñ', L"s"},   {L'ò', L"t"}, {L'ó', L"u"}, {L'ô', L"f"}, {L'õ', L"kh"}, {L'ö', L"ts"},
	{L'÷', L"ch"}, {L'ø', L"sh"}, {L'ù', L"sch"}, {L'ú', L"y"}, {L'û', L"y"}, {L'ü', L"y"}, {L'ý', L"e"},  {L'þ', L"yu"},
	{L'ÿ', L"ya"}
};
std::wstring transliterate_for_email(const std::wstring& target)
{

}

#pragma endregion


#endif