#pragma once

#include "Player.h"

class Lab
{
private:
	Player* backup_player;

public:
	// lab can "backup" a player, i.e., create a deep copy of it. (*BACKUP) <-- (*PLAYER)
	// lab can also "restore" a player. (*PLAYER) <-- (*BACKUP)

	Lab();
	Lab(const Lab& other);
	Lab(Lab&& other) noexcept;
	Lab& operator=(const Lab& other);
	Lab& operator=(Lab&& other) noexcept;
	~Lab();

	void backup(const Player& player);
	void restore(Player*& player_out) const;
};

