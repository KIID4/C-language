#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char test[100] = { 0 }; // ���� ���� �迭
	int arr[100] = { 0 }; // ���� �迭
	char arr2[100] = { 0 }; // ���ı�ȣ �迭
	int length, x = 0, y = 0; // x = ���ı�ȣ �迭ī��Ʈ y = ���� �迭ī��Ʈ
	
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
		else // ������ ���
		{
			arr[y] = test[i] - 48; // char�迭�󿡼� ���ڴ� ���ڷ� �νĵǾ� �ƽ�Ű �ڵ尪���� �����Ƿ� ���ڷ� ��ȯ
			y++;
		}
	}


	
	return 0;
} 