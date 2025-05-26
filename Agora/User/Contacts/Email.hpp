#pragma once
#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <iostream>
#include <string>
#include "../../Utils.hpp"

/// - The concept of e-mail;
/// - Random e-mail generator.

class Email;
const Email _EMPTY_EMAIL; /// default argument for constructors which don't require email


//NOTE: current implementation is de-facto constant.
class Email
{
public:

private:
	const std::string body,
					  domain;
};


#endif