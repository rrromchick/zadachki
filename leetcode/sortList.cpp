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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *temp = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        return mergelist(l1, l2);
    }

    ListNode *mergelist(ListNode *l1, ListNode *l2) {
        ListNode *ptr = new ListNode(0);
        ListNode *cur = ptr;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        if (l1 != nullptr) {
            cur->next = l1;
            l1 = l1->next;
        } 

        if (l2 != nullptr) {
            cur->next = l2;
            l2 = l2->next;
        }

        return ptr->next;
    }
};