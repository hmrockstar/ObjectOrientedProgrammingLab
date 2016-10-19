#include"iostream"
#include"fstream"
#include"string.h"
#include"iomanip"
using namespace std;
class emp
{
    int id,salary;
    string name;
public:
    emp()
    {
        id=-1;
        salary=0;
    }
    void getData(int i,string na,int sa)
    {
        id=i;
        name=na;
        salary=sa;
    }
    string retName()
    {
        return name;
    }
    int retSal()
    {
        return salary;
    }
    int retId()
    {
        return id;
    }
};
int main()
{
    int id,k=0,n=0,salary;
    string name;
    emp e[100];
    ifstream in;
    ofstream out;
    out.open("emp.txt");
    in.open("emp.txt");
    int ch,flag=0;;
    do
    {
        cout<<"\n1. Enter data\n2. Display data\n3. Delete\n4. Update\n5. Exit\nEnter your choice::";
        cin>>ch;
        switch(ch)
        {
            case 1 :cout<<"Enter ID : ";
                    cin>>id;
                    flag=0;
                    in.seekg(0,ios::beg);
                    for(int i=0;i<k;i++)
                    {
                        int x,z;
                        string y;
                        in>>x>>y>>z;
                        if(x==id)
                            flag=1;
                    }
                    if(flag==1)
                        cout<<"Person with Same id already exist!\n";
                    else
                    {
                        cout<<"Enter name: ";
                        cin>>name;
                        cout<<"Enter Salary: ";
                        cin>>salary;
                        out<<id<<" "<<name<<" "<<salary<<endl;
                        e[k++].getData(id,name,salary);
                        n++;
                    }
                    break;

            case 2 :if(k==0)
                    {
                        cout<<"No records present!"<<endl;
                        break;
                    }
                    in.seekg(0,ios::beg);
                    printf("Id    Name      Salary\n");
                    for(int i=0;i<k;i++)
                    {
                        in>>id>>name>>salary;
                        cout<<left<<setw(6)<< id<<setw(10)<<name<<setw(6)<<salary<<endl;
                    }
                    break;
            case 3 :if(k==0)
                    {
                        cout<<"No records present!"<<endl;
                        break;
                    }
                    cout<<"Enter id: ";
                    cin>>id;
                    flag=0;
                    for(int i=0;i<n;i++)
                    {
                        if(id==e[i].retId())
                        {
                            name=e[i].retName();
                            salary=e[i].retSal();
                            e[i].getData(-1,name,salary);
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        cout<<"No one with this id!";
                        break;
                    }
                    out.close();
                    out.open("emp.txt");
                    out.seekp(0,ios::beg);
                    for(int i=0;i<n;i++)
                        if(e[i].retId()!=-1)
                            out<<e[i].retId()<<" "<<e[i].retName()<<" "<<e[i].retSal()<<endl;
                    k--;
                    break;
            case 4 :if(k==0)
                    {
                        cout<<"No records present!"<<endl;
                        break;
                    }
                    cout<<"Enter id: ";
                    cin>>id;
                    flag=0;
                    for(int i=0;i<n;i++)
                    {
                        if(id==e[i].retId())
                        {
                            cout<<"Enter name : ";
                            cin>>name;
                            cout<<"Enter salary : ";
                            cin>>salary;
                            e[i].getData(e[i].retId(),name,salary);
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        cout<<"No one with this id!";
                        break;
                    }
                    out.close();
                    out.open("emp.txt");
                    out.seekp(0,ios::beg);
                    for(int i=0;i<n;i++)
                    {
                        if(e[i].retId()!=-1)
                        {
                            out<<e[i].retId()<<" "<<e[i].retName()<<" "<<e[i].retSal()<<endl;
                        }
                    }
                    break;
            case 5 :return 0;
                    break;
            default:cout<<"Invalid Input!!!\n";
        }
	}while(ch!=5);
}
