#include <iostream>
#include "MP3.h"
#include "MP4.h"
#include "Lab.h"

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int player_type;
	if (!(std::cin >> player_type)) return 0;
	Player* player = nullptr;
	Lab lab;
	if (player_type == 3) player = new MP3();
	else if (player_type == 4) player = new MP4();
	else return 0;

	int opcode;
	while (std::cin >> opcode) {
		if (opcode == 0) break;
		if (opcode == 1) {
			int id; std::cin >> id; player->add_first(id);
		} else if (opcode == 2) {
			int id; std::cin >> id; player->add_last(id);
		} else if (opcode == 3) {
			player->play_all();
		} else if (opcode == 4) {
			int index; std::cin >> index; player->remove_at(index);
		} else if (opcode == 5) {
			int index; std::cin >> index; player->swap_adjacent(index);
		} else if (opcode == 6) {
			lab.backup(*player);
		} else if (opcode == 7) {
			lab.restore(player);
		}
	}
	delete player;
	return 0;
}

