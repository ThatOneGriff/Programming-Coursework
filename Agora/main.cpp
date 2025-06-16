#include <string>
#include <Windows.h>

#include "Main_Menu.hpp"
#include "Menus/Registration/Registration.hpp"

#include "Utils.hpp"
using namespace Agora;
using namespace System::Windows::Forms;


[System::STAThread]
int WINAPI WinMain(const HINSTANCE, const HINSTANCE, const LPSTR, const int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	//#define DEBUG

	#ifndef DEBUG
	// Normal user sign in / sign up process
	User* user = load(USER_SAVEFILE_NAME);
	if (user == nullptr)
		Application::Run(gcnew Registration(nullptr));
	if (user == nullptr) /// Registration didn't work, or user closed the window.
		return 0; /// Closing the program.
	#endif

	/// = Known Errors =
	/// - preemptive savefile check
	
	/// Debug admin account.
	#ifdef DEBUG
	Individual_Name admin_name(L"Артём", L"Перваков", L"Иванович");
	Phone_Number phone(L"+7", L"123", L"4567890");
	Individual* user = new User(admin_name, phone, L"arper1vanin@gmail.com", L"", L"01.01.1970");
	#endif

    Application::Run(gcnew Main_Menu(user));

    return 0;
}