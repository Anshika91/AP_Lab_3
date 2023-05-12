#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll n,k,n1,n2,sum=0,i,cnt=0,num,fnd=0;
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> num;
        pq.push(num);
    }
    while(!pq.empty()){
        if(pq.size()==2){
            n1=pq.top();pq.pop();
            n2=pq.top();pq.pop();
            sum = n1+(n2*2);
            if(sum>=k) {fnd=1; break;}
            else break;
        }
        if(pq.size()==1 and pq.top()<k){
            fnd=0; break;
        }
        if(pq.top()>=k){ 
            fnd=1;break;
        }
        n1=pq.top();pq.pop();
        n2=pq.top();pq.pop();
        sum = n1+(n2*2);
        pq.push(sum);
        cnt++;
    }
    if(fnd)
        cout <<cnt<<endl;
    else
        cout <<-1<<endl;
    return 0;
}
