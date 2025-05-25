#include <Windows.h>
#include "Main_Menu.hpp"
#include "Menus/Registration.hpp"
using namespace Agora;


int WINAPI WinMain(const HINSTANCE, const HINSTANCE, const LPSTR, const int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Registration);
    Application::Run(gcnew Main_Menu);
    return 0;
}