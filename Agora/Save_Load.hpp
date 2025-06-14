#pragma once
#ifndef SAVE_LOAD_HPP
#define SAVE_LOAD_HPP

#include <fstream>
#include <string>

#include "Classes/User.hpp"
#include "Utils.hpp"


void save(User* user)
{
	std::wofstream savefile("user.txt");
	savefile << user->serialize();
	savefile.close();
}


#endif