#include "inc/general.h"

int main(int argc, char **argv) {
    srand(time(NULL));
    ArgumentHandler *argumentHandler = new ArgumentHandler(argv, argc);
    PuzzleConfiguration *configuration = argumentHandler->getPuzzleConfiguration();
    Puzzle& puzzle = Puzzle::getInstance();
    std::cout << (*configuration);
    if (configuration->source == E_RAND) {
        PuzzleGenerator generator = PuzzleGenerator(configuration);
        generator.setupPuzzle(puzzle);
    } else {

    }

    //    Dasha
    puzzle.solve();

    //      for(int y=0;y<puzzle.size();++y)
    // {
    //     for(int x=0;x<puzzle[y].size();++x)
    //     {
    //         cout<<puzzle[y][x]<<ends;
    //     }
    //     cout<<endl;
    // }
    return 0;
}
