#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void skait(int &n, int teig[], int neig[], int penki[])
{
    int m, k, p;
    int a = 0;
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> k;
        fin >> m;
        for(int j=0; j<m; j++)
        {
            fin >> p;
            if(p>0)
            {
                teig[k] += p;
                if(j==0)
                {
                    penki[a] = k;
                    a++;
                }
            }
            if(p<0)
            {
                neig[k] += p;
            }
        }
    }
}

void sorti(int penki[])
{
    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            if(penki[i] > penki[j])
            {
                swap(penki[i], penki[j]);
            }
        }
    }
}

int didi(int teig[])
{
    int did = 0;
    for(int i=0; i<100; i++)
    {
        if(teig[i] > did)
        {
            did = teig[i];
        }
    }
    return did;
}

int mazmaz(int neig[])
{
    int maz = 100;
    for(int i=0; i<100; i++)
    {
        if(neig[i] < maz)
        {
            maz = neig[i];
        }
    }
    return maz;
}

int main()
{
    int n;
    int teig[100] = {0};
    int neig[100] = {0};
    int penki[6];

    skait(n, teig, neig, penki);
    sorti(penki);
    int did = didi(teig);
    int maz = mazmaz(neig);

    ofstream fout("U1rez.txt");
    for(int i=0; i<5; i++)
    {
        fout << penki[i] << " ";
    }
    fout << endl;
    for(int i=0; i<100; i++)
    {
        if(teig[i] == did)
        {
            fout << i << " " << did << endl;
        }
    }
    for(int i=0; i<100; i++)
    {
        if(neig[i] == maz)
        {
            fout << i << " " << abs(maz) << endl;
        }
    }
    return 0;
}
