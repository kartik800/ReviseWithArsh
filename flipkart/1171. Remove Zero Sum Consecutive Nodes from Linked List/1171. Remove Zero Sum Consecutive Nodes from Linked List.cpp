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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        map<int, ListNode*> mp;
        mp[0]  = dummy;

        int prefix = 0;
        while(curr){
            prefix += curr->val;

            if(mp.count(prefix)){
                ListNode *p = mp[prefix]->next;
                int value = prefix;
                while(p != curr){
                    value += p->val;
                    mp.erase(value);
                    p = p->next;
                }
                mp[prefix]->next = curr->next;

            }else{
                mp[prefix] = curr;
            }
            curr = curr->next;

        }
        return dummy->next; 
    }
};