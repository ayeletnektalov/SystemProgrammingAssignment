#pragma once

#include "Player.h"

class MP4 : public Player {
public:
	using Player::Player;
	MP4() = default;
	MP4(const MP4& other) = default;
	MP4(MP4&& other) noexcept = default;
	MP4& operator=(const MP4& other) = default;
	MP4& operator=(MP4&& other) noexcept = default;
	~MP4() override = default;

	void play_all() override;
	Player* clone() const override { return new MP4(*this); }
};

