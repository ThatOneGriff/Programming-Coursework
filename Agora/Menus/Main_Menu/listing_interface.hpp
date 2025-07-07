#pragma once
#ifndef LISTING_INTERFACE_HPP
#define LISTING_INTERFACE_HPP

#include <Windows.h>
#include "../../Classes/Listing.hpp"
#include "../../Utils.hpp"
using namespace Agora;
using namespace System::Windows::Forms;


namespace Agora
{
public ref class Listing_Interface
{
public:

	Listing* listing;
	
	GroupBox ^ui_group;
	Label    ^name, ^author;
	Button   ^author_info, ^accept;
	Label    ^label_per_hr, ^per_hr, ^label_hrs;
	Control  ^hrs; /// May be a 'NumericUpDown' or a 'Label'
	Label	 ^total;


	/// TODO
	Listing_Interface()
	
	{}


	bool has(Control^ node)
	{
		/// Maybe do it via an 'unordered_set'?
		return (
			   node == ui_group     || node == name   || node == author
			|| node == author_info  || node == accept
			|| node == label_per_hr || node == per_hr
			|| node == label_hrs    || node == hrs
			|| node == total
		);
	}
};
}


#endif