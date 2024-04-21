#include<bits/stdc++.h>
using namespace std;

void skait(int prad[], int rez[])
{
    ifstream fin("U1.txt");
    for(int i=0; i<10; i++)
    {
        fin >> prad[i];
    }
}

void dal(int prad[], int rez[])
{
    for(int i=0; i<10; i++)
    {
        rez[i] = prad[i];
    }
    int kiek;
    for(int i=0; i<10; i++)
    {
        kiek = 10 - prad[i];
        for(int j = i+1; j<20; j++)
        {
            if(kiek > 0)
            {
                rez[j]++;
                kiek--;
            }
        }
    }
}

int main()
{
    int prad[11];
    int rez[21] = {0};
    skait(prad, rez);
    dal(prad, rez);
    ofstream fout("U1rez.txt");
    for(int i=0; i<20; i++)
    {
        fout << rez[i] << " ";
    }
    return 0;
}