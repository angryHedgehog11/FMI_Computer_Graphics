#include <iostream>
#include <conio.h>
#include "graphics.h"
#include <math.h>
#pragma comment(lib,"graphics.lib")

using std::cin; 
using std::cout; 

void FourSymmetric(int x, int y, int xc, int yc, int color)
{
	putpixel(xc + x, yc + y, color);
	putpixel(xc - x, yc - y, color);
	putpixel(xc + x, yc - y, color);
	putpixel(xc - x, yc + y, color);

	/*chonky pixels*/
	putpixel(xc + x + 1, yc + y, color);
	putpixel(xc - x + 1, yc - y, color);
	putpixel(xc + x + 1, yc - y, color);
	putpixel(xc - x + 1, yc + y, color);

	putpixel(xc + x, yc + y + 1, color);
	putpixel(xc - x, yc - y + 1, color);
	putpixel(xc + x, yc - y + 1, color);
	putpixel(xc - x, yc + y + 1, color);

	putpixel(xc + x + 1, yc + y + 1, color);
	putpixel(xc - x + 1, yc - y + 1, color);
	putpixel(xc + x + 1, yc - y + 1, color);
	putpixel(xc - x + 1, yc + y + 1, color);

	putpixel(xc + x - 1, yc + y, color);
	putpixel(xc - x - 1, yc - y, color);
	putpixel(xc + x - 1, yc - y, color);
	putpixel(xc - x - 1, yc + y, color);

	putpixel(xc + x, yc + y - 1, color);
	putpixel(xc - x, yc - y - 1, color);
	putpixel(xc + x, yc - y - 1, color);
	putpixel(xc - x, yc + y - 1, color);

	putpixel(xc + x - 1, yc + y - 1, color);
	putpixel(xc - x - 1, yc - y - 1, color);
	putpixel(xc + x - 1, yc - y - 1, color);
	putpixel(xc - x - 1, yc + y - 1, color);


}
void EightSymmetric(int x, int y, int xc, int yc, int color)
{
	FourSymmetric(x, y, xc, yc, color);
	FourSymmetric(y, x, xc, yc, color);
}

void SimpleCircle(int xc, int yc, int R, int color = GREEN)
{
	int x, y; 
	x = 0; 
	y = R; 
	putpixel(xc, yc + R, color);
	putpixel(xc, yc - R, color);
	putpixel(xc + R, yc, color);
	putpixel(xc - R, yc, color);
	while (x < y)
	{
		x++; 
		y = (int)sqrt((double)(R * R - x * x));
		EightSymmetric(x, y, xc, yc, color);
		delay(50);
	}
	if (x == y)
	{
		FourSymmetric(x, y, xc, yc, color);
	}
}

void DrawBresenhamCircle(int xc, int yc, int R, int color = RED)
{
	int x, y, d; 
	x = 0; 
	y = R;
	d = 3 - 2 * R; 
	putpixel(xc, yc + R, color);
	putpixel(xc, yc - R, color);
	putpixel(xc + R, yc, color);
	putpixel(xc - R, yc, color);
	
	while (1)
	{
		if (d > -y)
		{
			y--;
			d = d + (1 - 2 * y);
		}
		if (d <= x)
		{
			x++; 
			d = d + (1 + 2 * x); 
		}
		if (y == 0)
		{
			return; 
		}
		FourSymmetric(x, y, xc, yc, color); 
		delay(50);
	}
	/*
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
		{
			d = d + 4 * x + 6;
		}
		EightSymmetric(x, y, xc, yc, color);
	}*/
}
int main()
{

		int gd = DETECT, gm;
		int R, xc, yc, pk, x, y;
		char tr[8] = "C:TCBGI";
		initgraph(&gd, &gm, tr);
		char answer = 'Y';
		
		while (answer != 'N')
		{
			cout << "Enter the center co-ordinates\n";
			cin >> xc >> yc;
			cout << "Enter the radius of circle\n";
			cin >> R;
			DrawBresenhamCircle(xc, yc, R);
			delay(1000);
			SimpleCircle(xc, yc, R);
			cout << "Want to draw another?\n";
			cin >> answer;
			_getch();
		}
		closegraph();
	return 0; 
}
