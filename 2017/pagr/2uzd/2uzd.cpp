#include<bits/stdc++.h>
using namespace std;

struct figuros
{
    int x;
    int y;
    int dx;
    int dy;
    //int sp[3];
    int bbb;
};

struct spalva
{
   // int sp[300] = {255};
   int aaa;
};

void skait(int &n, figuros a[])
{
    ifstream fin("U2.txt");
    fin >> n; 
    for(int i=0; i<n; i++)
    {
        fin >> a[i].x >> a[i].y >> a[i].dx >> a[i].dy;
        //for(int j=0; j<3; j++)
        //{
        //    fin >> a[i].sp[j];
        //}
        fin >> a[i].bbb;
    }
}

void convert(int sk, figuros a[], spalva piesinys[][100])
{
    for(int i=a[sk].x; i<a[sk].dx; i++)
    {
        for(int j=a[sk].y; j<a[sk].dy; j++)
        {
            piesinys[i][j].aaa = a[sk].bbb;
        }
    }
} 

int main()
{
    int n;
    figuros a[100];
    spalva piesinys[100][100];
    skait(n, a);
    for(int i=0; i<n; i++)
    {
        convert(i, a, piesinys);
    }
    for(int i=0; i<)
    return 0;
}
