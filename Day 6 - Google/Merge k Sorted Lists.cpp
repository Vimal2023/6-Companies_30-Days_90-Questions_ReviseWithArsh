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
    // Logic - Like merge k sorted arrays (https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379?leftPanelTabValue=PROBLEM)
    // store freq of elements in map (it will be in sorted order)
    // traverse map and make new LL with values of map



    void insertAtTail(ListNode * &head, ListNode* &tail, int data){
        ListNode* newNode = new ListNode(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        map<int,int> m;

        for(int i = 0 ; i < lists.size(); i++){
            ListNode *curr = lists[i];

            while(curr){
                // cout<<curr -> val;
                // store freq in map
                m[curr -> val]++;
                curr = curr -> next;
            }
        }

        ListNode* head = NULL, *tail = NULL;

        // traverse map and insert values
        for(auto &x :m){
            int freq = x.second;
            while(freq--){
                insertAtTail(head,tail,x.first);
            }
        }

        return head;
    }
};
