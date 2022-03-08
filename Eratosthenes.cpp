#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>
void make();
int arr[246913] = { 0 };
int number = 246913;

void make()
{
	int num;
	
	num = int(sqrt(number));
	for (int i = 2; i <= num; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i * 2; j < number; j += i)
			{
				arr[j] = 1;
			}
		}
	}

}

int main()
{
	int num,count;

	make();
	arr[1] = 1;
	
	while (1)
	{
		scanf("%d", &num);
		if (num == 0) break;
		count = 0;
		for (int i = num + 1; i <= num * 2; i++)
		{
			if (arr[i] == 0) count++;
		}
		printf("%d\n", count);
	}
	


	return 0;
}