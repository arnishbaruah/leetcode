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
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalfHead = reverseLinkedList(slow->next);
        ListNode* firstHalfHead = head;

        ListNode* temp = secondHalfHead;
        bool isPalin = true;
        while (temp != nullptr) {
            if (firstHalfHead->val != temp->val) {
                isPalin = false;
                break;
            }
            firstHalfHead = firstHalfHead->next;
            temp = temp->next;
        }

        slow->next = reverseLinkedList(secondHalfHead);
        return isPalin;
    }
};
