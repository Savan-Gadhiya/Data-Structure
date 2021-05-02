#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next,*prev;
};
node* head = NULL,*tail = NULL;
node* craete_node()
{
    node* newnode = new node;
    newnode->next = newnode->prev = NULL;
    cout<<"Enter data: ";
    cin>>newnode->data;
    return newnode;
}
void create_list()
{
    node* newnode = craete_node();
    if(head == NULL && tail == NULL){
        head = tail = newnode;
    }
    else{
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}
void reverse()
{
    if(head==NULL)  return;
    if(head == tail) return;
    node *temp,*curr=head,*nextnode = head;
    while(curr != tail){
        curr = nextnode;
        nextnode = curr->next;

        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        //curr = curr->next;
    }
    temp = head;
    head = tail;
    tail = temp;
}
void display()
{
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    while(1){
        cout<<endl<<"1.insert "<<endl;
        cout<<"2. display"<<endl;
        cout<<"3. reverse"<<endl;
        cout<<"4. exit"<<endl;
        cout<<"Enter tour choice :";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
                create_list();
                break;
            case 2:
                display();
                break;
            case 3:
                reverse();
                break;
            case 4:
                exit(1);
            default:
                cout<<"In valid choice"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
