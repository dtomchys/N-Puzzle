//
// Created by Denys Tomchyshen on 04.01.2020.
//

#include "../inc/PuzzleGenerator.h"

PuzzleGenerator::PuzzleGenerator(PuzzleConfiguration *configuration) {
    this->conf = configuration;
}

void PuzzleGenerator::setupPuzzle(Puzzle &puzzle) {
    this->generate();
    this->shuffle();
    puzzle.setInitialState((*this->map), conf->getPuzzleSize(), conf->func);
}

void PuzzleGenerator::generate() {
    unsigned int size = this->conf->getPuzzleSize();
    unsigned int x = 0, y = 0, shift = 0, tile = 1;
    unsigned int maxTile = size * size;

    PUZZLE *targetState = new PUZZLE(size, std::vector<unsigned int>(size, 0));

    while (shift < size / 2) {
        while (++x < size - shift and tile < maxTile) { (*targetState)[y][x - 1] = tile++; }
        while (++y < size - shift and tile < maxTile) { (*targetState)[y - 1][x - 1] = tile++; }
        while (--x > shift and tile < maxTile) { (*targetState)[y - 1][x] = tile++; }
        while (--y > shift and tile < maxTile) { (*targetState)[y][x] = tile++; }
        x = y = ++shift;
    }

    this->map = targetState;
}

void PuzzleGenerator::shuffle() {
    size_t iterations = static_cast<size_t>(conf->getPuzzleIterations());
    unsigned int size = conf->getPuzzleSize();

    if (!conf->solvable) {
        (*map)[0][0] = 2;
        (*map)[0][1] = 1;
    }

    for (size_t count = 0; count < iterations; ++count) {
        std::pair<size_t,size_t> pos = getCoordinate(0, (*map));
        std::vector<std::pair<size_t,size_t>> moves;
        if (pos.first > 0)
            moves.push_back(std::make_pair(pos.first - 1, pos.second));
        if (pos.second > 0)
            moves.push_back(std::make_pair(pos.first, pos.second - 1));
        if (pos.first < size - 1)
            moves.push_back(std::make_pair(pos.first + 1, pos.second));
        if (pos.second < size - 1)
            moves.push_back(std::make_pair(pos.first, pos.second + 1));
        std::pair<size_t,size_t> swapPair = moves[rand() % moves.size()];
        int val = (*map)[swapPair.first][swapPair.second];
        (*map)[swapPair.first][swapPair.second] = 0;
        (*map)[pos.first][pos.second] = val;
    }
}

std::pair<size_t,size_t> PuzzleGenerator::getCoordinate(int val, PUZZLE const &map) {
    for (int y = 0; y < map.size(); y++)
        for (int x = 0; x < map[y].size(); x++)
            if (map[y][x] == val)
                return std::make_pair(y, x);
    return std::make_pair(0, 0);
}