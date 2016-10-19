//File (10)
#include"iostream"
#include"fstream"
using namespace std;
int main()
{
    int sum=0,count=0,check=0;
    ofstream out;
    out.open("test.txt");
    out<<"hjds"<<endl;
    cout<<"Enter data: ";
    char *a;
    a=new char;
    while(cin.getline(a,1000000))
    {
        out<<a<<endl;
    }
    out.close();
    ifstream in;
    in.open("test.txt");
    in.seekg(0,ios::end);
    unsigned size=in.tellg();
    while(size--)
    {   in.seekg(size,ios::beg);
        char c;
        in.get(c);
        cout<<c;
    }
    
    in.close();
}
