#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<string> &brd,int n,int rw,int col){
        for(int i=col;i>=0;i--){
            if(brd[rw][i]=='Q') return false;
        }
        int i = rw,j = col;
        while(i>=0 && j>=0){
            if(brd[i][j]=='Q') return false;
            i--;
            j--;
        }
        i = rw,j = col;
        while(i<n && j>=0){
            if(brd[i][j]=='Q') return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(vector<string> &brd,vector<vector<string>> &ans,int col,int n){
        if(col>=n){
            ans.push_back(brd);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(brd,n,i,col)){
                brd[i][col] = 'Q';
                solve(brd,ans,col+1,n);
                brd[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> brd;
        string s;
        for(int i=0;i<n;i++){
            s+='.';
        }
        for(int i=0;i<n;i++)
            brd.push_back(s);
        solve(brd,ans,0,n);
        return ans;
    }
};

int main(){
    Solution *ob = new Solution();
    vector<vector<string>> ans = ob->solveNQueens(8);
    return 0;
}