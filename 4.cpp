//Personnel information system using inheritance
#include<iostream>
#include<string.h>
using namespace std;
class basic
{
protected:
    char name[20],dob[10],bg[5];
public:
    basic()
    {
        name[0]=NULL;
        dob[0]=NULL;
        bg[0]=NULL;
    }
    basic(char n[],char d[],char b[])
    {
        strcpy(name,n);
        strcpy(dob,d);
        strcpy(bg,b);
    }
};

class bio:public basic
{
protected:
    float height,weight;
public:
    bio()
    {
        height=0;
        weight=0;
    }
    bio(char n[],char d[],char b[],float h,float w):basic(n,d,b)
    {
        height=h;
        weight=w;
    }
};

class add:public bio
{
protected:
    char ipn[20],address[30];
public:
    add()
    {
        ipn[0]=NULL;
        address[0]=NULL;
    }
    add(char n[],char d[],char b[],float h,float w,char in[],char addr[]):bio(n,d,b,h,w)
    {
        strcpy(ipn,in);
        strcpy(address,addr);
    }
};

class tel:public add
{
protected:
    long long teleno;
    char drlino[20];
public:
    tel()
    {
        teleno=0;
        drlino[0]='\0';
    }
    tel(char n[],char d[],char b[],float h,float w,char in[],char addr[],long long tel,char dr[]):add(n,b,d,h,w,in,addr)
    {
        teleno=tel;
        strcpy(drlino,dr);
    }
    void display();
    int search(char []);
    void edit();
    void deleting();
};

void tel::display()
{
    if(strlen(name)!=0)
        cout<<name<<"\t"<<dob<<"\t"<<bg<<"\t"<<height<<"\t"<<weight<<"\t"<<ipn<<"\t"<<address<<"\t"<<teleno<<"\t\t"<<drlino<<endl;
}

int tel::search(char in[])
{
    if(strcmp(ipn,in)==0)
        return 1;
    else
        return 0;
}

void tel::edit()
{
    int n;
    cout<<"\nWhat do you want do update\n1.Name\n2.DOB\n3.BG\n4.Height\n5.Weight\n6.Address\n7.Telephone\n8.LicenseNo.\nEnter your choice::";
    cin>>n;
    if(n==1)
    {
        cout<<"Enter the name::";
        cin>>name;
    }
    if(n==2)
    {
        cout<<"Enter the date of birth::";
        cin>>dob;
    }
    if(n==3)
    {
        cout<<"Enter the blood group::";
        cin>>bg;
    }
    if(n==4)
    {
        cout<<"Enter the height::";
        cin>>height;
    }
    if(n==5)
    {
        cout<<"Enter the new weight::";
        cin>>weight;
    }
    if(n==6)
    {
        cout<<"Enter the contact address::";
        cin>>address;
    }
    if(n==7)
    {
        cout<<"Enter the telephone number::";
        cin>>teleno;
    }
    if(n==8)
    {
        cout<<"Enter the driving license number::";
        cin>>drlino;
    }
}

void tel::deleting()
{
    name[0]=NULL;
    ipn[0]=NULL;
}

int main()
{
    tel *ob;
    ob = new tel[100];
    int c,i=0,j,temp;
    char n[20],d[10],b[5],in[20],addr[30],dr[20];
    float h,w;
    long long mob;
    do
    {
        cout<<"\n1.Insert\n2.Display\n3.Searching\n4.Edit\n5.Deleting\n6.Exit\nEnter your choice::";
        cin>>c;
        switch(c)
        {
            case 1:
                   {
                       temp=0;
                       cout<<"Enter the Insurance policy no::";
                       cin>>in;
                       for(j=0;j<i;j++)
                       {
                         if(ob[j].search(in)==1)
                           {
                             cout<<"The person with IPNo. "<<in<<" is already present\n";
                             break;
                           }
                       }
                       if(temp==0)
                       {
                            cout<<"Enter the name::";
                            cin>>n;
                            cout<<"Enter the date of birth::";
                            cin>>d;
                            cout<<"Enter the blood group::";
                            cin>>b;
                            cout<<"Enter the height::";
                            cin>>h;
                            cout<<"Enter the weight::";
                            cin>>w;
                            cout<<"Enter the contact address::";
                            cin>>addr;
                            cout<<"Enter the telephone number::";
                            cin>>mob;
                            cout<<"Enter the driving license number::";
                            cin>>dr;
                            tel ob1(n,d,b,h,w,in,addr,mob,dr);
                            ob[i++]=ob1;
                            break;
                       }
                   }
                   break;
            case 2:cout<<"\n\n\t\t\t\tDISPLAY\n\nName\tDOB\tBG\tHeight\tWeight\tIPN\tAddress\tTelephone\tDrLNo.\n";
                   for(j=0;j<i;j++)
                       ob[j].display();
                   break;
            case 3:cout<<"\nEnter the insurance policy number you want to searching for:: ";
                   cin>>in;
                   for(j=0;j<i;j++)
                   {
                       temp=ob[j].search(in);
                       if(temp==1)
                       {
                           cout<<"The person with IPNo. "<<in<<" is present\n";
                           cout<<"\n\n\t\t\t\tDISPLAY\n\nName\tDOB\tBG\tHeight\tWeight\tIPN\tAddress\tTelephone\tDrLNo.\n";
                           ob[j].display();
                           break;
                       }
                   }
                   if(temp==0)
                       cout<<"Not Present!!!\n";
                   break;
            case 4:cout<<"\nEnter the insurance policy number you want to edit:: ";
                   cin>>in;
                   for(j=0;j<i;j++)
                   {
                       temp=ob[j].search(in);
                       if(temp==1)
                       {
                           ob[j].edit();
                           break;
                       }
                   }
                   if(temp==0)
                       cout<<"Not Present!!!\n";
                   break;
            case 5:cout<<"\nEnter the insurance policy number you want to deleting:: ";
                   cin>>in;
                   for(j=0;j<i;j++)
                   {
                       temp=ob[j].search(in);
                       if(temp==1)
                       {
                           ob[j].deleting();
                           break;
                       }
                   }
                   if(temp==0)
                       cout<<"Not Present!!!\n";
                   break;
            case 6:return 0;
            default:cout<<"Invalid Input!!!";
        }
        cout<<"Want to continue(1/0)::";
        cin>>c;
    }while(c==1);
    return 0;
}
