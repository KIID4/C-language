// c��� ���� 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char test[100] = {' '}; // ���� ���� �迭
	char test2[100] = {' '}; // atoi�� �̿��ϱ����� �ӽ����� �迭
	double arr[100] = { 0 }; // ���� �迭
	char arr2[100] = { 0 }; // ���ı�ȣ �迭
	int length, x = 0, y = 0; // x = ���ı�ȣ �迭ī��Ʈ y = ���� �迭ī��Ʈ
	int fixed = 0; // ���� ��ȣ 3���̻� ���޾� * , /�� ��� ������ �ο� 
	int count = 0; // ���� ��ȣ 3���̻� �Ǻ� ����
	
	printf("������ �Է����ּ��� : ");
	gets_s(test, sizeof(test));

	length = strlen(test);
	for (int i = 0; i < length; i++) // ����, ����, ���ı�ȣ �Ǵ�
	{
		if ((test[i] == '+') || (test[i] == '-') || (test[i] == '/') || (test[i] == '*')) // ���ı�ȣ�� ���
		{
			arr2[x] = test[i];
			x++;
		}
		else if (test[i] == ' ') // ������ ��� 
		{
			continue;
		}
	}

	test[length] = '\n'; // ����Ű�� �ȵ�� �����Ƿ� ����Ű ����
	for (int i = 0; i < length + 2; i++)
	{
		if (test[i] == ' ' || test[i] == '*' || test[i] == '/' || test[i] == '+' || test[i] == '-' || test[i] == '\n') // ����, ���ı�ȣ �Ǻ�
		{
			if (test[i + 1] == ' ' || test[i + 1] == '*' || test[i + 1] == '/' || test[i + 1] == '+' || test[i + 1] == '-' || test[i + 1] == '\n') // ����, ���ı�ȣ�� ���޾� �������
			{
				continue;
			}
			else
			{
				arr[y] = atoi(test2);
				y++;
				for (int j = 0; j < fixed; j++)
				{
					test2[j] = ' ';
				}
				fixed = 0;
			}
		}
		else if (test[i] >= '0' && test[i] <= '9')
		{
			test2[fixed] = test[i];
			fixed++;
		}
	}

	for (int i = 0; i < x; i++) // ���ı�ȣ 2�� �پ��ִ��� �Ǻ� ����
	{
		if ((arr2[i] == '*' || arr2[i] == '/') && (arr2[i + 1] == '*' || arr2[i + 1] == '/'))
		{
			fixed = i;
			count++;
		}
	}

	if (count == 0) // ���ı�ȣ�� ���޾� * ,/ �� �ƴҰ��
	{
		for (int i = 0; i < x; i++) // ���� ������ �켱���� ���� 
		{
			if (arr2[i] == '*')
			{
				arr[i] = arr[i] * arr[i + 1];
				for (int j = i; j < length; j++)
				{
					arr[j + 1] = arr[j + 2]; // ���� �迭 ��ĭ�� �ڷ� ����
					arr2[j] = arr2[j + 1]; // ���Ĺ迭 ��ĭ�� �ڷ� ����
				}
			}
			else if (arr2[i] == '/')
			{
				arr[i] = arr[i] / arr[i + 1];
				for (int j = i; j < length; j++)
				{
					arr[j + 1] = arr[j + 2]; // ���� �迭 ��ĭ�� �ڷ� ����
					arr2[j] = arr2[j + 1]; // ���Ĺ迭 ��ĭ�� �ڷ� ����
				}
			}
		}
	}

	else if (count == 1) // ���ı�ȣ�� ���޾� * ,/ �ϰ��
	{
		for (int i = 0; i < x; i++) // ���� ������ �켱���� ���� 
		{
			if (arr2[fixed] == '*')
			{
				arr[fixed] = arr[fixed] * arr[fixed + 1];
				for (int j = fixed; j < length; j++)
				{
					arr[j + 1] = arr[j + 2]; // ���� �迭 ��ĭ�� �ڷ� ����
					arr2[j] = arr2[j + 1]; // ���Ĺ迭 ��ĭ�� �ڷ� ����
				}
			}
			else if (arr2[fixed] == '/')
			{
				arr[fixed] = arr[fixed] / arr[fixed + 1];
				for (int j = fixed; j < length; j++)
				{
					arr[j + 1] = arr[j + 2]; // ���� �迭 ��ĭ�� �ڷ� ����
					arr2[j] = arr2[j + 1]; // ���Ĺ迭 ��ĭ�� �ڷ� ����
				}
			}
		}
	}

	for (int i = 0; i < x; i++)
	{
		if (arr2[fixed] == '+')
		{
			arr[fixed] = arr[fixed] + arr[fixed + 1];
			for (int j = fixed; j < length; j++)
			{
				arr[j + 1] = arr[j + 2]; // ���� �迭 ��ĭ�� �ڷ� ����
				arr2[j] = arr2[j + 1]; // ���Ĺ迭 ��ĭ�� �ڷ� ����
			}
		}
		else if (arr2[fixed] == '-')
		{
			arr[fixed] = arr[fixed] - arr[fixed + 1];
			for (int j = fixed; j < length; j++)
			{
				arr[j + 1] = arr[j + 2]; // ���� �迭 ��ĭ�� �ڷ� ����
				arr2[j] = arr2[j + 1]; // ���Ĺ迭 ��ĭ�� �ڷ� ����
			}
		}
	}
	printf("����� : %.2lf�Դϴ�.",arr[0]);
	return 0;
} 