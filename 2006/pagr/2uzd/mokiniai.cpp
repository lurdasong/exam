#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct mokinys
{
    string pav;
    int paz[16];
    double vid;
};

void skait(int &n, int &p, double &v, mokinys mok[])
{
    ifstream fin("Duom2.txt");
    fin >> n >> p >> v;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        char eil[21];
        fin.get(eil, 21);
        mok[i].pav = eil;
        for(int j=0; j<p; j++)
        {
            fin >> mok[i].paz[j];
        }
        fin >> ws;
    }
}

double vidurkis(int p, int paz[])
{
    double sum = 0;
    for(int i=0; i<p; i++)
    {
        sum += paz[i];
    }
    return sum / p;
}

int pirmunai(int n, double v, mokinys mok[])
{
    int kiek = 0;
    for(int i=0; i<n; i++)
    {
        if(mok[i].vid >= v)
        {
            kiek++;
        }
    }
    return kiek;
}

int main()
{
    int n, p;
    double v;
    mokinys mok[21];

    skait(n, p, v, mok);
    for(int i=0; i<n; i++)
    {
        mok[i].vid = vidurkis(p, mok[i].paz);
    }
    int kiek = pirmunai(n, v, mok);

    ofstream fout("Rez2.txt");
    for(int i=0; i<n; i++)
    {
        fout << mok[i].pav << fixed << setprecision(1) << mok[i].vid << endl;
    }
    fout << kiek << endl;

    return 0;
}
