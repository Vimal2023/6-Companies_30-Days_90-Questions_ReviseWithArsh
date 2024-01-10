class LListNode{   // Creating our own double Lisked list
  public:
    
    int val;
    LListNode* next;
    LListNode* pre;
    
    LListNode(int x)
    {
        val=x;
        next= NULL;
        pre = NULL;
    }
    
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k == 1) // Base condition
            return n;
        LListNode* head = new LListNode(1); //  Creating head
        LListNode* tail = head;  //  Creating tail and assign it to head for now
        
        for(int i=2;i<=n;i++)  // Creating the rest of the list
        {
            LListNode* temp = new LListNode(i);
            
            tail->next = temp;
            temp->pre = tail;
            
            tail = tail->next;
        }
        
        head->pre = tail;
        tail->next = head; // Connecting the head and tail
     
        LListNode* temp = head;  // Iterator
        LListNode* p = head;

		while(temp->next != temp) // For the last remaining element the next will point to itself
        {
            for(int i=1;i<k-1;i++) 
            {
                temp = temp->next;
            }
			
            p = temp->next->next;
            p->pre = temp;
            temp->next = p;
            
            
            temp = temp->next;
            
        }
        
        return temp->val;
    }
};
