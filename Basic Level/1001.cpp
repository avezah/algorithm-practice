#include <cstdio>

int main(void)
{
	int num, step = 0;
	scanf("%d", &num);
	
	while(num != 1)
	{
		if (num%2 == 0)
			num = num/2;
		else if (num %2 == 1)
			num = (num*3 + 1)/2;
		
		step++;
	}
	printf("%d", step);
}
