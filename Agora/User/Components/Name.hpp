#pragma once
#ifndef NAME_HPP
#define NAME_HPP

#include <iostream>
#include <string>

class Name; /// virtual class
class Company_Name;
class Individual_Name;



class Name
{
public:
	virtual void get_full() = 0;
	virtual void get_short() = 0;
protected:
	const std::string name;
};


class Company_Name : public Name
{
public:

private:
	const std::string legal_form;
};



#endif