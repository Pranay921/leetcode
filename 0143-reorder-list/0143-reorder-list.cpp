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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return ;
        ListNode* mid=midd(head);
        ListNode* first=head;
        ListNode* second=reverse(mid);
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(first!=NULL && second!=NULL){
            temp->next=first;
            first=first->next;
            temp=temp->next;
            temp->next=second;
            second=second->next;
            temp=temp->next;
        }
        if(first!=NULL) temp->next=first;
        if(second!=NULL) temp->next=second;
    }
    ListNode* midd(ListNode* node){
        ListNode* slow=node;
        ListNode* fast=node;
        ListNode* prev;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL) prev->next=NULL;
        return slow;
    }
    ListNode* reverse(ListNode* node){
        ListNode* curr=node;
        ListNode* next;
        ListNode* prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};