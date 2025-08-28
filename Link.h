#pragma once

#include "Song.h"

class Link
{
private:
	const Song* song;
	Link* next;
	Link* prev;
};

