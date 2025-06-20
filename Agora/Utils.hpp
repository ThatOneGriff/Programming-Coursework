#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

/// Bundle include of:

#include "Utils/files.hpp"
#include "Utils/datetime.hpp"
#include "Utils/random.hpp"
#include "Utils/strings.hpp"

using namespace System::Windows::Forms;


void messagebox(const std::wstring to_show)
{
	MessageBox::Show(to_dotnet_string(to_show));
}


#endif