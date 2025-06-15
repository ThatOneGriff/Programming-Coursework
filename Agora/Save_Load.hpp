#pragma once
#ifndef SAVE_LOAD_HPP
#define SAVE_LOAD_HPP

#include <codecvt> // Locale things ('save' func)
#include <fstream>
#include <string>
#include <vector>

#include "Classes/User.hpp"
#include "Utils.hpp"

/// Here be:
User* load(const std::wstring address);
void  save(User* user, std::wstring address = L"");

std::wstring USER_SAVEFILE_NAME = L"user.txt";



/// POSSIBLE MEMORY LEAK: No time to deal with this pointer magic.
User* load(const std::wstring address)
{
	/// For 'MessageBox'
	using namespace System::Windows::Forms;

	// Empty check
	std::wifstream savefile(address);
	if (is_empty(savefile))
	{
		MessageBox::Show(L"'" + to_dotnet_string(address) + L"' пуст или недоступен!");
		savefile.close();
		return nullptr;
	}

	// Account type check
	std::wstring account_type;
	getline(savefile, account_type);
	if (account_type != L"individual" && account_type != L"company")
	{
		MessageBox::Show(L"'" + to_dotnet_string(address) + L"' - неправильный тип аккаунта '" + to_dotnet_string(account_type) + L"'");
		savefile.close();
		return nullptr;
	}

	// Reading the rest of the data
	std::vector<std::wstring> raw_data = to_string_bundle(savefile, 7);
	savefile.close();

	// Creating a new 'User*'

	/// POSSIBLE MEMORY LEAK: No time to deal with this pointer magic.
	/// WARNING: change of order => this breaks. Wish I had time to rewrite this to JSON.
	
	// Common variables
	const std::wstring account_creation_date = raw_data[0], /* Note how we read from 0, not 1: */
					   _name =				   raw_data[1], /* account type didn't get into raw data, */
					   _phone_number =		   raw_data[2], /* because it's already been read. */
					   email =				   raw_data[3],
					   extra_contacts =		   raw_data[4];
	
	/// Absolutely no checks in place. This shit can break in so many ways

	Phone_Number phone_number(separate(_phone_number));
	if (account_type == L"individual")
	{
		Individual_Name name(separate(_name));
		return new Individual(name, phone_number, email, extra_contacts, account_creation_date);
	}
	else if (account_type == L"company")
	{
		std::wstring website = raw_data[6];
		Company_Name name(separate(_name));
		return new Company(name, phone_number, email, website, extra_contacts, account_creation_date);
	}

	MessageBox::Show("Account hasn't been created - something that should NOT have happened. Look into it immediately.");
	return nullptr; // Something that under NO circumstance should happen
}


/// 'User*' instead of raw text as a protection from saving jackshit
void save(User* user, std::wstring address/* = L""*/)
{
	if (address == L"")
		address = user->name->as_filename(L".txt");
	std::wofstream savefile(address);
	// Copied from: https://stackoverflow.com/a/3950840/15540979
	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	savefile.imbue(loc);
	// The copied code deals with locales, enabling a full save into file without errors. I spent so much time!
	savefile << user->serialize();
	savefile.close();
}


#endif