#include <stdio.h>
#include <graphics.h>
#include <math.h>

void Reverse(char *str)
{
	char *rev = str ;
	char tmp ;

	while( *rev != '\0' )
	{
		rev++ ;
	}

	for( rev-- ; str < rev ; rev-- , str++ )
	{
		tmp = *str ;
		*str = *rev ;
		*rev = tmp ;
	}
}

void Myitoa(char *str,__int64 n,int radix)
{
	char *p = str ;

	char radix_under36[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	while(n)
	{
		*p++ = radix_under36[n%radix] ;
		n /= radix ;
	}

	*p = '\0' ;

	Reverse(str);
}

__int64 Myatoi(char *str,int radix)
{
	char radix_under36[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char *p = str ;
	Reverse(p);
	__int64  n = 0 ;
	int i ;
	int q = 0 ;

	while( *p != '\0' )
	{
		for( i = 0 ; i < 36 ; i++ )
		{
			if( *str >= 'a' && *str <= 'z' )
			{
				*str = *str - 'a' + 'A';	
			}

			if( *p == radix_under36[i] )
			{
				n += i*pow((double)radix,q++) ;
				break;
			}
		}
		p++;
	}

	Reverse(str);

	return n ;
}

void PrintUnder180()
{
	setcolor(0x4A4A4A);
	setfont(20,0,"宋体");

	int i , j , k ;
	char str[100];
	PIMAGE img0 = newimage();
	getimage(img0,"res\\0.PNG");

	for( i = 0,j=0,k= 0 ; j < 35 ; i++,j++ )
	{
		if( i == 7 )
			k++;

		i %= 7 ;
		putimage(i*100+30,k*35+15,img0);
	}

	for( i = 2,j = 0,k = 0; i < 37 ; i++,j++ )
	{
		if( j == 7)
			k++;

		j %= 7 ;
		sprintf(str,"%d进制",i);
		outtextxy(j*100+57,k*35+15,str);
	}
}

void PrintUp300()
{
	setcolor(0x4A4A4A);
	setfont(20,0,"宋体");

	int i , j , k ;
	char str[100];
	PIMAGE img0 = newimage();
	getimage(img0,"res\\0.PNG");

	for( i = 0,j=0,k= 0 ; j < 35 ; i++,j++ )
	{
		if( i == 7 )
			k++;

		i %= 7 ;
		putimage(i*100+30,k*35+305,img0);
	}
	
	for( i = 2,j = 0,k = 0; i < 37 ; i++,j++ )
	{
		if( j == 7)
			k++;

		j %= 7 ;
		sprintf(str,"%d进制",i);
		outtextxy(j*100+57,k*35+305,str);
	}
}

void PrintRectangle()
{
	PIMAGE imgin = newimage();
	getimage(imgin,"res\\INPUT.PNG");
	putimage(26,195,imgin);
}

void PrintResult()
{
	PIMAGE imgout = newimage();
	getimage(imgout,"res\\OUTPUT.PNG");
	putimage(16,480,imgout);
}

void ClearAndPrint()
{
	setcolor(0x4A4A4A);
	setfont(20,0,"宋体");

	int i , j , k ;
	char str[100];
	PIMAGE img0 = newimage();
	PIMAGE img1 = newimage();
	PIMAGE imgin = newimage();
	PIMAGE imgout = newimage();
	PIMAGE imglook = newimage();

	getimage(img0,"res\\0.PNG");
	getimage(img1,"res\\1.PNG");
	getimage(imgin,"res\\INPUT.PNG");
	getimage(imgout,"res\\OUTPUT.PNG");
	getimage(imglook,"res\\LOOKME.PNG");
	putimage(26,195,imgin);
	putimage(16,480,imgout);
	putimage(90,252,imglook);

	for( i = 0,j=0,k= 0 ; j < 35 ; i++,j++ )
	{
		if( i == 7 )
			k++;

		i %= 7 ;
		putimage(i*100+30,k*35+15,img0);
	}

	for( i = 2,j = 0,k = 0; i < 37 ; i++,j++ )
	{
		if( j == 7)
			k++;

		j %= 7 ;
		sprintf(str,"%d进制",i);
		outtextxy(j*100+57,k*35+15,str);
	}


	for( i = 0,j=0,k= 0 ; j < 35 ; i++,j++ )
	{
		if( i == 7 )
			k++;

		i %= 7 ;
		putimage(i*100+30,k*35+305,img0);
	}
	
	for( i = 2,j = 0,k = 0; i < 37 ; i++,j++ )
	{
		if( j == 7)
			k++;

		j %= 7 ;
		sprintf(str,"%d进制",i);
		outtextxy(j*100+57,k*35+305,str);
	}

}

void MainLoop()
{
	int arr[5][7] = {{2,3,4,5,6,7,8},{9,10,11,12,13,14,15},{16,17,18,19,20,21,22},{23,24,25,26,27,28,29},{30,31,32,33,34,35,36}};
	int i_inradix,j_inradix;
	int i_outradix,j_outradix;
	int sign_in = 0 ;
	int sign_out = 0 ;
	int sign_tangle = 0;
	char strtangle[100];
	char result[100];
	PIMAGE img0 = newimage();
	PIMAGE img1 = newimage();
	mouse_msg msg = {0};
	getimage(img0,"res\\0.PNG");
	getimage(img1,"res\\1.PNG");

	putimage(130,50,img1) ;
	sign_in = 1 ;
	i_inradix = 1 ;
	j_inradix = 1 ;


	for ( ; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}

		if( msg.is_down() && msg.y <= 180 && msg.y >=5 && msg.x >=20 && msg.x <= 720 )
		{
			sign_in = 0 ;
			i_inradix = (msg.y-5)/35;
			j_inradix = (msg.x-20)/100;
			PrintUnder180();
			putimage(j_inradix*100+30,i_inradix*35+15,img1);
			sign_in = 1;

			if( sign_in == 1 && sign_out == 1 && sign_tangle == 1 )
			{
				PrintResult();
				__int64  a = Myatoi(strtangle,arr[i_inradix][j_inradix]);
				Myitoa(result,a,arr[i_outradix][j_outradix]);
				outtextxy(111,502,result);
			}
		}

		else if(  msg.is_down() && msg.y <= 475 && msg.y >=300 && msg.x >=20 && msg.x <= 720 )
		{
			sign_out = 0 ;
			i_outradix = (msg.y-300)/35;
			j_outradix = (msg.x-20)/100;
			PrintUp300();
			putimage(j_outradix*100+30,i_outradix*35+305,img1);
			sign_out = 1 ;

			if( sign_in == 1 && sign_out == 1 && sign_tangle == 1 )
			{
				PrintResult();
				__int64  a = Myatoi(strtangle,arr[i_inradix][j_inradix]);
				Myitoa(result,a,arr[i_outradix][j_outradix]);
				outtextxy(111,502,result);
			}
		}

		else if( msg.is_down() && msg.y >= 185 && msg.y <= 240 && msg.x >= 25 && msg.x <= 680 )
		{
			sign_tangle = 0 ;
			inputbox_getline("请输入待转换数字","按回车确认",strtangle,100);
			PrintRectangle();
			outtextxy(107,204,strtangle);
			sign_tangle = 1 ;

			if( sign_in == 1 && sign_out == 1 && sign_tangle == 1 )
			{
				PrintResult();
				__int64  a = Myatoi(strtangle,arr[i_inradix][j_inradix]);
				Myitoa(result,a,arr[i_outradix][j_outradix]);
				outtextxy(111,502,result);
			}
		}
	}
}

int main()
{
	setinitmode(0);

	initgraph(760,570);

	setbkcolor(0xFFFFFF);

	ClearAndPrint();
	MainLoop();

	getch();

	closegraph();
	return 0;
}
