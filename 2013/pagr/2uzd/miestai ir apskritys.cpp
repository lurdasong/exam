#include <iostream>
#include <fstream>
using namespace std;

struct miestas
{
    string city;
    string aps;
    int gyv;
};

struct apskritis
{
    string aps;
    int maz = 5000000;
    int visi;
};

void skait(int &n, miestas m[])
{
    ifstream fin("U2.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> ws;
        char eil[21];
        fin.get(eil, 21);
        m[i].city = eil;
        char eil2[14];
        fin.get(eil2, 14);
        m[i].aps = eil2;
        fin >> m[i].gyv;
    }
}

void naujas(int &k, int n, miestas m[], apskritis a[])
{
    for(int i=0; i<n; i++)
    {
        int yra = 0;
        for(int j=0; j<k; j++)
        {
            if(m[i].aps == a[j].aps)
            {
                a[j].visi += m[i].gyv;
                yra = 1;
                if(m[i].gyv < a[j].maz)
                {
                    a[j].maz = m[i].gyv;
                }
            }
        }
        if(yra == 0)
        {
            a[k].aps = m[i].aps;
            a[k].visi = m[i].gyv;
            k++;
        }
    }
}

void sorti(int k, apskritis a[])
{
    for(int i=0; i<k-1; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            if(a[i].maz > a[j].maz)
            {
                swap(a[i].maz, a[j].maz);
                swap(a[i].visi, a[j].visi);
                swap(a[i].aps, a[j].aps);
            }
            else if(a[i].maz == a[j].maz && a[i].aps > a[j].aps)
            {
                swap(a[i].maz, a[j].maz);
                swap(a[i].visi, a[j].visi);
                swap(a[i].aps, a[j].aps);
            }
        }
    }
}

int main()
{
    int n;
    int k = 0;
    miestas m[104];
    apskritis a[104];

    skait(n, m);
    naujas(k, n, m, a);
    sorti(k, a);

    ofstream fout("U2rez.txt");
    fout << k << endl;
    for(int i=0; i<k; i++)
    {
        fout << a[i].aps << a[i].maz << " " << a[i].visi << endl;
    }
    return 0;
}
