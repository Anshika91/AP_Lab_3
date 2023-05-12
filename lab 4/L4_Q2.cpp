#include <bits/stdc++.h>
using namespace std;

void rec(vector<int> &vis, vector<string> &ans, string str, string s){
    if(str.size()==s.size()){
        ans.push_back(str);
        return;
    }
    
    for(int i=0;i<s.size();i++){
        if(vis[i]==0){
            vis[i]=1;
            str.push_back(s[i]);
            rec(vis,ans,str,s);
            str.pop_back();
            vis[i]=0;
        }
    }
}
int main()
{
    vector<string>ans;
    string s = "abc";
    vector<int> vis(s.length(),0);
    rec(vis, ans, "", s);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}
