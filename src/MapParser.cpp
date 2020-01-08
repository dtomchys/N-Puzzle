//
// Created by Denys Tomchyshen on 05.01.2020.
//

#include "../inc/MapParser.h"

MapParser::MapParser(PuzzleConfiguration *configuration) {
    this->conf = configuration;
}

void MapParser::setupPuzzle(Puzzle &puzzle) {
    std::string *filePath = conf->getSourcePath();
    std::string fileContent = readFile(*filePath);
    fileContent = trimComments(fileContent);
    this->map = validateAndSetMap(fileContent);
    puzzle.setInitialState((*this->map), this->conf->getPuzzleSize(), this->conf->func);
}

std::string MapParser::readFile(std::string filePath) {
    std::ifstream inFile;
    inFile.open(filePath);
    if (!inFile) {
        ErrorManager::shared().showParsingErrorAndExit(CANT_READ);
    }

    std::string fileContent;
    std::string buf;
    while (getline(inFile,buf)) {
        fileContent += buf + '\n';
    }
    fileContent.erase(fileContent.size() - 1);
    inFile.close();
    return  fileContent;
}

std::string MapParser::trimComments(std::string fileContent) {
    size_t commentBeginIndex = 0;

    while ((commentBeginIndex  = fileContent.find("#") )!= std::string::npos) {
        size_t commentEndIndex = fileContent.find("\n", commentBeginIndex);
        fileContent.erase(commentBeginIndex, commentEndIndex - commentBeginIndex);
    }
    while (fileContent[0] == '\n')
        fileContent.erase(0, 1);
    size_t index = fileContent.size() - 1;
    while (index > 1 && fileContent[index] == '\n') {
        fileContent.erase(index, 1);
        index = fileContent.size() - 1;
    }
    return fileContent;
}

PUZZLE* MapParser::validateAndSetMap(std::string fileContent) {
    size_t size;
    PUZZLE *targetState;
    try {
        size = std::stoi(fileContent.substr(0));
        fileContent.erase(0, 2);
        this->conf->setPuzzleSize(size);

        targetState = new PUZZLE(size, std::vector<unsigned int>(size, 0));
        size_t totalSum = 0;
        for (size_t y = 0; y < size; ++y) {
            for (int x = 0; x < size; ++x) {
                size_t numLength = 0;
                for (int i = 0; isNumber(fileContent.substr(i, 1)) ; i++, numLength++) {}
                (*targetState)[y][x] = std::stoi(fileContent.substr(0, numLength));
                totalSum += (*targetState)[y][x];
                fileContent.erase(0, numLength + (x < size - 1 ? 1 : 0));
            }
            while (fileContent[0] == '\n' || fileContent[0] == ' ' )
                fileContent.erase(0, 1);
        }
        if (!fileContent.empty() || totalSum != recurSum(size * size - 1))
            throw std::exception();
    } catch (const std::exception& e) {
        ErrorManager::shared().showParsingErrorAndExit(INVALID_PUZZLE);
    }
    return targetState;
}