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

private:
    std::string         *source_path;

public:
    SearchAlgorithm     algo;
    HeuristicFunction   func;
    PuzzleSource        source;

public:
    void setSourcePath(std::string source_path) {
        this->source = E_RAND;
        this->source_path = &source_path;
    }

    std::string* getSourcePath() {
        if (this->source == E_RAND) {
            return  NULL;
        } else {
            return  this->source_path;
        }
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
};

#endif //N_PUZZLE_ARGUMENTHANDLER_H
