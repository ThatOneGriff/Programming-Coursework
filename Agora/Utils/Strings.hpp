#pragma once
#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <msclr\marshal_cppstd.h> // string type magic
#include <string>		 // 'std::wstring'
#include <sstream>
#include <unordered_map> // mapping chars for transliteration
#include <vector>
using namespace System;  // all things CLR

#define BACKSPACE (char)8
#define ENTER	  '\r'


std::wstring erase_at(const std::wstring& target, const unsigned int index);
bool	is_digit (const System::Char target);
bool	is_letter(System::Char target, const std::wstring additional_symbols = L"-' ¸");
wchar_t		 lower(wchar_t target);
std::wstring lower(std::wstring target);
std::vector<std::wstring> separate(const std::wstring& raw_data);
System::String^ to_dotnet_string(const std::wstring& target);
std::wstring	to_std_wstring(System::String^ target);
std::wstring	translit_CtoL(std::wstring target);


/// Because 'wstring::erase' simply refused to work.
std::wstring erase_at(const std::wstring& target, const unsigned int index)
{
	std::wstring result = L"";
	for (int i = 0; i < target.size(); i++)
	{
		if (i == index)
			continue;
		result += target[i];
	}
	return result;
}


bool is_digit(const System::Char target)
{
	return (target >= L'0' && target <= L'9')
		|| (target == BACKSPACE);// || target == ENTER); // ENTER is used to switch input focus,
														 // thus *evilly* MUST NOT BE TOLERATED
}


// I suppose 'System::Char' is just 'wchar' without directly stating it. Gods, I hate .NET
bool is_letter(System::Char target, const std::wstring additional_symbols/* = L"-' ¸"*/)
{
	target = lower(target);
	return (target >= L'à' && target <= L'ÿ')
		|| (target >= L'a' && target <= L'z')
		|| (additional_symbols.find(target) != std::wstring::npos)
		|| (target == BACKSPACE);// || target == ENTER);
}


wchar_t lower(wchar_t target)
{
	if (target < L'à' && target >= L'À') // ru-RU
		return target - (L'À' - L'à');
	else if (target < L'a' && target >= L'A') // en-EN
		return target - (L'A' - L'a');
	else
		return target;
}


std::wstring lower(std::wstring target)
{
	for (int i = 0; i < target.size(); i++)
		target[i] = lower(target[i]);
	return target;
}


std::vector<std::wstring> separate(const std::wstring& raw_data)
{
	std::vector<std::wstring> result;
	std::wstringstream raw_data_sstr;
	raw_data_sstr << raw_data;

	std::wstring word;
	while(raw_data_sstr >> word)
		result.push_back(word);

	return result;
}


// Copied from: https://stackoverflow.com/a/1405251/15540979
System::String^ to_dotnet_string(const std::wstring& target)
{
	return msclr::interop::marshal_as<System::String^>(target);
}


// Copied from: https://stackoverflow.com/a/1405251/15540979
std::wstring to_std_wstring(System::String^ target) // System::String^ doesn't like to be const
{
	return msclr::interop::marshal_as<std::wstring>(target);
}


// it's non-const to read from '[]'
std::unordered_map<wchar_t, std::wstring> _char_transliterations {
	{L'à', L"a"},  {L'á', L"b"},  {L'â', L"v"},   {L'ã', L"g"}, {L'ä', L"d"}, {L'å', L"e"}, {L'¸', L"yo"}, {L'æ', L"zh"},
	{L'ç', L"z"},  {L'è', L"i"},  {L'é', L"y"},   {L'ê', L"k"}, {L'ë', L"l"}, {L'ì', L"m"}, {L'í', L"n"},  {L'î', L"o"},
	{L'ï', L"p"},  {L'ð', L"r"},  {L'ñ', L"s"},   {L'ò', L"t"}, {L'ó', L"u"}, {L'ô', L"f"}, {L'õ', L"kh"}, {L'ö', L"ts"},
	{L'÷', L"ch"}, {L'ø', L"sh"}, {L'ù', L"sch"}, {L'ú', L"y"}, {L'û', L"y"}, {L'ü', L""},  {L'ý', L"e"},  {L'þ', L"yu"},
	{L'ÿ', L"ya"}
};
/// Lowers, because I don't want to check for both low and high chars, and I'm too lazy to convert
std::wstring translit_CtoL(std::wstring target)
{
	for (int i = 0; i < target.size(); i++)
	{
		wchar_t c = lower(target[i]);
		if (_char_transliterations.find(c) == _char_transliterations.end())
			target[i] = c;
		else
			target.insert(i, _char_transliterations[c]); // 'insert' because some transliterations are 2 (sh) or even 3 (sch) symbols long
	}
	return target;
}

#endif