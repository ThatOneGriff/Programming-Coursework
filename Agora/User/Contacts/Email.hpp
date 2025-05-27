#pragma once
#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <iostream>
#include <string>
#include "../../Utils.hpp"


class Email;
bool  is_email(const std::wstring& target);
Email to_email(const std::wstring& target);


bool is_email(const std::wstring& target)
{
	// Presence of ONE '@'
	if (std::count(target.begin(), target.end(), L'@') != 1)
		return false;

	// "*@gmail.com" - looking for ONE dot and 2+ symbols after it
	int dot_count = 0, symbols_after_dot = 0;
	for (int i = target.find(L'@'); i < target.size(); i++)
	{
		if (target[i] == L'.' && ++dot_count > 1)
			return false;
		if (dot_count == 1)
			++symbols_after_dot;
	}

	return (dot_count == 1 && symbols_after_dot >= 2);
}


class Email
{
public:

	Email& operator=(const Email& to_set)
	{
		if (this == &to_set) {
			return *this;
		}

		this->body   = to_set.body;
		this->domain = to_set.domain;

		return *this;
	}


	Email(const std::wstring& _body, const std::wstring& _domain)
	: body(_body), domain(_domain)
	{}

	Email()
	{}


	std::wstring get()
	{
		return body + L'@' + domain;
	}
	
private:
	std::wstring body,
				 domain;
};


#endif