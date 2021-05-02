#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* prev,*next;
};
node* head=NULL,*tail=NULL;
node* create_node()
{
    node* newnode = new node;
    newnode->prev= newnode->next = NULL;
    cout<<"Enter a data : ";
    cin>>newnode->data;
    return newnode;
}
void create_list()
{
    node* newnode=  create_node();
    if(head==NULL and tail==NULL){
        head = tail= newnode;
    }
    else{
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}
void display()
{
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    int ch;
    while(1)
    {
        cout<<"1. Create List "<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. exit"<<endl;
        cout<<endl<<"Enter your choise : ";
        cin>>ch;
        switch(ch){
            case 1:
            create_list();
            break;
            case 2:
            display();
            break;
            case 3:
                exit(1);
            default:
                cout<<"invalid choice"<<endl;
        }
    }
}
