#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>


#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80


void gotoxy(int x, int y); // 좌표 이동 함수
void makegameboard(int board[][12]); // 테트리스 판 제작 함수 (0 : 도형 없음, 1 : 도형 있음, 2 : 충돌 라인)
void printingboard(int board[][12]); // 테트리스 판 출력 함수
void makeblockshape(int board[][12], int * num); // 랜덤하게 나온 도형들을 테트리스 판에 투입 함수

int shape[7][4][4][4] = { { {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},  // ㅁ 모양
						    {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
							{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
							{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}
						  },
						  { {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},  // ㅣ 모양
						    {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
							{0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},
							{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0}
						  },
						  { {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},  //  ㅡ 
						    {0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},  //    |
						    {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},  //     ㅡ    모양
						    {0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}
						  },
						  { {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},  //     ㅡ
							{0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0},  //    |
							{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},  //  ㅡ       모양
							{0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0}
						  },
						  { {0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},
						    {0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0},  //       |
						    {0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},  // ㅡㅡㅡ    모양
						    {0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0}
						  },
						  { {0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},
						    {0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0},  // |
						    {0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},  //  ㅡㅡㅡ   모양
						    {0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0}
						  },
						  { {0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},  // ㅗ  모양
						    {0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},
						    {0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},
						    {0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}
						  }
};

int main()
{
	int gameboard[24][12] = { {0} }; // 테트리스 판 배열
	int randblock = 0; // 7개의 도형중 랜덤하게 숫자가 들어갈 변수
	int key; // 키보드 입력된 아스키코드 저장 변수

	srand(time(NULL)); // 테트리스 게임을 시작할 때 랜덤 숫자(7개의 도형 번호)가 같은 패턴으로 나오는것을 방지
	randblock = rand() % 7; // 7개의 도형중 랜덤하게 숫자가 들어감
	makeblockshape(gameboard, &randblock); // 랜덤하게 나온 도형들을 테트리스 판에 투입 
	makegameboard(gameboard); // 테트리스 판 제작 (0 : 도형 없음, 1 : 도형 있음, 2 : 충돌 라인)
	printingboard(gameboard); // 테트리스 판 출력
	
	if (_kbhit()) // 0 : 키 입력이 없을 때, 1 : 키 입력이 있을 때
	{
		key = _getch();
	}
	
		







}


void makegameboard(int board[][12]) // 테트리스 판 제작 (0 : 도형 없음, 1 : 도형 있음, 2 : 충돌 라인)
{
	for (int i = 0; i < 24; i++)
	{
		board[i][0] = 1;
		board[i][11] = 1;
	}

	for (int i = 0; i < 12; i++)
	{
		board[23][i] = 1;
		board[0][i] = 2;
	}

}

void printingboard(int board[][12]) // 테트리스 판 출력
{
	int k = 5;
	for (int i = 0; i < 24; i++)
	{
		gotoxy(10, k);
		for (int j = 0; j < 12; j++)
		{
			if (board[i][j] == 1)
			{
				printf("■");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
		k++;
	}
}

void makeblockshape(int board[][12],int * num) // // 랜덤하게 나온 도형들을 테트리스 판에 투입
{
	int random = *num;
	int x = 4;
	int y = 1;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[y][x] = shape[random][0][i][j];
			x++;
		}
		x = 4;
		y++;
	}
}

void gotoxy(int x, int y) // 좌표 이동
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}