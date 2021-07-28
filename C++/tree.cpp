struct node
{
    int data;
    node *left;
    node *right;
};
node *insert(node *t,int x)
{
    if(t==NULL)
    {
        node *temp = new node;
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else{
        if(x<t->data){
            t->left=insert(t->left,x);
        }
        else{
            t->right=insert(t->right,x);
        }
        return t;
    }
}
int treeLevel(node *t)
{
    if(t==NULL)
    {return -1;}
    return 1+max(treeLevel(t->right),treeLevel(t->left));
}
void printPreorder(node *t)
{
    if(t!=NULL){
        printPreorder(t->left);
        cout<<t->data<<" ";
        printPreorder(t->right);
    }
}
void printPostorder(node *t)
{
    if(t!=NULL){
        printPreorder(t->left);
        printPreorder(t->right);
        cout<<t->data<<" ";
    }
}
