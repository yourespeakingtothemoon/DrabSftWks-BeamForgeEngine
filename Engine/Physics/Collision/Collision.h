#pragma once
#include "Contact.h"
#include "../../Framework/Body.h"
#include <vector>

namespace collision
{
	Contact GenerateContact(dbf::Body* bodyA, dbf::Body* bodyB);
	void CreateContacts(std::vector<dbf::Body*> bodies, std::vector<Contact>& contacts);
	void SeparateContacts(std::vector<Contact>& contacts);
	void ResolveContacts(std::vector<Contact>& contacts);
}