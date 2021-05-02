#include<iostream>
using namespace std;
class stack_
{
    char *arr;
    int size;
    int top_ = -1;
    public:
    stack_()
    {}
    stack_(int n)
    {
        size = n;
        arr = new char[size];
    }
    bool isEmpty()
    {
        return (top_ == -1)?1:0;
    }
    bool isFull()
    {
        return (top_ == size-1)?1:0;
    }
    char pop()
    {
        if(isEmpty())
            return '-1';
        else
        {
            return arr[top_--];
        }
    }
    //int top(){return top_;}
    char peek()
    {
        if(isEmpty())
            return '-1';
        else{
            return arr[top_];
        }
    }
    void push(char N)
    {
        if(isFull())
            cout<<"Error"<<endl;
        else{
            top_++;
            arr[top_] = N;
        }
    }
    void display()
    {
        for(int i=0;i<=top_;i++)
            cout<<arr[i];
        cout<<endl;
    }
};
int main()
{
    stack_ s(5);
    int ch;
    while(1)
    {cout<<"Enter your chioce:"<<endl;
    cin>>ch;
        switch(ch)
        {

            case 1:
                cout<<"Enter n:"<<endl;
                int n;
                cin>>n;
                s.push(n);
                break;
            case 2:
                cout<<s.pop()<<endl;
                break;
            case 3:
                cout<<s.peek()<<endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                exit(3);
        }
    }
}
