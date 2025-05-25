#pragma once
#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <iostream>
#include <string>
#include "../../Utils.hpp"

/// - The concept of e-mail;
/// - Random e-mail generator.

class Email;


//NOTE: current implementation is de-facto constant.
class Email
{
public:

private:
	const std::string body,
					  domain;
};


#endif