#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int FirstTen()
{
	int n, i = 3, count, c;
	
	printf ("Enter the number of Prime Numbers to print:\n");
	scanf ("%d", &n);
	
	if (n >= 1)
	{
		printf("First %d Prime Numbers are:\n", n);
		printf ("2\n");
	}
	for (count = 2; count <= n;)
	{
		for (c = 2; c <= i - 1; c++)
		{
			if (i%c == 0)
				break;
		}
		if (c ==i)
		{
			printf("%d\n", i);
			count++;
		}
		i++;
	}
	return 0;
}

int reverse (int m)   /*Returns reverse of m*/
{
	int rev = 0, r;
		while (m > 0)
		{
			r = m % 10;
			rev = rev * 10 + r;
			m /= 10;
		}
		return 0;
}

bool isPrime (int m)   /*Returns true if m is a Prime*/
{
	if (m <= 1)
		return false;
	if (m <= 3)
		return true;
	if (m % 2 == 0 || m % 3 == 0)
		return false;
	for (int j = 5; j * j <= m; j = j + 6)
		if (m % j == 0 || m % (j + 2) == 0)
			return false;
	return true;
}

bool checkTwistedPrime (int m)  /*code to check Twisted Prime Numbers*/
{
	if (isPrime(m) == false)
		return false;
	return isPrime(reverse(m));	
}

int main (void)  /* Driver Code*/
{
	printf("First few twisted prime numbers are:\n");
	for (int j = 2; j <= 200; j++)
		if (checkTwistedPrime (j))
			printf("%d", j);
	return 0;
}