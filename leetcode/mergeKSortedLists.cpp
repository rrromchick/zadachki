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
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for (int i = 0; i < lists.size(); ++i) {
            while (lists[i]) {
                q.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        if (q.size() == 0) {
            return nullptr;
        }
        ListNode *head = new ListNode(q.top());
        q.pop();
        ListNode* cur = head;
        while (q.size() > 0) {
            cur->next = new ListNode(q.top());
            q.pop();
            cur = cur->next;
        }

        return head;
    }
};