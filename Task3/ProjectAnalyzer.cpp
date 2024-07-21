#include "ProjectAnalyzer.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <algorithm>
#include <thread>

void trimLeadingWhitespaces(std::string& str) {
    auto it = str.begin();
    while (it != str.end() && std::isspace(*it)) {
        ++it;
    }
    str.erase(str.begin(), it);
}

ProjectAnalyzer::ProjectAnalyzer(const std::string& projectPath) 
    : projectPath(projectPath), blankLines(0), commentLines(0), codeLines(0), numberOfFiles(0) {
    files = listFilesInDirectory(projectPath);
    numberOfFiles = files.size();
}

std::vector<std::string> ProjectAnalyzer::listFilesInDirectory(const std::filesystem::path& path) {
    std::vector<std::string> files;
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
            if(entry.path().extension() == ".h" || entry.path().extension() == ".cpp" || 
                entry.path().extension() == ".hpp" || entry.path().extension() == ".c") {
                files.push_back(entry.path().string());
            }
        }
    } else {
        std::cerr << "The provided path is not a directory or does not exist." << std::endl;
    }
    return files;
}

void ProjectAnalyzer::countCommentsCodeBlank(const std::string& file) {
    std::ifstream fileStream(file);
    if (!fileStream.is_open()) {
        std::cerr << "Could not open file: " << file << std::endl;
        return;
    }

    std::string line;
    bool isMultilineComment = false;
    while (std::getline(fileStream, line)) {
        trimLeadingWhitespaces(line);
        if (line.empty()) {
            blankLines++;
        } else if (line.find("/*") != std::string::npos) {
            commentLines++;
            isMultilineComment = true;
        } else if (line.find("*/") != std::string::npos && isMultilineComment) {
            commentLines++;
            isMultilineComment = false;
        } else if (isMultilineComment) {
            commentLines++;
        } else if (line.find("//") != std::string::npos) {
            commentLines++;
            if(line.find("//") > 0) {
                codeLines++;
            }
        } else {
            codeLines++;
        }
    }

    fileStream.close();
}

void ProjectAnalyzer::analyze() {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> threads;
    int numThreads = std::thread::hardware_concurrency();
    int filesPerThread = files.size() / numThreads;
    int remainingFiles = files.size() % numThreads;

    for (int i = 0; i < numThreads; i++) {
        int start = i * filesPerThread;
        int end = (i + 1) * filesPerThread;
        if (i == numThreads - 1) {
            end += remainingFiles;
        }

        threads.push_back(std::thread([this, start, end]() {
            for (int j = start; j < end; j++) {
                countCommentsCodeBlank(files[j]);
            }
        }));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    timeOfExecution = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

void ProjectAnalyzer::printResults() {
    std::cout << "Number of files: " << numberOfFiles << std::endl;
    std::cout << "Number of blank lines: " << blankLines << std::endl;
    std::cout << "Number of comment lines: " << commentLines << std::endl;
    std::cout << "Number of code lines: " << codeLines << std::endl;
    std::cout << "Time of execution: " << timeOfExecution << " ms" << std::endl;

    std::string tmp = projectPath;
    std::replace(tmp.begin(), tmp.end(), '/', '_');
    tmp.erase(std::remove(tmp.begin(), tmp.end(), ':'), tmp.end());
    std::replace(tmp.begin(), tmp.end(), '\\', '_');

    std::string filename = "..\\" + tmp + "_results.txt";
    std::cout << "Results saved to: " << filename << std::endl;

    std::ofstream filest(filename);
    if (!filest.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    filest << "Number of files: " << numberOfFiles << std::endl;
    filest << "Number of blank lines: " << blankLines << std::endl;
    filest << "Number of comment lines: " << commentLines << std::endl;
    filest << "Number of code lines: " << codeLines << std::endl;
    filest << "Time of execution: " << timeOfExecution << " ms" << std::endl;

    filest.close();
}

int main(int argc, char **argv) {
    if (argc != 2)
    {
        std::cerr << "Run: " << "\n." << argv[0] << " <path>\n";
        return 1;
    }

    std::string projectPath = argv[1];

    ProjectAnalyzer projectAnalyzer(projectPath);
    projectAnalyzer.analyze();
    projectAnalyzer.printResults();
    

    return 0;
}