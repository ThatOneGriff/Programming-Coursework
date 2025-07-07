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


	Listing_Interface^ operator=(Listing_Interface^ other)
	{
		if (this != other)
		{
			ui_group	 = other->ui_group;
			name	     = other->name;
			author		 = other->author;
			author_info  = other->author_info;
			accept		 = other->accept;
			label_per_hr = other->label_per_hr;
			per_hr		 = other->per_hr;
			label_hrs	 = other->label_hrs;
			hrs			 = other->hrs;
			total		 = other->total;

			listing	= other->listing;
		}
		return this;
	}


	/// For compiler not to whine.
	Listing_Interface()
	{}


	Listing_Interface(GroupBox^ _ui_group,     Label^  _name,   Label^ _author,
					  Button^   _author_info,  Button^ _accept,
					  Label^    _label_per_hr, Label^  _per_hr, Label^ _label_hrs,
					  Control^ _hrs,		   Label^ _total,   Listing* _listing)
	: ui_group(_ui_group),		   name(_name),		author(_author),
	  author_info(_author_info),   accept(_accept),
	  label_per_hr(_label_per_hr), per_hr(_per_hr), label_hrs(_label_hrs),
	  hrs(_hrs),				   total(_total),   listing(_listing)
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