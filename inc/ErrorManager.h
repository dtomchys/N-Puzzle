//
// Created by Denys Tomchyshen on 30.12.2019.
//

#ifndef N_PUZZLE_ERRORMANAGER_H
#define N_PUZZLE_ERRORMANAGER_H

#include "general.h"

enum ARG_ERRORS { INVALID_FILE, INVALID_ALGO, INVALID_FUNC };

class ErrorManager {
private:
    ErrorManager() {}

    ErrorManager(ErrorManager const&);
    void operator=(ErrorManager const&);

public:
    static ErrorManager& shared() {
        static ErrorManager instance;
        return instance;
    }
    void showUsage();
    void showArgErrorAndExit(ARG_ERRORS error);
};


#endif //N_PUZZLE_ERRORMANAGER_H
