#include<iostream>
using namespace std;
struct Note
{
    int data;
    Note *next;
};
Note *create(int x)
{
    Note *temp = new Note;
    temp->next = NULL;
    temp->data = x;
    return temp;
}
Note *addElement(Note *p,int x)
{
    Note *temp = create(x);
    p->next = temp;
    return temp;
}
Note printList(Note *l)
{
    Note *p=l;
    while(p != NULL)
    {
        cout << p->data<<" ";
        p = p->next;
    }
}
Note *addHead(Note *l,int x)
{
    Note *temp = new Note;
    temp->data=x;
    temp->next=l;
    l=temp;
    return l;
}
Note *addTail(Note *l,int x)
{
    Note *p=l;
    while(p->next != NULL)
    {
        p=p->next;
    }
    Note *temp = new Note;
    temp->data=x;
    temp->next=NULL;
    p->next=temp;
    return l;
}
Note *addAt(Note *l, int k, int x){
	Note *p = l;
	for (int i = 0; i < k-1; i++){
		p = p->next;
	}	
	Note *temp = new Note;
	temp->data = x;
	temp->next = p->next;
	p->next = temp;
	
	return l;
}
Note *deleteHead(Note *l)
{
    Note *p=l;
    p=p->next;
    delete(l);
    return p;
}
Note *deleteTail(Note *l)
{
    Note *p=l;
    while (p->next->next!=NULL)
    {
        p=p->next;
    }
    delete(p->next);
    p->next=NULL;
    return l;
    
}
Note *deleteAt(Note *l,int k)
{
    Note *p = l;
    
    for(int i=0;i<k-1;i++)
    {
        p = p->next;
    }
    Note *temp = p->next;
    p->next=p->next->next;
    delete(temp);
    return l;
}
Note *printAt(Note *l,int k )
{
    Note *p=l;
    for(int i=1;i<k;i++)
    {
        p=p->next;
    }
    cout << p->data;
    return l;
}
int main()
{
    int n;
    int x;
    cin >> n;
    cin >> x;
    Note *l=create(x);
    Note *p=l;
    for(int i=0;i<n-1;i++)
    {
        cin >> x;
        p = addElement(p,x);
    }
    int k;
    cin >> k;
    
    printAt(l,k);
}
