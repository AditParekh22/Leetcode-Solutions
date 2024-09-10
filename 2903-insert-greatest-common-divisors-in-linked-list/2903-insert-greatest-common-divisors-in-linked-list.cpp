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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* frw = head->next;

        while(frw!=NULL){
            int GCD = __gcd(curr->val, frw->val);
            ListNode* temp = new ListNode(GCD);

            curr->next = temp;
            temp->next = frw;

            curr = frw;
            frw = frw->next;
        }

        return head;
        
    }
};