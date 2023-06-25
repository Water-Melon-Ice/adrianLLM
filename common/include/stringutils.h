#pragma once

#include <iostream>
#include <string>
#include <vector>

inline std::vector<std::string> splitStringWithNull(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    size_t startPos = 0;
    size_t endPos = 0;

    while (endPos < str.length()) {
        // Find the next occurrence of the delimiter
        endPos = str.find(delimiter, startPos);

        // Create a substring from the current position to the delimiter
        std::string token = str.substr(startPos, endPos - startPos);
        tokens.push_back(token);

        // Move the start position for the next iteration
        startPos = endPos + 1;
    }

    return tokens;
}

inline std::string rstrip(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch) && !(ch == '\n');
        }).base(), s.end());
    return s;
}

inline void bubbleSortFileLines(const std::string& inFile, const std::string& outFile) {
    std::ifstream input(inFile);
    if (!input) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }

    std::string line;
    bool swapped;
    int lineCount = 0;

    // Count the number of lines in the file
    while (std::getline(input, line)) {
        ++lineCount;
    }

    input.close();

    // Perform bubble sort line by line
    do {
        swapped = false;
        std::ifstream inputFile(inFile);
        std::ofstream outputFile(outFile);
        std::string prevLine, currentLine;

        for (int i = 0; i < lineCount - 1; ++i) {
            std::getline(inputFile, prevLine);
            std::getline(inputFile, currentLine);

            if (prevLine > currentLine) {
                // Swap lines
                outputFile << currentLine << '\n';
                outputFile << prevLine << '\n';
                swapped = true;
            }
            else {
                outputFile << prevLine << '\n';
                outputFile << currentLine << '\n';
            }
        }

        if (lineCount % 2 != 0) {
            // Copy the last line if there are an odd number of lines
            std::getline(inputFile, prevLine);
            outputFile << prevLine << '\n';
        }

        inputFile.close();
        outputFile.close();

    } while (swapped);

    std::remove(inFile.c_str());
    // Rename the sorted file to the original file name
    std::rename(outFile.c_str(), inFile.c_str());

    std::cout << "Sorting complete." << std::endl;
}