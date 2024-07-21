#include <string>
#include <vector>
#include <filesystem>

class ProjectAnalyzer {
private:
    std::string projectPath;
    std::vector<std::string> files;
    int blankLines;
    int commentLines;
    int codeLines;
    int numberOfFiles;
    int timeOfExecution;

    std::vector<std::string> listFilesInDirectory(const std::filesystem::path& path);
    void countCommentsCodeBlank(const std::string& file);

public:
    ProjectAnalyzer(const std::string& projectPath);
    void analyze();
    void printResults();
};
