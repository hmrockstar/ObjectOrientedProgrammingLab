//Complex numbers operator overloading

#include<iostream>
using namespace std;
class complex
{
	int real, img;
	public:
	complex(int r,int i)
	{
		real=r,img=i;
	}
	complex()
	{
		real=0,img=0;
	}
	void display()
	{
		cout<<real<<" "<<img<<endl;
	}

	complex operator +(complex b)
	{
		complex c;
		c.real=real+b.real;
		c.img=img+b.img;
		return c;
	}
	complex operator -(complex b)
	{
		complex c;
		c.real=real-b.real;
		c.img=img-b.img;
		return c;
	}
	friend complex operator *(complex,complex);
	friend complex operator /(complex,complex);
};
complex operator *(complex a,complex b)
{
	complex c;
	c.real=a.real*b.real-a.img*b.img;
	c.img=a.real*b.img+a.img*b.real;
	return c;
}
complex operator /(complex o1,complex o2)
{
complex o3;
o3.real=(o1.real*o2.real+o1.img*o2.img)/(o2.real^2+o2.img^2);
o3.img=-(o2.img*o1.real-o1.img*o2.real)/(o2.real^2+o2.img^2);
return o3;
}

int main()
{
	cout<<"Enter first complex number:";
	int a,b;
	cin>>a>>b;
	complex o1(a,b);
	cout<<"Enter second complex number:";
	cin>>a>>b;
	complex o2(a,b);
	complex c;
	while(1)
	{
		cout<<"1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit: ";
		int n;
		cin>>n;
		switch(n)
		{
			case 1:
				c=o1+o2;
				c.display();
				break;
			case 2:
				c=o1-o2;
				c.display();
				break;
			case 3:
				c=o1*o2;
				c.display();
				break;
			case 4:
				c=o1/o2;
				c.display();
				break;
			case 5:return 0;
		}
	
	}	
}
