#include <iostream>
#include <fstream>
using namespace std;

void skait(int &n, int &m, int g_nom[], int e_nom[], int g_kiek[], int e_kiek[])
{
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> g_nom[i];
    }
    for(int i=0; i<n; i++)
    {
        fin >> g_kiek[i];
    }
    fin >> m;
    for(int i=0; i<m; i++)
    {
        fin >> e_nom[i];
    }
    for(int i=0; i<m; i++)
    {
        fin >> e_kiek[i];
    }
}

void sk(int &a, int n, int naujas_g[], int g_nom[], int g_kiek[], int m, int e_nom[])
{
    int k;
    int visas = 0;
    for(int i=0; i<n; i++)
    {
        visas += g_nom[i] * g_kiek[i];
    }
    for(int i=0; i<m; i++)
    {
        k = visas / e_nom[i];
        visas = visas - (k * e_nom[i]);
        naujas_g[a] = k;
        a++;
    }
}

int suma(int a, int naujas_g[])
{
    int s = 0;
    for(int i=0; i<a; i++)
    {
        s += naujas_g[i];
    }
    return s;
}

int main()
{
    int n, m;
    int a = 0;
    int b = 0;
    int g_nom[51];
    int e_nom[51];
    int g_kiek[51];
    int e_kiek[51];
    int naujas_g[51];
    int naujas_e[51];

    skait(n, m, g_nom, e_nom, g_kiek, e_kiek);
    sk(a, n, naujas_g, g_nom, g_kiek, m, e_nom);
    sk(b, m, naujas_e, e_nom, e_kiek, n, g_nom);
    int sum_g = suma(a, naujas_g);
    int sum_e = suma(b, naujas_e);

    ofstream fout("U1rez.txt");
    for(int i=0; i<a; i++)
    {
        fout << e_nom[i] << " " << naujas_g[i] << endl;
    }
    fout << sum_g << endl;
    for(int i=0; i<b; i++)
    {
        fout << g_nom[i] << " " << naujas_e[i] << endl;
    }
    fout << sum_e << endl;
    return 0;
}