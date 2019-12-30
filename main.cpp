#include "inc/general.h"

int main(int argc, char **argv) {
    ArgumentHandler *argumentHandler = new ArgumentHandler(argv, argc);

    PuzzleConfiguration *configurtion = argumentHandler->getPuzzleConfiguration();
    return 0;
}
