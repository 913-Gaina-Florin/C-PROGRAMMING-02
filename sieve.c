#include <stdio.h>
#define NMAX 100000000 // 10^8

int n;

short is_not_prime[NMAX];

int main()
{
	printf("Input a number: ");
	scanf("%d", &n);

        if (n <= 0 || n > NMAX){
		printf("Invalid input\n");
		return 0;
	}
        
        is_not_prime[0] = is_not_prime[1] = 1;

        for (int i=2; i<=n; i++)
	{
		if (is_not_prime[i] == 0)
		{
		    for (int j=i+i; j<=n; j+=i)
		        is_not_prime[j] = 1;
		}
	}

	printf("The primes less than or equal to %d are: \n", n);
        for (int i=1; i<=n; i++)
		if (is_not_prime[i] == 0)
			printf("%d\n", i);

	return 0;
}
