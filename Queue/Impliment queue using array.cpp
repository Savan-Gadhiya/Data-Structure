#include<iostream>
using namespace std;
template <class T>
class Queue
{
    T *arr;
    int size;
    int front = -1,rear = -1;
public:
    Queue(int n){
        size = n;
        arr = new T[n];
        // cout<<"Enter a element of array: ";
        // for(int i=0;i<size;i++)        cin>>arr[i];
    }
    ~Queue(){
        cout<<"Distructor"<<endl;
        delete []arr;
    }
    void enqueue(T );
    T dequeue();
    T peek();
    void display();
    bool isEmpty();
};
template <class T>
void Queue<T>::enqueue(T x){
    if(front==-1 && rear==-1){//isEmpty()
        front = rear = 0;
    }
    else{
        if(rear==size){
            cout<<"Queue is Full"<<endl;
            return;
        }
        else        rear++;
    }
    arr[rear] = x;
}
template <class T>
T Queue<T>::dequeue(){
    if(front==-1 && rear==-1){//isEmpty()
        cout<<"Queue is Empty"<<endl;
        //return -1;
    }
    else if(front == rear){
        T temp = arr[front];
        front = -1;rear =-1;
        return temp;
    }
    else{
        T temp = arr[front];
        front++;
        return temp;//return arr[front++];
    }
}
template <class T>
T Queue<T>::peek()
{
    if(front==-1 && rear==-1){//isEmpty()
        cout<<"Queue is Empty"<<endl;
        //return -1;
    }
    else{
        return arr[front];
    }
}
template <class T>
void Queue<T>::display()
{
    if(isEmpty()){
        cout<<"Queue is empty\n";return;
    }
    for(int i=front;i<=rear;i++)     cout<<arr[i]<<" ";
    cout<<endl;
}
template <class T>
bool Queue<T>::isEmpty(){
    return (front==-1&& rear==-1)?1:0;
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
            if(!Q.isEmpty())    cout<<"data  = "<<x<<endl;
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
