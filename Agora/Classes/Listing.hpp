#pragma once
#ifndef LISTING_HPP
#define LISTING_HPP

#include <string>
#include <unordered_map>
#include "user.hpp"

#define CUSTOMER_LISTING   1
#define CONTRACTOR_LISTING 2


class Listing
{
public:

	std::wstring name;
	unsigned int per_hr;
	unsigned int hrs;

	///   подрядчик |  заказчик | автор
	User *contractor, *customer, *author;


	Listing& operator=(const Listing& other)
	{
		if (this != &other)
		{
			name   = other.name;
			per_hr = other.per_hr;
			hrs	   = other.hrs;

			contractor = other.contractor;
			customer   = other.customer;
			author	   = other.author;
		}
		return *this;
	}


	bool operator==(const Listing& other)
	{
		return (
			name	  == other.name
			&& per_hr == other.per_hr
			&& hrs	  == other.hrs
			&& contractor == other.contractor
			&& customer   == other.customer
			&& author	  == other.author
		);
	}

	
	Listing(const std::wstring& _name,   const unsigned int _hrs, const unsigned int _per_hr,
			User* _contractor = nullptr, User* _customer = nullptr)
	: name(_name), hrs(_hrs), per_hr(_per_hr),
	  contractor(_contractor), customer(_customer)
	{
		if (contractor != nullptr)
			author = contractor;
		else if (customer != nullptr)
			author = customer;
		else
			show_error(L"Listing with no users.");
	}


	/// For compiler not to whine.
	Listing(){}


	unsigned int payment_total()
	{
		return hrs * per_hr;
	}

	
	/// Assumes every contract involves 'user' - inter-NPC contracts impossible.
	std::wstring serialize() /// 'user' for comparing and finding where is 'user.txt' needed as a savefile
	{
		std::wstring result =
			  name + L'\n'
			+ std::to_wstring(per_hr) + L'\n'
			+ std::to_wstring(hrs)  + L'\n';

		if (contractor == nullptr)
			result += L'\n';
		else if (contractor == author)
			result += contractor->name->as_filename() + L'\n';
		else
			result += L"user.txt\n";

		if (customer == nullptr)
			result += L'\n';
		else if (customer == author)
			result += customer->name->as_filename() + L'\n';
		else
			result += L"user.txt\n";

		return result;
	}
};


#endif