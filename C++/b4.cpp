#include<iostream>
using namespace std;
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void vonglap(int n,int a[],int i)
{
    if(i==n){
        print(a,n);
        return;
    }
    a[i]=0;
    vonglap(n,a,i+1);
    a[i]=1;
    vonglap(n,a,i+1);

}
int main()
{
    int n;
    cin >> n;
    int a[100];
    vonglap(n,a,0);
    return 0;
}