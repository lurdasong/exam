#include<iostream>
#include<fstream>
using namespace std;

struct zmogus
{
    string name;
    int kiek;
    int b = 0;
    int r = 0;
    int l = 0;
    int suma = 0;
};

void skait(int &n, zmogus gryb[])
{
    int a;
    ifstream fin("U2.txt");
    fin >> n;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        char eil[16];
        fin.get(eil, 16);
        gryb[i].name = eil;
        fin >> gryb[i].kiek;
        fin >> ws;
        for(int j=0; j<gryb[i].kiek; j++)
        {
            fin >> a;
            gryb[i].b += a;
            fin >> a;
            gryb[i].r += a;
            fin >> a;
            gryb[i].l += a;
            fin >> ws;
        }
    }
    fin.close();
}

int didi(int n, zmogus gryb[])
{
    for(int i=0; i<n; i++)
    {
        gryb[i].suma = gryb[i].b + gryb[i].r + gryb[i].l;
    }
    int vieta = 0;
    for(int i=0; i<n; i++)
    {
        if(gryb[i].suma > gryb[vieta].suma)
        {
            vieta = i;
        }
    }
    return vieta;
}

void rez(int n, zmogus gryb[], int did)
{
    ofstream fout("U2rez.txt");
    for(int i=0; i<n; i++)
    {
        fout << gryb[i].name << gryb[i].b << " " << gryb[i].r << " " << gryb[i].l << endl;
    }
    fout << gryb[did].name << gryb[did].suma;
    fout.close();
}

int main()
{
    int n;
    zmogus gryb[101];
    skait(n, gryb);
    int did = didi(n, gryb);
    rez(n, gryb, did);
    return 0;
}