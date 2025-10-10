#include <stdio.h>

int main() {
    int popA = 80000;
    int popB = 200000;
    int anos = 0;
    
    while (popB > popA) {
        anos++;
        popB *= 1.015;
        popA *= 1.03;
    }
    
    printf("%d anos\n", anos);

    return 0;
}
