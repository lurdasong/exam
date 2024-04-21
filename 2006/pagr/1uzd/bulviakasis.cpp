#include <iostream>
#include <fstream>
using namespace std;

void skait(int &n, int &m, int uk[])
{
    ifstream fin("Duom1.txt");
    fin >> n >> m;
    for(int i=0; i<n; i++)
    {
        fin >> uk[i];
    }
}

int kiekis(int n, int m, int uk[])
{
    int kiek = 0;
    for(int i=0; i<n; i++)
    {
        kiek += uk[i] / m;
        if(uk[i] % 9 != 0)
        {
            kiek++;
        }
    }
    return kiek;
}

int didi(int n, int uk[])
{
    int vieta = 0;
    for(int i=0; i<n; i++)
    {
        if(uk[i] > uk[vieta])
        {
            vieta = i;
        }
    }
    return vieta;
}

int main()
{
    int n, m;
    int uk[101];

    skait(n, m, uk);
    int kiek = kiekis(n, m, uk);
    int did = didi(n, uk);
    int kartai = uk[did] / m;
    if(uk[did] % 9 != 0)
    {
        kartai++;
    }

    ofstream fout("Rez1.txt");
    fout << kiek << endl;
    fout << uk[did] << " " << kartai << endl;

    return 0;
}


