#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next,*prev;
};
node* head = NULL,*tail=NULL;
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
    if(head==NULL && tail==NULL){
        head = tail = newnode;
        head->prev = tail;
        tail->next = head;
    }
    else{
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        tail = newnode;
    }
}
void insert_at_beg()
{
    node* newnode = create_node();
    if(head==NULL and tail==NULL){
        head = tail = newnode;
        head->prev = tail;
        tail->next = head;
    }
    else{
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        head = newnode;
    }

}
void insert_at_end()
{
    node* newnode = create_node();
    if(head == NULL and tail ==NULL){
        head = tail = newnode;
        head->prev = tail;
        tail->next = head;
    }
    else{
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        tail->next = newnode;
        tail = newnode;
    }
}
void insert_at_pos(int pos)
{
    if(pos==0){
        insert_at_beg();
        return;
    }
    node* temp = head;int count=0;
    while(temp!=tail){
        count++;
        temp = temp->next;
    }
    if(head!=NULL)  count++;
    cout<<"Count is : "<<count<<endl;
    if(pos<0 || pos>count){
        cout<<"Invalid position"<<endl;
        return;
    }
    else if(pos == count){
        insert_at_end();return;
    }
    else{
        temp = head;count=1;//index start with 0
        while(count<pos){
            temp = temp->next;
            count++;
        }
        node* newnode = create_node();
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}
void display()
{
    node* temp = head;
    while(temp != tail){
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
