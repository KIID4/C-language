#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char test[100] = { 0 }; // 계산식 받을 배열
	int arr[100] = { 0 }; // 정수 배열
	char arr2[100] = { 0 }; // 수식기호 배열
	int length, x = 0, y = 0; // x = 수식기호 배열카운트 y = 숫자 배열카운트
	
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
		else // 숫자일 경우
		{
			arr[y] = test[i] - 48; // char배열상에서 숫자는 문자로 인식되어 아스키 코드값으로 나오므로 숫자로 변환
			y++;
		}
	}


	
	return 0;
} 