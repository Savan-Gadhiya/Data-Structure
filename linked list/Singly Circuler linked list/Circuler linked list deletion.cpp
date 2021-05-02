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
    node* newnode;
    newnode = new node;
    cout<<"Enter data : ";
    cin>>newnode->data;
    return newnode;
}
void create_list()
{
    node* newnode = create_node();
    // newnode = new node;
    // cout<<"Enter a data : ";
    // cin>>newnode->data;
    if(tail==NULL){
        tail = newnode;
        newnode->next = tail;
    }
    else{
        //node* temp = tail->next;
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void delete_at_beg()
{
    node* temp;
    //tail->next = temp->next;
    if(tail==NULL){
        cout<<"List is Empty"<<endl;return;
    }
    temp = tail->next;
    if(temp == temp->next){
        tail=NULL;
        return;
    }
    else{
        tail->next = temp->next;
        delete temp;
    }
}
void delete_at_end()
{
    if(tail==NULL){
        cout<<"List is Empty"<<endl;return;
    }
    node* temp = tail->next;
    if(tail == tail->next){
        tail=NULL;
        return;
    }
    else{
        node* curr = tail,*nextnode = curr->next;
        while(nextnode != tail){
           curr = nextnode;
           nextnode = curr->next;//next->next;
        }
        curr->next = tail->next;
        tail = curr;
        delete nextnode;
    }
}
void delete_at_pos(int pos)//same as delete from sigly link list
{
    int count=0;
    node *temp=tail->next;
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(temp->next == tail){
        tail=NULL;
        return;
    }
    while(temp->next != tail){
        count++;
        temp = temp->next;
    }
    count++;//temp->next != NULL lidhu che atle lasr node mate loop ni ander nahi ave
    if(pos<0 || pos>count){
        cout<<"Invalid position"<<endl;
        return;
    }
    if(pos==0){
        delete_at_beg();
        return;
    }
    else if(pos==count){
        delete_at_end();
        return;
    }
    else{
        temp = tail->next;count=1;
        while(count<pos-1)
        {
            temp = temp->next;
            count++;
        }
        node* t = temp->next;
        temp->next = temp->next->next;//t->next
        delete t;
    }
}
void display()
{
    if(tail==NULL){
        cout<<"List is empty"<<endl;return;
    }
    node* temp = tail->next;
    while(temp!=tail){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;//Last node mate temp = tail thai jashe aathi aae print nahi thay
    /*do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=tail->next);*///By this no need to print last node sepretly
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
                delete_at_beg();
                break;
            case 3:
                delete_at_end();
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
