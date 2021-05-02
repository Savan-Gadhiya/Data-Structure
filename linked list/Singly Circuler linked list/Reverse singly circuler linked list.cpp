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
    cout<<"Enter a data : ";
    cin>>newnode->data;
    return newnode;
}
void create_list()
{
    node* newnode = create_node();
    if(tail==NULL)
    {
        tail = newnode;
        newnode->next = tail;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail=  newnode;
    }
}
void reverse()
{
    node* curr,*prev,*nextnode;
    curr = tail->next;
    nextnode = curr->next;
    while(curr!=tail)
    {
        prev = curr;
        curr = nextnode;
        nextnode = nextnode->next;
        curr->next = prev;//reverse
    }
    nextnode->next = tail;
    tail = nextnode;
}
void display()
{
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
