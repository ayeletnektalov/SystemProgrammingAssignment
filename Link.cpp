#include "Link.h"

Link::Link(const Song* song_) : song(song_), next(nullptr), prev(nullptr) {}

Link::~Link() {}

const Song* Link::get_song() const { return song; }
Link* Link::get_next() const { return next; }
Link* Link::get_prev() const { return prev; }

void Link::set_next(Link* next_) { next = next_; }
void Link::set_prev(Link* prev_) { prev = prev_; }

