#pragma once

#include "Link.h"
#include "Song.h"

class Player
{
protected:
	Link* head;						// linked list is stored in Player code

public:
	virtual void play_all() = 0;	// implemented in MP3.cpp, MP4.cpp
};

