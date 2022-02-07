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

void gotoxy(int x, int y); // ��ǥ �̵� �Լ�
void makegameboard(int board[][12]); // ��Ʈ���� �� ���� �Լ� (0 : ���� ����, 1 : ���� ����, 2 : �浹 ����)
void printingboard(int board[][12]); // ��Ʈ���� �� ��� �Լ�
void makeblockshape(int board[][12], int* num, int* xdinate, int* ydinate); // �����ϰ� ���� �������� ��Ʈ���� �ǿ� ���� �Լ�
void keyLEFT(int board[][12], int* xdinate, int* ydinate);
void keyRIGHT(int board[][12], int* xdinate, int* ydinate);
//void keyUP(int board[][12], int* xdinate, int* ydinate);
//void keyDOWN(int board[][12], int* xdinate, int* ydinate);


int shape[7][4][4][4] = { { {0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},  // �� ���
						    {0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
							{0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
							{0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0}
						  },
						  { {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},  // �� ���
						    {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
							{0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},
							{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0}
						  },
						  { {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},  //  �� 
						    {0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},  //    |
						    {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},  //     ��    ���
						    {0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}
						  },
						  { {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},  //     ��
							{0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0},  //    |
							{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},  //  ��       ���
							{0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0}
						  },
						  { {0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},
						    {0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0},  //       |
						    {0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},  // �ѤѤ�    ���
						    {0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0}
						  },
						  { {0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},
						    {0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0},  // |
						    {0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},  //  �ѤѤ�   ���
						    {0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0}
						  },
						  { {0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},  // ��  ���
						    {0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},
						    {0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},
						    {0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}
						  }
};

int main()
{
	int gameboard[Y_SIZE][X_SIZE] = { {0} }; // ��Ʈ���� �� �迭
	int randblock = 0; // 7���� ������ �����ϰ� ���ڰ� �� ����
	int key = 0; // Ű���� �Էµ� �ƽ�Ű�ڵ� ���� ����
	int xdinate = 4; //������ ����� �ʱ� x ��ǥ;
	int ydinate = 1; //������ ����� �ʱ� y ��ǥ;


	makegameboard(gameboard); // ��Ʈ���� �� ���� (0 : ���� ����, 1 : ���� ����, 2 : �浹 ����)
	printingboard(gameboard); // ��Ʈ���� �� ���
	srand(time(NULL)); // ��Ʈ���� ������ ������ �� ���� ����(7���� ���� ��ȣ)�� ���� �������� �����°��� ����

	randblock = 1;
	makeblockshape(gameboard, &randblock, &xdinate, &ydinate); // �����ϰ� ���� �������� ��Ʈ���� �ǿ� ����

	while (1)
	{
		//randblock = rand() % 7; // 7���� ������ �����ϰ� ���ڰ� ��
		 
		printingboard(gameboard); // ��Ʈ���� �� ���
		if (_kbhit()) // 0 : Ű �Է��� ���� ��, 1 : Ű �Է��� ���� ��
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
		xdinate = 4; // ������ ��� ó���� �ٽ� �ʱ� x��ǥ ����
		ydinate = 1; // ������ ��� ó���� �ٽ� �ʱ� y��ǥ ����	


	}
		return 0;
}

void makegameboard(int board[][12]) // ��Ʈ���� �� ���� (0 : ���� ����, 1 : ���� ����, 2 : �浹 ����)
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

	for (int i = 1; i < X_SIZE - 1; i++) // ���� ���� ���� ����
	{
		board[0][i] = 2;
	}

}

void printingboard(int board[][12]) // ��Ʈ���� �� ���
{
	int k = 5;

	for (int i = 0; i < Y_SIZE; i++)
	{
		gotoxy(10, k);
		for (int j = 0; j < X_SIZE; j++)
		{
			if (board[i][j] == 1)
			{
				printf("��");
			}
			else if (board[i][j] == 3)
			{
				printf("��");
			}
			else if (board[i][j] == 4)
			{
				printf("��");
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

void makeblockshape(int board[][12],int * num, int * xdinate, int * ydinate) // // �����ϰ� ���� �������� ��Ʈ���� �ǿ� ����
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


void gotoxy(int x, int y) // ��ǥ �̵�
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}