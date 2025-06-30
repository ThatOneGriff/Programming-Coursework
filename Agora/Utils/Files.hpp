#pragma once
#ifndef FILES_HPP
#define FILES_HPP

#include <fstream>
#include <string>
#include <vector>

/// Here be:
bool is_empty(std::wifstream& file);
std::vector<std::wstring> to_string_bundle(std::wifstream& file, const unsigned int expected_size = 0);


// Copied from https://stackoverflow.com/a/2390938/15540979
bool is_empty(std::wifstream& file)
{
	return file.peek() == std::wifstream::traits_type::eof();
}


/// NOTE: function assumes the file has been checked
std::vector<std::wstring> to_string_bundle(std::wifstream& file, const unsigned int expected_size/* = 0*/)
{
	std::wstring file_line;
	std::vector<std::wstring> raw_data;
	raw_data.reserve(expected_size);
	while(getline(file, file_line))
		raw_data.push_back(file_line);
	return raw_data;
}



#endif