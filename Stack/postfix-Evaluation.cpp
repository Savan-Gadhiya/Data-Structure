/*
    scan equation form LEFT to RIGHT
    if oprend push into stack
    if operator pop 2 value from stack

    first poped value is OPEREND 2
    secound poped value is OPEREND 1

    op2 = pop();//pela pop thay ae op2
    op1 = pop();//pachi pop thay ae op1

    ans = op1 <OPERATOR> op2;
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class stack_
{
    int *arr;
    int size;
    int top_ = -1;
    public:
    stack_(){}
    stack_(int n)
    {
        size = n;
        arr = new int[size];
    }
    bool isEmpty()
    {
        return (top_ == -1)?1:0;
    }
    bool isFull()
    {
        return (top_ == size-1)?1:0;
    }
    int pop()
    {
        if(isEmpty())
            return '-1';
        else
        {
            return arr[top_--];
        }
    }
    int top(){return top_;}
    int peek()
    {
        if(isEmpty())
            cout<<"Stack is empty"<<endl;
            //return '-1';
        else{
            return arr[top_];
        }
    }
    void push(int N)
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
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};
bool isOperator(char ch)
{
    if(ch == '+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        return true;
    else
        return false;
}
int Answer(int op1 ,int op2, char ope)
{
    cout<<op1<<" "<<ope<<" "<<op2<<endl;
    switch(ope)
    {
        case '+':
            return op1+op2;
            break;
        case '-':
            return op1-op2;
            break;
        case '*':
            return op1*op2;
            break;
        case '/':
            return op1/op2;
        case '^':
            return pow(op1,op2);
        default:
            cout<<ope<<" is Invalid operator"<<endl;
    }
}
int main()
{
    int n;
    char str[1000];
    cout<<"Enter a string: "<<endl;
    cin>>str;
    n = strlen(str);
    stack_ s(n);
    for(int i=0;i<n;i++)
    {
       if(isOpertator(str[i]))
       {
           if(s.isEmpty())
                cout<<"Invalid Equation"<<endl;
           else{
                int op1,op2,ans;
                op2 = s.pop();
                op1 = s.pop();
                ans = Answer(op1,op2,str[i]);
               s.push(ans);
           }
       }
       else{
            if(str[i]=='('){
                int ANS=0;
                i++;
                while(str[i]!=')' || s.isEmpty()==true)
                {

                    //cout<<"Element is: "<<str[i]<<endl;
                    ANS = ANS*10 + str[i]-'0';
                    //cout<<"ANS IS: "<<ANS<<endl;
                    i++;
                }
                s.push(ANS);
            }
            else
                s.push(str[i]-'0');
       }
       //cout<<endl<<"Stack is: "<<endl;
       //s.display();
       //cout<<endl;
    }
    if(s.top()==0)
    {
        cout<<"Answer is: "<<s.pop()<<endl;
    }
    else{
        s.display();
        cout<<"Invalid postfix equaition:"<<endl;
    }
}

