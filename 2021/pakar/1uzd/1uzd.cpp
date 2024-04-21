#include<bits/stdc++.h>
using namespace std;

struct diena
{
    int nr;
    int start;
    int finish;
    int time;
    int toys[10];
    int kiek_nul = 0;
    int kiek_toys = 0;
};

void skait(int &n, diena day[])
{
    int val, min;
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> day[i].nr >> val >> min;
        day[i].start = (val*60) + min;
        fin >> val >> min;
        day[i].finish = (val*60) + min;
        for(int j=0; j<5; j++)
        {
            fin >> day[i].toys[j];
        }
    }
}

void laikas(int n, diena day[])
{
    for(int i=0; i<n; i++)
    {
        day[i].time = day[i].finish - day[i].start;
    }
}

void kiek(int n, diena day[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<5; j++)
        {
            day[i].kiek_toys += day[i].toys[j];
            if(day[i].toys[j] == 0)
            {
                day[i].kiek_nul++;
            }
        }
    }
}

int mini(int n, diena day[])
{
    int maz = 100;
    for(int i=0; i<n; i++)
    {
        if(day[i].kiek_nul < maz)
        {
            maz = day[i].kiek_nul;
        }
    }
    return maz;
}

int didi(int n, diena day[], int maz)
{
    int did = 0;
    for(int i=0; i<n; i++)
    {
        if(day[i].kiek_nul == maz)
        {
            if(day[i].kiek_toys > did)
            {
                did =  day[i].kiek_toys;
            }
        }
    }
    return did;
}

int main()
{   
    int n;
    diena day[100];
    skait(n, day);
    laikas(n, day);
    kiek(n, day);
    int maz = mini(n, day);
    int did = didi(n, day, maz);

    ofstream fout("U1rez.txt");
    for(int i=0; i<n; i++)
    {
        if(day[i].kiek_nul == maz && day[i].kiek_toys == did)
        {
            fout << day[i].nr << " " << day[i].time << endl;
        }
    }
    return 0;
}