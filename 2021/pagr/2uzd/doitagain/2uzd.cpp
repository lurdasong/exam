#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct mokinys
{
    string vardas;
    string dalykas;
    int m;
    double pazymiai[50];
    double vidurkis;
};

struct sarasas
{
    string dalykas;
    int kiek_pasirinko;
};

void skait(int &n, mokinys mok[])
{
    ifstream fin("U2.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> mok[i].vardas >> mok[i].dalykas >> mok[i].m;
        for(int j=0; j<mok[i].m; j++)
        {
            fin >> mok[i].pazymiai[j];
        }
    }
}

void vidurkis(int n, mokinys mok[])
{
    for(int i=0; i<n; i++)
    {
        int suma = 0;
        for(int j=0; j<mok[i].m; j++)
        {
            suma += mok[i].pazymiai[j];
        }
        mok[i].vidurkis = suma / mok[i].m;
    }
}

void skaic(int n, int &z, mokinys mok[], sarasas sar[])
{
    for(int i=0; i<n; i++)
    {
        if(mok[i].vidurkis >= 9)
        {
            int yra = 0;
            for(int j=0; j<z; j++)
            {
                if(mok[i].dalykas == sar[j].dalykas)
                {
                    sar[j].kiek_pasirinko++;
                    yra = 1;
                }
            }
            if(yra == 0)
            {
                sar[z].dalykas = mok[i].dalykas;
                sar[z].kiek_pasirinko = 1;
                z++;
            }
        }
    }
}

void sorti(int n, sarasas sar[])
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(sar[i].kiek_pasirinko < sar[j].kiek_pasirinko)
            {
                swap(sar[i].kiek_pasirinko, sar[j].kiek_pasirinko);
                swap(sar[i].dalykas, sar[j].dalykas);
            }
            else if(sar[i].kiek_pasirinko == sar[j].kiek_pasirinko)
            {
                if(sar[i].dalykas > sar[j].dalykas)
                {
                    swap(sar[i].kiek_pasirinko, sar[j].kiek_pasirinko);
                    swap(sar[i].dalykas, sar[j].dalykas);
                }
            }
        }
    }
}

int main()
{
    int n;
    int z = 0;
    mokinys mok[100];
    sarasas sar[100];
    skait(n, mok);
    vidurkis(n, mok);
    skaic(n, z, mok, sar);
    sorti(n, sar);

    ofstream fout("U2rez.txt");
    int yra = 0;
    for(int i=0; i<n; i++)
    {
        if(mok[i].vidurkis >= 9)
        {
            yra = 1;
        }
    }
    if(yra == 0)
    {
        fout << "Neatitinka vidurkiai" << endl;
    }
    for(int i=0; i<z; i++)
    {
        fout << sar[i].dalykas << " " << sar[i].kiek_pasirinko << endl;
        for(int j=0; j<n; j++)
        {
            if(mok[j].vidurkis >= 9)
            {
                if(mok[j].dalykas == sar[i].dalykas)
                {
                    fout << mok[j].vardas << endl;
                }
            }
        }
    }
    return 0;
}