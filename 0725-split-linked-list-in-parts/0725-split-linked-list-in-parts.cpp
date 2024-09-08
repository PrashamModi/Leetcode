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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cntNodes = 0;
        ListNode* curr = head;
        while(curr){
            cntNodes++;
            curr = curr->next;
        }
        int div = cntNodes / k;
        int extra = cntNodes % k;
        curr = head;
        vector<ListNode* > ans(k);
        for(int i = 0; i < k; i++){
            ListNode* temp = curr;
            int j = 0;
            while(j < div - 1 + (i < extra ? 1 : 0)){
                if(curr)
                    curr = curr->next;
                j++;
            }
            if(curr){
                ListNode *prev = curr;
                curr = curr->next;
                prev->next = NULL; 
            }
            ans[i] = temp;
        }
        return ans;
    }
};