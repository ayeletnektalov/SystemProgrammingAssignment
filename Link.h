#pragma once

#include "Song.h"

class Link
{
private:
	const Song* song;
	Link* next;
	Link* prev;
public:
	Link(const Song* song_);
	~Link();

	const Song* get_song() const;
	Link* get_next() const;
	Link* get_prev() const;

	void set_next(Link* next_);
	void set_prev(Link* prev_);
};

