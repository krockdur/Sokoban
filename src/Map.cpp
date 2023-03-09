#include "Map.h"

Map::Map(Case case_player) {
	populate_map();
	set_player_position(case_player);

	this->print_map();
}

Map::~Map() {

}



void Map::populate_map() {
	std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

	//std::ifstream sFile("D:\\A1_DEV\\Sokoban\\src\\Sokoban\\Debug\\lvl1.txt", std::ifstream::in);
	std::ifstream sFile("./lvl1.txt", std::ifstream::in);


	if (sFile) {

		std::string ligne;

		int y = 0;
		while (getline(sFile, ligne)) {

			for (int x = 0; x < NB_TILE_X; x++) {
				Case c(x, y, ligne[x]);
				this->map.push_back(c);
			}
			y++;
		}
	}
	else {
		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
	}

}

Case Map::get_case(int x, int y) {
	Case cRet(0,0,0);
	for (Case c : this->map) {
		if (c.get_x() == x && c.get_y() == y){
			cRet = c;
		}
	}
	return cRet;
}

void Map::print_map() {

	for (int y = 0; y < NB_TILE_Y; y++){
		std::cout << "|  ";
		for (int x = 0; x < NB_TILE_X; x++){
			std::cout << this->get_case(x, y).get_value() << "  |  ";
		}
		std::cout << std::endl;
	}
}

void Map::set_player_position(Case player_position) {

	for(Case& c : map){
		if(player_position.get_x() == c.get_x() && player_position.get_y() == c.get_y()){

			//update map
			c.set_value(player_position.get_value());

		}
	}


}

void Map::change_case_value(Case new_case) {

}
