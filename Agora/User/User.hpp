#pragma once
#ifndef USER_HPP
#define USER_HPP

#include			"Contacts.hpp";
#include "Components/Contractor_Info.hpp"
#include "Components/Name.hpp"
#include		 "../Utils.hpp";

/// Here be:
class User;
class Individual;
class Company;

Individual random_individual();
Company	   random_company();



#pragma region = Classes =

/// Parent class for 'Individual' and 'Company'
class User
{
public:

	Phone_Number phone_number;
	Email email;
	std::wstring extra_contacts;

	Contractor_Info contractor_info;


	User(const Phone_Number& _phone_number, const Email& _email/* = _EMPTY*/, const std::wstring& _extra_contacts/* = L""*/)
	: phone_number(_phone_number), email(_email), extra_contacts(_extra_contacts)
	{}
};



class Individual : public User
{
public:
	
	Individual_Name name;


	Individual(const Individual_Name& _name,	   const Phone_Number& _phone_number,
			   const Email& _email = _EMPTY_EMAIL, const std::wstring& _extra_contacts = L"")
	: name(_name), User(_phone_number, _email, _extra_contacts)
	{}
};



class Company : public User
{
public:
	
	Company_Name name;
	std::wstring website;

	Company(const Company_Name& _name, const Phone_Number& _phone_number,
			const Email& _email,	   const std::wstring& _website,
			const std::wstring& _extra_contacts = L"")
	: name(_name), User(_phone_number, _email, _extra_contacts), website(_website)
	{}
};

#pragma endregion



#pragma region = Functions =

Individual random_invididual()
{
	// Random name, random phone number, random email
}

#pragma endregion



#endif