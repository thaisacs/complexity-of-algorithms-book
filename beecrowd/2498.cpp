#include <iostream>

struct node {
  int w, v;
};

int knapsack(node *books, unsigned int N, unsigned int C) {
  int memo[N + 1][C + 1];
  for(int i = 0; i < N + 1; i++) {
    for(int j = 0; j < C + 1; j++) {
      memo[i][j] = 0;
    }
  }
  for(int i = 1; i < N + 1; i++) {
    int W, V;
    W = books[i-1].w;
    V = books[i-1].v;
    for(int j = 1; j < C + 1; j++) {
      if(W <= j) {
        int buff = memo[i-1][j-W] + V;
        if(buff > memo[i-1][j]) {
          memo[i][j] = buff;
        }else {
          memo[i][j] = memo[i-1][j];
        }
      }else {
        memo[i][j] = memo[i-1][j];
      }
    }
  }
  return memo[N][C];
}

int main() {
  unsigned int N, C, id = 1;

  std::cin >> N >> C; 
  do {
    node books[N];
    int W, V;
    for(int i = 0; i < N; i++) {
      std::cin >> W >> V; 
      books[i].w = W;
      books[i].v = V;
    }
    std::cout << "Caso " << id << ": " << knapsack(books, N, C) << std::endl;
    id++;
    std::cin >> N >> C; 
  } while(N && C);
  
  return 0;
}
