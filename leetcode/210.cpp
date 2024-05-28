#include <bits/stdc++.h>
#include <stack>
using namespace std;

int time_ = 0;

struct node {
  int s, f;
};

void dfs_visit(int u, node* V, vector<int>* adj) {
  time_++;
  V[u].s = time_;
  for(int i = 0; i < adj[u].size(); i++) {
    if(V[adj[u][i]].s == -1){
      dfs_visit(adj[u][i], V, adj);
    }
  }
  time_++;
  V[u].f = time_;
}

void dfs(int numCourses, node* V, vector<int>* adj, stack<int>& Stack) {
  for(int i = 0; i < numCourses; i++) {
    if(V[i].s == -1) {
      dfs_visit(i, V, adj);
    }
  }
}

void findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> adj[numCourses];
  vector<int> adjR[numCourses];
  node V[numCourses];
  for(int i = 0; i < numCourses; i++) {
    V[i].s = -1;
    V[i].f = -1;
  }
  for(int i = 0; i < prerequisites.size(); i++) {
    int u = prerequisites[i][0];
    int v = prerequisites[i][1];
    adj[u].push_back(v);
    adjR[v].push_back(u);
  }
  stack<int> Stack;
  dfs(numCourses, V, adj, Stack);
  //dfs(numCourses, V, adjR);

  for(int i = 0; i < numCourses; i++) {
    cout << V[i].s << " " << V[i].f << endl;
  }
}

int main() {
  int numCourses = 2;
  vector<vector<int>> prerequisites;

  vector<int> value1;
  value1.push_back(1);
  value1.push_back(0);
  prerequisites.push_back(value1);

  //vector<int> value2;
  //value2.push_back(0);
  //value2.push_back(2);
  //prerequisites.push_back(value2);

  //vector<int> value3;
  //value3.push_back(1);
  //value3.push_back(0);
  //prerequisites.push_back(value3);

  findOrder(numCourses, prerequisites);

  //vector<int> value4;
  //value4.push_back(3);
  //value4.push_back(2);
  //prerequisites.push_back(value4);
  //if(canFinish(numCourses, prerequisites)) {
  //  cout << "true" << endl;
  //}else {
  //  cout << "false" << endl;
  //}

  return 0;
}
