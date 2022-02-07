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
#define Y_SIZE 24
#define X_SIZE 12

void gotoxy(int x, int y); // 좌표 이동 함수
void makegameboard(int board[][12]); // 테트리스 판 제작 함수 (0 : 도형 없음, 1 : 도형 있음, 2 : 충돌 라인)
void printingboard(int board[][12]); // 테트리스 판 출력 함수
void makeblockshape(int board[][12], int* num, int* xdinate, int* ydinate); // 랜덤하게 나온 도형들을 테트리스 판에 투입 함수
void keyLEFT(int board[][12], int* xdinate, int* ydinate);
void keyRIGHT(int board[][12], int* xdinate, int* ydinate);
//void keyUP(int board[][12], int* xdinate, int* ydinate);
//void keyDOWN(int board[][12], int* xdinate, int* ydinate);


int shape[7][4][4][4] = { { {0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},  // ㅁ 모양
						    {0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
							{0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
							{0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0}
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
	int gameboard[Y_SIZE][X_SIZE] = { {0} }; // 테트리스 판 배열
	int randblock = 0; // 7개의 도형중 랜덤하게 숫자가 들어갈 변수
	int key = 0; // 키보드 입력된 아스키코드 저장 변수
	int xdinate = 4; //랜덤한 블록의 초기 x 좌표;
	int ydinate = 1; //랜덤한 블록의 초기 y 좌표;


	makegameboard(gameboard); // 테트리스 판 제작 (0 : 도형 없음, 1 : 도형 있음, 2 : 충돌 라인)
	printingboard(gameboard); // 테트리스 판 출력
	srand(time(NULL)); // 테트리스 게임을 시작할 때 랜덤 숫자(7개의 도형 번호)가 같은 패턴으로 나오는것을 방지

	randblock = 1;
	makeblockshape(gameboard, &randblock, &xdinate, &ydinate); // 랜덤하게 나온 도형들을 테트리스 판에 투입

	while (1)
	{
		//randblock = rand() % 7; // 7개의 도형중 랜덤하게 숫자가 들어감
		 
		printingboard(gameboard); // 테트리스 판 출력
		if (_kbhit()) // 0 : 키 입력이 없을 때, 1 : 키 입력이 있을 때
		{
			switch (key = _getch())
			{
				case LEFT:
					keyLEFT(gameboard, &xdinate, &ydinate);
					break;
				case RIGHT:
					keyRIGHT(gameboard, &xdinate, &ydinate);
					break;
				case UP:
					//keyUP(gameboard, &xdinate, &ydinate);
					break;
				case DOWN:
					//keyDOWN(gameboard, &xdinate, &ydinate);
					break;
			}
		}
		Sleep(10);
		xdinate = 4; // 랜덤한 블록 처리시 다시 초기 x좌표 설정
		ydinate = 1; // 랜덤한 블록 처리시 다시 초기 y좌표 설정	


	}
		return 0;
}

void makegameboard(int board[][12]) // 테트리스 판 제작 (0 : 도형 없음, 1 : 도형 있음, 2 : 충돌 라인)
{
	for (int i = 0; i < Y_SIZE; i++)
	{
		board[i][0] = 1;
		board[i][11] = 1;
	}

	board[0][0] = 3;
	board[0][11] = 4;

	for (int i = 0; i < X_SIZE; i++)
	{
		board[23][i] = 1;
	}

	for (int i = 1; i < X_SIZE - 1; i++) // 게임 제한 라인 설정
	{
		board[0][i] = 2;
	}

}

void printingboard(int board[][12]) // 테트리스 판 출력
{
	int k = 5;

	for (int i = 0; i < Y_SIZE; i++)
	{
		gotoxy(10, k);
		for (int j = 0; j < X_SIZE; j++)
		{
			if (board[i][j] == 1)
			{
				printf("■");
			}
			else if (board[i][j] == 3)
			{
				printf("▷");
			}
			else if (board[i][j] == 4)
			{
				printf("◁");
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

void makeblockshape(int board[][12],int * num, int * xdinate, int * ydinate) // // 랜덤하게 나온 도형들을 테트리스 판에 투입
{
	int random = *num;
	int x = * xdinate;
	int y = * ydinate;

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

void keyLEFT(int board[][12], int* xdinate, int* ydinate)
{
	int fixedx = *xdinate;
	int fixedy = *xdinate;
	int x = *xdinate;
	int y = *ydinate;
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[y][x - 1] = board[y][x];
			x++;
		}
		x = fixedx;
		y++;
	}

	for (int i = fixedy; i < fixedy + 4; i++)
	{
		board[i][fixedx + 3] = 0;
	}

	*xdinate -= 1;
}

void keyRIGHT(int board[][12], int* xdinate, int* ydinate)
{
	int fixedx = *xdinate;
	int fixedy = *xdinate;
	int x = *xdinate;
	int y = *ydinate;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[y][x + 4] = board[y][x + 3];
			x--;
		}
		x = fixedx;
		y++;
	}

	for (int i = fixedy; i < fixedy + 4; i++)
	{
		board[i][fixedx] = 0;
	}

	*xdinate += 1;
}


void gotoxy(int x, int y) // 좌표 이동
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}