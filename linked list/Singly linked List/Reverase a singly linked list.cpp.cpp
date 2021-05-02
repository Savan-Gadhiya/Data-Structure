#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
node* head = NULL;
void create_list()
{
    node* newnode = new node;
    newnode->next = NULL;
    cout<<"Enter a data : ";
    cin>>newnode->data;
    if(head == NULL){
        head = newnode;
    }
    else{
        node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}
void reverse()
{
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    node* prev = NULL,*curr = head,*nextnode = head;
    while(nextnode!=NULL){
        //cout<<"in while start"<<endl;
        nextnode = curr->next;//or nextnode= nextnode->next because at line 38 both are same
        curr->next = prev;//reverese
        prev = curr;
        curr = nextnode;
        //cout<<"in while"<<endl;
    }
    head = prev;//Ahiya prev atle aave karan ke curr node and next node bane sathe NULL thashe (while loop ni foesr line and last line) and tayare prev ae last node ne point karato hashe
}
void display(){
    node* temp= head;
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return ;
    }
    while(temp!=NULL) {  cout<<temp->data<<" "; temp = temp->next;}
    cout<<endl;
}
int main()
{
     while(1){
        cout<<"1.insert "<<endl;
        cout<<"2.reverse "<<endl;
        cout<<"3. display"<<endl;
        cout<<"4. exit"<<endl;
        cout<<"Enter tour choice :";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
                create_list();
                break;
            case 2:
                reverse();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                cout<<"In valid choice"<<endl;
        }
    }
    return 0;
}
