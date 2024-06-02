#include <iostream>
#include <cstdlib>

struct node {
  unsigned int d, p;
};

void swap(node *tasks, int i, int j) {
  node buff = tasks[i];
  tasks[i] = tasks[j];
  tasks[j] = buff;
}

int partition(node *tasks, int p, int r, short flag) {
  node pivo = tasks[r];
  int i = p-1;
  for(int j = p; j < r; j++) {
    if(!flag && tasks[j].d <= pivo.d) {
      i = i + 1;
      swap(tasks, i, j);
    }
    if(flag && tasks[j].p > pivo.p) {
      i = i + 1;
      swap(tasks, i, j);
    }
  }
  i = i + 1;
  swap(tasks, i, r);
  return i;
}

int random_partition(node *tasks, int p, int r, short flag) {
  int pivo = (rand() % (r - p + 1)) + p;
  swap(tasks, pivo, r);
  return partition(tasks, p, r, flag);
}

void quick_sort(node *tasks, int p, int r, short flag) {
  if(p < r) {
    int q = random_partition(tasks, p, r, flag);
    quick_sort(tasks, p, q - 1, flag);
    quick_sort(tasks, q + 1, r, flag);
  }
}

void intercala(node *tasks, int p, int q, int r) {
  node *buffer = (node*) malloc((r - p + 1)*sizeof(node));
  for(int i = p; i <= q; i++) {
    buffer[i-p] = tasks[i];
  }
  int k = r - p;
  for(int i = q + 1; i <= r; i++) {
    buffer[k] = tasks[i];
    k--;
  }
  int i = p;
  int j = r;

  for(int k = p; k <= r; k++) {
    if(buffer[i-p].d <= buffer[j-p].d) {
      tasks[k] = buffer[i-p];
      i = i + 1;
    }else {
      tasks[k] = buffer[j-p];
      j = j - 1;
    }
  }
}

void merge_sort(node *tasks, int p, int r) {
  if(p < r) {
    int q = int((p + r)/2);
    merge_sort(tasks, p, q);
    merge_sort(tasks, q + 1, r);
    intercala(tasks, p, q, r);
  }
}

int solver(node *tasks, int N) {
  int t = tasks[0].d;
  for(int i = 0; i < N; i++) {
    if(t < tasks[i].d) {
      t = tasks[i].d + tasks[i].p;
    }else {
      t += tasks[i].p;
    }
  }
  return t;
}


int main() {
  int N;

  std::cin >> N;
  do {
    node tasks[N];

    for(int i = 0; i < N; i++) {
      int d, p;
      std::cin >> d >> p;
      tasks[i].d = d;
      tasks[i].p = p;
    }

    merge_sort(tasks, 0, N-1);

    std::cout << solver(tasks, N) << std::endl;

    N = 0;
    std::cin >> N;
    std::cout << N << std::endl;
  }while(N);

  return 0;
}

