#include "MP4.h"
#include <iostream>

void MP4::play_all() {
	// play in reverse: go to tail first
	Link* tail = get_head();
	if (!tail) return;
	while (tail->get_next()) tail = tail->get_next();
	while (tail) {
		std::cout << tail->get_song()->get_id() << std::endl;
		tail = tail->get_prev();
	}
}

