#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

 Node(int data){
    this->data = data;
    this->next = NULL;
 }
};

void print( Node* head){
    Node* temp = head;
    while (temp!= NULL)
    {
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;

}
// checking loop is present or not
bool checkforLoop(Node* &head){
    if(head==NULL){
        cout<<"LL is empty";
    }
    Node* slow = head;
    Node*fast = head;
    while (fast!=NULL)
    {
    fast= fast->next;
    if(fast!=NULL){
        fast = fast->next;
        slow= slow->next;

    }
    if(slow== fast){
        return true;
    }
    }
    return false;
    
}
// find starting position of loop in linked list
Node* startofLoop(Node* &head){
    if(head==NULL){
        cout<<"LL is empty";
        
    }
    Node* slow = head;
    Node*fast = head;
    while (fast!=NULL)
    {
    fast= fast->next;
    if(fast!=NULL){
        fast = fast->next;
        slow= slow->next;

    }
    if(slow== fast){
      slow = head;
      break;
    }
    }
    while(slow!=fast){
        slow = slow->next;
        fast= fast->next;
    }
    
    return slow;
   
    
}
// Delete of loop from Linked list
Node* removeofLoop(Node* &head){
    if(head==NULL){
        cout<<"LL is empty";  
    }
    Node* slow = head;
    Node*fast = head;
    while (fast!=NULL)
    {
    fast= fast->next;
    if(fast!=NULL){
        fast = fast->next;
        slow= slow->next;

    }
    if(slow== fast){
      slow = head;
      break;
    }
    }
    Node* prev = fast;
    while(slow!=fast){
        prev = fast;
        slow = slow->next;
        fast= fast->next;
    }
    prev->next = NULL;
    return slow;
   
     
}
int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third= new Node(30);
    Node* forth= new Node(40);
    Node*fifth= new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eigth = new Node(80);
   
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eigth;
    eigth->next= forth;

    // print(head);
    // cout<<endl;
    cout<<"loop is present or not\t\t" << checkforLoop(head)<<endl;
    cout<<"start of loop value is :"<<startofLoop(head)->data<<endl;
    cout<<" remove te loop:\n";
    removeofLoop(head);
    print(head);

    return 0;
}
