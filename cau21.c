#include <stdio.h>
#include <math.h>


int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}


int count_primes(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime(i)) {
            count++;
        }
    }
    return count;
}


int is_super_prime(int x) {
    int prime_count = count_primes(x);
    return is_prime(prime_count);
}

int main() {
    int A, B;
    printf("Nhap A: ");
    scanf("%d", &A);
    printf("Nhap B: ");
    scanf("%d", &B);

    int super_prime_count = 0;

    for (int i = A; i <= B; i++) {
        if (is_super_prime(i)) {
            super_prime_count++;
            printf("%d la sieu so nguyen to\n", i);
        }
    }

    printf("Tong so luong sieu so nguyen to trong khoang [%d, %d] la: %d\n", A, B, super_prime_count);

    return 0;
}
