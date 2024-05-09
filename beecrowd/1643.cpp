#include <iostream>

struct node {
  unsigned int value;
  struct node *next;
};

node* invert_list(node *list) {
  node *new_list = nullptr;
  while(list) {
    node *aux = list->next;
    list->next = new_list;
    new_list = list;
    list = aux;
  }
  return new_list;
}

int main() {
  unsigned int t;
  int x;

  std::cin >> t;
  
  while(t > 0) {
    unsigned int buffer_one = 1, buffer_two = 1;
    std::cin >> x;

    node *list = nullptr;
    while(buffer_two < x) {
      unsigned int buffer = buffer_two;
      buffer_two = buffer_two + buffer_one;
      buffer_one = buffer;

      node *num = (node*) malloc(sizeof(node));
      num->value = buffer_one;
      num->next = list;
      list = num;

    }

    node *f_list = nullptr;
    node *aux_list = list;
    while(aux_list) {
      node *num = (node*) malloc(sizeof(node));
      int value = aux_list->value;
      if((x - value) >= 0) {
        num->value = 1;
        x = x - value;
      }else {
        num->value = 0;
      }
      num->next = f_list;
      f_list = num;
      aux_list = aux_list->next;
    }
    
    f_list = f_list->next;
    list = invert_list(list->next);
    
    unsigned int y = 0;
    while(f_list) {
      y += f_list->value * list->value;
      f_list = f_list->next;
      list = list->next;
    }

    std::cout << y << std::endl;
    t--;
  }

  return 0;
}
