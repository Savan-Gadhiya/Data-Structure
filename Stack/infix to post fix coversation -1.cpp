#include<iostream>
#include<stack>
using namespace std;
bool is_operator(char ch)
{
    return !((ch>='A' && ch<='Z')||(ch>='a' && ch<='z')|| (ch>='0' && ch<='9'));
}
int precident(char ch)
{
    if(ch=='(') return 4;
    else if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else {
        //cout<<ch<<" is unkown operator\n";
        return -1;
    }
 }
int main()
{
    int n;
    string str,ans="";
    cin>>str;
    n = str.length();
    stack <char> s;
    for(int i=0;i<n;i++){
        cout<<str[i]<<endl;
        if(is_operator(str[i])){
            if(s.empty() || s.top()=='(' || str[i]=='(' ||
                precident(s.top()) < precident(str[i])){
                s.push(str[i]);
            }
            else if(str[i] == ')')
            {
                while(!s.empty() && s.top()!='('){
                    ans+=s.top();
                    s.pop();
                }
                if(!s.empty() && s.top()=='(')  s.pop();
            }
            else if(!s.empty()  && precident(s.top()) >= precident(str[i])){
                while(s.top()!='(' && !s.empty() && (precident(s.top()) > precident(str[i])) ){
                    ans+=s.top();
                    cout<<"in else while for : "<<s.top()<<endl;
                    s.pop();
                }
                if(!s.empty() && (precident(s.top()) >= precident(str[i])) && precident(s.top())<=2){
                    while(s.top()!='(' && !s.empty() && (precident(s.top()) >= precident(str[i])) && precident(s.top())<=2){
                        ans+=s.top();
                        s.pop();
                    }
                }
                if(str[i]!=')')  s.push(str[i]);
            }
        }
        else{
            ans+=str[i];
        }
    }
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    cout<<ans<<endl;
}
