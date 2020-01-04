//
// Created by Denys Tomchyshen on 30.12.2019.
//

#ifndef N_PUZZLE_GENERAL_H
#define N_PUZZLE_GENERAL_H

#define PUZZLE std::vector<std::vector<unsigned int>>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <list>

#include "ErrorManager.h"
#include "ArgumentHandler.h"
#include "Node.hpp"
#include "Puzzle.hpp"

inline bool isNumber(const std::string & s) {
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char * p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

#endif //N_PUZZLE_GENERAL_H
