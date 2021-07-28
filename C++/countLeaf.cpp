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
    bool isleafnode(node *t)
    {
        return(t->left==NULL && t->right==NULL);
    }
    int countLeaf(node *t)
    {
        if(t==NULL)
        {
            return 0;
        }
        if(isleafnode(t))
        {
            return 1;
        }
        return countLeaf(t->left)+countLeaf(t->right);
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
    cout << countLeaf(t);
    return 0;
}