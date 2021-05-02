#include<iostream>
using namespace std;
class Queue
{
    int *arr;
    int n;
    int front=-1,rear=-1;
    public:
    Queue(int n1)
    {
        n = n1;
        arr = new int[n];
    }
    ~Queue(){
        delete []arr;
    }
    void insert_front(int );
    void enqueue(int);
    int dequeue();
    int delete_last();
    int get_front();
    int get_rear();
    void display();
};
void Queue::insert_front(int x)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        arr[front]=x;
    }
    else if(front==(rear+1)%n){//if((front==0 && rear==n-1 ) || front == rear+1)
        cout<<"Queue is Full"<<endl;
        return;
    }
    else if(front==0){
        front=n-1;
        arr[front] = x;
    }
    else{
        front--;
        arr[front] = x;
    }
}
void Queue::enqueue(int x)//insert_last
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        arr[rear]=x;
    }
    else if(front==(rear+1)%n){//f((front==0 && rear==n-1 ) || front == rear+1)
        cout<<"Queue is Full"<<endl;
        return;
    }
    else if(rear==n-1){
        rear=0;
        arr[rear]=x;
    }
    else{
        rear++;
        arr[rear]=x;
    }
}
int Queue::delete_last()
{
    if(front==-1 && rear==-1){
        cout<<"Queue is Full"<<endl;
        return -2;
    }
    else if(front==rear)
    {
        int temp = arr[rear];
        front=rear=-1;
        return temp;
    }
    else if(rear==0){
        int temp = arr[rear];
        rear=n-1;
        return temp;
    }
    else{
        int temp = arr[rear];
        rear--;
        return temp;
    }
}
int Queue::dequeue()
{
    int temp;
    if(front==-1 && rear==-1){
        cout<<"Queue is Full"<<endl;
        return -1;
    }
    else if(front==rear)
    {
        int temp = arr[front];
        front=rear=-1;
        return temp;
    }
    else if(front == n-1){
        temp = arr[front];
        front = 0;
        return temp;
    }
    else{
        temp  = arr[front];
        front++;
        return temp;//return[front++]
    }
}
int Queue::get_front()
{
    if(front==-1 && rear==-1){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else{
        return arr[front];
    }
}
int Queue::get_rear()
{
    if(front==-1 && rear==-1){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else{
        return arr[rear];
    }
}
void Queue::display()
{
    if(front==-1 && rear==-1){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        int i;
        for(i=front;i!=rear;i=(i+1)%n)
            cout<<arr[i]<<" ";
        cout<<arr[i]<<endl;
    }
}
int main()
{
    Queue Q(5);
     while(1){
        cout<<"\n1.enqueue\n";
        cout<<"2.dequque\n";
        cout<<"3.delete_last\n";
        cout<<"4.insert_front\n";
        cout<<"5.get_front\n";
        cout<<"6.get_back\n";
        cout<<"7.display\n";
        cout<<"8.exit\n";
        cout<<"\nEnter your choice : ";
        int ch;
        cin>>ch;
        int x;
        switch(ch)
        {
        case 1:
            cout<<"Enter a Data: ";     cin>>x;
            Q.enqueue(x);
            break;
        case 2:
            x = Q.dequeue();
            cout<<"data  = "<<x<<endl;
            break;
        case 3:
            x = Q.delete_last();
            //if(!empty())
            cout<<"data  = "<<x<<endl;
            break;
        case 4:
            cout<<"Enter a Data: ";     cin>>x;
            Q.insert_front(x);
            break;
        case 5:
            x = Q.get_front();
            cout<<"data = "<<x<<endl;
            break;
        case 6:
            x = Q.get_rear();
            cout<<"data = "<<x<<endl;
            break;
        case 7:
            Q.display();
            break;
        case 8:
            exit(1);
        default:
            cout<<"Invalid choice\n";
        }
    }
    return 0;
}
