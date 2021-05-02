/*

    scan equation from right to left
    if oprend push into satck;

    in operator pop two element from stack
    frist poped ele is op1
    secound poped ele is op2

    op1 = pop();
    op2 = pop();

    ans  = op1 <OPERATOR> op2
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
    stack_()
    {}
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
bool isOperator(char op)
{
    if(op == '*'||op=='/'||op=='+'||op=='-'||op=='^')
        return true;
    else
        return false;
}
int Answer(int op1,int op2,char op)
{
    cout<<op1<<" "<<op<<" "<<op2<<endl;
    switch(op)
    {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
        case '^':
            return pow(op1,op2);
        default:
            cout<<op<<" is invalis operator"<<endl;
    }

}

int rev(int n)
{

    int temp,r;
    temp = n;
    int ans = 0;
    while(temp > 0)
    {
        r = temp%10;
        ans = ans*10+r;
        temp = temp/10;
    }
    return ans;
}
int main()
{
    stack_ s;
    char str[100];
    int n;
    cin>>str;
    n = strlen(str);
    int op1,op2,ans;
    for(int i=n-1;i>=0;i--)
    {
        if(isOperator(str[i]))
        {
            op1= s.pop();
            op2 = s.pop();
            ans = Answer(op1,op2,str[i]);
            s.push(ans);
        }
        else{
            if(str[i]==')')///Equation revese scan kariye atle pela ) aa breket ave
            {
                int num = 0,r;
                i--;
                while(str[i]!='(')
                {
                    num=num*10+str[i]-'0';
                    i--;
                }
                //i--;karan loop farithi chalashe tayare i-- thai jashe
                num = rev(num);
                s.push(num);
            }
            else{
                s.push(str[i]-'0');
            }
        }
    }
    if(s.top()!=-1){
        s.display();
        cout<<"Answer is: "<<s.pop()<<endl;}
    else
        cout<<"Invalid expretion"<<endl;
}
