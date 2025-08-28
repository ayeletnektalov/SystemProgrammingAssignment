#include "MP3.h"
#include <iostream>

void MP3::play_all() {
	Link* current = get_head();
	while (current) {
		std::cout << current->get_song()->get_id() << std::endl;
		current = current->get_next();
	}
}

