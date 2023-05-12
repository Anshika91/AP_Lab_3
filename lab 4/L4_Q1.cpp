#include <bits/stdc++.h>
using namespace std;

void rec(vector<vector<int>> &grid, vector<vector<int>> &vis, vector<string> &ans, string str, int x, int y){
    int n = grid.size(), m = grid[0].size();
    
    if(x==n-1 && y==m-1){
        ans.push_back(str);
        return;
    }
    
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    
    for(int i=0;i<4;i++){
        int new_x = x+dx[i];
        int new_y = y+dy[i];
        
        if(new_x>=0 && new_y>=0 && new_x<n && new_y<m && grid[new_x][new_y]==1 && vis[new_x][new_y]==0){
            vis[new_x][new_y] = 1;
            if(i==0){
                str.push_back('U');
            }
            else if(i==1){
                str.push_back('D');
            }
            else if(i==2){
                str.push_back('L');
            }
            else{
                str.push_back('R');
            }
            rec(grid, vis, ans, str, new_x, new_y);
            vis[new_x][new_y] = 0;
            str.pop_back();
        }
    }
}
int main()
{
    vector<string>ans;
    int n;
    cin>>n;
    vector<vector<int>> vis(n,vector<int>(n,0)), grid(n, vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    rec(grid, vis, ans, "", 0, 0);

    if(ans.size()==0) cout<<-1<<endl;
    else for(auto it: ans) cout<<it<<" ";
    return 0;
}
