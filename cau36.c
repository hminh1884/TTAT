#include<stdio.h>
#include<math.h> 
#include<string.h>
int main() 
{
    char t[1000],p[1000];
    int l[127]; 
    printf("\nNhap T: "); fgets(t,sizeof(t),stdin);
    printf("\nNhap P: "); fgets(p,sizeof(p),stdin); 
    int lap=0;
    for(int i=0;i<127;i++)
    { 
        l[i]=-1;
    } 
    for(int i=0;i<(int)strlen(p)-1;i++)
    {
        l[(int)p[i]]=i; 
    }
    int cong_them,i,j,d=0; 
    for(i=0;i<(int)strlen(p)-1;i++)
    { 
        printf("%c ",p[i]);
        printf("%d \n",l[(int)p[i]]);
    } 
    i=strlen(p)- 2 ;    j=strlen(p)- 2; d=0;
    

    while(i<strlen(t)-1)
    {   d=0;
        while(d!=strlen(p)-1)
        { 
        if(t[i]==p[j])
        {
   
            i--;j--; 
            d++;
            lap++; 
   
 
        }
        else
        { 
            int min;
            if (j > 1 + l[(int)t[i]]) 
            {
                min = 1 + l[(int)t[i]]; 
            }
            else
            { 
                min = j;
            } 
     
          if(min==0)
           i = i + strlen(p) - min-1; 
           if(min!=0)
            i = i + strlen(p) - min-1;
           j = strlen(p) - 2 ; 

           lap++; 
           break;
        } 
        }
        if (d == strlen(p)-1)
        { 
            printf("P co trong T, bat dau tai vi tri %d\n", i +1);
            printf("\nLap: %d",lap); 
            return 0;
        }
    } 
    printf("P khong co trong T\n");
    printf("\nLap: %d",lap); 
}