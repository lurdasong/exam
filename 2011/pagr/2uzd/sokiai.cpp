#include<bits/stdc++.h>
using namespace std;

struct dalyvis
{
    string vardai;
    int tech[100];
    int art[100];
    bool vienodi_tech = false;
    bool vienodi_art = false;
    int rez = 0;
};

void skait(int &n, int &m, dalyvis dal[])
{
    ifstream fin("U2.txt");
    fin >> n >> m;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        char eil[21];
        fin.get(eil, 21);
        dal[i].vardai = eil;
        fin >> ws;
        for(int j=0; j<m; j++)
        {
            fin >> dal[i].tech[j];
        }
        fin >> ws;
        for(int j=0; j<m; j++)
        {
            fin >> dal[i].art[j];
        }
        fin >> ws;
    }
}

int sk(int m, int sar[])
{
    int maz = 11;
    for(int i=0; i<m; i++)
    {
        if(sar[i] < maz)
        {
            maz = sar[i];
        }
    }

    int did = 0;
    for(int i=0; i<m; i++)
    {
        if(sar[i] > maz)
        {
            did = sar[i];
        }
    }
    
    int sum = 0;
    for(int i=0; i<m; i++)
    {
        if(sar[i] != maz && sar[i] != did)
        {
            sum += sar[i];
        }
    }
    return sum;
}

void sorti(int n, dalyvis dal[])
{
    for(int i=0; i<(n-1); i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(dal[i].rez < dal[j].rez)
            {
                swap(dal[i].rez, dal[j].rez);
                swap(dal[i].vardai, dal[j].vardai);
            }
        }
    }
}

int main()
{
    int n, m;
    dalyvis dal[100];
    skait(n, m, dal);
    
    for(int i=0; i<n; i++)
    {
        int kiek1 = 0;
        int kiek2 = 0;
        for(int j=0; j<m; j++)
        {
            if(dal[i].tech[j] == dal[i].tech[0])
            {
                kiek1++;
            }
        }
        if(kiek1 == m)
        {
            for(int j=0; j<(m-2); j++)
            {
                dal[i].rez += dal[i].tech[j];
            }
        }
        else
        {
            dal[i].rez += sk(m, dal[i].tech);
        }


        for(int j=0; j<m; j++)
        {
            if(dal[i].art[j] == dal[i].art[0])
            {
                kiek2++;
            }
        }
        if(kiek2 == m)
        {
            for(int j=0; j<(m-2); j++)
            {
                dal[i].rez += dal[i].art[j];
            }
        }
        else
        {
            dal[i].rez += sk(m, dal[i].art);
        }
        
    }

    sorti(n, dal);

    ofstream fout("U2rez.txt");
    for(int i=0; i<n; i++)
    {
        fout << dal[i].vardai << " " << dal[i].rez << endl;
    }

    
    return 0;
}