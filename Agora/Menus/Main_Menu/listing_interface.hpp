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
	Button   ^author_info, ^button;
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
			button		 = other->button;
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
					  Button^   _author_info,  Button^ _button,
					  Label^    _label_per_hr, Label^  _per_hr, Label^ _label_hrs,
					  Control^  _hrs,		   Label^ _total)
	: ui_group(_ui_group),		   name(_name),		author(_author),
	  author_info(_author_info),   button(_button),
	  label_per_hr(_label_per_hr), per_hr(_per_hr), label_hrs(_label_hrs),
	  hrs(_hrs),				   total(_total)
	{
		ui_group->Enabled = true;
		ui_group->Visible = true;
	}

	
	/// Intended only for UI's with variable hour settings!
	void calculate_and_display_total(const unsigned int hrs)
	{
		listing->hrs = hrs;
		total->Text = L"Итого, ₽: " + listing->payment_total();
	}


	bool has(Control^ node)
	{
		/// Maybe do it via an 'unordered_set'?
		return (
			   node == ui_group     || node == name   || node == author
			|| node == author_info  || node == button
			|| node == label_per_hr || node == per_hr
			|| node == label_hrs    || node == hrs
			|| node == total
		);
	}


	void set_listing(Listing* new_listing)
	{
		listing = new_listing;

		ui_group->Enabled = true;
		name->Text   = to_dotnet_string(listing->name);
		per_hr->Text = Convert::ToString(listing->per_hr);

		if ((listing->author == listing->contractor) && (listing->contractor != nullptr))
		{
			calculate_and_display_total(1);
			author->Text = to_dotnet_string(listing->contractor->name->get_normal());
		}
		else if ((listing->author == listing->customer) && (listing->customer != nullptr))
		{
			hrs->Text = Convert::ToString(listing->hrs);
			author->Text = to_dotnet_string(listing->customer->name->get_normal());
		}
		else
			show_error(L"Incorrect listing author.");
	}
};
}


#endif