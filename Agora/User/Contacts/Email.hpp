#pragma once
#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <iostream>
#include <string>
#include "../../Utils.hpp"

/// - The concept of e-mail.

class Email;


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