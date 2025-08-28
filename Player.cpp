#include "Player.h"
#include <stdexcept>

Player::Player() : head(nullptr) {}

Player::~Player() {
	Link* current = head;
	while (current) {
		Link* next = current->get_next();
		delete current->get_song();
		delete current;
		current = next;
	}
	head = nullptr;
}

static Link* deep_copy_list(const Link* source_head) {
	Link* new_head = nullptr;
	Link* tail = nullptr;
	const Link* current = source_head;
	while (current) {
		const Song* src_song = current->get_song();
		Song* new_song = new Song(src_song->get_id());
		Link* node = new Link(new_song);
		if (!new_head) {
			new_head = node;
			tail = node;
		} else {
			tail->set_next(node);
			node->set_prev(tail);
			tail = node;
		}
		current = current->get_next();
	}
	return new_head;
}

Player::Player(const Player& other) : head(deep_copy_list(other.head)) {}

Player::Player(Player&& other) noexcept : head(other.head) {
	other.head = nullptr;
}

Player& Player::operator=(const Player& other) {
	if (this == &other) return *this;
	this->~Player();
	head = deep_copy_list(other.head);
	return *this;
}

Player& Player::operator=(Player&& other) noexcept {
	if (this == &other) return *this;
	this->~Player();
	head = other.head;
	other.head = nullptr;
	return *this;
}

void Player::add_first(const int song_id) {
	Song* song = new Song(song_id);
	Link* node = new Link(song);
	node->set_next(head);
	if (head) head->set_prev(node);
	head = node;
}

void Player::add_last(const int song_id) {
	Song* song = new Song(song_id);
	Link* node = new Link(song);
	if (!head) {
		head = node;
		return;
	}
	Link* tail = head;
	while (tail->get_next()) tail = tail->get_next();
	tail->set_next(node);
	node->set_prev(tail);
}

void Player::remove_at(const int index) {
	if (!head) return;
	int i = 0;
	Link* current = head;
	while (current && i < index) {
		current = current->get_next();
		++i;
	}
	if (!current) return;
	Link* prev = current->get_prev();
	Link* next = current->get_next();
	if (prev) prev->set_next(next); else head = next;
	if (next) next->set_prev(prev);
	delete current->get_song();
	delete current;
}

void Player::swap_adjacent(const int index) {
	// swap nodes at index and index+1
	if (!head) return;
	int i = 0;
	Link* a = head;
	while (a && i < index) { a = a->get_next(); ++i; }
	if (!a) return;
	Link* b = a->get_next();
	if (!b) return;
	Link* prev = a->get_prev();
	Link* next = b->get_next();
	// rewire: prev->b->a->next
	if (prev) prev->set_next(b); else head = b;
	b->set_prev(prev);
	b->set_next(a);
	a->set_prev(b);
	a->set_next(next);
	if (next) next->set_prev(a);
}

int Player::size() const {
	int count = 0;
	Link* current = head;
	while (current) { ++count; current = current->get_next(); }
	return count;
}

Link* Player::get_head() const { return head; }

