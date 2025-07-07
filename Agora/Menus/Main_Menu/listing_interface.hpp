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
	
	GroupBox ^ui_group;
	Label    ^name, ^author;
	Button   ^author_info, ^accept;
	Label    ^label_per_hr, ^per_hr, ^label_hrs;
	Control  ^hrs; /// May be a 'NumericUpDown' or a 'Label'
	Label	 ^total;

	Listing* listing;


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
					  Control^  _hrs,		   Label^ _total)
	: ui_group(_ui_group),		   name(_name),		author(_author),
	  author_info(_author_info),   accept(_accept),
	  label_per_hr(_label_per_hr), per_hr(_per_hr), label_hrs(_label_hrs),
	  hrs(_hrs),				   total(_total)
	{}

	
	/// Intended only for UI's with variable hour settings!
	void calculate_and_display_total(const unsigned int total_hrs)
	{
		listing->total_hrs = total_hrs;
		total->Text = L"Итого, ₽: " + listing->payment_total();
	}


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


	void set_listing(Listing* new_listing, const unsigned int listing_type)
	{
		listing = new_listing;

		ui_group->Enabled = true;
		name->Text   = to_dotnet_string(listing->name);
		author->Text = to_dotnet_string(listing->contractor->name->get_short());
		per_hr->Text = Convert::ToString(listing->payment_hr);

		if (listing_type == CUSTOMER_LISTING)
			hrs->Text = Convert::ToString(listing->total_hrs);
		else if (listing_type == CONTRACTOR_LISTING)
			calculate_and_display_total(1);
		else
			show_error(L"Wrong listing type \"" + std::to_wstring(listing_type) + L"\".");
	}
};
}


#endif