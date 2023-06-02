#include "Collision.h"
#include "../../Framework/Shapes/CircleShape.h"
#include "../../Core/Random.h"

namespace collision
{
    Contact GenerateContact(dbf::Body* bodyA, dbf::Body* bodyB)
    {
        Contact contact;

        contact.bodyA = bodyA;
        contact.bodyB = bodyB;

        glm::vec2 direction = bodyA->position - bodyB->position;
        float distance = glm::length(direction);
        if (distance == 0)
        {
            direction = { randomf(-0.05, 0.05), randomf(-0.05, 0.05) };
        }

        float radius = dynamic_cast<dbf::CircleShape*>(bodyA->shape)->radius + dynamic_cast<dbf::CircleShape*>(bodyB->shape)->radius;
        contact.depth = radius - distance;

        contact.normal = glm::normalize(direction);

        contact.restitution = (bodyA->restitution + bodyB->restitution) * 0.5f;

        return contact;
    }

    void CreateContacts(std::vector<dbf::Body*> bodies, std::vector<Contact>& contacts)
    {
        for (size_t i = 0; i < bodies.size(); i++)
        {
            for (size_t j = i + 1; j < bodies.size(); j++)
            {
                dbf::Body* bodyA = bodies[i];
                dbf::Body* bodyB = bodies[j];
                if (bodyA->type != dbf::Body::DYNAMIC && bodyB->type != dbf::Body::DYNAMIC) continue;
                if (bodyA->Intersects(bodyB))
                {
                    Contact contact = GenerateContact(bodyA, bodyB);
                    contacts.push_back(contact);
                }
            }
        }
    }

    void SeparateContacts(std::vector<Contact>& contacts)
    {
        for (auto& contact : contacts)
        {
            float totalInvMass = contact.bodyA->invMass + contact.bodyB->invMass;
            glm::vec2 separation = contact.normal * (contact.depth / totalInvMass);

            contact.bodyA->position += separation * contact.bodyA->invMass;
            contact.bodyB->position -= separation * contact.bodyB->invMass;
        }
    }

    void ResolveContacts(std::vector<Contact>& contacts)
    {

    }

}
