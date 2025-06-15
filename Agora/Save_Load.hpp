#pragma once
#ifndef SAVE_LOAD_HPP
#define SAVE_LOAD_HPP

#include <codecvt> // Locale things ('save' func)
#include <fstream>
#include <string>

#include "Classes/User.hpp"
#include "Utils.hpp"

/// Here be:
User* load(const std::wstring address);
void  save(User* user, std::wstring address = L"");


/*User* load(const std::wstring address)
{
	std::wifstream savefile(address);
	
}*/


/// 'User*' instead of raw text as a protection from saving jackshit
void save(User* user, std::wstring address/* = L""*/)
{
	if (address == L"")
		address = user->name->as_filename(L".txt");
	std::wofstream savefile(address);
	// Copied from: https://stackoverflow.com/a/3950840/15540979
	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	savefile.imbue(loc);
	// The copied code deals with locales, enabling a full save into file without errors.
	savefile << user->serialize();
	savefile.close();
}


#endif