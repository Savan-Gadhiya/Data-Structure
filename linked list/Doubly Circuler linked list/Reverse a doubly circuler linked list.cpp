#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* prev,*next;
};
node* head = NULL,*tail=NULL;
node* create_node()
{
    node* newnode = new node;
    cout<<"Enter a data: "<<endl;
    cin>>newnode->data;
    return newnode;
}
void create_list()
{
    node* newnode = create_node();
    if(head==NULL and tail==NULL){
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
void reverse()
{
    if(head==NULL){
        cout<<"list is empty"<<endl;return;
    }
    if(head==tail)return;
    node* curr=head,*nextnode = curr->next;node* temp;
    while(curr!=tail){

        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = nextnode;
        nextnode = nextnode->next;//curr->next;
    }
    temp = curr->prev;//Last node mate curr = tail thai jashe aathi ae swap nahi thay
    curr->prev = curr->next;
    curr->next = temp;

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
    while(temp != tail){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
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
