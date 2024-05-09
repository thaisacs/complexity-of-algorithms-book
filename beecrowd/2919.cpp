#include <iostream>

struct node {
  int value, index;
};

int solver(int *list, int N) {
  int L = 0;
  node memo[N+1];
  memo[0].value = -1;
  memo[0].index = 0;

  for(int i = 0; i < N; i++) {
    int lo = 0;
    int hi = L + 1;
    while(lo < hi) {
      int m = lo + int((hi-lo)/2);
      if(memo[m].value >= list[i])
        hi = m;
      else
        lo = m + 1;
    }
    int newL = lo;
    memo[newL].value = list[i];
    memo[newL].index = i;
    if(newL > L) {
      L = newL;
    }
  }

  return L;
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
