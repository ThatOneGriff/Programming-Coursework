#pragma once
#ifndef USER_HPP
#define USER_HPP

#include "User/Name.hpp"
#include "User/Phone_Number.hpp"
#include   "../Utils.hpp"

/// Here be:
class User;
class Individual;
class Company;



/// Parent class for 'Individual' and 'Company'
class User
{
public:

	Phone_Number phone_number;
	std::wstring email;
	std::wstring extra_contacts;


	User(const Phone_Number& _phone_number, const std::wstring& _email /* = L""*/, const std::wstring& _extra_contacts/* = L""*/)
	: phone_number(_phone_number), email(_email), extra_contacts(_extra_contacts), account_creation_date(get_date())
	{}

	/// Temporary measure before (and if) I decide to go with JSON.
	virtual std::wstring serialize() = 0;

protected:

	const std::wstring account_creation_date;
};



class Individual : public User
{
public:
	
	Individual_Name name;


	Individual(const Individual_Name& _name, const Phone_Number& _phone_number,
			   const std::wstring& _email = L"", const std::wstring& _extra_contacts = L"")
	: name(_name), User(_phone_number, _email, _extra_contacts)
	{}


	std::wstring serialize()
	{
		std::wstring result =
			L"ind\n"
			+ account_creation_date  + L'\n'
			+ name.get_full()		 + L'\n'
			+ phone_number.as_text() + L'\n'
			+ email			 + L'\n'
			+ extra_contacts + L'\n';

		return result;
	}
};



class Company : public User
{
public:
	
	Company_Name name;
	std::wstring website;


	Company(const Company_Name& _name,    const Phone_Number& _phone_number, const std::wstring& _email,
		    const std::wstring& _website, const std::wstring& _extra_contacts = L"")
	: name(_name), User(_phone_number, _email, _extra_contacts), website(_website)
	{}


	std::wstring serialize()
	{
		std::wstring result =
			L"com\n"
			+ account_creation_date  + L'\n'
			+ name.get_full()		 + L'\n'
			+ phone_number.as_text() + L'\n'
			+ email			 + L'\n'
			+ website		 + L'\n'
			+ extra_contacts + L'\n';

		return result;
	}
};

#endif