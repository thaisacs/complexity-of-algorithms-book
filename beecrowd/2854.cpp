#include<bits/stdc++.h>

using namespace std;

void dfs_visit(vector<vector<int>>& graph, vector<int>& status, int id) {
  status[id] = 1; 
  for(int i = 0; i < graph[id].size(); i++) {
    int buff = graph[id][i];
    if(status[buff] == 0)
      dfs_visit(graph, status, buff);
  }
  status[id] = 2; 
}

int dfs(vector<vector<int>>& graph) {
  int c = 0;
  vector<int> status;
  for(int i = 0; i < graph.size(); i++) {
    status.push_back(0);
  }

  for(int i = 0; i < status.size(); i++) {
    if(status[i] == 0) {
      dfs_visit(graph, status, i);
      c++;
    }
  }
  return c;
}

int main() {
  int M, N, id = 0;
  string buffer, v1, v2;
  vector<vector<int>> graph;
  map<string, int> vertices;

  cin >> M >> N;

  for(int i = 0; i < M; i++) {
    vector<int> v;
    graph.push_back(v);
  }

  while(N > 0) {
    cin >> v1;
    if(vertices.find(v1) == vertices.end()) {
      vertices[v1] = id;
      id++;
    }
    cin >> buffer;
    cin >> v2;
    if(vertices.find(v2) == vertices.end()) {
      vertices[v2] = id;
      id++;
    }
    graph[vertices[v1]].push_back(vertices[v2]);
    graph[vertices[v2]].push_back(vertices[v1]);
    N--;
  }

  cout << dfs(graph) << endl;

  return 0;
}
