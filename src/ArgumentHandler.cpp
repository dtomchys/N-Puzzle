//
// Created by Denys Tomchyshen on 30.12.2019.
//

#include "../inc/ArgumentHandler.h"

ArgumentHandler::ArgumentHandler(char** arguments, int argumentCount) {
    for (int i = 1; i < argumentCount; ++i) {
        this->arguments.push_back(arguments[i]);
    }
}

PuzzleConfiguration* ArgumentHandler::getPuzzleConfiguration() {
    PuzzleConfiguration *configResult = ArgumentHandler::makeDefaultConfiguration();
    for (int i = 0; i < arguments.size(); ++i) {
        std::string arg = arguments[i];
        switch (arg.at(1)) {
            case 'f':
                checkAndSetFileConfiguration(arguments[i + 1], configResult);
                i++;
                break;
            case 'a':
                checkAndSetAlgorithmConfiguration(arguments[i + 1], configResult);
                i++;
                break;
            case 'h':
                checkAndSetHeuristicConfiguration(arguments[i + 1], configResult);
                i++;
                break;
            default:
                ErrorManager::shared().showUsage();
                break;
        }
    }
    return configResult;
}

PuzzleConfiguration* ArgumentHandler::makeDefaultConfiguration() {
    PuzzleConfiguration *configResult = new PuzzleConfiguration();
    configResult->algo = E_ASEARCH;
    configResult->func = E_MANHATTAN;
    configResult->source = E_RAND;
    return configResult;
}

void ArgumentHandler::checkAndSetFileConfiguration(std::string file, PuzzleConfiguration *config) {
    if (access( file.c_str(), F_OK ) == -1)
        ErrorManager::shared().showArgErrorAndExit(INVALID_FILE);
    config->setSourcePath(file);
}

void ArgumentHandler::checkAndSetAlgorithmConfiguration(std::string algo, PuzzleConfiguration *config) {
    if (!algo.compare("a_search"))
        config->algo = E_ASEARCH;
    else
        ErrorManager::shared().showArgErrorAndExit(INVALID_ALGO);
}

void ArgumentHandler::checkAndSetHeuristicConfiguration(std::string func, PuzzleConfiguration *config) {
    if (!func.compare("man"))
        config->func = E_MANHATTAN;
    else
        ErrorManager::shared().showArgErrorAndExit(INVALID_FUNC);
}

std::ostream& operator<<(std::ostream& os, const PuzzleConfiguration& conf) {
    std::string output;
    output = "Search algorithm: ";
    switch (conf.algo) {
        case E_ASEARCH:
            output += "A search algorithm.";
            break;
        default:
            output += "unknown algo.";
            break;
    }
    output += "\n";
    output += "Heuristic function: ";
    switch (conf.func) {
        case E_MANHATTAN:
            output += "Manhattan.";
            break;
        default:
            output += "Undefined.";
            break;
    }
    output += "\n";
    output += "Puzzle source: ";
    switch (conf.source) {
        case E_RAND:
            output += "Randomly generated";
            break;
        case E_FILE:
            const std::string *result = conf.getSourcePath();
            output += *result + ".";
            break;
    }
    output += "\n";
    os << output;
    return os;
}
