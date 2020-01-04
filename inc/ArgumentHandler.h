//
// Created by Denys Tomchyshen on 30.12.2019.
//

#ifndef N_PUZZLE_ARGUMENTHANDLER_H
#define N_PUZZLE_ARGUMENTHANDLER_H

#include "general.h"

enum SearchAlgorithm { E_ASEARCH };
enum HeuristicFunction { E_MANHATTAN };
enum PuzzleSource { E_RAND, E_FILE };

struct PuzzleConfiguration {

    friend std::ostream& operator<<(std::ostream& os, const PuzzleConfiguration& conf);

private:
    std::string         *source_path;
    unsigned int        puzzleSize = 3;
    unsigned int        puzzleIterations = 1000;

public:
    SearchAlgorithm     algo;
    HeuristicFunction   func;
    PuzzleSource        source;

public:
    std::string* getSourcePath() const {
        if (this->source == E_RAND) {
            return  NULL;
        } else {
            return  this->source_path;
        }
    }
    void setSourcePath(std::string source_path) {
        this->source = E_FILE;
        this->source_path = new std::string(source_path);
    }

    unsigned int getPuzzleSize() const {
        return this->puzzleSize;
    }
    void setPuzzleSize(unsigned int size) {
        this->puzzleSize = size;
    }

    unsigned int getPuzzleIterations() const {
        return this->puzzleIterations;
    }
    void setPuzzleIterations(unsigned int iterationNumber) {
        this->puzzleIterations = iterationNumber;
    }
};

class ArgumentHandler {

private:
    std::vector<std::string> arguments;

public:
    ArgumentHandler(char** arguments, int argumentCount);
    PuzzleConfiguration* getPuzzleConfiguration();

private:
    PuzzleConfiguration* makeDefaultConfiguration();
    void checkAndSetFileConfiguration(std::string file, PuzzleConfiguration *config);
    void checkAndSetAlgorithmConfiguration(std::string algo, PuzzleConfiguration *config);
    void checkAndSetHeuristicConfiguration(std::string func, PuzzleConfiguration *config);
    void checkAndSetCustomPuzzleSize(std::string size, PuzzleConfiguration *config);
    void checkAndSetPuzzleIterations(std::string iterationNumber, PuzzleConfiguration *config);
};

#endif //N_PUZZLE_ARGUMENTHANDLER_H
