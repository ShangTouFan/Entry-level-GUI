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

void InitMaze(Mazetype *maze,ma *m_arr) ;//��ʼ���Թ�

int InitStack(Sqstack *S);//��ʼ��ջ

int Pass(Mazetype *maze,Point p);//�жϵ�ǰ·��ͨ��

int Foot_Mark(Mazetype *maze,Point p);//�߹���·�����ϱ��

Elem NewElem(int n_num,Point n_seat,int n_di);//�����½��

int Push(Sqstack *S,Elem e);//���Ԫ�ص�ջ��

Point NextPoint( Point cp,int di );//��һ�������ѡ��

int DelTop(Sqstack *S,Elem *e);//ɾ��ջ��Ԫ��

int EmptyStack(Sqstack *S);//�ж�ջ�Ƿ�Ϊ��

int MazePath(Sqstack *S,Mazetype maze,Point start,Point end);//�õ�һ��ͨ��·��

void PrintMaze(Mazetype *maze);//��ʼ���Թ�����

void Foot_Print(Mazetype *maze,Sqstack *S);//·����ӡ2

void PrintSqstack(const Sqstack *S,Mazetype *maze);//·����ӡ1

int Map_Rand();//�����


//int (*map_arr[10])[20] = {map1,map2,map3,map4,map5,map6,map7,map8,map9,map10};
