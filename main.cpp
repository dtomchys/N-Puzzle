#include "inc/general.h"

int main(int argc, char **argv) {
    ArgumentHandler *argumentHandler = new ArgumentHandler(argv, argc);
    PuzzleConfiguration *configurtion = argumentHandler->getPuzzleConfiguration();
    std::cout << (*configurtion);

    //    Dasha
    Puzzle& puzzle = Puzzle::getInstance();
    puzzle.solve();
    return 0;
}
