#include <stdio.h>
#define NMAX 100000000 // 10 ^ 8

int n;
short is_not_prime[NMAX];

void sieve(short *array, int n)
{
	array[0] = array[1] = 1;
	for (int i=2; i<=n; i++)
	{
		if (array[i] == 0){
			for (int j = i + i; j <= n; j += i)
				array[j]  = 1;
		}
	}
}

int main()
{
	printf("Input a number: ");
	scanf("%d", &n);

	if (n <= 0 || n > NMAX)
	{
		printf("Invalid Input!");
		return 0;
	}

	sieve(is_not_prime, n);

	printf("The primes less than or equal to %d are: \n", n);

	for (int i = 1; i <= n; i ++)
		if (is_not_prime[i] == 0)
			printf("%d \n", i);

	return 0;
}
