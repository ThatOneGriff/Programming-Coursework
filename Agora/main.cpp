#include <string>
#include <Windows.h>

#include "Menus/Main_Menu/main_menu.hpp"
#include "Menus/Registration/registration.hpp"

#include "utils.hpp"
using namespace Agora;
using namespace System::Windows::Forms;


[System::STAThread]
int WINAPI wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
	
	/// = TODO =
	/// - string split by char
	/// - headings for every 'MessageBox'
	
	/// = Possibilities =
	/// - we could define a '=' between 'System::String^' and 'std::wstring'

	//#define DEBUG

	#ifndef DEBUG
	/// Release sign in / sign up process.
	User* user = load(USER_SAVEFILE_NAME);
	if (user == nullptr) /// Not registered.
	{
		Application::Run(gcnew Registration(user));
		user = load(USER_SAVEFILE_NAME); /// loading saved data
	}
	if (user == nullptr) /// Registration didn't work, or user closed the window.
		return 0;
	#endif
	
	#ifdef DEBUG
	/// Debug admin account. Un-/comment for Individual/Company via-code switch.
	Date birth_date(01, 01, 1970);
	Phone_Number phone(L"+7", L"123", L"4567890");
	//Individual_Name admin_name(L"Артём", L"Перваков", L"Иванович");
	//Individual_Name admin_name(L"Артём", L"Перваков", L"Иванович");
	Company_Name admin_name(L"ИП", L"Артём Перваков");
	//Individual* user = new Individual(admin_name, phone, L"arper1vanin@gmail.com", L"", L"01.01.1970");
	Company* user = new Company(admin_name, birth_date, phone, L"test@test.com", L"test.com");
	#endif

    Application::Run(gcnew Main_Menu(user));

    return 0;
}