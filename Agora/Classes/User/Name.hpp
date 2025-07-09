#pragma once
#ifndef NAME_HPP
#define NAME_HPP

#include <string>
#include <vector>
#include "../../utils.hpp"

class Name; /// abstract class
class Individual_Name;
class Company_Name;



class Name
{
public:

	Name(const std::wstring& _name)
	: name(_name)
	{}

	virtual std::wstring as_filename(const std::wstring& extension = L".txt") = 0;
	virtual std::vector<std::wstring> as_vector() = 0;
	virtual std::wstring get_normal() = 0;
	virtual std::wstring get_full() = 0;
	virtual std::wstring get_short() = 0;

protected:

	std::wstring name;
};



class Individual_Name: public Name
{
public:

	Individual_Name(const std::vector<std::wstring>& separated_raw_data)
	: surname(separated_raw_data[0]), Name(separated_raw_data[1]), patronym(separated_raw_data[2])
	{}

	Individual_Name(const std::wstring& _name, const std::wstring& _surname, const std::wstring& _patronym = L"")
	: Name(_name), surname(_surname), patronym(_patronym)
	{}

	/// ivanov_ivan_ivanovich<...>
	std::wstring as_filename(const std::wstring& extension = L".txt")
	{
		return translit_CtoL(surname) + L'_' + translit_CtoL(name) + L'_' + translit_CtoL(patronym) + extension;
	}

	std::vector<std::wstring> as_vector()
	{
		const std::vector<std::wstring> result = {surname, name, patronym};
		return result;
	}

	/// The form that'll appear in interface. Returns 'get_short()'
	std::wstring get_normal()
	{
		return get_short();
	}

	/// Иванов Иван Иванович
	std::wstring get_full()
	{
		if (patronym == L"")
			return surname + L' ' + name;
		return surname + L' ' + name + L' ' + patronym;
	}

	/// Иванов И.И.
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

	Company_Name(const std::vector<std::wstring>& separated_raw_data)
	: legal_form(separated_raw_data[0]), Name(separated_raw_data[1])
	{
		// adding the rest of the name. Kinda dirty code
		for (int i = 2; i < separated_raw_data.size(); i++)
			name += L" " + separated_raw_data[i];
	}


	Company_Name(const std::wstring& _legal_form, const std::wstring& _name)
	: legal_form(_legal_form), Name(_name)
	{}

	/// tmyvbabla<...>
	std::wstring as_filename(const std::wstring& extension = L".txt")
	{
		return translit_CtoL(name) + extension;
	}

	std::vector<std::wstring> as_vector()
	{
		const std::vector<std::wstring> result = {legal_form, name};
		return result;
	}

	/// The form that'll appear in interface. Returns 'get_full()'
	std::wstring get_normal()
	{
		return get_full();
	}

	/// ООО "Тмывбабла"
	std::wstring get_full()
	{
		return legal_form + L' ' + name; /// it's already wrapped in quote marks
	}

	/// Тмывбабла
	std::wstring get_short()
	{
		return name;
	}

private:

	std::wstring legal_form;
};



#endif