#include "map.h"

//char filename[MAX_PATH];

//bool GetMapFile(HWND hwnd, LPSTR mfilename)//���ļ�
//{
//	OPENFILENAMEA op;
//	char szFilter[] = "�ı��ĵ� (*.txt)\0*.txt\0"
//		"(*.*)\0*.*\0\0";
//
//	*mfilename = 0;
//	memset(&op, 0, sizeof(OPENFILENAMEA));
//	op.lStructSize = sizeof OPENFILENAMEA;
//	op.hwndOwner = hwnd;
//	op.hInstance = NULL;
//	op.lpstrFilter = szFilter;
//	op.nMaxFile = MAX_PATH;
//	op.lpstrDefExt = "txt";
//	op.lpstrFile = mfilename;
//	op.lpstrTitle = "���ҵ����ƽ��Թ��ı��ļ�!";
//	op.Flags = OFN_HIDEREADONLY | OFN_CREATEPROMPT;
//
//	return !!GetOpenFileNameA(&op);
//}

void InitMaze(Mazetype *maze,ma *m_arr)//��ʼ���Թ�
{
	maze->row = ROW ;
	maze->col = COL ;
	maze->map = (int (*)[COL])malloc(sizeof(int)*ROW*COL);
	maze->footprint = (int (*)[COL])malloc(sizeof(int)*ROW*COL);

	if(!maze->map||!maze->footprint)
	{
		xyprintf(50,100,"����ռ�ʧ�ܣ��Թ��޷���ʼ��.\n");
		exit(0);
	}


	memset(maze->footprint,0,ROW*COL*sizeof(int));

	for( int i = 0 ; i < ROW ; i++ )
	{
		for( int j = 0 ; j < COL ; j++ )
		{
			maze->map[i][j] = m_arr->map[i][j];
		}
	}
}

int InitStack(Sqstack *S)//��ʼ��ջ
{
	S->base = (Elem *)malloc(STACK_INIT_SIZE*sizeof(Elem));

	if( !S->base )
	{
		xyprintf(50,50,"��ʼ��ջʧ�ܣ�");
		return 0 ;
	}

	S->top = S->base ;
	S->stacksize = STACK_INIT_SIZE;

	return 1 ;
}

int Pass(Mazetype *maze,Point p)//�жϵ�ǰ·��ͨ��
{
	if(p.x > maze->row || p.y > maze->col )
		xyprintf(50,200,"λ�ó�����Χ");

	if( maze->footprint[p.x][p.y] == 0 && maze->map[p.x][p.y] != 1 )
		return 1;

	else
		return 0 ;
}

int Foot_Mark(Mazetype *maze,Point p)//�߹���·�����ϱ��
{
	if(p.x > maze->row || p.y > maze->col )
	{
		xyprintf(50,300,"���λ�ó�����Χ");
		return 0 ;
	}

	else
	{
		maze->footprint[p.x][p.y] = 1 ;
		return 1 ;
	}
}

Elem NewElem(int n_num,Point n_seat,int n_di)//�����½��
{
	Elem e ;

	e.num = n_num ;
	e.seat = n_seat ;
	e.di = n_di ;

	return e ;
}

int Push(Sqstack *S,Elem e)//���Ԫ�ص�ջ��
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(Elem *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(Elem));

		if(!S->base)
		{
			xyprintf(50,400,"ջ�޷����ݣ�");
			return 0 ;
		}

		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}

    *(S->top)++=e;
	
	return 1 ;
}

Point NextPoint( Point cp,int di )//��һ�������ѡ��
{
	switch(di)
	{
	case 1 : cp.x++ ; break ;
	case 2 : cp.y++ ; break ;
	case 3 : cp.x-- ; break ;
	case 4 : cp.y-- ; break ;
	default : xyprintf(50,500,"λ����Ϣ����");
	}

	return cp ;
}

int DelTop(Sqstack *S,Elem *e)//ɾ��ջ��Ԫ��
{
	if( S->base == S->top )
		return 0 ;

	else
	{
		*e = *(--S->top);
		return 1 ;
	}
}

int EmptyStack(Sqstack *S)//�ж�ջ�Ƿ�Ϊ��
{
	if( S->base == S->top )
		return 1 ;

	else
		return 0 ;
}

int MazePath(Sqstack *S,Mazetype maze,Point start,Point end)//�õ�һ��ͨ��·��
{
	int curstep = 1 ;
	Elem e ;
	Point curpo = start ;
	InitStack(S);

	do{
		if( Pass(&maze,curpo) )
		{
			Foot_Mark(&maze,curpo) ;
			e = NewElem(curstep,curpo,1) ;
			Push(S,e) ;

			if( curpo.x == end.x && curpo.y == end.y )
			{
				return 1 ;
			}
			
			curpo = NextPoint(curpo,1);
			curstep++;
		}

		else
		{
			if( !EmptyStack(S) )
			{
				DelTop(S,&e);

				while( e.di == 4 && !EmptyStack(S) )
				{
					Foot_Mark(&maze,e.seat);
					DelTop(S,&e);
				}

				if( e.di < 4 )
				{
					e.di++;
					Push(S,e);
					curpo =NextPoint(e.seat,e.di);
				}
			}
		}
	}while( !EmptyStack(S) );

	return 0 ;
}

void PrintMaze(Mazetype *maze)//��ʼ���Թ�����
{
	int i ;
	int j ;
	PIMAGE img_ba = newimage();
	PIMAGE img_end = newimage();
	getimage(img_ba,"ba.png");
	getimage(img_end,"end.png");

	
	for( i = 0 ; i < ROW ; i++ )
	{
		for( j = 0 ; j < COL ; j++ )
		{
			if( maze->map[i][j] == 1 )
				putimage(j*40,i*60,img_ba);

			else if( maze->map[i][j] == 3 )
				putimage(j*40,i*60,img_end);
		}
	}
}

void Foot_Print(Mazetype *maze,Sqstack *S)//·����ӡ2
{
	if(S->base == S->top)
	{
		xyprintf(50,550,"ջ�ǿյ�") ;
		return ;
	}

	memset(maze->footprint,0,sizeof(int)*(maze->col)*(maze->row));

	Elem *p = S->base ;
	setfillcolor(0xdbc7a6);

	while( p != S->top )
	{
		bar(p->seat.y*40,p->seat.x*60,(p->seat.y+1)*40,(p->seat.x+1)*60);
		p++;
		Sleep(60);
	}
}

void PrintSqstack(const Sqstack *S,Mazetype *maze)//·����ӡ1
{
	PIMAGE img_start = newimage();
	getimage(img_start,"start.png");

	Elem *p = S->base;

	if(S->base == S->top)
	{
		xyprintf(50,450,"ջΪ��ջ");
		return ;
	}

	while(p != S->top)
	{
		cleardevice();
		PrintMaze(maze);
		putimage(p->seat.y*40,p->seat.x*60,img_start);
		p++;
		Sleep(100);
	}
}

int Map_Rand()//�����
{
	return random(10);
}