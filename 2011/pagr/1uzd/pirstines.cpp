#include <iostream>
#include <fstream>
using namespace std;

struct pirstine
{
    int lytis;
    int kuriranka;
    int dydis;
    int kiek = 1;
};

void skait(int &n, pirstine pir[])
{
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> pir[i].lytis >> pir[i].kuriranka >> pir[i].dydis;
    }
}

void kiekis(pirstine pir[], pirstine rezz[], int n, int &m)
{
    for(int i=0; i<n; i++)
    {
        int yra = 0;
        for(int j=0; j<m; j++)
        {
            if(pir[i].lytis == rezz[j].lytis)
            {
                if(pir[i].kuriranka == rezz[j].kuriranka)
                {
                    if(pir[i].dydis == rezz[j].dydis)
                    {
                        rezz[j].kiek++;
                        yra = 1;
                    }
                }
            }
        }
        if(yra == 0)
        {
            rezz[m].lytis = pir[i].lytis;
            rezz[m].kuriranka = pir[i].kuriranka;
            rezz[m].dydis = pir[i].dydis;
            m++;
        }
    }
}

int poros(pirstine rezz[], int lytis, int m)
{
    int kiekporu = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=i+1; j<m; j++)
        {
            if(rezz[i].lytis == lytis && rezz[j].lytis == lytis)
            {
                if(rezz[i].dydis == rezz[j].dydis)
                {
                    if(rezz[i].kuriranka != rezz[j].kuriranka)
                    {
                        if(rezz[i].kiek > 0 && rezz[j].kiek > 0)
                        {
                            kiekporu++;
                            rezz[i].kiek--;
                            rezz[j].kiek--;
                        }
                    }
                }
            }
        }
    }
    return kiekporu;
}

int liko(pirstine rezz[], int lytis, int m)
{
    int kiekliko = 0;
    for(int i=0; i<m; i++)
    {
        if(rezz[i].lytis == lytis)
        {
            kiekliko += rezz[i].kiek;
        }
    }
    return kiekliko;
}

int main()
{
    int n;
    int m = 0;
    pirstine pir[100];
    pirstine rezz[100];

    skait(n, pir);
    kiekis(pir, rezz, n, m);

    int kiekporu_m = poros(rezz, 4, m);
    int kiekporu_v = poros(rezz, 3, m);
    int kiekliko_m = liko(rezz, 4, m);
    int kiekliko_v = liko(rezz, 3, m);

    ofstream fout("U1rez.txt");
    fout << kiekporu_m << endl;
    fout << kiekporu_v << endl;
    fout << kiekliko_m << endl;
    fout << kiekliko_v << endl;
    return 0;
}
