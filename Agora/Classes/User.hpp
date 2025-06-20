#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <vector>

#include "User/name.hpp"
#include "User/phone_number.hpp"
#include   "../utils.hpp"

/// Here be:
class User;
class Individual;
class Company;



/// Parent class for 'Individual' and 'Company'
class User
{
public:

	/// POSSIBLE MEMORY LEAK: Trying to wrap it in a destructor caused errors I have no time to fix.
	Name* name;
	Phone_Number phone_number;
	Date birth_date;
	std::wstring email;
	/// This is dirty, but doing something about websites available only with 'Companies' would make it even dirtier.
	/// It's accessible, but useless from 'Individual' anyway.
	std::wstring website;
	std::wstring extra_contacts;


	User(const Date _birth_date,			   const Phone_Number& _phone_number,
		 const std::wstring& _email/* = L""*/, const std::wstring& _extra_contacts/* = L""*/)
	: birth_date(_birth_date), phone_number(_phone_number), email(_email), extra_contacts(_extra_contacts)
	{}

	/// Temporary measure before (and if) I decide to go with JSON.
	virtual std::wstring serialize() = 0;
};



class Individual : public User
{
public:

	Individual(const Individual_Name& _name,	 const Date& _birth_date, const Phone_Number& _phone_number,
			   const std::wstring& _email = L"", const std::wstring& _extra_contacts = L"")
	: name_obj(_name), User(_birth_date, _phone_number, _email, _extra_contacts)
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
			+ birth_date.dd_mm_yyyy(L" ") + L'\n'
			+ name->get_full()			  + L'\n'
			+ phone_number.serialized()   + L'\n'
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

	Company(const Company_Name& _name,	const Date& _birth_date, const Phone_Number& _phone_number,
			const std::wstring& _email, const std::wstring& _website,
			const std::wstring& _extra_contacts = L"")
	: name_obj(_name), User(_birth_date, _phone_number, _email, _extra_contacts)
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
			+ birth_date.dd_mm_yyyy(L" ")  + L'\n'
			+ name->get_full()			   + L'\n'
			+ phone_number.serialized()    + L'\n'
			+ email			 + L'\n'
			+ extra_contacts + L'\n'
			+ website		 + L'\n';

		return result;
	}

private:

	Company_Name name_obj;
};

#endif