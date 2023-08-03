#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::Contact(Contact &new_contact)
{
	first_name = new_contact.first_name;
	last_name = new_contact.last_name;
	nick_name = new_contact.nick_name;
	phone_number = new_contact.phone_number;
	darkest_secret = new_contact.darkest_secret;
}