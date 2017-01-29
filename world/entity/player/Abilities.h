#pragma once

class CommandPermissionLevel;

// Size : 20
class Abilities
{
public:
	char filler1; // 0
	bool isFlying; // 1
	char filler2[6]; // 2
	float walkSpeed; // 8
	float flySpeed; // 12
	bool isWorldBuilder; // 16
	char filler3[3]; // 17
	PermissionsHandler permissionsHandler; // 20

	Abilities();

	void addSaveData(CompoundTag&) const;
	CommandPermissionLevel getCommandPermissions() const;
	float getFlyingSpeed() const;
	float getWalkingSpeed() const;
	bool isFlying() const;
	bool isWorldBuilder() const;
	void loadSaveData(const CompoundTag&);
	void setCommandPermissions(CommandPermissionLevel);
	void setFlyingSpeed(float);
	void setWalkingSpeed(float);
	void setWorldSpeed(float);
};
