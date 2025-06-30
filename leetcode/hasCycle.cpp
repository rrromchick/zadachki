#include <unordered_map>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        std::unordered_map<ListNode*, bool> vis;
        ListNode *node = head->next;
        vis[head] = true;
        while (node && node->next != NULL) {
            if (vis[node]) return true;
            vis[node] = true;
            node = node->next;
        }

        return false;
    }
};