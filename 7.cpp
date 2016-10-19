//Exception Handling
#include<iostream>
using namespace std;
int k;
class tv
{
    int model;
    float size;
    long long  money;
    public:
    friend istream& operator >>(istream& input,tv &s);
    friend ostream& operator <<(ostream& output,tv &s);
    friend int se(int p);

};
istream& operator >>(istream& input,tv &s)
{
    while(1)
    {
        try
        {
            cout<<"Enter Model: ";
            input>>s.model;
            if(s.model<0||s.model>1000)
            {
                throw s.model;
            }
            break;
        }
        catch(int)
        {
            cout<<"Not Valid!!!\n";
        }
    }
    while(1)
    {
        try
        {
            cout<<"Enter price: ";
            input>>s.money;
            if(s.money<0||s.money>20000)
            {
                throw s.money;
            }
            break;
        }
        catch(long long )
        {
            cout<<"Not Valid!!!\n";
        }
    }
    while(1)
    {
        try
        {
            cout<<"Enter Size: ";
            input>>s.size;
            if(s.size>70||s.size<12)
            {
                throw s.size;
            }
            break;
        }
        catch(float)
        {
            cout<<"Not Valid!!!\n";
        }
    }
    //cout<<"Hol1";
    //return input;
}
ostream& operator <<(ostream& output,tv &s)
{
    output<<"Model: "<<s.model<<endl;
    output<<"Money: "<<s.money<<endl;
    output<<"Size: "<<s.size<<endl;
}
int main()
{
    tv t;
    cin>>t;
    cout<<"--------DISPLAY--------"<<endl;
    cout<<t;
}
