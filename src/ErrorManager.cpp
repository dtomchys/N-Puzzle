//
// Created by Denys Tomchyshen on 30.12.2019.
//

#include "../inc/ErrorManager.h"

void ErrorManager::showUsage() {
    std::cout << "./N_Puzzle [-f file_path] [-a <a_search>] [-h <man>]\n"
                 "-f <file_path>            Select a path to a puzzle\n"
                 "-a <search algorithm>     Select searching algorithm\n"
                 "-h <heuristic>            Select heuristic function\n"
                 "Default ./N_Puzzle [random_generated_puzzle] [a_search] [man]\n" << std::endl;
    exit(0);
}

void ErrorManager::showArgErrorAndExit(ARG_ERRORS error) {
    std::string errorMessage;
    switch (error) {
        case INVALID_FILE:
            errorMessage = "Invalid file! Please, make sure the file exists or has correct permission access.";
            break;
        case INVALID_ALGO:
            errorMessage = "Invalid algorithm option! Please, choose a correct one.";
            break;
        case INVALID_FUNC:
            errorMessage = "Invalid heuristic function option! Please, choose a correct one.";
            break;
    }
    std::cerr << errorMessage << std::endl;
    exit(1);
}
