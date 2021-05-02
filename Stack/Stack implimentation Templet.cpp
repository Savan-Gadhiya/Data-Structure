#include<iostream>
using namespace std;
template<class T>
class stack
{
    T *arr;
    int size;
    int top;
    public:
    stack(){top=-1;}
    stack(int n){
        top = -1;
        size = n;
        arr = new T[size];
    }
    void push(T n){
        if(top==size-1){cout<<"Stack is full"<<endl;return;}
        top++;
        arr[top] = n;
    }
    int top_(){  return top;  }
    T pop(){
        cout<<"top = "<<top<<endl;
        if(top==-1){cout<<"in if"<<endl;
            cout<<"Underflow\n";return -1;}
        T temp = arr[top];
        top--;
        return temp;//return arr[top--];

    }
    T peek(){
        if(top==-1){cout<<"Underflow\n";return -1;}
        return arr[top];
    }
    void display(){
        if(top==-1){cout<<"Stack is empty\n";return;}
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
//jo funcation class ni bahar lakhava hoy to dareak funcation in uper template <class T>lakhavu
/**template <class T>
T stack<T>::pop(){
        if(top==-1){cout<<"Underflow\n";return -1;}
        T temp = arr[top];
        top--;
        return temp;//return arr[top--];

    }*/
int main()
{
    int ch;
    //cout<<"1"<<endl;
    stack <int> s(5);
    //cout<<"2"<<endl;
    while(1)
    {
        int x;
        cout<<"1. push"<<endl;
        cout<<"2. pop"<<endl;
        cout<<"3. peek"<<endl;
        cout<<"4. display"<<endl;
        cout<<"5. exit"<<endl;
        cout<<endl<<"Enter your choise: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter a element :";
                cin>>x;
                s.push(x);
                break;
            case 2:
                if(s.top_()!=-1){
                    cout<<"poped data is : "<<s.pop()<<endl;
                }
                break;
            case 3:
                if(s.top_()!=-1){
                    cout<<"peeked data is : "<<s.peek()<<endl;
                }
                break;
            case 4:
                s.display();
                break;
            case 6:
                cout<<"top =  "<<s.top_()<<endl;
            case 5:
                exit(1);
            default:
                cout<<"Invalid choice: ";
        }

    }return 0;
}
