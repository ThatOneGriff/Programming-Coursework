#pragma once
#ifndef LISTING_HPP
#define LISTING_HPP

#include <string>
#include <unordered_map>
#include "user.hpp"

/// Represents an unsigned (1 user), signed (2 users), or completed contract.


/// ������, ������ �� ���� ����� - ������ ��������� ��������� ������ �� �����������.
/// ����������� ��, �� ���� - ���������� ������������ �����.
/// ����������, ��� � ���� ��������� 5/2 8 �./����.
const std::unordered_map<std::wstring, unsigned int> PAYMENT_TYPES = {
  /// �� ����� | ����. ������
	{    L"�.",  1 },
	{    L"�.",  8 },
	{  L"���.",  8*5 },  ///    5 = ������ - 2 ��������
	{  L"���.",  8*25 }, /// 25 = 4 ������ - 8 ��������
	{ L"������", 1 }     /// ��������� ������. ���������� � ������������.
};


enum Listing_Status
{
	Closed,
	Open,
	Signed,
	Finished
};


class Listing
{
public:

	const std::wstring name, time_units;
	const unsigned int payment_hr;
	unsigned int	   payment_total;

	const Date until;
	Listing_Status status = Listing_Status::Closed;


	/// ��� ������ �� �������� �������
	Listing(const std::wstring& _name,		 const Date& _until,
			const unsigned int  _payment_hr, const std::wstring& _time_units,
			User* _contractor = nullptr,     User* _customer = nullptr)
	: name(_name), until(_until),
	  payment_hr(_payment_hr), time_units(_time_units)
	{
		if (_contractor != nullptr)
			set_contractor(_contractor);
		if (_customer   != nullptr)
			set_customer  (_customer);

		if (time_units == L"������")
		{
			Listing(_name,       _until,
					_payment_hr, _contractor,  _customer);
			return;
		}

		payment_total = payment_hr * PAYMENT_TYPES.at(time_units) * -1/* PLACEHOLDER: days until contract ends */;
	}


	/// ��� ������ ������
	Listing(const std::wstring& _name,   const Date& _until,
		    const unsigned int  _payment_full,
			User* _contractor = nullptr, User* _customer = nullptr)
	: name(_name), until(_until),
	  payment_hr(_payment_full), time_units(L"������")
	{
		if (_contractor != nullptr)
			set_contractor(_contractor);
		if (_customer   != nullptr)
			set_customer  (_customer);

		payment_total = payment_hr;
	}


	void set_contractor(User* _contractor)
	{
		contractor = _contractor;
		if (customer == nullptr)
			status = Listing_Status::Open;
		else
			status = Listing_Status::Signed;
	}

	
	void set_customer(User* _customer)
	{
		customer = _customer;
		if (contractor == nullptr)
			status = Listing_Status::Open;
		else
			status = Listing_Status::Signed;
	}


private:

	///   ��������� | ��������
	User *contractor, *customer;
};


#endif