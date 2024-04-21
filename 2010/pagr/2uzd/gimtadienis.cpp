#include <iostream>
#include <fstream>
using namespace std;

struct patiekalas
{
    string name;
    int kiek[11];
    int visas = 0;
};

void skait(int &n, int &p, int kainos[], patiekalas piet[])
{
    ifstream fin("U2.txt");
    fin >> n >> p;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        fin >> kainos[i];
    }
    fin >> ws;
    for(int i=0; i<p; i++)
    {
        char eil[16];
        fin.get(eil, 16);
        piet[i].name = eil;
        for(int j=0; j<n; j++)
        {
            fin >> piet[i].kiek[j];
        }
        fin >> ws;
    }
}

void kainos_skaiciavimas(int n, int p, int kainos[], patiekalas piet[])
{
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<n; j++)
        {
            piet[i].visas += piet[i].kiek[j] * kainos[j];
        }
    }
}

int pietu_kaina(int p, patiekalas piet[])
{
    int kaina = 0;
    for(int i=0; i<p; i++)
    {
        kaina += piet[i].visas;
    }
    return kaina;
}

int main()
{
    int n, p;
    int kainos[11];
    patiekalas piet[13];

    skait(n, p, kainos, piet);
    kainos_skaiciavimas(n, p, kainos, piet);
    int kaina = pietu_kaina(p, piet);

    ofstream fout("U2rez.txt");
    for(int i=0; i<p; i++)
    {
        fout << piet[i].name << " " << piet[i].visas << endl;
    }
    fout << kaina / 100 << " " << kaina % 100 << endl;
    return 0;
}
