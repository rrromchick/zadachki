/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
#include <vector>
#include <algorithm>

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(std::vector<std::vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());
    }
private:
    Node *helper(const std::vector<std::vector<int>>& grid, int i, int j, int w) {
        if (allSame(grid, i, j, w)) {
            return new Node(grid[i][j], true);
        }

        Node* node = new Node(true, false);
        node->topLeft = helper(grid, i, j, w / 2);
        node->topRight = helper(grid, i, j + w / 2, w / 2);
        node->bottomLeft = helper(grid, i + w / 2, j, w / 2);
        node->bottomRight = helper(grid, i + w / 2, j + w / 2, w / 2);
        return node;
    }

    bool allSame(const std::vector<std::vector<int>>& grid, int i, int j, int w) {
        return std::all_of(std::begin(grid) + i, std::begin(grid) + i + w,
            [&](const std::vector<int> &row) {
                return std::all_of(std::begin(row) + j, std::begin(row) + j + w,
                    [&](int num) { return num == grid[i][j]; });
            });
    }
};