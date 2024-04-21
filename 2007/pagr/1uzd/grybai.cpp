#include <iostream>
#include <fstream>
using namespace std;

void skait(int &n, int d[], int b[], int r[], int l[])
{
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> d[i] >> b[i] >> r[i] >> l[i];
    }
}

void nauji(int &a, int n, int d[], int b[], int r[], int l[], int drez[], int brez[], int rrez[], int lrez[])
{
    for(int i=0; i<n; i++)
    {
        int yra = 0;
        for(int j=0; j<a; j++)
        {
            if(d[i] == drez[j])
            {
                brez[j] += b[i];
                rrez[j] += r[i];
                lrez[j] += l[i];
                yra = 1;
            }
        }
        if(yra == 0)
        {
            drez[a] = d[i];
            brez[a] = b[i];
            rrez[a] = r[i];
            lrez[a] = l[i];
            a++;
        }
    }
}

void sorti(int a, int drez[], int brez[], int rrez[], int lrez[])
{
    for(int i=0; i<a-1; i++)
    {
        for(int j=i+1; j<a; j++)
        {
            if(drez[i] > drez[j])
            {
                swap(drez[i], drez[j]);
                swap(brez[i], brez[j]);
                swap(rrez[i], rrez[j]);
                swap(lrez[i], lrez[j]);
            }
        }
    }
}

int didi(int a, int drez[], int brez[], int rrez[], int lrez[], int suma[])
{
    for(int i=0; i<a; i++)
    {
        suma[i] = brez[i] + rrez[i] + lrez[i];
    }
    int vieta = 0;
    for(int i=0; i<a; i++)
    {
        if(suma[i] > suma[vieta])
        {
            vieta = i;
        }
    }
    return vieta;
}

void rez(int a, int drez[], int brez[], int rrez[], int lrez[], int suma[], int did)
{
    ofstream fout("U1rez.txt");
    for(int i=0; i<a; i++)
    {
        fout << drez[i] << " " << brez[i] << " " << rrez[i] << " " << lrez[i] << endl;
    }
    fout << drez[did] << " " << suma[did] << endl;
}

int main()
{
    int n;
    int a = 0;
    int d[101];
    int b[101];
    int r[101];
    int l[101];
    int drez[101] = {0};
    int brez[101] = {0};
    int rrez[101] = {0};
    int lrez[101] = {0};
    int suma[101];

    skait(n, d, b, r, l);
    nauji(a, n, d, b, r, l, drez, brez, rrez, lrez);
    sorti(a, drez, brez, rrez, lrez);
    int did = didi(a, drez, brez, rrez, lrez, suma);
    rez(a, drez, brez, rrez, lrez, suma, did);

    return 0;
}
