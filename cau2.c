#include <stdio.h>
#include <math.h>

int main() {
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);


    int a = pow(10, N);
    int b = pow(10, N-1);


    int ktra[a];
    for (int i = 2; i < a; i++) {
        ktra[i] = 1; 
    }


    for (int i = 2; i < a; i++) {
        if (ktra[i]) {
            for (int j = i * 2; j < a; j += i) {
                ktra[j] = 0; 
            }
        }
    }

    
    for (int i = b; i < a; i++) {
        if (ktra[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
