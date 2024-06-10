#include<bits/stdc++.h>

using namespace std;

void dfs_visit(vector<vector<int>>& graph, vector<int>& status, int id, vector<int>& output) {
  status[id] = 1; 
  for(int i = 0; i < graph[id].size(); i++) {
    int buff = graph[id][i];
    if(status[buff] == 0)
      dfs_visit(graph, status, buff, output);
  }
  output.push_back(id);
}

int dfs(vector<int> order, vector<vector<int>>& graph, vector<int>& output) {
  int c = 0;
  vector<int> status;
  for(int i = 0; i < graph.size(); i++) {
    status.push_back(0);
  }

  for(int i = 0; i < status.size(); i++) {
    if(status[order[i]] == 0) {
      dfs_visit(graph, status, order[i], output);
      c++;
    }
  }
  return c;
}

bool solver(vector<vector<int>>& graph) {
  vector<int> output;
  vector<int> output_final;
  vector<int> input;
  for(int i = 0; i < graph.size(); i++) {
    input.push_back(i);
  }
  dfs(input, graph, output);
  int c = dfs(output, graph, output_final);
  if(c > 1)
    return false;
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

  if(solver(graph)) {
    cout << 'S' << endl;
  }else{
    cout << 'N' << endl;
  }

  return 0;
}
