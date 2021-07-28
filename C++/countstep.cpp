#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *insert(node *t,int a)
{
    if(t==NULL)
    {
    node *temp = new node;
    temp->data=a;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
    }
    else
    {
        if(a<t->data)
        {
            t->left=insert(t->left,a);
        }
        else{
            t->right=insert(t->right,a);
        }
        return t;
    }
}
bool isLeafNode(node *t)
{
    return(t->left==0&&t->right==0);
}
int CountStep(node *t)
{
    if(t==NULL)
    {
        return -1;
    }
    return 1+max(CountStep(t->left),CountStep(t->right));
}
int main()
{
    int n,x;
    cin >> n;
    node *t =NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        t=insert(t,x);
    }
    cout << CountStep(t);
    return 0;
}