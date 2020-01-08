//
// Created by Denys Tomchyshen on 05.01.2020.
//

#ifndef N_PUZZLE_MAPPARSER_H
#define N_PUZZLE_MAPPARSER_H

class Puzzle;
struct PuzzleConfiguration;

#include "general.h"

class MapParser {

private:
    PuzzleConfiguration *conf;
    PUZZLE          *map;

public:
    MapParser(PuzzleConfiguration *configuration);
    void setupPuzzle(Puzzle &puzzle);

private:
    std::string readFile(std::string filePath);
    std::string trimComments(std::string fileContent);
    PUZZLE*      validateAndSetMap(std::string fileContent);
};


#endif //N_PUZZLE_MAPPARSER_H
