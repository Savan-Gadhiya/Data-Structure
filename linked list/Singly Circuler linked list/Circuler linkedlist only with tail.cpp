#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
node* tail = NULL;
void create_list()
{
    node* newnode;
    newnode = new node;
    cout<<"Enter a data : ";
    cin>>newnode->data;
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
        cout<<"1.insert "<<endl;
        cout<<"2. display"<<endl;
        cout<<"3, exit"<<endl;
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
                exit(1);
            default:
                cout<<"In valid choice"<<endl;
        }
    }
    return 0;
}