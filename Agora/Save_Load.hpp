#pragma once
#ifndef SAVE_LOAD_HPP
#define SAVE_LOAD_HPP

#include <codecvt>    /// Locales
#include <fstream>	  /// File reading and writing
#include <string>	  /// 'std::wstring>
#include <vector>	  /// vectors of 'std::wstring'

#include "Classes/listing.hpp"
#include "Classes/user.hpp"
#include "utils.hpp"

/// This file is for saving and loading 'Individuals's.
/// Companies are predefined instead of randomly generated.
/// [!!!] FILE MANIPULATION is in 'Utils/files.hpp'.

/// Here be:

const std::wstring SAVEFILES_DIRECTORY  = L"./SaveData/";
const std::string  USER_SAVEFILE_NAME_S =  "user.txt";
const std::wstring USER_SAVEFILE_NAME   = L"user.txt";
const std::wstring USER_LISTINGS_FILE_NAME		 = L"user_listings.txt";
const std::wstring SAVED_INDIVIDUALS_FILE_NAME = L"listing_individuals.txt";

User* load(const std::wstring address);
void  save(User* user, std::wstring address = L"", std::vector<Listing> active_listings = {});

std::vector<Listing> load_listings(User* user);
void load_predefined_companies();
void load_saved_individuals();
std::vector<User*> PREDEFINED_COMPANIES;
std::vector<User*> SAVED_INDIVIDUALS;



/// POSSIBLE MEMORY LEAK: No time to deal with this pointer magic.
User* load(const std::wstring filename)
{
	std::wifstream savefile(SAVEFILES_DIRECTORY + filename);

	/// Empty check
	if (is_empty(SAVEFILES_DIRECTORY + filename))
	{
		savefile.close();
		return nullptr;
	}

	// Copied from: https://stackoverflow.com/a/3950840/15540979
	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	savefile.imbue(loc);
	// The copied code deals with locales, enabling a full save into file without errors. I spent so much time!

	/// Account type check
	std::wstring account_type;
	getline(savefile, account_type);
	if (account_type != L"individual" && account_type != L"company")
	{
		show_error((std::wstring)L"'" + filename + L"' - неправильный тип аккаунта '" + account_type + L"'");
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
	return nullptr; /// Something that under NO circumstance should happen
}


/// 'User*' instead of raw text as a protection from saving jackshit
void save(User* user, std::wstring filename/* = L""*/, std::vector<Listing> active_listings/* = {}*/)
{
	if (filename == L"")
		filename = user->name->as_filename();
	std::wofstream savefile(SAVEFILES_DIRECTORY + filename);

	// Copied from: https://stackoverflow.com/a/3950840/15540979
	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	savefile.imbue(loc);
	// The copied code deals with locales, enabling a full save into file without errors. I spent so much time!

	savefile << user->serialize();
	savefile.close();

	
	if (active_listings.empty())
		return;
	std::wofstream savefile_listings(SAVEFILES_DIRECTORY + USER_LISTINGS_FILE_NAME);
	savefile_listings.imbue(loc);
	std::wofstream savefile_individuals(SAVEFILES_DIRECTORY + SAVED_INDIVIDUALS_FILE_NAME);
	savefile_individuals.imbue(loc);

	for (Listing& listing : active_listings)
	{
		savefile_listings << listing.serialize() << L'\n';

		if ((listing.contractor != user) && (typeid(*listing.contractor) == typeid(Individual)))
			savefile_individuals << listing.contractor->serialize() << L'\n';
		else if ((listing.customer != user) && (typeid(*listing.customer) == typeid(Individual)))
			savefile_individuals << listing.customer->serialize() << L'\n';
	}
	savefile_listings.close();
	savefile_individuals.close();
}


std::vector<Listing> load_listings(User* user)
{
	if (PREDEFINED_COMPANIES.empty())
	{
		show_error(L"Predefined companies need to be loaded before listings.");
		return {};
	}

	std::wifstream savefile(SAVEFILES_DIRECTORY + USER_LISTINGS_FILE_NAME);

	/// Empty check
	if (is_empty(SAVEFILES_DIRECTORY + USER_LISTINGS_FILE_NAME))
	{
		savefile.close();
		return {};
	}

	// Copied from: https://stackoverflow.com/a/3950840/15540979
	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	savefile.imbue(loc);
	// The copied code deals with locales, enabling a full save into file without errors. I spent so much time!

	std::vector<std::wstring> raw_data = to_string_bundle(savefile);
	savefile.close();

	std::vector<Listing> result;
	for (int i = 0; i < raw_data.size(); i++)
	{
		if (raw_data[i] == L"")
			continue;
		/// Reading raw data in segments of 5
		std::wstring name		= raw_data[i++];
		unsigned int payment_hr = stoi(raw_data[i++]);
		unsigned int total_hrs  = stoi(raw_data[i++]);

		User *contractor = nullptr, *customer = nullptr;
		std::wstring contractor_path = raw_data[i++];
		if (contractor_path == L"user.txt")
			contractor = user;
		// I'm sure I can refactor this.
		else
		{
			for (User* company : PREDEFINED_COMPANIES)
			{
				if (company->name->as_filename() == contractor_path)
					contractor = company;
			}
			if (contractor == nullptr); /// contractor NOT found in companies
			{
				for (User* individual : SAVED_INDIVIDUALS)
				{
					if (individual->name->as_filename() == contractor_path)
						contractor = individual;
				}
			}
		}

		std::wstring customer_path = raw_data[i];
		if (customer_path == L"user.txt")
			customer = user;
		else
		{
			for (User* company : PREDEFINED_COMPANIES)
			{
				if (company->name->as_filename() == customer_path)
					customer = company;
			}
			if (contractor == nullptr) /// customer NOT found in companies
			{
				for (User* individual : SAVED_INDIVIDUALS)
				{
					if (individual->name->as_filename() == customer_path)
						customer = individual;
				}
			}
		}

		Listing new_listing(name, total_hrs, payment_hr, contractor, customer);
		result.push_back(new_listing);
	}

	return result;
}


/// Wish I could do that via scanning all the files in a folder.
/// Sadly, 'filesystem' gave me some hellish errors...
const std::wstring _PREDEFINED_COMPANY_SAVEPATHS[10] = {
	L"agroprom.txt", L"ekoresurs.txt",	    L"energoplyus.txt", L"finansovyy_alyans.txt", L"innovatsii_buduschego.txt",
	L"medtekh.txt",  L"softrazrabotka.txt", L"stroymaster.txt", L"tekhnoprogress.txt",    L"tsifrovye_resheniya.txt"
};
/// POSSIBLE MEMORY LEAK
void load_predefined_companies()
{
	PREDEFINED_COMPANIES.reserve(10);
	
	for (std::wstring filename : _PREDEFINED_COMPANY_SAVEPATHS)
	{
		filename = L"/Predefined_Companies/" + filename;
		User* new_company = load(filename);
		PREDEFINED_COMPANIES.push_back(new_company);
	}
}


void load_saved_individuals()
{
	std::wifstream savefile(SAVEFILES_DIRECTORY + SAVED_INDIVIDUALS_FILE_NAME);

	/// Empty check
	if (is_empty(SAVEFILES_DIRECTORY + SAVED_INDIVIDUALS_FILE_NAME))
	{
		savefile.close();
		return;
	}

	// Copied from: https://stackoverflow.com/a/3950840/15540979
	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	savefile.imbue(loc);
	// The copied code deals with locales, enabling a full save into file without errors. I spent so much time!

	std::vector<std::wstring> raw_data = to_string_bundle(savefile);
	savefile.close();


	std::wstring birth_date, name, phone_number, email, extra_contacts;

	for (int i = 0; i < raw_data.size(); i++)
	{
		if (raw_data[i] == L"")
			continue;
		++i; /// accounting for 'individual' line in every serialization
		/// Reading raw data in segments of 5
		birth_date     = raw_data[i++];
		name =			 raw_data[i++];
		phone_number   = raw_data[i++],
		email =			 raw_data[i++],
		extra_contacts = raw_data[i++];

		Date birth_date(birth_date);
		Phone_Number phone_number(separate(phone_number));
		Individual_Name name(separate(name));

		SAVED_INDIVIDUALS.push_back(new Individual(name, birth_date, phone_number, email, extra_contacts));
	}
}


#endif