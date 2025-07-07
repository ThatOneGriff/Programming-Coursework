#pragma once
#ifndef MESSAGEBOX_WRAPPER_HPP
#define MESSAGEBOX_WRAPPER_HPP

#include <string>
#include "strings.hpp"
using namespace System::Windows::Forms;

/// Here be:
void show_info   (System::String^ info, const std::wstring& heading = L"����������");
void show_info   (const std::wstring& info,	   const std::wstring& heading = L"����������");
void show_warning(const std::wstring& warning, const std::wstring& heading = L"��������!");
void show_error  (const std::wstring& error,   const std::wstring& heading = L"������");


void show_info(System::String^ info, const std::wstring& heading/* = L"����������"*/)
{
	MessageBox::Show(info, to_dotnet_string(heading), MessageBoxButtons::OK, MessageBoxIcon::Information);
}


void show_info(const std::wstring& info, const std::wstring& heading/* = L"����������"*/)
{
	MessageBox::Show(to_dotnet_string(info), to_dotnet_string(heading), MessageBoxButtons::OK, MessageBoxIcon::Information);
}


void show_warning(const std::wstring& warning, const std::wstring& heading/* = L"��������!"*/)
{
	MessageBox::Show(to_dotnet_string(warning), to_dotnet_string(heading), MessageBoxButtons::OK, MessageBoxIcon::Warning);
}


void show_error(const std::wstring& error, const std::wstring& heading/* = L"������"*/)
{
	MessageBox::Show(to_dotnet_string(error), to_dotnet_string(heading), MessageBoxButtons::OK, MessageBoxIcon::Error);
}


#endif