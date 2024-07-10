#include <stdio.h>
#include <math.h>

int main() {
  int A, B;
  printf("Nhap A: ");
  scanf("%d", &A);
  printf("Nhap B: ");
  scanf("%d", &B);


  int ktra[B + 1];
  for (int i = 2; i <= B; i++) {
    ktra[i] = 1;  
  }


  for (int i = 2; i * i <= B; i++) {
    if (ktra[i] == 1) {  
      for (int j = i * i; j <= B; j += i) {
        ktra[j] = 0;  
      }
    }
  }

  
  int s = 0;
  for (int i = A; i <= B; i++) {
    if (ktra[i] == 1) {
      s += i;
    }
  }

  printf("tong cac so nguyen to: %d\n", s);
  return 0;
}
