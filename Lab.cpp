#include "Lab.h"

Lab::Lab() : backup_player(nullptr) {}

Lab::Lab(const Lab& other) : backup_player(nullptr) {
	if (other.backup_player) {
		backup_player = other.backup_player->clone();
	}
}

Lab::Lab(Lab&& other) noexcept : backup_player(other.backup_player) {
	other.backup_player = nullptr;
}

Lab& Lab::operator=(const Lab& other) {
	if (this == &other) return *this;
	delete backup_player;
	backup_player = nullptr;
	if (other.backup_player) {
		backup_player = other.backup_player->clone();
	}
	return *this;
}

Lab& Lab::operator=(Lab&& other) noexcept {
	if (this == &other) return *this;
	delete backup_player;
	backup_player = other.backup_player;
	other.backup_player = nullptr;
	return *this;
}

Lab::~Lab() {
	delete backup_player;
	backup_player = nullptr;
}

void Lab::backup(const Player& player) {
	delete backup_player;
	backup_player = player.clone();
}

void Lab::restore(Player*& player_out) const {
	if (!backup_player) return;
	delete player_out;
	player_out = backup_player->clone();
}

