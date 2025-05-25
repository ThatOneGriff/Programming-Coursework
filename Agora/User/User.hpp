#pragma once
#ifndef USER_HPP
#define USER_HPP

#include "../Utils.hpp";
#include "Contacts.hpp";
#include "Contractor_Info.hpp"

/// Here be:
class User;
class Individual;
class Company;



/// Parent class for 'Individual' and 'Company'
class User
{
public:

protected:
	std::string name;

	Phone_Number phone_number;
	Email email;
	std::string extra_contacts;

	Contractor_Info contractor_info;
};



class Individual : public User
{
public:
	
	Individual(const std::string&  _name,		  const std::string& _surname, const std::string& _patronym,
			   const Phone_Number& _phone_number, const Email& _email,		   const std::string& _extra_contacts)
	{}

private:

	//int age;
	std::string surname,
				patronym;
};



class Company : public User
{
public:


private:
	
	//TODO: categories and experience for each of them
};



#endif