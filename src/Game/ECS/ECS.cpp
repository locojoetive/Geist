#include "ECS.h"

void Entity::addGroup(Group _group)
{
	groupBitSet[_group] = true;
	manager.AddToGroup(this, _group);
}