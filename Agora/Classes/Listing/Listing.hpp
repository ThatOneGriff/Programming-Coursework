#pragma once
#ifndef LISTING_HPP
#define LISTING_HPP

#include <string>
#include "../user.hpp"

/// Represents an unsigned (1 user), signed (2 users), or completed contract.


class Listing
{
public:

	std::wstring name, description;
	unsigned int payment, length_days;

	///   заказчик   подрядчик
	User *customer, *contractor;

	Listing(const std::wstring& _name, const std::wstring& _description, const unsigned int _payment, const int _length_days)
	: name(_name), description(_description), payment(_payment), length_days(_length_days)
	{}w
};


#endif