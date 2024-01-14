#include <iostream>
#include <conio.h>
#include "graphics.h"
#include <math.h>
#pragma comment(lib,"graphics.lib")

//TODO: Validations of point coordinates
//TODO: Take coordinates of polygon from mouse click

using std::cin;
using std::cout;

void drawline(int x1, int y1, int x2, int y2)
{
	int x, y, H, V;
	int incX = 1;
	int incY = 1;
	int Est, incUP, incDN, i;
	bool reverse = false; 
	H = abs(x2 - x1);
	V = abs(y2 - y1);	
	if (x2 < x1)
	{
		incX = -1; 
	}
	if (y2 < y1)
	{
		incY = -1; 
	}
	if (H < V)
	{
		reverse = true; 
		i = H; 
		H = V; 
		V = i; 
	}
	incUP = 2 * V - 2 * H; 
	incDN = 2 * V; 
	x = x1; 
	y = y1; 
	Est = 2 * V - H; 
	i = 0; 
	while (i < H)
	{
		putpixel(x, y, GREEN); 
		if (Est >= 0)
		{
			Est = Est + incUP;
			x = x + incX; 
			y = y + incY; 
		}
		else
		{
			Est = Est + incDN;
			if (reverse)
			{
				y = y + incY;
			}
			else
			{
				x = x + incX; 
			}
		}
		i++; 
	}
}

void SimpleBoundaryFill_4(int x, int y, int fill_color = YELLOW, int boundary_color = GREEN)
{

	if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color)
	{
		putpixel(x, y, fill_color);
		SimpleBoundaryFill_4(x - 1, y, fill_color, boundary_color);
		SimpleBoundaryFill_4(x + 1, y, fill_color, boundary_color);
		SimpleBoundaryFill_4(x, y + 1, fill_color, boundary_color);
		SimpleBoundaryFill_4(x, y - 1, fill_color, boundary_color);
		//return; 
	}
	//return; 
}
int main()
{

	int gd = DETECT, gm;
	char tr[8] = "C:TCBGI";
	initgraph(&gd, &gm, tr);

	int x1, y1, x2, y2, x3, y3, x4, y4; 

	cout << "Coordinates of the first angle point: ";
	cin >> x1 >> y1; 
	cout << "Coordinates of the second angle point: "; 
	cin >> x2 >> y2; 
	drawline(x1, y1, x2, y2);
	cout << "Coordinates of the third angle point: ";
	cin >> x3 >> y3; 
	drawline(x2, y2, x3, y3);
	cout << "Coordinates of the forth angle point: "; 
	cin >> x4 >> y4; 

	drawline(x1, y1, x2, y2); 
	drawline(x2, y2, x3, y3); 
	drawline(x3, y3, x4, y4); 
	drawline(x4, y4, x1, y1); 
	
	SimpleBoundaryFill_4(x1+2, y1+3);
	delay(1000);
	_getch();
	closegraph();
	return 0;
}
