#pragma once
#include <graphics.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600
#define STACK_INIT_SIZE 200
#define STACKINCREMENT 10
#define ROW 10
#define COL 20

typedef struct
{
	int (*map)[COL] ;
	int (*footprint)[COL] ;
	int row;
	int col;
}Mazetype;

typedef struct
{
	int x ;
	int y ;
}Point;

typedef struct
{
	int num ;
	Point seat ;
	int di ;
}Elem;

typedef struct
{
	Elem *base ;
	Elem *top ;
	int stacksize ;
}Sqstack;

typedef struct
{
	int (*map)[COL] ;
	Point start ;
	Point end ;
}ma;

void InitMaze(Mazetype *maze,ma *m_arr) ;//初始化迷宫

int InitStack(Sqstack *S);//初始化栈

int Pass(Mazetype *maze,Point p);//判断当前路可通否

int Foot_Mark(Mazetype *maze,Point p);//走过的路径做上标记

Elem NewElem(int n_num,Point n_seat,int n_di);//创建新结点

int Push(Sqstack *S,Elem e);//添加元素到栈顶

Point NextPoint( Point cp,int di );//下一步方向的选择

int DelTop(Sqstack *S,Elem *e);//删除栈顶元素

int EmptyStack(Sqstack *S);//判断栈是否为空

int MazePath(Sqstack *S,Mazetype maze,Point start,Point end);//得到一条通关路径

void PrintMaze(Mazetype *maze);//初始化迷宫界面

void Foot_Print(Mazetype *maze,Sqstack *S);//路径打印2

void PrintSqstack(const Sqstack *S,Mazetype *maze);//路径打印1

int Map_Rand();//随机数


//int (*map_arr[10])[20] = {map1,map2,map3,map4,map5,map6,map7,map8,map9,map10};
