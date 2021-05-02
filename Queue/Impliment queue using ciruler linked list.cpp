#include<iostream>
using namespace std;
//template <class T>
class node
{
    public:
    int data;
    node* next;

    ~node()
    {
        delete next;
    }
};
node* front=NULL,*rear=NULL;
node* create_node(int x)
{
    node* newnode = new node;
    newnode->data = x;
    newnode->next=NULL;
    return newnode;
}
void enqueue(int x)
{
    node* newnode = create_node(x);
    if(front==NULL && rear==NULL){
        front=rear=0;
        front = rear = newnode;
        newnode->next = front;
    }
    else{
        rear->next = newnode;
        newnode->next = front;
    }
}
int  dequeue()
{
    node* temp = front;
    if(front==NULL && rear == NULL){
        cout<<"Queue is Empty"<<endl;
        return -1;
    }
    else if(front==rear){
        int t = front->data;
        front=rear=NULL;
        return t;
    }
    else
    {
        int t = front->data;
        front = front->next;
        delete temp;
        return t;
    }
}
int peek()
{
    if(front==NULL){
        cout<<"Queue is Empty"<<endl;
        return -1;
    }
    return front->data;
}
void display()
{
    if(front==NULL && rear == NULL){
        cout<<"Queue is empty"<<endl;
        return ;
    }
    node* temp=front;
    while(temp != rear)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
int main()
{
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
            //if(!empty())
            cout<<"data  = "<<x<<endl;
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
    return 0;
}
