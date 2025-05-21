#include <Windows.h>
#include "Main_Menu.hpp"
using namespace Agora;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Main_Menu);
    return 0;
}