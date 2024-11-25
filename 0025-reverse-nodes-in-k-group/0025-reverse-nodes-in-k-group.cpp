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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* node, int k) {
        while (node != nullptr && k > 1) {
            node = node->next;
            k--;
        }
        return node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kthNode = getKthNode(groupPrev->next, k);
            if (kthNode == nullptr) break;

            ListNode* groupNext = kthNode->next;
            ListNode* groupStart = groupPrev->next;
            kthNode->next = nullptr;

            reverseLinkedList(groupStart);

            groupPrev->next = kthNode;
            groupStart->next = groupNext;
            groupPrev = groupStart;
        }

        return dummy->next;
    }
};
