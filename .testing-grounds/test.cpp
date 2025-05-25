#include <iostream>
#include "Contacts.hpp"


int main()
{
	for (int i = 0; i < 15; i++)
	{
		Phone_Number number;
		std::cout << number.as_text() << '\n';
		std::cout << number.concealed() << "\n\n";
	}

	return 0;
}