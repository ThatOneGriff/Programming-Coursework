#include <string>
#include <Windows.h>

#include "Menus/Main_Menu/main_menu.hpp"
#include "Menus/Registration/registration.hpp"
// Should menus be able to include each other?
// Or should we opt for a more modular approach?

#include "utils.hpp"
using namespace Agora;
using namespace System::Windows::Forms;


[System::STAThread]
int WINAPI WinMain(const HINSTANCE, const HINSTANCE, const LPSTR, const int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	/// = Known Errors =
	/// - preemptive savefile check
	/// - date of 'est' is not even saved within company
	
	/// = TODO =
	/// - we could define a '=' between 'System::String^' and 'std::wstring'
	/// - string split by char
	/// - headings for every 'MessageBox'

	//#define DEBUG

	#ifndef DEBUG
	// Normal user sign in / sign up process
	User* user = load(USER_SAVEFILE_NAME);
	if (user == nullptr)
		Application::Run(gcnew Registration(nullptr));
	if (user == nullptr) /// Registration didn't work, or user closed the window.
		return 0; /// Closing the program.
	#endif
	
	/// Debug admin account.
	#ifdef DEBUG
	//Individual_Name admin_name(L"Артём", L"Перваков", L"Иванович");
	Company_Name admin_name(L"ИП", L"Артём Перваков");
	Phone_Number phone(L"+7", L"123", L"4567890");
	//Individual* user = new Individual(admin_name, phone, L"arper1vanin@gmail.com", L"", L"01.01.1970");
	Company* user = new Company(admin_name, phone, L"test@test.com", L"test.com", L"", L"01.01.1970");
	#endif

    Application::Run(gcnew Main_Menu(user));

    return 0;
}