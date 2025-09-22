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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1=head;
        int size=0;
        while(temp1!=NULL){
            size++;
            temp1=temp1->next;
        }
        ListNode* temp2=head;
        if(size-n==0){
            head=head->next;
            temp2->next=NULL;
            delete temp2;
            return head;
        }
        for(int i=1;i<size-n;i++){
            temp2=temp2->next;
        }
        ListNode* xyz=temp2->next;
        temp2->next=temp2->next->next;
        delete xyz;
        return head;
    }
};