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
    ListNode* findKth(ListNode* head, int k) {
        ListNode* temp = head;
        while (temp != nullptr && k > 1) {
            --k;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while (temp != nullptr) {
            ListNode* kthNode = findKth(temp, k);
            if (kthNode == nullptr) {
                if (prevNode) {
                    prevNode->next = temp;
                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseList(temp);

            if (temp == head) {
                head = kthNode; 
            } else {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};