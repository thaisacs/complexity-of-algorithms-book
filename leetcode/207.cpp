
#include <bits/stdc++.h>
using namespace std;

int time_ = 0;

struct node {
  int s, f;
};

bool dfs_visit(int u, node* V, vector<int>* adj) {
  time_++;
  V[u].s = time_;
  bool ret = true;
  for(int i = 0; i < adj[u].size(); i++) {
    if(V[adj[u][i]].s != -1 && V[adj[u][i]].f == -1) {
      return false;
    }else if(V[adj[u][i]].s == -1){
      ret = dfs_visit(adj[u][i], V, adj);
      if(ret == false)
        return false;
    }
  }
  time_++;
  V[u].f = time_;
  return ret;
}

bool dfs(int numCourses, node* V, vector<int>* adj) {
  for(int i = 0; i < numCourses; i++) {
    if(V[i].s == -1) {
      if(dfs_visit(i, V, adj) == false) {
        return false;
      }
    }
  }
  return true;
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> adj[numCourses];
  node V[numCourses];
  for(int i = 0; i < numCourses; i++) {
    V[i].s = -1;
    V[i].f = -1;
  }
  for(int i = 0; i < prerequisites.size(); i++) {
    int u = prerequisites[i][0];
    int v = prerequisites[i][1];
    adj[u].push_back(v);
  }
  return dfs(numCourses, V, adj);
}

int main() {
  int numCourses = 3;
  vector<vector<int>> prerequisites;

  vector<int> value1;
  value1.push_back(0);
  value1.push_back(1);
  prerequisites.push_back(value1);

  vector<int> value2;
  value2.push_back(0);
  value2.push_back(2);
  prerequisites.push_back(value2);

  vector<int> value3;
  value3.push_back(1);
  value3.push_back(0);
  prerequisites.push_back(value3);

  //vector<int> value4;
  //value4.push_back(3);
  //value4.push_back(2);
  //prerequisites.push_back(value4);

  if(canFinish(numCourses, prerequisites)) {
    cout << "true" << endl;
  }else {
    cout << "false" << endl;
  }

  return 0;
}
