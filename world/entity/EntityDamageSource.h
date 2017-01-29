#pragma once

#include <string>

class Entity;
class EntityDamageCause;

class EntityDamageSource {
public:
	EntityDamageSource(EntityDamageCause);

	virtual ~EntityDamageSource();
	virtual bool isEntitySource() const;
	virtual void getEntity() const;
	virtual bool isChildEntitySource() const;
	virtual void getChildEntity() const;
	virtual bool isBlockSource() const;
	virtual std::string getDeathMessage(std::string, Entity*);
};

