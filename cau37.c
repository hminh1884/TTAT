#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

int soSanhChuoi(char p[], int j, int i){
    int check = 0;
    for(int k = 0; k < i; k++){  
        if(p[k] == p[j - i + k]){   
            check++;
        }
    }
    if(check == i){
        return 1;
    }
    return 0;
}

int kiemTra(char p[], int j){
    for(int i = j-1; i >= 1; i--){
        if(soSanhChuoi(p, j, i) == 1){
            return i;
        }
    }
    return 0;
}

void failureFunction(char p[], int f[]){
    f[0]=-1;
    f[1]=0;
    for(int j = 2; j < strlen(p); j++){
        f[j] = kiemTra(p, j);
    }
}

int xuLy(char t[], char p[], int f[]){
    int i = 0, j = 0, check = 0, sopheptinhlap = 0;
    while(i < strlen(t) - strlen(p) ){
        int checkp = j, k = i+j;
        while(checkp != strlen(p)){
            if(t[k] == p[j]){
                k++;
                j++;
                checkp++;
                sopheptinhlap++;
            } else {
                i = i + j - f[j];
                j = f[j] == -1 ? 0 : f[j];
                sopheptinhlap++;
                break;
            }
        }
        if(checkp == strlen(p)){
            printf("\nKQ: Vi tri %d", i);
            check = 1;
            j=0;
            i=i+strlen(p);
        }
    }
    if(check == 0){
        printf("\nKQ: Khong co chuoi can tim");
    }
    return sopheptinhlap;
}

int main(){
    char t[5000],p[100];
    printf("Nhap doan van ban T: ");
    fflush(stdin);
    gets(t);
    printf("Nhap chuoi P can tim: ");
    fflush(stdin);
    gets(p);
    int f[strlen(p)];
    failureFunction(p, f);
    int sopheptinhlap = xuLy(t, p, f);
    printf("\nSo phep tinh lap la: %d", sopheptinhlap);
    getch();
    return 0;
}