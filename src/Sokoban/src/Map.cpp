#include "Map.h"

Map::Map() {
	this->populate_map();
}

Map::~Map() {

}

void Map::populate_map() {

	// lecture csv
	std::ifstream sFile("D:\\A1_DEV\\Sokoban\\src\\Sokoban\\Debug\\lvl1.txt", std::ifstream::in);

	if (sFile) {

		std::string ligne;

		int y = 0;
		while (getline(sFile, ligne)) {

			for(int x = 0; x < NB_TILE_X; x++){
				Case c(x, y, ligne[x]);
				this->map.push_back(c);
				std::cout << c.get_x() << "   " << c.get_y() << "   " << c.get_value() << std::endl;

			}

			std::cout << ligne[0] << std::endl;

			y++;
		}

	}
	else {
		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture."
				<< std::endl;
	}

	this->print_map();


}

void Map::print_map() {

	std::cout << "-------------------------------" << std::endl;
	for(Case c : this->map){
		std::cout << c.get_x() << "   " << c.get_y() << "   " << c.get_value() << std::endl;
	}

}
