#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node* next,*prev;
};
node* head = NULL,*tail= NULL;
node* create_node()
{
    node* newnode = new node;
    cout<<"Enter a data : ";
    cin>>newnode->data;
    return newnode;
}
void create_list()
{
    node* newnode = create_node();
    if(head==NULL && tail ==NULL){
        head = tail = newnode;
        head->prev = newnode;
        tail->next = newnode;
    }
    else{
        newnode->next = head;
        newnode->prev = tail;
        tail->next = newnode;
        head->prev = newnode;
        tail = newnode;
    }
}
void delete_from_beg()
{
    node* temp = head;
    if(head==NULL && tail==NULL){
        cout<<"List is empty"<<endl;
    }
    else if(head==tail){
        head = tail = NULL;
        delete temp;
    }
    else{
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
}
void delete_from_end()
{
    node* temp = tail;
    if(head==NULL && tail==NULL){
        cout<<"List is empty"<<endl;
    }
    else if(head==tail){
        head = tail = NULL;
        delete temp;
    }
    else{
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }
}
void delete_at_pos(int pos)
{
    node* temp = head;int count=0;
    if(head==NULL && tail==NULL){
        cout<<"List is empty"<<endl;
    }
    if(head==tail && pos==0){
        head = tail = NULL;
        delete temp;
    }
    while(temp!=tail){
        count++;
        temp = temp->next;
    }
    if(temp!=NULL)  count++;
    if(pos<0 || pos>count){
        cout<<"Invalid position"<<endl;
        return;
    }
    else if(pos==0){
        delete_from_beg();return;
    }
    else if(pos==count){
        delete_from_end();return;
    }
    else{
        temp  = head;count=0;
        while(count<pos){
            temp = temp->next;
            count++;
        }
        //node *t = temp;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;//delete templ
    }
}
void display()
{
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
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

        cout<<endl<<"1. createlist"<<endl;
        cout<<"2. Delete from beg"<<endl;
        cout<<"3. Delete from end"<<endl;
        cout<<"4. Delete at pos"<<endl;
        cout<<"5. Display"<<endl;
        cout<<endl<<" Enter your choise: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                create_list();
                break;
            case 2:
                delete_from_beg();
                break;
            case 3:
                delete_from_end();
                break;
            case 4:
                cout<<"Enter a pos"<<endl;
                int pos;
                cin>>pos;
                delete_at_pos(pos);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(3);
                break;
            default:
                cout<<"Invalid Choice:"<<endl;
        }
        cout<<endl;
    }
}
