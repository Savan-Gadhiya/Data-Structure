#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
node *top= NULL;
void push(int x){
    node *newnode = new node;
    newnode->data = x;
    newnode->next = NULL;
    if(top==NULL){
        top = newnode;
    }
    else{
        newnode->next = top;
        top = newnode;
    }
}
int pop(){
    if(top==NULL){
        cout<<"UnderFlow\n";return -1;
    }
    node* temp = top;
    int t = top->data;
    top  = top->next;
    delete temp;
    return t;
}
int peek(){
    if(top==NULL){
        cout<<"UnderFlow\n";return -1;
    }
    return top->data;
}
void display()
{
    node* temp = top;
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
        int x;
        cout<<"1. push"<<endl;
        cout<<"2. pop"<<endl;
        cout<<"3. peek"<<endl;
        cout<<"4. display"<<endl;
        cout<<"5. exit"<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter a element :";
                cin>>x;
                push(x);
                break;
            case 2:
                if(top!=NULL){
                    cout<<"poped data is : "<<pop()<<endl;
                }
                break;
            case 3:
                if(top!=NULL){
                    cout<<"peeked data is : "<<peek()<<endl;
                }
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                cout<<"Invalid choice: ";
        }

    }return 0;
}
