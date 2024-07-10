#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ktsnt(int n)
{
   if(n<2){
    return 0;
   }
   for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
        return 0;
	}
	}
   return 1;
 }
int euclidmr(int e,int en)
{
  	int a,b,R;
  	a=e;
  	b=en;
  	while (b>0)
    {
        R = a%b;
        a=b;
        b=R;
    }
  return a;
 }
int tinhd(int e,int en)
{
	int q,r,x,y,x1=0,x2=1,y1=1,y2=0;
  while(e>0){
    q=en/e;
    r=en%e;
    x=x2-x1*q;
    y=y2-y1*q;
    en=e;
    e=r;
    x2=x1;
    y2=y1;
    x1=x;
    y1=y;
  }
  return(y2);
 }
int main()
{
    int p,q,n,en,e;
    printf("Nhap p>100:");	scanf("%d",&p);

	while(p<=100||ktsnt(p)==0)
		{
        printf("Nhap lai snt p >100:");	scanf("%d",&p);
    	}
    
	printf("Nhap snt q<500:");	scanf("%d",&q);
    
	while(q>=500||ktsnt(p)==0)
		{
        printf("Nhap lai snt q >100:");	scanf("%d",&q);
    	}
    	
    n=p*q;
    printf("n =%d",n);
    en=(p-1)*(q-1);
    printf("\ne(n)=%d",en);
    printf("\nNhap 1<e<e(n), nguyen to cung nhau voi e(n):");	scanf("%d",&e);
    
	while(e<=1||e>=en||euclidmr(e,en)!=1)
	{
        printf("\nnhap lai 1<e<e(n), nguyen to cung nhau voi e(n): ");	scanf("%d",&e);
    }
    
    printf("\nd=%d\n",tinhd(e,en));
    
	int m,a,k,K[50],b,i,j;
    j=0;
    printf("Nhap SBD: "); scanf("%d",&m);
    m=m+123;
    printf("Thong diep m = SBD + 123 = %d\n",m);
   
	k=e;
    a=m;
    b=1;
	while (k>0)
    {
        K[j]=k%2;
        k=(k-K[j])/2;
        j++;
    }
    
    if (K[0]==1) b=a;
    for (i=1;i<j;i++)
    {
        a = (a*a) % n;
        if (K[i]==1)
        {
            b=(a*b) % n;
        }
    }
    
    printf("\nBan ma c cua thong diep %d la: %d",m,b);

	k=tinhd(e,en);
    a=b;
    b=1;
	while (k>0)
    {
        K[j]=k%2;
        k=(k-K[j])/2;
        j++;
    }
    
    if (K[0]==1) b=a;
    for (i=1;i<j;i++)
    {
        a = (a*a) % n;
        if (K[i]==1)
        {
            b=(a*b) % n;
        }
    }
	

	printf("\nGiai mai thong diep la: %d",b);
    
    return 0;
}