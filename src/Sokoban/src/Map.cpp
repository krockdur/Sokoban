
#include "Map.h"
#include "csv/csv.hpp"
using namespace csv;

Map::Map(){
	this->populate_map();
}

Map::~Map(){

}

void Map::populate_map() {

	// lecture csv
	CSVReader reader("D:/A1_DEV/Sokoban/src/Sokoban/Debug/lvl1.csv");
	CSVRow row;

	while (reader.read_row(row)) {
	    // Do stuff with row here
		std::cout << "test" << std::endl;
	}

	for (int y = 0; y <= 15; y++){

		for (int x = 0; x <= 15; x++){

			Case c(x, y, 0);

		}

	}

}

