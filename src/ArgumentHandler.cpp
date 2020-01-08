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
        if (arg.size() < 2)
            ErrorManager::shared().showUsage();
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
            case 's':
                checkAndSetCustomPuzzleSize(arguments[i + 1], configResult);
                i++;
                break;
            case 'i':
                checkAndSetPuzzleIterations(arguments[i + 1], configResult);
                i++;
                break;
            case 'u':
                configResult->solvable = false;
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
    configResult->solvable = true;
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

void ArgumentHandler::checkAndSetCustomPuzzleSize(std::string size, PuzzleConfiguration *config) {
    try {
        int intSize = std::stoi(size);
        if (isNumber(size) && intSize > 0)
            config->setPuzzleSize(intSize);
        else
            throw ;
    }
    catch (const std::exception& e) {
        ErrorManager::shared().showArgErrorAndExit(INVALID_SIZE);
    }
}

void ArgumentHandler::checkAndSetPuzzleIterations(std::string iterationNumber, PuzzleConfiguration *config) {
    try {
        int intIterations = std::stoi(iterationNumber);
        if (isNumber(iterationNumber) && intIterations > 0)
            config->setPuzzleIterations(intIterations);
        else
            throw ;
    }
    catch (const std::exception& e) {
        ErrorManager::shared().showArgErrorAndExit(INVALID_ITERATIONS);
    }
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
        case E_RAND: {
            std::string size = std::to_string(conf.getPuzzleSize());
            std::string iter = std::to_string(conf.getPuzzleIterations());
            output += "Randomly generated with puzzle size = " + size + " and iteration = " + iter;
            break;
        }
        case E_FILE: {
            const std::string *result = conf.getSourcePath();
            output += *result + ".";
            break;
        }
    }
    output += "\n";
    os << output;
    return os;
}
