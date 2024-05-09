#include <iostream>

int solver(int *list, int N) {
  int memo[N];
  for(int i = 0; i < N; i++) {
    memo[i] = 1;
  }
  for(int i = 1; i < N; i++) {
    int m = i;
    for(int j = i - 1; j >= 0; j--) {
      if(list[i] > list[j] && memo[j] >= memo[m]) {
        memo[i] = memo[j] + 1;
        m = j;
      }
    }
  }
  return memo[N - 1];
}

int main() {
  int N;
  std::cin >> N;

  do {
    int list[N];
    for(int i = 0; i < N; i++) {
      std::cin >> list[i];
    }
    std::cout << solver(list, N) << std::endl;
    N = 0;
    std::cin >> N;
  } while(N); 

  return 0;
}
