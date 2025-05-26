#pragma once
#ifndef NAME_HPP
#define NAME_HPP

#include <iostream>
#include <string>

class Name; /// virtual class
class Company_Name;
class Individual_Name;

/// ��	�������� �� 'wstring'-��.



class Name
{
public:

	virtual std::wstring get_full() = 0;
	virtual std::wstring get_short() = 0;


	Name(const std::wstring& _name)
	: name(_name)
	{}

protected:

	std::wstring name;
};



class Company_Name : public Name
{
public:

	Company_Name(const std::wstring& _legal_form, const std::wstring& _name)
	: legal_form(_legal_form), Name(_name)
	{}

	// ��� "���������"
	std::wstring get_full()
	{
		return legal_form + L" \"" + name + L'"';
	}

	// ���������
	std::wstring get_short()
	{
		return name;
	}

private:

	std::wstring legal_form;
};



class Individual_Name: public Name
{
public:

	Individual_Name(const std::wstring& _name, const std::wstring& _surname, const std::wstring& _patronym)
	: Name(_name), surname(_surname), patronym(_patronym)
	{}

	// ������ ���� ��������
	std::wstring get_full()
	{
		return surname + L' ' + name + L' ' + patronym;
	}

	// ������ �.�.
	std::wstring get_short()
	{
		return surname + L' ' + name[0] + L'.' + patronym[0] + L'.';
	}

private:

	std::wstring surname,
				 patronym;
};



#endif