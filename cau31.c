#include <stdio.h>
#include <math.h>
int main()
{
	int MSV, SBD,MSVd,MSVt,i,cduoi,ctren,check,done,b,k,a,K[50],j,n;
	cduoi=ctren=0;
	n=123456;			
	printf("Nhap MSV:"); scanf("%d",&MSV);
	printf("Nhap SBD: "); scanf("%d",&SBD);
	MSVd=MSVt=MSV;
	duoi:
	MSVd--;
	cduoi++;
	check=0;
	for(i=2;i<=sqrt(MSVd);i++)
	{
		if (MSVd%i==0) check=1;
	}
	
	if (check==1)
	{
		goto duoi;
	}
	check=0;
	tren:
	MSVt++;
	ctren++;
	check=0;
	for(i=2;i<=sqrt(MSVt);i++)
	{
		if (MSVt%i==0) check=1;
	}
	
	if (check==1)
	{
		goto tren;
	}
	if (cduoi<=ctren) MSV=MSVd;
	else MSV=MSVt;
	
	k=MSV;
    a=SBD;
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

	printf(" %d ^ %d mod %d = %d",SBD,MSV,n,b);

}