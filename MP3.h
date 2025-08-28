#pragma once

#include "Player.h"

class MP3 : public Player {
public:
	using Player::Player;
	MP3() = default;
	MP3(const MP3& other) = default;
	MP3(MP3&& other) noexcept = default;
	MP3& operator=(const MP3& other) = default;
	MP3& operator=(MP3&& other) noexcept = default;
	~MP3() override = default;

	void play_all() override;
	Player* clone() const override { return new MP3(*this); }
};

