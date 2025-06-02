#pragma once
#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <string>		 // 'std::wstring'
#include <unordered_map> // mapping chars for transliteration
using namespace System;  // all things CLR

#define BACKSPACE (char)8
#define ENTER	  '\r'


bool	is_digit (const System::Char target);
bool	is_letter(System::Char target, const std::wstring additional_symbols = L"-' ¸");
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
	if (target < L'à' && target >= L'À')
		return target - (L'À' - L'à');
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
	{L'à', L"a"},  {L'á', L"b"},  {L'â', L"v"},   {L'ã', L"g"}, {L'ä', L"d"}, {L'å', L"e"}, {L'¸', L"yo"}, {L'æ', L"zh"},
	{L'ç', L"z"},  {L'è', L"i"},  {L'é', L"y"},   {L'ê', L"k"}, {L'ë', L"l"}, {L'ì', L"m"}, {L'í', L"n"},  {L'î', L"o"},
	{L'ï', L"p"},  {L'ð', L"r"},  {L'ñ', L"s"},   {L'ò', L"t"}, {L'ó', L"u"}, {L'ô', L"f"}, {L'õ', L"kh"}, {L'ö', L"ts"},
	{L'÷', L"ch"}, {L'ø', L"sh"}, {L'ù', L"sch"}, {L'ú', L"y"}, {L'û', L"y"}, {L'ü', L""},  {L'ý', L"e"},  {L'þ', L"yu"},
	{L'ÿ', L"ya"}
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