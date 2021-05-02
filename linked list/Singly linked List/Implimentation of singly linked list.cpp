#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
node* head=NULL;
node* create_node(){
    node* newnode;
    newnode = new node;
    cout<<"Enter a data value"<<endl;
    cin>>newnode->data;
    newnode->next = NULL;
    return newnode;
}
void create_list()
{
    node* newnode = create_node();
    if(head==NULL){
        head = newnode;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }

}
void display(){
    node* temp= head;
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return ;
    }
    while(temp!=NULL) {  cout<<temp->data<<" "; temp = temp->next;}
    cout<<endl;
}
int main()
{
    while(1){
        cout<<"1.insert "<<endl;
        cout<<"2. display"<<endl;
        cout<<"3, exit"<<endl;
        cout<<"Enter tour choice :";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
                create_list();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(1);
            default:
                cout<<"In valid choice"<<endl;
        }
    }
    return 0;
}