#include <iostream>
using namespace std;

void toh(int n, char s, char d, char i){
    if(n==1){
        cout<<n<<" "<<"from "<<s<<" "<<"to "<<d<<endl;
        return;
    }
    toh(n-1, s, i, d);
    cout<<n<<" "<<"from "<<s<<" "<<"to "<<d<<endl;
    toh(n-1, i, d, s);
}
int main()
{
    toh(3,'A', 'C', 'B');
    return 0;
}
