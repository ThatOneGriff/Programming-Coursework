#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <time.h> /// time
#include <string> /// 'std::wstring'

#include "Utils/Random.hpp"
#include "Utils/Strings.hpp"


int get_time()
{
	/// Copied from https://stackoverflow.com/a/68124506/15540979
	time_t rawtime;
	struct tm timeinfo;
	wchar_t buffer[20];

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	wcsftime(buffer, 20, L"%H%M%S", &timeinfo);

	return std::stoi(buffer);
}


#endif