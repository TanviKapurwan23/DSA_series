#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> directories;
        std::stringstream ss(path);
        std::string directory;
        
        // Split the path by '/'
        while (std::getline(ss, directory, '/')) {
            // Ignore empty or '.' directories
            if (directory.empty() || directory == ".") {
                continue;
            }
            // Handle '..' directories
            else if (directory == "..") {
                if (!directories.empty()) {
                    directories.pop_back();
                }
            }
            // Regular directory
            else {
                directories.push_back(directory);
            }
        }
        
        // Construct the simplified path
        std::string simplifiedPath = "/";
        for (const std::string& dir : directories) {
            simplifiedPath += dir + "/";
        }
        
        // Remove the trailing '/' if not root directory
        if (simplifiedPath.size() > 1) {
            simplifiedPath.pop_back();
        }
        
        return simplifiedPath;
    }
};

int main() {
    Solution solution;

    std::string path1 = "/home/";
    std::string path2 = "/home//foo/";
    std::string path3 = "/home/user/Documents/../Pictures";

    std::cout << "Input 1: " << solution.simplifyPath(path1) << std::endl;
    std::cout << "Input 2: " << solution.simplifyPath(path2) << std::endl;
    std::cout << "Input 3: " << solution.simplifyPath(path3) << std::endl;

    return 0;
}
