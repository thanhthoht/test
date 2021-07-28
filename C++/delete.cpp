#include<iostream>
#include<math.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *insert(node *t, int x){
	if (t == NULL){
		node *temp = new node;
		temp->data =x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} else{
		if (x < t->data){
			t->left = insert(t->left, x);
		} else{
			t->right = insert(t->right, x);
		}
        return t;
	}	
}
void deleteNode(node *t){
	if(t != NULL){
		if (t->left != NULL) deleteNode(t->left);
		if (t->right != NULL) deleteNode(t->right);
		delete(t);
	}
}

void print(node *t)
{
    if(t!=NULL)
    {
        print(t->left);
        cout<<t->data<<" ";
        print(t->right);
    }
}
node *deletenumber(node *t,int x){
    if(t!=NULL){
        if(t->data==x){
            deleteNode(t->left);
            deleteNode(t->right);
            t=NULL;
        }
        else if(t->data>x){
            t->left=deletenumber(t->left,x);
    }
        else{
            t->right=deletenumber(t->right,x);
    }
    }
    return t;
}
int main()
{
    int n,x,a;
    cin>>n;
    node *t=NULL;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        t=insert(t,x);
    }

    cin>> a;
    t=deletenumber(t,a);
    if (t == NULL) cout <<"NULL";
	else print(t);
    return 0;
}