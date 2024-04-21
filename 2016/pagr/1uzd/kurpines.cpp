#include<bits/stdc++.h>
using namespace std;

int sunk(int &n, int kup)
{
    int big = 0;
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> kup;
        if(kup > big)
        {
            big = kup;
        }
    }
    return big;
}

int kiekis(int n, int kup, int big)
{
    int kiek = 0;
    ifstream fin("U1.txt");
    for(int i=0; i<n; i++)
    {
        fin >> kup;
        if(kup * 2 <= big)
        {
            kiek++;
        }
    }
    return kiek;
}

int main()
{
    int n;
    int kup;
    int big = sunk(n, kup);
    int kiek = kiekis(n, kup, big);
    ofstream fout("U1rez.txt");
    fout << big << " " << kiek-1 << endl;
    return 0;
}