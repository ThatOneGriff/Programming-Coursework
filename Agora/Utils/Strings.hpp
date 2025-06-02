#pragma once
#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <string>		 // 'std::wstring'
#include <unordered_map> // mapping chars for transliteration
using namespace System;  // all things CLR

#define BACKSPACE (char)8
#define ENTER	  '\r'


bool	is_digit (const System::Char target);
bool	is_letter(System::Char target, const std::wstring additional_symbols = L"-' �");
wchar_t lower(wchar_t target);
System::String^ to_dotnet_string(const std::wstring& target);
std::wstring	to_std_wstring(System::String^ target);
std::wstring	translit_CtoL(const std::wstring& target);



bool is_digit(const System::Char target)
{
	return (target >= L'0' && target <= L'9')
		|| (target == BACKSPACE);// || target == ENTER); // ENTER is used to switch input focus,
														 // thus *evilly* MUST NOT BE TOLERATED
}


// I suppose 'System::Char' is just 'wchar' without directly stating it. Gods I hate .NET
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
	if (target < L'�' && target >= L'�')
		return target - (L'�' - L'�');
	else if (target < L'a' && target >= L'A')
		return target - (L'A' - L'a');
	else
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


// it's non-const to read from '[]'
std::unordered_map<wchar_t, std::wstring> _char_transliterations {
	{L'�', L"a"},  {L'�', L"b"},  {L'�', L"v"},   {L'�', L"g"}, {L'�', L"d"}, {L'�', L"e"}, {L'�', L"yo"}, {L'�', L"zh"},
	{L'�', L"z"},  {L'�', L"i"},  {L'�', L"y"},   {L'�', L"k"}, {L'�', L"l"}, {L'�', L"m"}, {L'�', L"n"},  {L'�', L"o"},
	{L'�', L"p"},  {L'�', L"r"},  {L'�', L"s"},   {L'�', L"t"}, {L'�', L"u"}, {L'�', L"f"}, {L'�', L"kh"}, {L'�', L"ts"},
	{L'�', L"ch"}, {L'�', L"sh"}, {L'�', L"sch"}, {L'�', L"y"}, {L'�', L"y"}, {L'�', L""},  {L'�', L"e"},  {L'�', L"yu"},
	{L'�', L"ya"}
};
std::wstring translit_CtoL(const std::wstring& target)
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

#endif