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
    node* newnode = new node;
    cout<<"Enter a data : ";
    cin>>newnode->data;
    newnode->next = NULL;
    return newnode;
}
void create_list()
{
    node* newnode = create_node();
    node* temp = head;
    if(head==NULL)
        head = newnode;
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}
void delete_from_beg()
{
    node *temp = head;
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->next == NULL)
    {
        head = NULL;
        return;
    }
    head = temp->next;
    delete temp;
}
void delete_from_end()
{
    node* curr = head;
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    //if(head->next == NULL){
    node* prev = head;curr=head;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    if(curr==head){
        head=NULL;
        delete curr;
        return;
    }

    prev->next = NULL;
    delete curr;
    /*node* temp,*previous;
    temp = previous = head;
    while(temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }
    if(head == temp){//Jayaree only ek j node hoy tayare
        head = NULL;
        //delete temp;
    }
    else
    {
        previous->next = NULL;
        //delete temp;
    }
    delete temp;
//    return head;*/
}
node* deleteByPos(node* head)
{
    node *temp,*previous;
    temp = previous = head;
    int pos;
    cout<<"Enter a position\n";
    cin>>pos;
    int i=1;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    node* nextnode = temp->next;
    temp->next = nextnode->next;
    delete nextnode;
    return head;
}
void delete_from_pos(int pos)
{
    int count=0;
    node *temp=head;
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->next == NULL){
        head=NULL;
        return;
    }
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    count++;//temp->next != NULL lidhu che atle lasr node mate loop ni ander nahi ave
    if(pos<0 || pos>count){
        cout<<"Invalid position"<<endl;
        return;
    }
    if(pos==0){
        delete_from_beg();
        return;
    }
    else if(pos==count){
        delete_from_end();
        return;
    }
    else{
        temp = head;count=1;
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
        cout<<"2. delete at beg "<<endl;
        cout<<"3. delete at end "<<endl;
        cout<<"4. delete at pos "<<endl;
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
                delete_from_beg();
                break;
            case 3:
                delete_from_end();
                break;
            case 4:
                int pos;
                cout<<"Enter a position: ";
                cin>>pos;
                delete_from_pos(pos);
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
