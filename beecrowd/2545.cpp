#include<bits/stdc++.h>

using namespace std;

int dfs_visit(vector<vector<int>>& graph, vector<int>& status, int id, vector<int>& output) {
  int count = 0;
  status[id] = 1; 

  for(int i = 0; i < graph[id].size(); i++) {
    int buff = graph[id][i];
    if(status[buff] == 0) {
      int ret = dfs_visit(graph, status, buff, output);
      if(ret == -1) {
        return -1;
      }
      if(ret > count)
        count = ret;
    }else if(status[buff] == 1) {
      return -1;
    }
  }
  count++;

  output.push_back(id);
  status[id] = 2; 

  return count;
}

int dfs(vector<int>& order, vector<vector<int>>& graph, vector<int>& output) {
  vector<int> status;

  for(int i = 0; i < graph.size(); i++) {
    status.push_back(0);
  }

  int fc = 0;
  for(int i = order.size()-1; i >= 0; i--) {
    if(status[order[i]] == 0) {
      int ret = dfs_visit(graph, status, order[i], output);
      if(ret == -1) {
        return -1;
      }
      if(ret > fc) {
        fc = ret;
      }
    }
  }

  return fc;
}

int solver(vector<vector<int>>& graph) {
  vector<int> output, final_output;
  vector<int> order;

  for(int i = 0; i < graph.size(); i++) {
    order.push_back(i);
  }

  int ret = dfs(order, graph, output);

  if(ret == -1)
    return -1;

  ret = dfs(output, graph, final_output);

  return ret;
}

int main() {
  int N, M, buffer;

  cin >> N;

  while(N > 0) {
    vector<vector<int>> graph;
    for(int i = 0; i < N; i++) {
      vector<int> v;
      graph.push_back(v);
    }

    for(int i = 0; i < N; i++) {
      cin >> M;
      for(int j = 0; j < M; j++) {
        cin >> buffer;
        buffer--;
        graph[i].push_back(buffer);
      }
    }

    cout << solver(graph) << endl;

    N = 0;
    cin >> N;
  }

  return 0;
}
