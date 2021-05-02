#include<iostream>
using namespace std;
template <class T>
class Queue_
{
    T *arr;
    int size;
    int rear=-1,front=-1;
    public:
    Queue_(int n)
    {
        size = n;
        arr = new T[n];
    }
    ~Queue_()
    {
        delete []arr;
    }
    void enqueue(T n);
    T dequeue();
    void display();
    T peek();//T front();
    bool isEmpty();
};
 template <class T>
bool Queue_<T>::isEmpty()
{
    return (rear == -1 && front == -1)?1:0;
}
template <class T>
void Queue_<T>::enqueue(T n)
{
    if(rear == size-1)
    {
        cout<<"Queue_ is full"<<endl;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        arr[rear] = n;
    }
    else
    {
        rear++;
        arrr[rear] = n;
    }
}
template <class T>
T Queue_<T>::dequeue()
{
    if(rear == -1 && front==-1)
    {
        cout<<"Queue_ is empty"<<endl;
    }
    else if(rear == front)
    {
        T temp;
        temp = arr[front];
        front = rear = -1;
        return temp;
    }
    else{
        T temp;
        temp = arr[front];
        front++;
        return temp;
    }
}
template <class T>
void Queue_<T>::display()
{
    for(T i=front;i<rear;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
template <class T>
T Queue_<T>::peek()
{
    T temp;
    if(front == -1 && rear == -1)
        cout<<"Queue_ is empty"<<endl;
    else{
        return arr[front];
    }
}
int main()
{
    int n;
    cout<<"Enter  A number of data"<<endl;
    cin>>n;
    Queue_ <int> Q(n);
    while(1)
    {
        cout<<"1> enqueue"<<endl;
        cout<<"2> dequeue"<<endl;
        cout<<"3> peek"<<endl;
        cout<<"4> display"<<endl;
        cout<<"5> exit"<<endl;
        int ch;
        cout<<endl<<" Enter tour choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int data;
                cout<<"Enter a value"<<endl;
                cin>>data;
                Q.enqueue(data);
            }
            break;
            case 2:
            {
                int data = Q.dequeue();
                if(!Q.isEmpty())
                    cout<<"Data is:"<<data;
                cout<<endl;
            }
            break;
            case 3:
            {
                int data = Q.peek();
                if(!Q.isEmpty())
                {
                    cout<<"Data peeked is: "<<data<<endl;
                }
            }
            break;
            case 4:
                Q.display();
                break;
            case 5:
                exit(1);
        }
    }
    return 0;
}
