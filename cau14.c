#include <stdio.h>
#include <math.h>

int ktsnt(int n)
{
	if (n <= 1)
		return 0;
	if (n <= 3)
		return 1;
	if (n % 2 == 0 || n % 3 == 0)
		return 0;
	for (int i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
	}
	return 1;
}

int chuyen(int n)
{
	int mang[100];
	int m = 0;
	while (n > 0)
	{
		mang[m] = n % 10;
		n /= 10;
		m++;
	}
	int s = 0;
	int a = 1;
	for (int i = m - 1; i >= 0; i--)
	{
		int b = mang[i] * a;
		a = a * 10;
		s += b;
	}
	return s;
}

int ktslp(int n)
{
	int root = cbrt(n);
	return (root * root * root == n);
}

int main()
{
	for (int i = 100; i < 1000; i++)
	{
		if (ktsnt(i))
		{
			int a = chuyen(i);
			if (ktslp(a))
			{
				printf("%d\t", i);
			}
		}
	}
	return 0;
}
