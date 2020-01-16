#include "inc/general.h"

int main(int argc, char **argv) {
    srand(time(NULL));
    ArgumentHandler *argumentHandler = new ArgumentHandler(argv, argc);
    PuzzleConfiguration *configuration = argumentHandler->getPuzzleConfiguration();
    delete argumentHandler;
    Puzzle& puzzle = Puzzle::getInstance();
    std::cout << (*configuration);
    if (configuration->source == E_RAND) {
        PuzzleGenerator *generator = new PuzzleGenerator(configuration);
        generator->setupPuzzle(puzzle);
        delete generator;
    } else {
        MapParser *parser = new MapParser(configuration);
        parser->setupPuzzle(puzzle);
        delete parser;
    }
    delete configuration;
    puzzle.solve();
//    while (1) {
//
//    }
    //system("leaks N_Puzzle");
    return 0;
}
