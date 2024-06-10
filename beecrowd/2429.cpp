#include<bits/stdc++.h>

using namespace std;

void dfs_visit(vector<vector<int>>& graph, vector<int>& status, int id) {
  status[id] = 1; 
  for(int i = 0; i < graph[id].size(); i++) {
    int buff = graph[id][i];
    if(status[buff] == 0)
      dfs_visit(graph, status, buff);
  }
}

bool solver(vector<vector<int>>& graph, int id) {
  vector<int> status;
  for(int i = 0; i < graph.size(); i++) {
    status.push_back(0);
  }
  dfs_visit(graph, status, id);
  for(int i = 0; i < graph.size(); i++) {
    if(status[i] == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int N, A, B;
  vector<vector<int>> graph;

  cin >> N;

  for(int i = 0; i < N; i++) {
    vector<int> v;
    graph.push_back(v);
  }

  while(N > 0) {
    cin >> A;
    cin >> B;
    A--;
    B--;
    graph[A].push_back(B);
    N--;
  }

  for(int i = 0; i < graph.size(); i++) {
    if(!solver(graph, i)) {
      cout << 'N' << endl;
      return 0;
    }
  }
  cout << 'S' << endl;
  return 0;
}
