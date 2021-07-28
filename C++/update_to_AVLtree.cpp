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
int treeLevel(node *t)
{
    if(t==NULL){
        return -1;
    }
    return 1+max(treeLevel(t->left),treeLevel(t->right));
}
bool checkAvl(node *t){
	if (t == NULL) 	return true;
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	return checkAvl(t->left) && checkAvl(t->right);
}
node *turnright(node *t)
{
    node *b=t->left;
    node *c=b->right;
    t->left=c;
    b->right=t;
    return b;
}
node *turnleft(node *t)
{
    node *b=t->right;
    node *c=b->left;
    t->right=c;
    b->left=t;
    return b;
}
node *updateTreeAVL(node *t)
{
    if(abs(treeLevel(t->left)-treeLevel(t->right))>1){
        if(treeLevel(t->left)>treeLevel(t->right)){
            node *p=t->left;
            if(treeLevel(p->left)>=treeLevel(p->right)){
                t=turnright(t);
            }else{
                t->left=turnleft(t->left);
                t=turnright(t);
            }
        }
        else{
            node *p=t->right;
            if(treeLevel(p->right)>=treeLevel(p->left)){
                t=turnleft(t);
            }else{
                t->right=turnright(t->right);
                t=turnleft(t);
            }
        }
    }
    if(t->left!=NULL){
        t->left=updateTreeAVL(t->left);
    }
    if(t->right!=NULL){
        t->right=updateTreeAVL(t->right);
    }
    return t;
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
int count(node *t, int x){
	if (t == NULL) return 0;
	if (t->data == x) return 1 + count(t->left, x) + count(t->right, x);
	else if (t->data < x) return count(t->right, x);
	return count(t->left, x);
}
int main(){
	int n, x, temp;
	cin >> n;
	node * t = NULL;
	for (int i = 0; i < n; i++){
		cin >> temp;
		t = insert(t, temp);
	}
	while(checkAvl(t)!=0){
		t = updateTreeAVL(t);		
	}
	cin >> x;
	cout << count(t, x);
	return 0;
}
