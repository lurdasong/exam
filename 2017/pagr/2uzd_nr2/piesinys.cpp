#include<bits/stdc++.h>
using namespace std;

struct piesinys
{
    int x;
    int y;
    int dx;
    int dy; 
    int r, g, b;
};

void skait(int &n, piesinys pies[])
{
    ifstream fin("U2.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> pies[i].x >> pies[i].y >> pies[i].dx >> pies[i].dy;
        fin >> pies[i].r >> pies[i].g >> pies[i].b;
    }
}

void stat(int n, piesinys pies[], int rez[], int &didx, int &didy)
{
    for(int i=0; i<n; i++)
    {
        if(pies[i].dx > didx)
        {
            didx = pies[i].dx;
        }
        if(pies[i].dy > didy)
        {
            didy = pies[i].dy;
        }
    }

    int start;
    int a;
    for(int i=0; i<n; i++)
    {
        start = pies[i].x + (pies[i].y * didx);
        for(int j=0; j<pies[i].dy; j++)
        {
            a = j*didx;
            for(int k=0; k<pies[i].dx; k++)
            {
                rez[start + k + a] = i+1;
            }
        }
    }
}


int main()
{
    int n;
    int didx=0, didy=0;
    piesinys pies[100];
    int rez[50] = {0};

    skait(n, pies);
    stat(n, pies, rez, didx, didy);

    ofstream fout("U2rez.txt");
    fout << didx << " " << didy << endl;
    for(int i=0; i<didx*didy; i++)
    {
        if(rez[i] != 0)
        {
            fout << pies[rez[i]-1].r << " ";
            fout << pies[rez[i]-1].g << " ";
            fout << pies[rez[i]-1].b << endl;
        }
        else 
        {
            fout << 255 << " " << 255 << " " << 255 << endl;
        }
    }
    return 0;
}