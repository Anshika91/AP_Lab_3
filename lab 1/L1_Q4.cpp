#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a==b) return a;
    
    if(a>b) return gcd(a%b, b);
    else return gcd(b%a, a);
    return gcd
}
int main()
{
    cout<<gcd(4,6);
    return 0;
}
