#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Node {
    std::string name;
    std::unordered_map<std::string, Node*> children;
    std::string signature;

    Node(std::string name) : name(name) {}
};

class Solution {
public:
    std::vector<std::vector<std::string>> deleteDuplicateFolder(std::vector<std::vector<std::string>>& paths) {
        Node* root = new Node("");
        for (const auto& path : paths) {
            Node* curr = root;
            for (const std::string& folder : path) {
                if (curr->children.find(folder) == curr->children.end()) {
                    curr->children[folder] = new Node(folder);
                }
                curr = curr->children[folder];
            }
        }

        std::unordered_map<std::string, int> signatureCount;
        dfs(root, signatureCount);

        std::vector<std::vector<std::string>> result;
        std::vector<std::string> currentPath;
        for (const auto& [name, child] : root->children) {
            dfs2(child, currentPath, result, signatureCount);
        }

        delete root;
        return result;
    }
private:
    void dfs(Node* node, std::unordered_map<std::string, int>& signatureCount) {
        if (node->children.empty()) {
            node->signature = "";
            return;
        }

        std::vector<std::string> childSignatures;
        for (const auto& [name, child] : node->children) {
            dfs(child, signatureCount);
            childSignatures.push_back(name + "(" + child->signature + ")");
        }
        std::sort(childSignatures.begin(), childSignatures.end());
        node->signature = "";
        for (const std::string& sig : childSignatures) {
            node->signature += sig;
        }
        signatureCount[node->signature]++;
    }

    void dfs2(Node* node, std::vector<std::string>& currentPath, std::vector<std::vector<std::string>>& result, std::unordered_map<std::string, int>& signatureCount)
    {
        if (!node->children.empty() && signatureCount[node->signature] >= 2) {
            return;
        }
        currentPath.push_back(node->name);
        result.push_back(currentPath);
        for (const auto& [name, child] : node->children) {
            dfs2(child, currentPath, result, signatureCount);
        }
        currentPath.pop_back();
    }
};