#include <cstdio>
#include <cstring>

int main(void)
{
	int n;	
	int stu[100010];
	int num, grade;
	memset(stu, 0, sizeof(stu));
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &num, &grade);
		stu[num] += grade;
	}
	
	num = grade = -1;
	for(int i = 1; i <= n; i++)
	{
		if(stu[i] > grade)
		{
			grade = stu[i];
			num = i;
		}
	}
	printf("%d %d", num, grade);
}
