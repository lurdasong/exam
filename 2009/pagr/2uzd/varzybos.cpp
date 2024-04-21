#include <iostream>
#include <fstream>
using namespace std;

struct zmogus
{
    string name;
    int laikas;
    int grupe;
};

void skait(int &a, int &n, zmogus zm[], int kiek[])
{
    int val, min;
    ifstream fin("U2.txt");
    fin >> n;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        fin >> kiek[i];
        fin >> ws;
        for(int j=0; j<kiek[i]; j++)
        {
            char eil[21];
            fin.get(eil, 21);
            zm[a].name = eil;
            fin >> val;
            fin >> min;
            zm[a].laikas = (val*60)+min;
            zm[a].grupe = i;
            a++;
            fin >> ws;
        }
    }
}

void sorti(int t, zmogus temp[])
{
    for(int i=0; i<t-1; i++)
    {
        for(int j=i+1; j<t; j++)
        {
            if(temp[i].laikas > temp[j].laikas)
            {
                swap(temp[i].laikas, temp[j].laikas);
                swap(temp[i].name, temp[j].name);
            }
        }
    }
}

void rinkimai(int &z, int n, int a, zmogus zm[], int kiek[], zmogus rezz[])
{
    zmogus temp[50];
    for(int i=0; i<n; i++)
    {
        int t = 0;
        for(int j=0; j<a; j++)
        {
            if(zm[j].grupe == i)
            {
                temp[t].name = zm[j].name;
                temp[t].laikas = zm[j].laikas;
                t++;
            }
        }

        sorti(t, temp);
        
        for(int j=0; j<(kiek[i] / 2); j++)
        {
            rezz[z].name = temp[j].name;
            rezz[z].laikas = temp[j].laikas;
            z++;
        }
    }
}

void rez(int z, zmogus rezz[])
{
    ofstream fout("U2rez.txt");
    for(int i=0; i<z; i++)
    {
        fout << rezz[i].name << rezz[i].laikas / 60 << " " << rezz[i].laikas - ((rezz[i].laikas / 60) * 60) << endl;
    }
}

int main()
{
    int n, a=0, z=0;
    zmogus zm[50];
    zmogus rezz[50];
    int kiek[50];

    skait(a, n, zm, kiek);
    rinkimai(z, n, a, zm, kiek, rezz);
    sorti(z, rezz);
    rez(z, rezz);

    return 0;
}