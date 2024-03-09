#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char* argv[])
{
	ifstream fin;
	char ch;
	fin.open(argv[1]);
	for (int i = 0;i < 54;i++)
		fin.get(ch);
	int px[24][24];
	for (int w = 0;w < 24;w++)
	{
		for (int h = 0;h < 24;h++)
		{
			fin.get(ch);
			px[w][h] = ch;
			fin.get(ch);
			fin.get(ch);
		}
	}
	fin.close();
	char wd[72];
	int x = 0;
	for (int w = 0;w < 24;w++)
	{
		int a = 0, b = 0, c = 0, ta = 128, tb = 128, tc = 128;
		for (int h = 0;h < 24;h++)
		{
			if (h >= 0 && h < 8)
			{
				if (px[w][h] == 0)
					a += 1 * ta;
				ta /= 2;
			}
			else if (h >= 8 && h < 16)
			{
				if (px[w][h] == 0)
					b += 1 * tb;
				tb /= 2;
			}
			else if (h >= 16 && h < 24)
			{
				if (px[w][h] == 0)
					c += 1 * tc;
				tc /= 2;
			}
		}
		if (a >= 32 && a <= 126)
		{
			wd[x] = (char)a;
			x++;
		}
		if (b >= 32 && b <= 126)
		{
			wd[x] = (char)b;
			x++;
		}
		if (c >= 32 && c <= 126)
		{
			wd[x] = (char)c;
			x++;
		}
	}
	for (int w = 0;w < x;w++)
		cout << wd[w];
	return 0;
}
