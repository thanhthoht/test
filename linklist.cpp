#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *createNode(int x){
    node *temp=new node;
    temp->data=x;
    temp->next=NULL;
    return temp;
}
node *addElement(node *t,int x){
    node *temp=createNode(x);
    t->next=temp;
    return temp;
}

int main(){
    int n;
    cin>>n;

}
