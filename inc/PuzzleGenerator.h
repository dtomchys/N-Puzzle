//
// Created by Denys Tomchyshen on 04.01.2020.
//

#ifndef N_PUZZLE_PUZZLEGENERATOR_H
#define N_PUZZLE_PUZZLEGENERATOR_H

class Puzzle;
struct PuzzleConfiguration;

#include "general.h"

class PuzzleGenerator {

private:
    PuzzleConfiguration *conf;
    PUZZLE          *map;

public:
    PuzzleGenerator(PuzzleConfiguration *configuration);
    void setupPuzzle(Puzzle &puzzle);

private:
    void generate();
    void shuffle();
    std::pair<size_t, size_t> getCoordinate(int val, PUZZLE const &map);
};


#endif //N_PUZZLE_PUZZLEGENERATOR_H
