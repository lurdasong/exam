#include<bits/stdc++.h>
using namespace std;

struct logo
{
    int log1 = 0;
    int log2 = 0;
    int log3 = 0;
};

void skait(int &n, logo log[], int dir_log[])
{
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> log[i].log1 >> log[i].log2 >> log[i].log3;
    }
    for(int i=0; i<3; i++)
    {
        fin >> dir_log[i];
    }
}

void kiekis(int log1, int log2, int log3, int rez[])
{
    if(log1 > log2 && log1 > log3)
    {
        rez[0] += 4;
    }
    else if(log1 == log2 && log1 > log3)
    {
        rez[0] += 2;
        rez[1] += 2;
    }
    else if(log1 == log3 && log1 > log2)
    {
        rez[0] += 2;
        rez[2] += 2;
    }
    else if(log2 > log1 && log2 > log3)
    {
        rez[1] += 4;
    }
    else if(log2 == log3 && log2 > log1)
    {
        rez[1] += 2;
        rez[2] += 2;
    }
    else if(log3 > log1 && log3 > log2)
    {
        rez[2] += 4;
    }
}

int main()
{
    int n;
    logo log[11];
    int rez[3] = {0};
    int rez_b[3] = {0};
    int dir_log[3];
    ofstream fout("U1rez.txt");

    skait(n, log, dir_log);
    for(int i=0; i<n; i++)
    {
        rez_b[0] += log[i].log1;
        rez_b[1] += log[i].log2;
        rez_b[2] += log[i].log3;
        kiekis(log[i].log1, log[i].log2, log[i].log3, rez);
    }

    fout << rez_b[0] << " " << rez_b[1] << " " << rez_b[2] << endl;
    fout << rez[0] << " " << rez[1] << " " << rez[2] << endl;

    if(rez[0] == rez[1] || rez[0] == rez[2] || rez[1] == rez[2])
    {
        rez[0] += dir_log[0];
        rez[1] += dir_log[1];
        rez[2] += dir_log[2];
    }

    int laimi = 0;
    for(int i=0; i<3; i++)
    {
        if(rez[i] > rez[laimi])
        {
            laimi = i;
        }
    }
    fout << laimi + 1 << endl;

    return 0;
}

// 0 0 4
// 0 4 0
// 0 2 2
// 4 0 0
// 2 2 0
// 0 4 0

// 6 12 6