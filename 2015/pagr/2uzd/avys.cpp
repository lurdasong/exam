#include<bits/stdc++.h>
using namespace std;

struct avis
{
    string name;
    string code;
    int koef = 0;
};

void skait(int &n, int&m, int &nr, avis avys[])
{
    ifstream fin("U2.txt");
    fin >> n >> m;
    fin >> ws;
    fin >> nr;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        char eil[11];
        fin.get(eil, 11);
        avys[i].name = eil;
        fin >> ws;
        fin >> avys[i].code;
        fin >> ws;
    }
}

void koko(int n, int m, int nr, avis avys[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(avys[nr-1].code[j] == avys[i].code[j])
            {
                avys[i].koef++;
            }
        }
    }
}

void sorti(int n, avis avys[])
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(avys[i].koef < avys[j].koef)
            {
                swap(avys[i].koef, avys[j].koef);
                swap(avys[i].name, avys[j].name);
            }
            else if(avys[i].koef == avys[j].koef)
            {
                if(avys[i].name > avys[j].name)
                {
                    swap(avys[i].koef, avys[j].koef);
                    swap(avys[i].name, avys[j].name);
                }
            }
        }
    }
}

void rezz(int n, avis avys[], string sheep_name)
{
    ofstream fout("U2rez.txt");
    fout << sheep_name << endl;
    for(int i=0; i<n; i++)
    {
        if(avys[i].name != sheep_name)
        {
            fout << avys[i].name << " " << avys[i].koef << endl;
        }
    }
}

int main()
{
    int n, m;
    int nr;
    avis avys[21];
    skait(n, m, nr, avys);
    koko(n, m, nr, avys);
    string sheep_name = avys[nr-1].name;
    sorti(n, avys);
    rezz(n, avys, sheep_name);
    return 0;
}