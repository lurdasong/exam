#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct timess
{
    string name;
    int h;
    int mi;
    int sec;
    int total;
    int kiek_truko;
};

void skait(int &n, int &m, timess st[], timess fini[])
{
    ifstream fin("U2.txt");
    fin >> n;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        char eil[21];
        fin.get(eil, 21);
        st[i].name = eil;
        fin >> st[i].h >> st[i].mi >> st[i].sec;
        fin >> ws;
    }
    fin >> m;
    fin >> ws;
    for(int i=0; i<m; i++)
    {
        char eil[21];
        fin.get(eil, 21);
        fini[i].name = eil;
        fin >> fini[i].h >> fini[i].mi >> fini[i].sec;
        fin >> ws;
    }
}

void skaic_time(int n, int m, timess st[], timess fini[])
{
    for(int i=0; i<n; i++)
    {
        st[i].total = st[i].h * 3600 + st[i].mi * 60 + st[i].sec;
    }
    for(int i=0; i<m; i++)
    {
        fini[i].total = (fini[i].h * 3600) + (fini[i].mi * 60) + fini[i].sec;
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(fini[i].name == st[j].name)
            {
                fini[i].kiek_truko = fini[i].total - st[j].total;
            }
        }
    }
}

void sorti(int m, timess fini[])
{
    for(int i=0; i<m-1; i++)
    {
        for(int j=i+1; j<m; j++)
        {
            if(fini[i].kiek_truko > fini[j].kiek_truko)
            {
                swap(fini[i].kiek_truko, fini[j].kiek_truko);
                swap(fini[i].name, fini[j].name);
            }
            else if(fini[i].kiek_truko == fini[j].kiek_truko)
            {
                if(fini[i].name > fini[j].name)
                {
                    swap(fini[i].kiek_truko, fini[j].kiek_truko);
                    swap(fini[i].name, fini[j].name);
                }
            }
        }
    }
}

void rez(int m, timess fini[])
{
    ofstream fout("U2rez.txt");
    for(int i=0; i<m; i++)
    {
        fout << fini[i].name << " " << fini[i].kiek_truko / 60 << " " << fini[i].kiek_truko % 60 << endl;
    }
}

int main()
{
    int n, m;
    timess st[31];
    timess fini[31];
    skait(n, m, st, fini);
    skaic_time(n, m, st, fini);
    sorti(m, fini);
    rez(m, fini);
    return 0;
}
