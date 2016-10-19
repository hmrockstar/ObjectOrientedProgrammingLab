//Book shop's inventory management using member functions and constructors.
#include "iostream"
#include "string"
#include "string.h"
using namespace std;
class books{

    int len,price, stock,id;
    char *name, *auth, *pub;
public:
    static int un,suc;
    books()
    {
        len = 0;
        price = 0;
        stock = 0;
        name=new char(len+1);
        auth=new char(len+1);
        pub=new char(len+1);
    }
    add(char *z)
    {
        strcpy(name,z);
        cout<<"Enter author:";
        cin>>auth;
        cout<<"Enter publication:";
        cin>>pub;
        cout<<"Enter price:";
        cin>>price;
        cout<<"Enter number of books:";
        cin>>stock;
    }
    display()
    {
        cout<<"Title: "<<name<<endl;
        cout<<"Author: "<<auth<<endl;
        cout<<"Publication: "<<pub<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Number of books: "<<stock<<endl;
    }
    void update()
    {
        cout<<"Enter choice:\n";
        cout<<"Update Title"<<endl;
        cout<<"Update Author"<<endl;
        cout<<"Update Publication"<<endl;
        cout<<"Update Price"<<endl;
        cout<<"Update Number of books"<<endl;
        int in;
        cin>>in;
        switch(in)
        {
            case 1: cout<<"Enter new title:";
                    cin.getline(name,50);
                    cin.getline(name,50);
                    break;
            case 2:cout<<"Enter new author:";
                    cin>>auth;
                     break;
            case 3:cout<<"Enter new publication:";
                    cin>>pub;
                     break;
            case 4:cout<<"Enter new price:";
                    cin>>price;
                     break;
            case 5:cout<<"Enter number of books added to stock:";
                    int z;
                    cin>>z;
                    stock+=z;
                     break;
        }


    }
    int purchase()
    {
        if(stock==0)
        {
            cout<<"Book not available!!!";
            un++;
            return 0;
        }
        int num;
        cout<<"Enter number of books: ";
        cin>>num;
        char z;
        while(num>stock)
        {
            cout<<"Sorry Only "<<stock<<" Book(s) available!"<<endl;
            cout<<"1.Want to buy another book"<<endl<<"2.Want to continue"<<endl;
            int che;
            cin>>che;
            if(che==1)
            {
                un++;
                return 0;
            }
            cout<<"Enter number of books: ";
            cin>>num;
        }
        stock-=num;
        cout<<"Total cost: "<<price*num<<endl<<"Want to proceed?(Y/N)"<<endl;
        cin>>z;
        if(z=='N'||z=='N')
        {
            un++;
            return 0;
        }
        cout<<"Transaction Successfull!!!"<<endl;
        suc++;
        return 0;
    }
    friend int sea(char *, books);

};
int books:: suc;
int books:: un;
int sea(char *a,books b)
{
    if(!strcmp(b.name,a))
    {
        return 0;
    }
    return -1;
}

 int main()
 {
     books b[50];
     //char n[100],pub[100,*aut,id;
     int k=0,pr,st,id;
     char *z=new char(1);
//     b[i]=new books;
     int ch;
     while(1)
     {
         cout<<"Enter Choice:\n1.Input Data\n2.Upadate\n3.Search a book data\n4.Purchase a book\n5.Numer of successful and unseccessful records\n6.Display\n7.Exit\n";
        cin>>ch;
        int i;
        switch(ch)
        {
            case 1:
                cout<<"Enter book name: ";
                cin>>z;
                for(i=0;i<k;i++)
                {
                    if(sea(z,b[i])==0)
                    {
                        i=k+2;
                    }
                }
                if(i!=k+3)
                    b[k++].add(z);
                else
                    cout<<"Book with same book name already present!";
			//b[k++]=books(n,aut,pub,pr,st,id);
			//b[k-1].display();
                break;
            case 2: cout<<"\nUpdate data\n";
                cout<<"Enter book name: ";
                cin>>z;
                for(i=0;i<k;i++)
                {
                    if(sea(z,b[i])==0)
                    {
                        b[i].update();
                        b[i].display();
                        i=k+2;
                    }
                }
                if(i!=k+3)
                    cout<<"No book found!"<<endl;
                break;
        case 3: cout<<"Enter book name: ";
                cin>>z;
                for(i=0;i<k;i++)
                {
                    if(sea(z,b[i])==0)
                    {
                        b[i].display();
                        i=k+2;
                    }
                }
                if(i!=k+3)
                    cout<<"No book found!"<<endl;
                break;
        case 4: cout<<"Enter book name: ";
                cin>>z;
                for(i=0;i<k;i++)
                {
                    if(sea(z,b[i])==0)
                    {
                        b[i].purchase();
                        i=k+2;
                    }
                }
                if(i!=k+3)
                    cout<<"No book found!"<<endl;
                break;
        case 5: cout<<"Successful: "<<books::suc<<"\nUnsuccessful: "<<books::un<<endl;
                break;
        case 6:
                for(int i=0;i<k;i++)
                {
                    b[i].display();
                }
                break;
		case 7:
			return 0;
        }
        cout<<"\nEnter new choice"<<endl;
     }
     return 0;
 }
