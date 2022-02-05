// c언어 계산기 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char test[100] = {' '}; // 계산식 받을 배열
	char test2[100] = {' '}; // atoi를 이용하기위한 임시저장 배열
	double arr[100] = { 0 }; // 정수 배열
	char arr2[100] = { 0 }; // 수식기호 배열
	int length, x = 0, y = 0; // x = 수식기호 배열카운트 y = 숫자 배열카운트
	int fixed = 0; // 수식 기호 3개이상 연달아 * , /일 경우 고정값 부여 
	int count = 0; // 수식 기호 3개이상 판별 변수
	
	printf("수식을 입력해주세요 : ");
	gets_s(test, sizeof(test));

	length = strlen(test);
	for (int i = 0; i < length; i++) // 숫자, 공백, 수식기호 판단
	{
		if ((test[i] == '+') || (test[i] == '-') || (test[i] == '/') || (test[i] == '*')) // 수식기호일 경우
		{
			arr2[x] = test[i];
			x++;
		}
		else if (test[i] == ' ') // 공백일 경우 
		{
			continue;
		}
	}

	test[length] = '\n'; // 엔터키가 안들어 갔으므로 엔터키 대입
	for (int i = 0; i < length + 2; i++)
	{
		if (test[i] == ' ' || test[i] == '*' || test[i] == '/' || test[i] == '+' || test[i] == '-' || test[i] == '\n') // 공백, 수식기호 판별
		{
			if (test[i + 1] == ' ' || test[i + 1] == '*' || test[i + 1] == '/' || test[i + 1] == '+' || test[i + 1] == '-' || test[i + 1] == '\n') // 공백, 수식기호가 연달아 있을경우
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

	for (int i = 0; i < x; i++) // 수식기호 2개 붙어있는지 판별 여부
	{
		if ((arr2[i] == '*' || arr2[i] == '/') && (arr2[i + 1] == '*' || arr2[i + 1] == '/'))
		{
			fixed = i;
			count++;
		}
	}

	if (count == 0) // 수식기호가 연달아 * ,/ 이 아닐경우
	{
		for (int i = 0; i < x; i++) // 곱셉 나눗셈 우선순위 설정 
		{
			if (arr2[i] == '*')
			{
				arr[i] = arr[i] * arr[i + 1];
				for (int j = i; j < length; j++)
				{
					arr[j + 1] = arr[j + 2]; // 숫자 배열 한칸씩 뒤로 저장
					arr2[j] = arr2[j + 1]; // 수식배열 한칸씩 뒤로 저장
				}
			}
			else if (arr2[i] == '/')
			{
				arr[i] = arr[i] / arr[i + 1];
				for (int j = i; j < length; j++)
				{
					arr[j + 1] = arr[j + 2]; // 숫자 배열 한칸씩 뒤로 저장
					arr2[j] = arr2[j + 1]; // 수식배열 한칸씩 뒤로 저장
				}
			}
		}
	}

	else if (count == 1) // 수식기호가 연달아 * ,/ 일경우
	{
		for (int i = 0; i < x; i++) // 곱셉 나눗셈 우선순위 설정 
		{
			if (arr2[fixed] == '*')
			{
				arr[fixed] = arr[fixed] * arr[fixed + 1];
				for (int j = fixed; j < length; j++)
				{
					arr[j + 1] = arr[j + 2]; // 숫자 배열 한칸씩 뒤로 저장
					arr2[j] = arr2[j + 1]; // 수식배열 한칸씩 뒤로 저장
				}
			}
			else if (arr2[fixed] == '/')
			{
				arr[fixed] = arr[fixed] / arr[fixed + 1];
				for (int j = fixed; j < length; j++)
				{
					arr[j + 1] = arr[j + 2]; // 숫자 배열 한칸씩 뒤로 저장
					arr2[j] = arr2[j + 1]; // 수식배열 한칸씩 뒤로 저장
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
				arr[j + 1] = arr[j + 2]; // 숫자 배열 한칸씩 뒤로 저장
				arr2[j] = arr2[j + 1]; // 수식배열 한칸씩 뒤로 저장
			}
		}
		else if (arr2[fixed] == '-')
		{
			arr[fixed] = arr[fixed] - arr[fixed + 1];
			for (int j = fixed; j < length; j++)
			{
				arr[j + 1] = arr[j + 2]; // 숫자 배열 한칸씩 뒤로 저장
				arr2[j] = arr2[j + 1]; // 수식배열 한칸씩 뒤로 저장
			}
		}
	}
	printf("결과는 : %.2lf입니다.",arr[0]);
	return 0;
} 