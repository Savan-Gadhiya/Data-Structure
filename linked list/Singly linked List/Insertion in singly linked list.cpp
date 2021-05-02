#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
node* head = NULL;
node* create_node()
{
    node* newnode;
    newnode = new node;
    cout<<"Enter a Data : ";
    cin>>newnode->data;
    newnode->next = NULL;
    return newnode;
}
void create_list()
{
    node *newnode = create_node();
    if(head==NULL)
        head = newnode;
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insert_At_beg()
{
    node* newnode = create_node();
    if(head==NULL)  head = newnode;
    else{
        newnode->next = head;
        head = newnode;
    }
}
void insert_At_end()
{
    node* newnode = create_node();
    if(head==NULL)   head = newnode;
    else{
        node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insert_At_pos(int pos)//pos staring from zero
{
    node* temp = head;
    int count=0;
    if(head==NULL){ insert_At_beg();return;}
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    count++;//temp->next != NULL lidhu che atle last node mate loop ni ander nahi ave
    cout<<"Count is = "<<count<<endl;
    if(pos<0 || pos>count){
        cout<<"Invalid position"<<endl;
        return;
    }

    else if(pos==0) insert_At_beg();
    else if(pos==count) insert_At_end();
    else{
        temp = head;count=0;
        while(count<pos-1){//count=1
            temp = temp->next;
            count++;
        }
        node* newnode = create_node();
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void display()
{
    node* temp = head;
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
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
                insert_At_beg();
                break;
            case 3:
                insert_At_end();
                break;
            case 4:
                int pos;
                cout<<"Enter a position: ";
                cin>>pos;
                insert_At_pos(pos);
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
