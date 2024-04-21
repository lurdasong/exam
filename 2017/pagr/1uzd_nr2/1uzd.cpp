#include<bits/stdc++.h>
using namespace std;

struct sp
{
    int spalvos[100];
};

void skait(int &ilgis, int &plotis, sp sp[])
{
    ifstream fin("U1.txt");
    fin >> ilgis >> plotis;
    for(int i=0; i<(ilgis*plotis); i++)
    {
        for(int j=0; i<3; j++)
        {
            fin >> sp[i].spalvos[j];
        }
    }
}

void convert(int sk)
{
    int x, y;
    x = sk / 16;
    y = sk % 16;
}

int main()
{
    int ilgis, plotis;
    sp sp[100];
    skait(ilgis, plotis, sp);
    return 0;
}