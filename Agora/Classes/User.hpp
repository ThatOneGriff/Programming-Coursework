#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <vector>

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

	std::wstring website;
	/// This is dirty, but doing something about websites available only with 'Companies' would make it even dirtier.
	/// It's inaccessible from 'Individual' anyway.

	/// POSSIBLE MEMORY LEAK: Trying to wrap it in a destructor caused errors I have no time to fix.
	Name* name;
	Phone_Number phone_number;
	std::wstring email;
	std::wstring extra_contacts;


	User(const Phone_Number& _phone_number,			    const std::wstring& _email/* = L""*/,
		 const std::wstring& _extra_contacts/* = L""*/, const std::wstring& _account_creation_date/* = get_date()*/)
	: phone_number(_phone_number), email(_email), extra_contacts(_extra_contacts), account_creation_date(_account_creation_date)
	{}

	/// Temporary measure before (and if) I decide to go with JSON.
	virtual std::wstring serialize() = 0;

protected:

	const std::wstring account_creation_date;
};



class Individual : public User
{
public:

	Individual(const Individual_Name& _name,	 const Phone_Number& _phone_number,
			   const std::wstring& _email = L"", const std::wstring& _extra_contacts = L"",
			   const std::wstring& _account_creation_date = get_date())
	: name_obj(_name), User(_phone_number, _email, _extra_contacts, _account_creation_date)
	{
		/// Pointer magic. Basically, 'name' used to be a pointer
		/// to an object you gave the constructor. It resulted in
		/// a problem where 'name' kinda existed, but kinda was in this limbo
		name = &name_obj;
	}


	std::wstring serialize()
	{
		std::wstring result =
			L"individual\n"
			+ account_creation_date  + L'\n'
			+ name->get_full()		 + L'\n'
			+ phone_number.serialized() + L'\n'
			+ email			 + L'\n'
			+ extra_contacts + L'\n';

		return result;
	}

private:

	Individual_Name name_obj;
};



class Company : public User
{
public:

	Company(const Company_Name& _name,	const Phone_Number& _phone_number,
			const std::wstring& _email, const std::wstring& _website,
			const std::wstring& _extra_contacts = L"", const std::wstring& _account_creation_date = get_date())
	: name_obj(_name), User(_phone_number, _email, _extra_contacts, _account_creation_date)
	{
		website = _website;
		/// Pointer magic. Basically, 'name' used to be a pointer
		/// to an object you gave the constructor. It resulted in
		/// a problem where 'name' kinda existed, but kinda was in this limbo
		name = &name_obj;
	}


	std::wstring serialize()
	{
		std::wstring result =
			L"company\n"
			+ account_creation_date  + L'\n'
			+ name->get_full()		 + L'\n'
			+ phone_number.serialized() + L'\n'
			+ email			 + L'\n'
			+ extra_contacts + L'\n'
			+ website		 + L'\n';

		return result;
	}

private:

	Company_Name name_obj;
};

#endif