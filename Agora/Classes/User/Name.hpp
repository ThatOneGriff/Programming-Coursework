#pragma once
#ifndef NAME_HPP
#define NAME_HPP

#include <string>

class Name; /// abstract class
class Individual_Name;
class Company_Name;



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



class Individual_Name: public Name
{
public:

	Individual_Name(const std::wstring& _name, const std::wstring& _surname, const std::wstring& _patronym = L"")
	: Name(_name), surname(_surname), patronym(_patronym)
	{}

	// Иванов Иван Иванович
	std::wstring get_full()
	{
		if (patronym == L"")
			return surname + L' ' + name;
		return surname + L' ' + name + L' ' + patronym;
	}

	// Иванов И.И.
	std::wstring get_short()
	{
		if (patronym == L"")
			return surname + L' ' + name[0] + L'.';
		return surname + L' ' + name[0] + L'.' + patronym[0] + L'.';
	}

private:

	std::wstring surname,
				 patronym;

friend std::wstring _get_email(const Individual_Name& name);
};



class Company_Name : public Name
{
public:

	Company_Name(const std::wstring& _legal_form, const std::wstring& _name)
	: legal_form(_legal_form), Name(_name)
	{}

	// ООО "Тмывбабла"
	std::wstring get_full()
	{
		return legal_form + L" \"" + name + L'"';
	}

	// Тмывбабла
	std::wstring get_short()
	{
		return name;
	}

private:

	std::wstring legal_form;
};



#endif