#pragma once
#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <msclr/marshal_cppstd.h> // string type magic
#include <string>		 // 'std::wstring'
#include <sstream>
#include <unordered_map> // mapping chars for transliteration
#include <vector>
#include <Windows.h>
using namespace System;  // all things CLR

#define BACKSPACE (char)8
#define ENTER	  '\r'


std::wstring erase_at(const std::wstring& target, const unsigned int index);
bool	is_digit (const System::Char target);
bool	is_letter(System::Char target, const std::wstring additional_symbols = L"-' �");
wchar_t		 lower(wchar_t target);
std::wstring lower(std::wstring target);
std::vector<std::wstring> separate(const std::wstring& raw_data);
int				dstoi(System::String^ target);
System::String^ to_dotnet_string(const std::wstring& target);
System::String^ to_dotnet_string(const int target);
std::wstring	to_std_wstring(System::String^ target);
std::wstring	translit_CtoL(const std::wstring& target);


System::String^ operator=(const std::wstring& wstr)
{
	return to_dotnet_string(wstr);
}


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
bool is_letter(System::Char target, const std::wstring additional_symbols/* = L"-' �"*/)
{
	target = lower(target);
	return (target >= L'�' && target <= L'�')
		|| (target >= L'a' && target <= L'z')
		|| (additional_symbols.find(target) != std::wstring::npos)
		|| (target == BACKSPACE);// || target == ENTER);
}


wchar_t lower(wchar_t target)
{
	if (target < L'�' && target >= L'�') // ru-RU
		return target - (L'�' - L'�');
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
	raw_data_sstr.str(raw_data);

	std::wstring word;
	while(raw_data_sstr >> word)
		result.push_back(word);

	return result;
}


int	dstoi(System::String^ target)
{
	std::wstring middleman = to_std_wstring(target);
	return _wtoi(middleman.c_str());
}


// Copied from: https://stackoverflow.com/a/1405251/15540979
System::String^ to_dotnet_string(const std::wstring& target)
{
	return msclr::interop::marshal_as<System::String^>(target);
}


/// 'int' to .NET string
System::String^ to_dotnet_string(const int target)
{
	std::wstring middleman = std::to_wstring(target);
	return to_dotnet_string(middleman);
}


// Copied from: https://stackoverflow.com/a/1405251/15540979
std::wstring to_std_wstring(System::String^ target) // System::String^ doesn't like to be const
{
	return msclr::interop::marshal_as<std::wstring>(target);
}


const std::unordered_map<wchar_t, std::wstring> _char_transliterations {
	{L'�', L"a"},  {L'�', L"b"},  {L'�', L"v"},   {L'�', L"g"}, {L'�', L"d"}, {L'�', L"e"}, {L'�', L"yo"}, {L'�', L"zh"},
	{L'�', L"z"},  {L'�', L"i"},  {L'�', L"y"},   {L'�', L"k"}, {L'�', L"l"}, {L'�', L"m"}, {L'�', L"n"},  {L'�', L"o"},
	{L'�', L"p"},  {L'�', L"r"},  {L'�', L"s"},   {L'�', L"t"}, {L'�', L"u"}, {L'�', L"f"}, {L'�', L"kh"}, {L'�', L"ts"},
	{L'�', L"ch"}, {L'�', L"sh"}, {L'�', L"sch"}, {L'�', L"y"}, {L'�', L"y"}, {L'�', L""},  {L'�', L"e"},  {L'�', L"yu"},
	{L'�', L"ya"}, {L' ', L"_"}
};

std::wstring translit_CtoL(const std::wstring& target)
{
	/// We could make edits directly to 'target',
	/// but it was causing very hard-to-catch errors.
	std::wstring result = L"";

	for (int i = 0; i < target.size(); i++)
	{
		/// Lowering happens because
		/// 1) translit is only ever needed while lowering,
		/// 2) I'm lazy
		wchar_t c = lower(target[i]);
		if (_char_transliterations.find(c) == _char_transliterations.end())
			result += c;
		else
			result += _char_transliterations.at(c);
	}
	return result;
}

#endif