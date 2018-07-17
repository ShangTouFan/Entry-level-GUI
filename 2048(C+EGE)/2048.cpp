#include <graphics.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

void ClearAndPrint(int (*arr)[4])
{
	int i ;
	int j ;
	PIMAGE img = newimage();
	char str[100];
	cleardevice();

	for( i = 0 ; i < 4 ; i++)
	{
		for( j = 0 ; j < 4 ; j++ )	
		{
			sprintf(str,"res\\%d.PNG",arr[i][j]);
			getimage(img,str);
			putimage(j*120+20,i*120+20,img);
		}
	}
}

int ReadKey()
{
	key_msg k = getkey();

      if( k.msg == key_msg_down && k.key == key_up )
	  {
		return 'U' ;
	  }

	  else if( k.msg == key_msg_down && k.key == key_down )
	  {
		return 'D' ;
	  }

	  else if( k.msg == key_msg_down && k.key == key_left )
	  {
		return 'L' ;
	  }

 	  else if( k.msg == key_msg_down && k.key == key_right )
	  {
		return 'R' ;
	  }
}

//void PictureMove( int (*arr)[4],int key,int k,int i,int j,int tmp )
//{
	//char str[100];
	//char str1[100];
	//PIMAGE img = newimage() ;
	//PIMAGE img1 = newimage() ;

	//if(tmp)
	//{
	//	switch(key)
	//	{
	//	case 'D' : 
	//		sprintf(str,"res\\%d.jpg",arr[k][j]);
	//		sprintf(str1,"res\\%d.jpg",arr[k][j]*2);
	//		getimage(img,str);
	//		getimage(img1,str1);
	//		for(  ; k <= i ;k++)
	//		{
	//			ClearAndPrint(arr);
	//			putimage(j*120+20,k*120+20,img);
	//		}
	//		putimage(j*120+20,i*120+20,img1);
	//		break;

	//	case 'U' : 
	//		sprintf(str,"res\\%d.jpg",arr[k][j]);
	//		sprintf(str1,"res\\%d.jpg",arr[k][j]*2);
	//		getimage(img,str);
	//		getimage(img1,str1);
	//		for(  ; k >= i ;k-- )
	//		{
	//			ClearAndPrint(arr);
	//			putimage(j*120+20,k*120+20,img);
	//		}
	//		putimage(j*120+20,i*120+20,img1);
	//		break;

	//	case 'L' : 
	//		sprintf(str,"res\\%d.jpg",arr[i][k]);
	//		sprintf(str1,"res\\%d.jpg",arr[i][k]*2);
	//		getimage(img,str);
	//		getimage(img1,str1);
	//		for(  ; k >= j ; k-- )
	//		{
	//			ClearAndPrint(arr);
	//			putimage(k*120+20,i*120+20,img);
	//		}
	//		putimage(j*120+20,i*120+20,img1);
	//		break;

	//	case 'R' : 
	//		sprintf(str,"res\\%d.jpg",arr[i][k]);
	//		sprintf(str1,"res\\%d.jpg",arr[i][k]*2);
	//		getimage(img,str);
	//		getimage(img1,str1);
	//		for(  ; k <= j ; k++ )
	//		{
	//			ClearAndPrint(arr);
	//			putimage(k*120+20,i*120+20,img);
	//		}
	//		putimage(j*120+20,i*120+20,img1);
	//		break;
	//	}
	//	
	//}

	//else
	//{
	//	switch(key)
	//	{
	//	case 'D':
	//		sprintf(str,"res\\%d.jpg",arr[k][j]);
	//		getimage(img,str);
	//		for(  ; k <= i ; k++ )
	//		{
	//			ClearAndPrint(arr);
	//			putimage(j*120+20,k*120+20,img);
	//		}
	//		putimage(j*120+20,i*120+20,img);
	//		break;

	//	case 'U':
	//		sprintf(str,"res\\%d.jpg",arr[k][j]);
	//		getimage(img,str);
	//		for(  ; k >= i ; k-- )
	//		{
	//			ClearAndPrint(arr);
	//			putimage(j*120+20,k*120+20,img);
	//		}
	//		putimage(j*120+20,i*120+20,img);
	//		break;

	//	case 'L':
	//		sprintf(str,"res\\%d.jpg",arr[i][k]);
	//		getimage(img,str);
	//		for(  ; k >= j ; k-- )
	//		{
	//			ClearAndPrint(arr);
	//			putimage(k*120+20,i*120+20,img);
	//		}
	//		putimage(j*120+20,i*120+20,img);
	//		break;

	//	case 'R':
	//		sprintf(str,"res\\%d.jpg",arr[i][k]);
	//		getimage(img,str);
	//		for(  ; k <= j ; k++ )
	//		{
	//			ClearAndPrint(arr);
	//			putimage(k*120+20,i*120+20,img);
	//		}
	//		putimage(j*120+20,i*120+20,img);
	//		break;
	//	}
	//}
//}

int NumberMove(int (*arr)[4])
{
	int key = ReadKey();
	int i ;
	int j ;
	int k ;
	int Count = 0 ;
	int tmp = 0 ;

	if( key == 'D' )
	{
		for( j = 0 ; j < 4 ; j++ )
		{
			for( i = 3 ; i > 0 ; i -- )
			{
				for( k = i -1 ; k >= 0 ; k-- )
				{
					tmp += arr[k][j];
					if(tmp == arr[i][j] && tmp != 0)
					{
						arr[i][j] *= 2;
						arr[k][j] = 0 ;
						Count++;
						break;
					}

					else if( tmp > arr[i][j] || (tmp != 0 && tmp < arr[i][j]) )
					{
						break ;
					}
				}
				tmp = 0 ;
			}
		}

		for( j = 0 ; j < 4 ; j++ )
		{
			for( i = 3 ; i >= 0 ; i-- )
			{
				if( arr[i][j] == 0 )
				{
					for( k = i - 1 ; k >= 0 ; k-- )
					{
						if( arr[k][j] != 0 )
						{
							arr[i][j] = arr[k][j];
							arr[k][j] = 0 ;
							Count++;
							break ;
						}
					}
				}
			}
		}
	}

	while(kbhit())
	{
		getch();
	}

	if( key == 'U' )
	{
		for( j = 0 ; j < 4 ; j++ )
		{
			for( i = 0 ; i < 3 ; i++ )
			{
				for( k = i +1 ; k < 4 ; k++ )
				{
					tmp += arr[k][j];
					if(tmp == arr[i][j] && tmp != 0)
					{
						arr[i][j] *= 2;
						arr[k][j] = 0 ;
						Count++;
						break;
					}

					else if( tmp > arr[i][j] || (tmp != 0 && tmp < arr[i][j])  )
					{
						break ;
					}
				}
				tmp = 0 ;
			}
		}

		for( j = 0 ; j < 4 ; j++ )
		{
			for( i = 0 ; i < 4 ; i++ )
			{
				if( arr[i][j] == 0 )
				{
					for( k = i + 1 ; k < 4 ; k++ )
					{
						if( arr[k][j] != 0 )
						{
							arr[i][j] = arr[k][j];
							arr[k][j] = 0 ;
							Count++;
							break ;
						}
					}
				}
			}
		}
	}

	while(kbhit())
	{
		getch();
	}

	if( key == 'R' )
	{
		for( i = 0 ; i < 4 ; i++ )
		{
			for( j = 3 ; j > 0 ; j-- )
			{
				for( k = j -1 ; k >= 0 ; k-- )
				{
					tmp += arr[i][k];
					if(tmp == arr[i][j] && tmp != 0)
					{
						arr[i][j] *= 2;
						arr[i][k] = 0 ;
						Count++;
						break;
					}

					else if( tmp > arr[i][j] || (tmp != 0 && tmp < arr[i][j])  )
					{
						break ;
					}
				}
				tmp = 0 ;
			}
		}

		for( i = 0 ; i < 4 ; i++ )
		{
			for( j = 3 ; j >= 0 ; j-- )
			{
				if( arr[i][j] == 0 )
				{
					for( k = j - 1 ; k >= 0 ; k-- )
					{
						if( arr[i][k] != 0 )
						{
							arr[i][j] = arr[i][k];
							arr[i][k] = 0 ;
							Count++;
							break ;
						}
					}
				}
			}
		}
	}

	while(kbhit())
	{
		getch();
	}

	if( key == 'L' )
	{
		for( i = 0 ; i < 4 ; i++ )
		{
			for( j = 0 ; j < 3 ; j++ )
			{
				for( k = j +1 ; k < 4 ; k++ )
				{
					tmp += arr[i][k];
					if(tmp == arr[i][j] && tmp != 0)
					{
						arr[i][j] *= 2;
						arr[i][k] = 0 ;
						Count++;
						break;
					}

					else if( tmp > arr[i][j] || (tmp != 0 && tmp < arr[i][j]) )
					{
						break ;
					}
				}
				tmp = 0 ;
			}
		}

		for( i = 0 ; i < 4 ; i++ )
		{
			for( j = 0 ; j < 4 ; j++ )
			{
				if( arr[i][j] == 0 )
				{
					for( k = j + 1 ; k < 4 ; k++ )
					{
						if( arr[i][k] != 0 )
						{
							arr[i][j] = arr[i][k];
							arr[i][k] = 0 ;
							Count++;
							break ;
						}
					}
				}
			}
		}
	}

	while(kbhit())
	{
		getch();
	}

	return Count ;
}

int Blank_Count( int (*arr)[4] )
{
	int count = 0 ;
	
	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 4 ; j++ )
		{
			arr[i][j] == 0 ? count++ : 1 ;
		}
	} 

	return count ;
}

void RandNum( int (*arr)[4] )
{
	srand(time(NULL));
	PIMAGE img = newimage() ;
	char str[100];

	int n = rand() % Blank_Count( arr ) ;

	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 4 ; j++ )
		{
			if( arr[i][j] == 0 && n-- == 0 )
			{
				arr[i][j] = rand() % 5 ? 2 : 4 ;
				for(int k = 0 ; k < 6 ; delay_fps(50),k++)
				{
					sprintf(str,"res\\%d%d.PNG",arr[i][j],k);
					getimage(img,str);
					putimage(j*120+20,i*120+20,img);
				}
				break ;
			}
		}
	}

}

int Finish2048(int (*arr)[4])
{
	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 4 ; j++ )
		{
			if( arr[i][j] == 2048 )
			{
				return 1 ;
			}
		}
	}

	return 0 ;
}

int Sign_ifOver(int (*arr)[4])
{
	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 3 ; j++ )
		{
			if( arr[i][j] == arr[i][j+1] || arr[j][i] == arr[j+1][i] )
			{
				return 1 ;
			}
		}
	}

	return 0 ;
}

void Start_Game()
{
	PIMAGE img = newimage() ;

	getimage(img,"res\\START.PNG");

	putimage(0,0,img);

	getkey();

	delimage(img);

}

void game_run(int (*arr)[4])
{
	int Count  ;
	int sign = 0 ;
	PIMAGE img = newimage();
	RandNum(arr);

	while(1)
	{
		if( Finish2048(arr) == 1 )
		{
			getimage(img,"res\\WIN.PNG");
			putimage(0,0,img);
			return ;
		}

		while( ( Count = NumberMove(arr) ) == 0 )
		{
			if( (sign = Sign_ifOver(arr)) == 0 && Blank_Count(arr) == 0 )
			{
				getimage(img,"res\\GAMEOVER.PNG");
				putimage(0,0,img);
				return ;
			}
		}
		
		RandNum(arr);
		
		ClearAndPrint(arr);
	}
}

int main(void)
{
	setinitmode(0);
	
	initgraph(500,500);

	setbkcolor(0xD7C16B);

	setrendermode(RENDER_MANUAL);

	Start_Game();
	
	int arr[4][4] = {0};
	ClearAndPrint(arr);

	game_run(arr);

	getch();

	closegraph();

	return 0;
}