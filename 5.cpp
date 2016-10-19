//Virtual functions 

#include"bits/stdc++.h"
#define pi 3.141592653589793238462643383279502
using namespace std;
class shape
{
    protected:
        double x,y;
    public:
            virtual double area()=0;
            void getdata(int t)
            {
                if(t==1)
                {
                    cin>>x;
                }
                else
                    cin>>x>>y;
            }

};
class tri: public shape
{
public:
    double area()
    {
        return 0.5*x*y;
    }
};
class square: public shape
{
public:
    double area()
    {
        return x*x;
    }
};
class circle: public shape
{
public:
    double area()
    {
        return pi*x*x;
    }
};

int main()
{
   while(1)
   {
       cout<<"FIND THE AREA\n1.Trialngle\n2.Square\n3.Circle\n4.Exit\nEnter choice: ";
   int n;
   cin>>n;
   shape *sh;
   switch(n)
   {
    case 1:    {
                tri t;
               sh=&t;
               sh->getdata(0);
               cout<<sh->area();
               break;
               }
    case 2:    {
                square s;
               sh=&s;
               sh->getdata(1);
               cout<<sh->area();
               break;
               }
    case 3:{
                circle c;
               sh=&c;
               sh->getdata(1);
               cout<<sh->area();
               break;
            }
    case 4: {
        return 0;
        }
   }
   cout<<endl<<endl;
   }
}
