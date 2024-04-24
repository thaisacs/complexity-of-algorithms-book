#include <iostream>
#include <vector>

struct order {
  int time, amount;
};

void print_vector(std::vector<order> orders) {
  for(int i = 0; i < orders.size(); i++) {
    std::cout << orders[i].time << " " << orders[i].amount << std::endl;
  }
}

void recover(std::vector<std::vector<int>> memo, std::vector<order> orders, int n, int m) {
  int i = n;
  int j = m;   
  while(n > 0) {
    int item = n - 1;
    if(memo[n][m] != memo[n-1][m]) {
      std::cout << n << std::endl;
      m = m - orders[item].amount;
      n = n - 1;
    }else {
      n = n - 1;
    }
  }
}

void solve(std::vector<order> orders, int P) {
  int n = orders.size();
  int m = P;
  std::vector<std::vector<int>> memo;

  for(int i = 0; i <= n; i++) {
    std::vector<int> buffer;
    for(int j = 0; j <= m; j++) {
      buffer.push_back(0);
    }
    memo.push_back(buffer);
  }
  for(int i = 1; i <= n; i++) {
    int item = i - 1;
    for(int j = 1; j <= m; j++) {
      int v1 = memo[i-1][j];
      if(orders[item].amount <= j) {
        int w = j - orders[item].amount;
        int v2 = orders[item].time + memo[i-1][w];
        if(v1 > v2)
          memo[i][j] = v1;
        else
          memo[i][j] = v2;
      }else {
        memo[i][j] = v1;
      }
    }
  }
  //recover(memo, orders, n, m);
  //for(int i = 0; i <= n; i++) {
  //  for(int j = 0; j <= m; j++) {
  //    std::cout << memo[i][j] << " ";
  //  }
  //  std::cout << std::endl;
  //}
  std::cout << memo[n][m] << " min." << std::endl;
}

int main() {
  int P, N;
   
  std::cin >> N >> P;

  do{
    std::vector<order> orders;
    while(N) {
      order new_order;
      std::cin >> new_order.time;
      std::cin >> new_order.amount;
      orders.push_back(new_order);
      N -= 1;
    }
    solve(orders, P);
    std::cin >> N >> P;
  }while(N);

  return 0;
}
