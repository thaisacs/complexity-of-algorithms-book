#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>& grid, int i, int j) {
  if(i >= grid.size())
    return;
  if(j >= grid[0].size())
    return;
  if(i < 0 || j < 0)
    return;
  if(grid[i][j] == '1') {
    grid[i][j] = '0';
    bfs(grid, i+1, j);
    bfs(grid, i, j+1);
    bfs(grid, i-1, j);
    bfs(grid, i, j-1);
  }
}

int numIslands(vector<vector<char>>& grid) {
  int num = 0;

  for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < grid[0].size(); j++) {
      if(grid[i][j] == '1') {
        num++;
        bfs(grid, i, j);
      }
    }
  }

  return num;        
}

int main() {
  //vector<vector<char>> grid = {
  //  {'1','1','1','1','0'},
  //  {'1','1','0','1','0'},
  //  {'1','1','0','0','0'},
  //  {'0','0','0','1','1'}
  //};
  vector<vector<char>> grid = {
    {'1', '1', '1'},
    {'0', '1', '0'},
    {'1', '1', '1'}
  };
  cout << numIslands(grid) << endl;

  return 0;
}
