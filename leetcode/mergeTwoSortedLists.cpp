struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode();
        ListNode *res = dummy;
        
        while (list1 || list2) {
            if ((list1 && !list2) || (list1 && list2 && list1->val < list2->val)) {
                res->next = new ListNode(list1->val);
                list1 = list1->next;
                res = res->next;
            } else if ((list2 && !list1) || (list2 && list1 && list2->val <= list1->val)) {
                res->next = new ListNode(list2->val);
                list2 = list2->next;
                res = res->next;
            }
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};