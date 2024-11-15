#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the base(a) and power(b)";
    int a,b;
    cin>>a>>b;
    int ans=1;
    while(b){
        if(b&1){
            ans*=a;
        }
        a=a*a;
        b>>=1;
    }
    cout<<"The answer is"<<ans<<endl;
}

/*
For eg we have to evaluate:3^13(13->1101)   =>3^8*3^4*3^0(we do not want it ok)*3^1
a        b        ans
3       1101      ans=1*3                   If set bit multiply ans by current power of base

b=>110
a=>3^2
Not set

3^2      110       ans=3

b=11
a=3^4
Set

3^4       11       ans=3*3^4

b=1
a=3^8
Set

3^8        1       ans=3^5*3^8


3^16
b=0  stops






*/
