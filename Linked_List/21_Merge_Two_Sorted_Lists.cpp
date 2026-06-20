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
        vector<int> ans;
        while(list1 != nullptr){
            ans.push_back(list1->val);
            list1 = list1->next;
        }
        while(list2 != nullptr){
            ans.push_back(list2->val);
            list2 = list2->next;
        }

        sort(ans.begin(), ans.end());
        if(ans.empty()) return nullptr;
        ListNode* head = new ListNode(ans[0]);
        ListNode* tail = head;
        for(int i = 1; i < ans.size(); i++){
            ListNode* temp = new ListNode(ans[i]);
            tail->next = temp;
            tail = tail->next;
        }


        return head;
    }
};
