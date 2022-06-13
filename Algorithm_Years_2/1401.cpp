#include <bits/stdc++.h>
using namespace std;


long n, holeX, holeY;
long holeX_mem, holeY_mem, figure_num = 1, square[515][515];

void draw_figure(long num, long x1, long y1, long x2, long y2);
void rec(long x1, long y1, long x2, long y2);
void print(long square[515][515]);


int main()
{

	cin >> n;
	cin >> holeX >> holeY;
	n = 1 << n;
	
	holeX_mem = holeX;
	holeY_mem = holeY;
	rec(1, 1, n, n);
	
	square[holeX_mem][holeY_mem] = 0;

    print(square);
	
		
	return 0;
}

void print(long square[515][515]){
    for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << square[i][j] << " ";
		cout << "\n";
	}
}

void draw_figure(long num, long x1, long y1, long x2, long y2) {
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			if (square[i][j] == 0) square[i][j] = num;
}

void rec(long x1, long y1, long x2, long y2) {
	long rec_num;
	long centerX = x1 + (x2 - x1 + 1) / 2;
	long centerY = y1 + (y2 - y1 + 1) / 2;

	if (x2 - x1 == 1) {
		draw_figure(figure_num++, x1, y1, x2, y2);
		return;
	}


	if (holeX >= centerX) {
		if (holeY >= centerY) {
			rec_num = 1;
			rec(centerX, centerY, x2, y2);
		}
		else {
			rec_num = 2;
			rec(centerX, y1, x2, centerY - 1);
		}
	}
	else {
		if (holeY >= centerY) {
			rec_num = 3;
			rec(x1, centerY, centerX - 1, y2);
		}
		else {
			rec_num = 4;
			rec(x1, y1, centerX - 1, centerY - 1);
		}
	}

	draw_figure(figure_num++, centerX - 1, centerY - 1, centerX, centerY);

	if (rec_num != 1) {
		holeX = centerX;
		holeY = centerY;
		rec(centerX, centerY, x2, y2);
	}
	if (rec_num != 2) {
		holeX = centerX;
		holeY = centerY - 1;
		rec(centerX, y1, x2, centerY - 1);
	}
	if (rec_num != 3) {
		holeX = centerX - 1;
		holeY = centerY;
		rec(x1, centerY, centerX - 1, y2);
	}
	if (rec_num != 4) {
		holeX = centerX - 1;
		holeY = centerY - 1;
		rec(x1, y1, centerX - 1, centerY - 1);
	}

}