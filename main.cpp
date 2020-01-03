#include "inc/general.h"

int main(int argc, char **argv) {
    ArgumentHandler *argumentHandler = new ArgumentHandler(argv, argc);
    PuzzleConfiguration *configurtion = argumentHandler->getPuzzleConfiguration();
    std::cout << (*configurtion);

    //    Dasha
    Puzzle& puzzle = Puzzle::getInstance();
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
