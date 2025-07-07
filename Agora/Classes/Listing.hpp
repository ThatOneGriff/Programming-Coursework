#pragma once
#ifndef LISTING_HPP
#define LISTING_HPP

#include <string>
#include <unordered_map>
#include "user.hpp"

/// Represents an open (1 user), signed (2 users), or finished contract.


/// Базово, каждый из этих типов - просто умножение почасовой оплаты на коэффициент.
/// Коэффициент же, по сути - количество отработанных часов.
/// Представим, что у всех поголовно 5/2 8 ч./день.
/*const std::unordered_map<std::wstring, unsigned int> PAYMENT_TYPES = {
  /// ЗА ВРЕМЯ | КОЭФ. ОПЛАТЫ
	{    L"ч.",  1 },
	{    L"д.",  8 },
	{  L"нед.",  8*5 },  ///    5 = неделя - 2 выходных
	{  L"мес.",  8*25 }, /// 25 = 4 недели - 8 выходных
	{ L"полная", 1 }     /// Отдельный случай. Отражается в коэффициенте.
};*/


/*enum Listing_Status
{
	Open,
	Signed,
	Finished
};*/


#define CUSTOMER_LISTING   1
#define CONTRACTOR_LISTING 2


class Listing
{
public:

	std::wstring name;
	//const std::wstring time_units;
	unsigned int payment_hr;
	unsigned int total_hrs;

	///   подрядчик |  заказчик
	User *contractor, *customer;

	//Listing_Status status = Listing_Status::Closed;


	Listing& operator=(const Listing& other)
	{
		if (this != &other)
		{
			name	      = other.name;
			payment_hr	  = other.payment_hr;
			total_hrs	  = other.total_hrs;

			contractor = other.contractor;
			customer   = other.customer;
		}
		return *this;
	}

	
	Listing(const std::wstring& _name,   const unsigned int _total_hrs, const unsigned int _payment_hr,
			User* _contractor = nullptr, User* _customer = nullptr)
	: name(_name), total_hrs(_total_hrs), payment_hr(_payment_hr),
	  contractor(_contractor), customer(_customer)
	{
		/*if (_contractor != nullptr)
			set_contractor(_contractor);
		if (_customer   != nullptr)
			set_customer  (_customer);*/

		/*if (time_units == L"полная")
		{
			Listing(_name,       _total_hrs,
					_payment_hr, _contractor,  _customer);
			return;
		}*/

		//payment_total = payment_hr * /*PAYMENT_TYPES.at(time_units) **/ total_hrs;
	}


	/// For compiler
	Listing(){}


	unsigned int payment_total()
	{
		return total_hrs * payment_hr;
	}


	/// Listings are only serialized if a customer and a contractor paired.
	const std::wstring serialize(User* user) /// 'user' for comparing and finding where is 'user.txt' needed as a savefile
	{
		std::wstring result =
			  name + L'\n'
			+ std::to_wstring(payment_hr) + L'\n'
			+ std::to_wstring(total_hrs)  + L'\n';

		if (contractor == nullptr) result += L'\n';
		else if (contractor == user) result += L"user.txt\n";
		else result += contractor->name->as_filename() + L'\n';

		if (customer == nullptr) result += L'\n';
		else if (customer == user) result += L"user.txt\n";
		else result += customer->name->as_filename() + L'\n';

		return result;
	}


	/*/// Для полной оплаты
	Listing(const std::wstring& _name,   const Date& _until,
		    const unsigned int  _payment_full,
			User* _contractor = nullptr, User* _customer = nullptr)
	: name(_name), until(_until),
	  payment_hr(_payment_full), time_units(L"полная")
	{
		if (_contractor != nullptr)
			set_contractor(_contractor);
		if (_customer   != nullptr)
			set_customer  (_customer);

		payment_total = payment_hr;
	}*/


	/*void set_contractor(User* _contractor)
	{
		contractor = _contractor;
		/*if (customer == nullptr)
			status = Listing_Status::Open;
		else
			status = Listing_Status::Signed;
	}

	
	void set_customer(User* _customer)
	{
		customer = _customer;
		/*if (contractor == nullptr)
			status = Listing_Status::Open;
		else
			status = Listing_Status::Signed;
	}*/
};


#endif