#include <stdio.h>
#include <math.h>

int ktsnt(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);

    int ktra[N + 1];
    for (int i = 2; i <= N; i++) {
        ktra[i] = 1; 
    }

    for (int i = 2; i <= sqrt(N); i++) {
        if (ktra[i] == 1) {
            for (int j = i * i; j <= N; j += i) {
                ktra[j] = 0; 
            }
        }
    }
    int mang[100000];
    int m = 0;
    for (int i = 2; i <= N; i++) {
        if (ktra[i] == 1) {
            mang[m] = i;
            m++;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            int tong = mang[i] + mang[j];
            int hieu = mang[j] - mang[i];
            if (ktsnt(tong) && ktsnt(hieu)) {
                printf("(%d, %d)\n", mang[i], mang[j]);
            }
        }
    }

    return 0;
}
