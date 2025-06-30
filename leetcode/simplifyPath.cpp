#include <string>
#include <stack>
#include <sstream>
#include <vector>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stringstream ss(path);
        std::string comp;
        while (std::getline(ss, comp, '/')) {
            if (comp == "" || comp == ".") {
                continue;
            }

            if (comp == "..") {
                if (!st.empty()) {
                    st.pop_back();
                } 
            } else {
                st.push_back(comp);
            }
        }

        std::stringstream simplifiedPath;
        for (const auto& s : st) {
            simplifiedPath << "/" << s;
        }

        return simplifiedPath.str().empty() ? "/" : simplifiedPath.str();
    }
private:
    std::vector<std::string> st;
};