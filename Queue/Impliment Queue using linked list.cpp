#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
node* front=NULL,*rear=NULL;
void enqueue(int x)
{
    node* newnode = new node;
    newnode->data = x;
    newnode->next = NULL;
    if(front==NULL && rear == NULL){
        front  = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear =newnode;
    }
}
int dequeue(){
    //---node* temp = front;,int D;
    if(front==NULL && rear==NULL){
        cout<<"Queue is empty\n";
        return -1;
    }
    if(front==rear){
        int D = front->data;
        node* temp = front;//---
        front = rear = NULL;
        delete temp;//---
        return D;//---
    }
    else
    {
        node* temp = front;//---
        int D = front->data;//if above declare than no declare here
        front = front->next;
        delete temp;//---
        return D;//---
    }
    // delete temp;
    // return D;
}
int peek()
{
    if(front==  NULL  && rear==NULL){
        cout<<"Queue is empty\n";return -1;
    }
    return front->data;
}
void display()
{
    node *temp = front;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    //Queue <int> Q(5);
    while(1){
        cout<<"\n1.enqueue\n";
        cout<<"2.dequque\n";
        cout<<"3.peek\n";
        cout<<"4.display\n";
        cout<<"5.exit\n";
        cout<<"\nEnter your choice : ";
        int ch;
        cin>>ch;
        int x;
        switch(ch)
        {
        case 1:
            cout<<"Enter a Data: ";     cin>>x;
            enqueue(x);
            break;
        case 2:
            x = dequeue();
            cout<<"data  = "<<x<<endl;
            break;
        case 3:
            x = peek();
            if(front != NULL && rear!=NULL)    cout<<"data  = "<<x<<endl;
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            cout<<"Invalid choice\n";
        }
    }
}
