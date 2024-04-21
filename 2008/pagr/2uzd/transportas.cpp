#include<iostream>
#include<fstream>
using namespace std;

struct stotele
{
    string name;
    int kiek;
    int nr[100];
};

struct sarasas
{
    int nr;
    int kiek = 1;
};

void skait(int &n, stotele st[])
{
    ifstream fin("U2.txt");
    fin >> n;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        char eil[21];
        fin.get(eil, 21);
        st[i].name = eil;
        fin >> st[i].kiek;
        for(int j=0; j<st[i].kiek; j++)
        {
            fin >> st[i].nr[j];
        }
        fin >> ws;
    }
}

void idk(int &a, int n, sarasas senas[], stotele st[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<st[i].kiek; j++)
        {
            senas[a].nr = st[i].nr[j];
            a++;
        }
    }
}

void naujas(int &m, int a, sarasas senas[], sarasas nw[])
{
    for(int i=0; i<a; i++)
    {
        int yra = 0;
        for(int j=0; j<m; j++)
        {
            if(senas[i].nr == nw[j].nr)
            {
                nw[j].kiek++;
                yra = 1;
            }
        }
        if(yra == 0)
        {
            nw[m].nr = senas[i].nr;
            m++;
        }
    }
}

int didi(int m, sarasas nw[])
{
    int vieta = 0;
    for(int i=0; i<m; i++)
    {
        if(nw[i].kiek > nw[vieta].kiek)
        {
            vieta = i;
        }
    }
    return nw[vieta].nr;
}

void rezz(int n, stotele st[], int did)
{
    ofstream fout("U2rez.txt");
    fout << did << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<st[i].kiek; j++)
        {
            if(did == st[i].nr[j])
            {
                fout << st[i].name << endl;
            }
        }
    }
}

int main()
{
    int n;
    int a = 0;
    int m = 0;
    stotele st[101];
    sarasas nw[101];
    sarasas senas[101];

    skait(n, st);
    idk(a, n, senas, st);
    naujas(m, a, senas, nw);
    int did = didi(m, nw);
    rezz(n, st, did);

    return 0;
}