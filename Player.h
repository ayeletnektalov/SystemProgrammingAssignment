#pragma once

#include "Link.h"
#include "Song.h"

class Player
{
protected:
	Link* head;					// linked list is stored in Player code

public:
	Player();
	virtual ~Player();

	Player(const Player& other);
	Player(Player&& other) noexcept;
	Player& operator=(const Player& other);
	Player& operator=(Player&& other) noexcept;

	void add_first(const int song_id);
	void add_last(const int song_id);
	void remove_at(const int index);
	void swap_adjacent(const int index);
	int size() const;
	Link* get_head() const;

	virtual void play_all() = 0;	// implemented in MP3.cpp, MP4.cpp
	virtual Player* clone() const = 0;
};

