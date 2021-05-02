#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
node* tail = NULL;
node* create_node()
{
    node* newnode = new node;
    cout<<"Enter a data: ";
    cin>>newnode->data;
    return newnode;
}
void create_list()
{
    node* newnode = create_node();
    if(tail == NULL)
    {
        tail = newnode;
        newnode->next = tail;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void insert_at_beg()
{
    node* newnode= create_node();
    if(tail==NULL){
        tail = newnode;
        newnode->next = tail;
        tail= newnode;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
    }
}
void insert_at_end()
{
    node* newnode = create_node();
    if(tail==NULL){
        tail = newnode;
        newnode->next = tail;
        tail= newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void insert_at_pos(int pos)
{
    int n=0,count=1;
    node* newnode;
    if(tail==NULL){
        newnode = create_node();
        tail = newnode;
        newnode->next = tail;
        tail= newnode;
        return;
    }
    node* temp = tail->next;
    while(temp!=tail){
        temp= temp->next;
        count++;
    }
    n = count;
    if(pos<0 || pos>n) cout<<"Invalid position"<<endl;
    else if(pos == 0) insert_at_beg();
    else if(pos == n) insert_at_end();
    else{
        count=1;temp = tail->next;
        while(count<pos){
            temp = temp->next;
            count++;
        }
        node* newnode = create_node();
        cout<<"1"<<endl;
        newnode->next = temp->next;
        cout<<"2"<<endl;
        temp->next = newnode;
        cout<<"3"<<endl;
    }
}
void display()
{
    node* temp = tail->next;
    while(temp!=tail){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
int main()
{
     int ch;
    while(1)
    {
        cout<<"1. insert node"<<endl;
        cout<<"2. insert at beg "<<endl;
        cout<<"3. insert at end "<<endl;
        cout<<"4. insert at pos "<<endl;
        cout<<"5. display"<<endl;
        cout<<"6. exit"<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                create_list();
                break;
            case 2:
                insert_at_beg();
                break;
            case 3:
                insert_at_end();
                break;
            case 4:
                int pos;
                cout<<"Enter a position: ";
                cin>>pos;
                insert_at_pos(pos);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(1);
            default:
                cout<<"Invalid choise "<<endl;
        }
    }
    return 0;
}
