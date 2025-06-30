#pragma once
#ifndef MESSAGEBOX_WRAPPER_HPP
#define MESSAGEBOX_WRAPPER_HPP

#include <string>
#include "strings.hpp"
using namespace System::Windows::Forms;

/// Here be:
void show_info   (const std::wstring& info,	   const std::wstring& heading = L"Информация");
void show_warning(const std::wstring& warning, const std::wstring& heading = L"Внимание!");
void show_error  (const std::wstring& error,   const std::wstring& heading = L"Ошибка");


const std::wstring program_info =
(std::wstring)L"Agora v.1.0 от 16.06.2025\n" // it was INSISTING I'm trying to initialize with 'System::String'
+ L"Курсовой проект от Первакова А.И.\n"
+ L"КубГАУ, Прикладная информатика, ИТ2403";


void show_info(const std::wstring& info, const std::wstring& heading/* = L""*/)
{
	MessageBox::Show(to_dotnet_string(info), to_dotnet_string(heading), MessageBoxButtons::OK, MessageBoxIcon::Information);
}


void show_warning(const std::wstring& warning, const std::wstring& heading/* = L"Внимание!"*/)
{
	MessageBox::Show(to_dotnet_string(warning), to_dotnet_string(heading), MessageBoxButtons::OK, MessageBoxIcon::Warning);
}


void show_error(const std::wstring& error, const std::wstring& heading/* = L"Ошибка"*/)
{
	MessageBox::Show(to_dotnet_string(error), to_dotnet_string(heading), MessageBoxButtons::OK, MessageBoxIcon::Error);
}


#endif