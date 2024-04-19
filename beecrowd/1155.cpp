#include <stdio.h>

int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
    int i;
    float S = 0.0;
    for(i = 1; i <= 100; i++){
      S += 1.0/i;
    }
    printf("%.2f\n", S);
    return 0;
}
