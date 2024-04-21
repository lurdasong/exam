#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Pratimas
{
    string pav;
    int kartai;
};

void skait(int &n, Pratimas prat[])
{
    ifstream fin("U2.txt");
    fin >> n;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        char eil[21];
        fin.get(eil, 21);
        prat[i].pav = eil;
        fin >> prat[i].kartai;
        fin >> ws;
    }
}

void sorti(int k, Pratimas rezz[])
{
    for(int i=0; i<k-1; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            if(rezz[i].kartai < rezz[j].kartai)
            {
                swap(rezz[i].kartai, rezz[j].kartai);
                swap(rezz[i].pav, rezz[j].pav);
            }
            else if(rezz[i].kartai == rezz[j].kartai)
            {
                if(rezz[i].pav > rezz[j].pav)
                {
                    swap(rezz[i].kartai, rezz[j].kartai);
                    swap(rezz[i].pav, rezz[j].pav);
                }
            }
        }
    }
}

int main()
{
    int n;
    Pratimas prat[100];
    Pratimas rezz[100];
    int k=0;
    skait(n, prat);

    for(int i=0; i<n; i++)
    {
        int yra=0;
        for(int j=0; j<k; j++)
        {
            if(prat[i].pav == rezz[j].pav)
            {
                rezz[j].kartai = rezz[j].kartai + prat[i].kartai;
                yra = 1;
            }
        }
        if(yra == 0)
        {
            rezz[k].pav = prat[i].pav;
            rezz[k].kartai = prat[i].kartai;
            k++;
        }
    }

    sorti(k, rezz);
    ofstream fout("U2rez.txt");
    for(int i=0; i<k; i++)
    {
        fout << rezz[i].pav << " " << rezz[i].kartai << endl;
    }
    return 0;
}
