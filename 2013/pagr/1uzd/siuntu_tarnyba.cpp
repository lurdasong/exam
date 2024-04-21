#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;

struct imone
{
    string pav;
    double x; 
    double y;
};

void skait(int &n, int &m, imone im[])
{
    double a, b;
    ifstream fin("U1.txt");
    fin >> n >> m;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        char eil[11];
        fin.get(eil, 11);
        im[i].pav = eil;
        fin >> a;
        fin >> b;
        im[i].x = a;
        im[i].y = b;
        fin >> ws;
    }
}

int km(int x, int y)
{
    int z = abs(x) + abs(y);
    return 2*z;
}

int main()
{
    int n, m;
    vector<int> index;
    int kiek = 0, a = 0;
    imone im[100];

    skait(n, m, im);
    for(int i=0; i<n; i++)
    {
        kiek += km(im[i].x, im[i].y);
        if(kiek < m)
        {
            index.push_back(i);
        }
    }

    for(int i=0; i<index.size(); i++)
    {
        if(index[i] > a)
        {
            a = index[i];
        }
    }

    int k = 0;
    int s = 0;
    for(int i=0; i<a+1; i++)
    {
        k++;
        s += km(im[i].x, im[i].y);
    }

    ofstream fout("U1rez.txt");
    fout << k << " " << s << " " << im[a].pav << endl;

    return 0;
}