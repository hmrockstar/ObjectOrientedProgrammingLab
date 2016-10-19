//Monthly Weather Report using Constructor, Destructor.

#include<iostream>
using namespace std;
class wheather{
int day,hTemp,lTemp,amntRain,amntSnow;
public:
wheather()
{
	day=0,hTemp=0,lTemp=0,amntRain=0,amntSnow=0;
}
int input(int b)
{
	if(day==b)
	{
		cout<<"Data already available!"<<endl;
		return 0;
	}
	day=b;
	cout<<"Enter High temp., low temp., amount of rain, amount of snow respectively:";
	cin>>hTemp>>lTemp>>amntRain>>amntSnow;/
	return 0;
}
int display(int c,int d)
{
	if(day==0&&d==1)
	{
		cout<<"NO DATA Found for date "<<c<<" !!!!"<<endl;
		return 0;
	}
	if(d==1)
	{
		cout<<"Day highTemp lowTemp amountRain amountSnow\n";
	}
	if(day!=0)
	{
        cout<<c;
        cout<<"\t"<<hTemp<<"\t"<<lTemp<<"\t"<<amntRain<<"\t"<<amntSnow<<"\n";
	}
}
void modify(int z,int p)
{
	if(p==1)
	{
		cout<<"Enter new Hight temp:";
		cin>>hTemp;
	}
	if(p==2)
	{
		cout<<"Enter new Low temp:";
		cin>>lTemp;
	}
	if(p==3)
	{
		cout<<"Enter new Amount Rain:";
		cin>>amntRain;
	}
	if(p==4)
	{
		cout<<"Enter new Amount snow:";
		cin>>amntSnow;
	}
}
void del()
{
	day=0;
}
friend void average(wheather,int);
};
void average(wheather i ,int j)
{
    static double h=0,l=0,ar=0,as=0,num=0;
	h+=i.hTemp,l+=i.lTemp,ar+=i.amntRain,as+=i.amntSnow;
	if(i.day!=0)
        num++;
    if(j==31)
    cout<<"Average High Temp: "<<h/num<<endl<<"Average low Temp: "<<l/num<<endl<<"Average Rain fall: "<<ar/num<<endl<<"Average snow fall: "<<as/num<<endl;
}
int main()
{
	int n,ch;
	wheather a[32];


	while(1)
	{
	cout<<"Enter Choice:\n1.Input Data\n2.Display all Data\n3.Display specific day's data\n4.Modify data\n5.Monthly Report\n6.Delete\n7.Exit\n";
		cin>>ch;
	switch(ch)
	{
		case 1:cout<<"Enter date:";
			cin>>n;
			while(n>31)
			{
				cout<<"Not a valid date!!!"<<endl<<"Enter new date:";
				cin>>n;
			}
			a[n].input(n);
			break;
		case 2:cout<<"Day highTemp lowTemp amountRain amountSnow\n";
			for(int i=1;i<32;i++)
			a[i].display(i,0);
			break;
		case 3:cout<<"Enter date:";
			int z;
			cin>>z;
			a[z].display(z,1);
			break;
		case 4:cout<<"Enter the date:";
			cin>>z;
			cout<<"Enter the data to be modify:\n1.HighTemp\n2.LowTemp\n3.AmountRain\n4.AmountSnow\n:";
			int p;
			cin>>p;
			a[z].modify(z,p);
			break;
		case 5: for(int i=1;i<32;i++)
				{
					average(a[i],i);
				}
			break;
		case 6:cout<<"Enter date:";
			cin>>z;
			a[z].del();
			break;
		case 7:
			return 0;
	}
		cout<<"Enter new choice"<<endl;

	}
}
