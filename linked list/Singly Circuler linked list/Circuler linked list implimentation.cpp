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
    return newnode;
}
void create_list()
{
    node* newnode  = create_node();
    if(head==NULL){
        head = newnode;
        newnode->next = newnode;
    }
    else{

        node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}
void display()
{
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);//Jo ahi do while loop no lakhavu hoy to last node alag thi print karavo pase see file without prectice
    cout<<endl;
}
int main()
{
    while(1)
    {
        cout<<"1. insert "<<endl;
        cout<<"2. display"<<endl;
        cout<<"3. exit"<<endl;
        cout<<endl<<"Enter your choice: ";
        int ch;
        cin>>ch;
        switch(ch)
        {
        case 1:
            create_list();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(2);
        }
    }
    return 0;
}
