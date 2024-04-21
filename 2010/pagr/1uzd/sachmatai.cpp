#include <iostream>
#include <fstream>
using namespace std;

void skait(int &n, int fig[])
{
    int x;
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<6; j++)
        {
            fin >> x;
            fig[j] += x;
        }
    }
}

int kiekis(int n, int fig[], int vertes[])
{
    for(int i=0; i<6; i++)
    {
        fig[i] = fig[i] / vertes[i];
    }

    int kiek = 100;
    for(int i=0; i<6; i++)
    {
        if(fig[i] < kiek)
        {
            kiek = fig[i];
        }
    }
    return kiek;
}

int main()
{
    int n;
    int fig[7] = {0};
    int vertes[7] = {8, 2, 2, 2, 1, 1};
    skait(n, fig);
    int kiek = kiekis(n, fig, vertes);
    ofstream fout("U1rez.txt");
    fout << kiek;
    return 0;
}
