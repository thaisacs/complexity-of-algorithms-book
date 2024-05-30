#include <bits/stdc++.h>
#include <stack>
using namespace std;

int time_ = 0;

struct node {
  int s, f;
};

void dfs_visit(int u, node* V, vector<int>* adj, vector<int>& output) {
  time_++;
  V[u].s = time_;
  for(int i = 0; i < adj[u].size(); i++) {
    if(V[adj[u][i]].s == -1){
      dfs_visit(adj[u][i], V, adj, output);
    }
  }
  output.push_back(u);
  time_++;
  V[u].f = time_;
}

void dfs(vector<int> input, node* V, vector<int>* adj, vector<int>& output) {
  for(int i = input.size() - 1; i >= 0; i--) {
    if(V[input[i]].s == -1) {
      dfs_visit(input[i], V, adj, output);
    }
  }
}

void findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> adj[numCourses];
  vector<int> adjR[numCourses];
  vector<int> input;
  node V[numCourses];
  for(int i = numCourses - 1; i >= 0; i--) {
    V[i].s = -1;
    V[i].f = -1;
    input.push_back(i);
  }
  for(int i = 0; i < prerequisites.size(); i++) {
    int u = prerequisites[i][0];
    int v = prerequisites[i][1];
    adj[u].push_back(v);
    adjR[v].push_back(u);
  }

  vector<int> output2;
  vector<int> output;
  dfs(input, V, adj, output2);
  for(int i = 0; i < numCourses; i++) {
    V[i].s = -1;
    V[i].f = -1;
  }
  dfs(output2, V, adjR, output);

  cout << "[";
  for(int i = output.size()-1; i > 0; i--) {
    cout << output[i] << ",";
  }
  if(output.size())
    cout << output[0];
  cout << "]";
  cout << endl;
}

int main() {
  int numCourses = 4;
  vector<vector<int>> prerequisites;

  vector<int> value1;
  value1.push_back(1);
  value1.push_back(0);
  prerequisites.push_back(value1);

  vector<int> value2;
  value2.push_back(2);
  value2.push_back(0);
  prerequisites.push_back(value2);

  vector<int> value3;
  value3.push_back(3);
  value3.push_back(1);
  prerequisites.push_back(value3);

  vector<int> value4;
  value4.push_back(3);
  value4.push_back(2);
  prerequisites.push_back(value4);

  findOrder(numCourses, prerequisites);

  return 0;
}
