#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int N) {
    bool prime[N+1];
    for (int i = 0; i <= N; i++) {
        prime[i] = true;
    }

    prime[0] = false;
    prime[1] = false;

    for (int p = 2; p * p <= N; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= N; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= N; p++) {
        if (prime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}

int main() {
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);
    sieveOfEratosthenes(N);
    return 0;
}
