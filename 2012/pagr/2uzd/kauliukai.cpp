#include <iostream>
#include <fstream>
using namespace std;

struct dievas
{
    string name;
    int met[11];
    int kiek_lyg = 0;
    int kiek_nelyg = 0;
    int taskai = 0;
};

void skait(int &n, int &k, dievas diev[])
{
    ifstream fin("U2.txt");
    fin >> n >> k;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        char eil[11];
        fin.get(eil, 11);
        diev[i].name = eil;
        for(int j=0; j<k; j++)
        {
            fin >> diev[i].met[j];
        }
        fin >> ws;
    }
}

void tasku_skaciavimas(int n, int k, dievas diev[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(diev[i].met[j] % 2 == 0)
            {
                diev[i].taskai += diev[i].met[j];
                diev[i].kiek_lyg++;
            }
            else if(diev[i].met[j] % 2 == 1)
            {
                diev[i].taskai -= diev[i].met[j];
                diev[i].kiek_nelyg++;
            }
        }
    }
}

int valdovas(int n, int k, dievas diev[])
{
    int did = 0;
    int daug_tasku[51];
    int a = 0;
    for(int i=0; i<n; i++)
    {
        if(diev[i].taskai > did)
        {
            did = diev[i].taskai;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(diev[i].taskai == did)
        {
            daug_tasku[a] = i;
            a++;
        }
    }

    int vieta = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<a; j++)
        {
            if(diev[vieta].kiek_lyg < diev[daug_tasku[j]].kiek_lyg)
            {
                vieta = i;
            }
        }
    }
    return vieta;
}

int main()
{
    int n, k;
    dievas diev[51];

    skait(n, k, diev);
    tasku_skaciavimas(n, k, diev);
    int vald = valdovas(n, k, diev);

    ofstream fout("U2rez.txt");
    fout << diev[vald].name << " " << diev[vald].taskai;
    return 0;
}
