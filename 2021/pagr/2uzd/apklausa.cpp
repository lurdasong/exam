#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Draugas
{
    string vardas;
    string dalykas;
    int m; // pazymiu skaicius
    double pazymiai[50]; // pazymiu masyvas
    double vidurkis;
};

struct Populiarumas
{
    string dalykas;
    int kiek_pasirinko = {0};
};

void skait(int &n, Draugas apklausa[])
{
    int k;
    ifstream fin("U2.txt");
    fin >> n; 
    for(int i=0; i<n; i++)
    {
        fin >> apklausa[i].vardas >> apklausa[i].dalykas >> apklausa[i].m;
        for(int j=0; j<apklausa[i].m; j++)
        {
            fin >> apklausa[i].pazymiai[j];
        }
    }
}

void vikurkiu_skaic(int n, Draugas apklausa[])
{
    for(int i=0; i<n; i++)
    {
        int suma = 0;
        for(int j=0; j<apklausa[i].m; j++)
        {
            suma += apklausa[i].pazymiai[j];
        }
        apklausa[i].vidurkis = suma/apklausa[i].m;
    }
}

void bandymas(int n, int &z, Draugas apklausa[], Populiarumas dalykai[])
{
    for(int i=0; i<n; i++)
    {
        if(apklausa[i].vidurkis >= 9)
        {
            int yra = 0;

            for(int j=0; j<z; j++)
            {
                if(apklausa[i].dalykas == dalykai[j].dalykas)
                {
                    dalykai[j].kiek_pasirinko++;
                    yra = 1;
                }
            }

            if(yra == 0)
            {
                dalykai[z].dalykas = apklausa[i].dalykas;
                dalykai[z].kiek_pasirinko = 1;
                z++;
            }
        }
    }
}

void sorti(int n, Populiarumas dalykai[])
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(dalykai[i].kiek_pasirinko < dalykai[j].kiek_pasirinko)
            {
                swap(dalykai[i].kiek_pasirinko, dalykai[j].kiek_pasirinko);
                swap(dalykai[i].dalykas, dalykai[j].dalykas);
            }
            else if(dalykai[i].kiek_pasirinko == dalykai[j].kiek_pasirinko)
            {
                if(dalykai[i].dalykas > dalykai[j].dalykas)
                {
                    swap(dalykai[i].kiek_pasirinko, dalykai[j].kiek_pasirinko);
                    swap(dalykai[i].dalykas, dalykai[j].dalykas);
                }
            }
        }
    }
}

int main()
{
    int n;
    int z=0;
    swap(n, z);
    Draugas apklausa[100];
    Populiarumas dalykai[100];
    skait(n, apklausa);
    vikurkiu_skaic(n, apklausa);
    bandymas(n, z, apklausa, dalykai);
    sorti(n, dalykai);

    ofstream fout("U2rez.txt");
    int yra = 0;
    for(int i=0; i<n; i++)
    {
        if(apklausa[i].vidurkis >= 9)
        {
            yra = 1;
        }
    }
    if(yra == 0)
    {
        fout << "Neatitinka vidurkis" << endl;
    }

    for(int i=0; i<z; i++)
    {
        fout << dalykai[i].dalykas << " " << dalykai[i].kiek_pasirinko << endl;
        for(int j=0; j<n; j++)
        {
            if(apklausa[j].dalykas == dalykai[i].dalykas)
            {
                if(apklausa[j].vidurkis >= 9)
                {
                    fout << apklausa[j].vardas << endl;
                }
            }
        }
    }
    
    return 0;
}
