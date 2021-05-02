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
    newnode->prev = newnode->next = NULL;
    cout<<"Enter a Data: ";
    cin>>newnode->data;
    return newnode;
}
void create_list()
{
    node* newnode = create_node();
    if(head==NULL && tail==NULL){
        head = tail = newnode;
    }
    else{
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}
void insert_at_beg()
{
    node* newnode = create_node();
    if(head == NULL && tail == NULL)
    {
        head = tail = newnode;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head= newnode;
    }
}
void insert_at_end()
{
    node* newnode = create_node();
    if(head == NULL && tail == NULL){
        head = tail = newnode;
    }
    else{
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}
void insert_at_pos(int pos)
{
    node* temp=head;
    int count=0;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if(pos<0 || pos>count){
        cout<<"Invalid position"<<endl;
        return;
    }
    if(pos==0){
        insert_at_beg();
        return;
    }
    else if(pos==count){
        insert_at_end();return;
    }
    else{
        temp = head,count=1;
        while(count<pos){
            temp = temp->next;
            count++;
        }
        node* newnode = create_node();
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}
void display()
{
    node* temp = head;
    while(temp!=NULL){
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
