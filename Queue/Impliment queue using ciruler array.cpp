#include<iostream>
using namespace std;
template <class T>
class Queue
{
    T *arr;
    int n;
    int front=-1,rear=-1;
    public:
    Queue(int n1)
    {
        n = n1;
        arr = new T[n];
    }
    ~Queue(){
        delete []arr;
    }
    void enqueue(T x);
    T dequeue();
    T peek();
    void display();
    bool empty();
    bool isFull();
};
template <class T>
void Queue<T>::enqueue(T x)
{
        if(front==-1 && rear==-1){
            front=rear=0;
            arr[rear]=x;
        }
        else if(front==(rear+1)%n)//if((front==0 && rear==n-1 ) || front == rear+1)  OR isFull()
        {
            cout<<"Queue is full\n";
        }
        else{
            rear= (rear+1)%n;
            arr[rear]=x;
        }
}
template <class T>
T Queue<T>::dequeue()
{
    if(front==-1 && rear==-1){//empty()
        cout<<"Queue is Empty\n";
    }
    else if(front==rear)
    {
        T temp=arr[front];
        front=rear=-1;
        return temp;
    }
    else
    {
        T temp = arr[front];
        front = (front+1)%n;
        return temp;
    }
}
template <class T>
T Queue<T>::peek()
{
    if(front!=-1 && rear!=-1)
        return arr[front];
    else    cout<<"Queue is Empty\n";//empty()
}
template <class T>
void Queue<T>::display()
{
    int i;
    if(front==-1 && rear==-1){//empty()
        cout<<"Queue is Empty\n";
    }
    for(i=front;i!=rear;i=(i+1)%n){
        cout<<arr[i]<<" ";
    }
    cout<<arr[i]<<endl;//Last mate front == rear thashe atle ae aalag thi print karavo padashe
}
template <class T>
bool Queue<T>::empty()
{
    return (front==-1 && rear==-1);
}
template <class T>
bool Queue<T>::isFull()
{
    return (front==(rear+1)%n);
}
int main()
{
    Queue <int> Q(5);
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
            Q.enqueue(x);
            break;
        case 2:
            x = Q.dequeue();
            cout<<"data  = "<<x<<endl;
            break;
        case 3:
            x = Q.peek();
            //if(!Q.empty())
            cout<<"data  = "<<x<<endl;
            break;
        case 4:
            Q.display();
            break;
        case 5:
            exit(1);
        default:
            cout<<"Invalid choice\n";
        }
    }
    return 0;
}
