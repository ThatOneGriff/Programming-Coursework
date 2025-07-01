#pragma once
#ifndef SAVE_LOAD_HPP
#define SAVE_LOAD_HPP

#include <codecvt>    /// Locales
#include <filesystem> /// for reading all files from a directory
namespace fs = std::filesystem;
#include <fstream>	  /// File reading and writing
#include <string>	  /// 'std::wstring>
#include <vector>	  /// vectors of 'std::wstring'

#include "Classes/user.hpp"
#include "utils.hpp"

/// This file is for saving and loading 'Individuals's.
/// Companies are predefined instead of randomly generated.
/// [!!!] FILE MANIPULATION is in 'Utils/files.hpp'.

/// Here be:
User* load(const std::wstring address);
void  save(User* user, std::wstring address = L"");
std::vector<Company> load_predefined_companies();
const std::vector<Company> PREDEFINED_COMPANIES = load_predefined_companies();

std::string  USER_SAVEFILE_NAME_S =  "user.txt";
std::wstring USER_SAVEFILE_NAME   = L"user.txt";



/// POSSIBLE MEMORY LEAK: No time to deal with this pointer magic.
User* load(const std::wstring address)
{
	#ifdef DEBUG
		return nullptr;
	#endif

	std::wifstream savefile(address);
	// Copied from: https://stackoverflow.com/a/3950840/15540979
	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	savefile.imbue(loc);
	// The copied code deals with locales, enabling a full save into file without errors. I spent so much time!

	/// Empty check
	if (is_empty(savefile))
	{
		savefile.close();
		return nullptr;
	}

	/// Account type check
	std::wstring account_type;
	getline(savefile, account_type);
	if (account_type != L"individual" && account_type != L"company")
	{
		show_error((std::wstring)L"'" + address + L"' - неправильный тип аккаунта '" + account_type + L"'");
		savefile.close();
		return nullptr;
	}

	/// Reading the rest of the data
	std::vector<std::wstring> raw_data = to_string_bundle(savefile, 7);
	savefile.close();

	/// Creating a new 'User*'

	/// POSSIBLE MEMORY LEAK: No time to deal with this pointer magic.
	/// WARNING: change of order => this breaks. Wish I had time to rewrite this to JSON.
	
	/// Common variables
	const std::wstring _birth_date =    raw_data[0], /* Note how we read from 0, not 1: */
					   _name =			raw_data[1], /* account type didn't get into raw data, */
					   _phone_number =  raw_data[2], /* because it's already been read. */
					   email =			raw_data[3],
					   extra_contacts =	raw_data[4];
	
	/// Absolutely no checks in place. This shit can break in so many ways

	Date birth_date(_birth_date);
	Phone_Number phone_number(separate(_phone_number));
	if (account_type == L"individual")
	{
		Individual_Name name(separate(_name));
		return new Individual(name, birth_date, phone_number, email, extra_contacts);
	}
	else if (account_type == L"company")
	{
		std::wstring website = raw_data[5];
		Company_Name name(separate(_name));
		return new Company(name, birth_date, phone_number, email, website, extra_contacts);
	}

	show_error(L"Аккаунт не создан по неизвестной причине.");
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


std::vector<Company> load_predefined_companies()
{
	std::vector<Company> result;

	// Copied from: https://stackoverflow.com/a/612176/15540979
	std::string path = "/predefined_companies";
	for (const auto & entry : fs::directory_iterator(path))
		show_info(entry.path().wstring());
}


#endif