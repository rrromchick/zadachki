#include <vector>
#include <string>

class Node {
public:
    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr);
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node *get(char ch) {
        return links[ch - 'a'];
    }

    void setIsEnd() {
        flag = true;
    }

    bool getIsEnd() {
        return flag;
    }

    void setIsWordFound() {
        isWordFound = true;
    }

    bool getIsWordFound() {
        return isWordFound;
    }
private:
    Node *links[26];
    bool flag = false;
    bool isWordFound = false;
};

class Trie {
public:
    Trie() {
        root = new Node();
    }

    Node *getRoot() {
        return root;
    }

    void insert(std::string &word) {
        Node *node = root;
        for (char &ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setIsEnd();
    }

    void search(int row, int col, std::vector<std::vector<int>> &vis, std::string &str, Node *node, 
        std::vector<std::vector<char>> &board, int m, int n, std::vector<std::string> &ans)
    {
        if (node == nullptr) return;
        vis[row][col] = 1;
        str += board[row][col];

        if (node->getIsEnd() && !node->getIsWordFound()) {
            ans.push_back(str);
            node->setIsWordFound();
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; ++i) {
            int x = row + dx[i];
            int y = col + dy[i];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                char ch = board[x][y];
                if (node->containsKey(ch)) {
                    search(x, y, vis, str, node->get(ch), board, m, n, ans);
                }
            }
        }
        str.pop_back();
        vis[row][col] = 0;
    }
private:
    Node *root;
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        Trie trie;
        for (std::string &word : words) trie.insert(word);

        int m = board.size(), n = board[0].size();
        std::vector<std::vector<int>> vis(m, std::vector<int>(n, 0));

        std::vector<std::string> ans;
        Node *node = trie.getRoot();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (node->containsKey(board[i][j])) {
                    std::string str = "";
                    trie.search(i, j, vis, str, node->get(board[i][j]), board, m, n, ans);
                }
            }
        }

        return ans;
    }
};