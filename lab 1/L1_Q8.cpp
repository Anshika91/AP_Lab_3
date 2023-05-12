#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int egg(int n, int k){
    if (k == 1 || k == 0)return k;
    if (n == 1) return k;
    int min = INT_MAX, x, res;
    for (x = 1; x <= k; x++)
    {
        res = max(egg(n - 1, x - 1), egg(n, k - x));
        if (res < min)
            min = res;
    }
    return min + 1;
}
int main(){
    int n = 2, k = 5;
    cout << "Minimum number of trials" << n << " eggs and " << k << " floors is "<< egg(n, k) << endl;
    return 0;
}
