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

	// No user registration now, programming main menu.
	/*User* user = load(USER_SAVEFILE_NAME);
	if (user == nullptr)
		Application::Run(gcnew Registration(nullptr, L"individual"));
	if (user == nullptr) /// Registration didn't work, or user closed the window.
		return 0; /// Closing the program.*/

	/// = Known Errors =
	/// - preemptive savefile check
	
	/// Debug admin account.
	Individual_Name admin_name(L"Артём", L"Перваков", L"Иванович");
	Phone_Number phone(L"+7", L"123", L"4567890");
	Individual admin(admin_name, phone, L"arper1vanin@gmail.com", L"", L"01.01.1970");

    Application::Run(gcnew Main_Menu(&admin));

    return 0;
}