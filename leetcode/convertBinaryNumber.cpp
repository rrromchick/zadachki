/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        std::vector<int> bits;
        ListNode *node = head;
        while (node) {
            bits.push_back(node->val);
            node = node->next;
        }

        int ans = 0;
        for (int i = 0; i < bits.size(); ++i) {
            ans += (bits[i] ? (1 << (bits.size() - i - 1)) : 0);
        }

        return ans;
    }
};