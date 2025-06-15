#pragma once
#ifndef SAVE_LOAD_HPP
#define SAVE_LOAD_HPP

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


void save(User* user, std::wstring address/* = L""*/)
{
	if (address == L"")
		address = user->name->as_filename(L".txt");
	std::wofstream savefile(address);
	savefile << user->serialize();
	savefile.close();
}


#endif