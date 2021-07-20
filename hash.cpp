#include<iostream>
#include<vector>
using namespace std;

class Student // Khai bao lop Student
{   
    public:
    int ID; 
    string Name;
    string Class;
    Student();
    Student (int id, string name,string cl)
    {
        ID=id;
        Name=name;
        Class=cl;
    }
};
class Hash
{
    int n;
    vector<Student> *table;
    public:
    Hash (int V)
    {
        this->n=V;
        table = new vector<Student>[n];
    }

int hashFunction(int x)
{
    return x % n;
}
void Insert(int ID,string Name,string Class)
{
    Student st(ID,Name,Class);
    int index = hashFunction(ID);
    table[index].push_back(st);
}
void Delete(int key)
{
    int index = hashFunction(key);
    vector<Student> :: iterator i;
    for(i=table[index].begin();i!=table[index].end();i++)
    {
        Student& st = *i;
        if(st.ID==key)
        {
            table[index].erase(i);
            break;
        }
        if(i==table[index].end())
        {
            break;
        }
    }
}
void Infor(int x)
{
    int index=hashFunction(x);
    vector<Student> :: iterator i;
    for(i=table[index].begin();i != table[index].end();i++)
    {
        Student& st = *i;
        if(st.ID == x)
        {
            cout << st.Name <<","<<st.Class<<endl;
            break;
        }
    }
    if(i==table[index].end())
    {
        cout << "NA,NA"<<endl;
    }
}
};

int main()
{
    Hash h(7);
    h.Insert(1,"Tuan","K11");
    h.Insert(2,"Vinh","K22");
    h.Infor(3);
    h.Infor(2);
    h.Delete(2);
    h.Infor(2);
    return 0;
}


