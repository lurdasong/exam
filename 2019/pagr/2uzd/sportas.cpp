#include<bits/stdc++.h>
using namespace std;

struct zmog
{
    string name;
    int nr;
    int lytis;
    int h;
    int mini;
    int sec;
    int laikas;
    int sov = 0;
};

void skait(int &n, int &m, zmog star[], zmog fn[])
{
    ifstream fin("U2.txt");
    fin >> n;
    fin >> ws;
    for(int i=0; i<n; i++)
    {
        char eil[21];
        fin.get(eil, 21);
        star[i].name = eil;
        fin >> star[i].nr >> star[i].h >> star[i].mini >> star[i].sec;
        fin >> ws;
    }
    fin >> m;
    int k;
    for(int i=0; i<m; i++)
    {
        fin >> fn[i].nr >> fn[i].h >> fn[i].mini >> fn[i].sec;
        fn[i].lytis = fn[i].nr/100;
        if(fn[i].lytis == 1)
        {
            for(int j=0; j<2; j++)
            {
                fin >> k;
                fn[i].sov += k;
            }
        }
        else if(fn[i].lytis == 2)
        {
            for(int j=0; j<4; j++)
            {
                fin >> k;
                fn[i].sov += k;
            }
        }
    }
}

void sorti(int a, zmog sar[])
{
    for(int i=0; i<a-1; i++)
    {
        for(int j=i+1; j<a; j++)
        {
            if(sar[i].laikas > sar[j].laikas)
            {
                swap(sar[i].laikas, sar[j].laikas);
                swap(sar[i].name, sar[j].name);
                swap(sar[i].nr, sar[j].nr);
            }
            else if(sar[i].laikas == sar[j].laikas)
            {
                if(sar[i].name > sar[j].name)
                {
                    swap(sar[i].laikas, sar[j].laikas);
                    swap(sar[i].name, sar[j].name);
                    swap(sar[i].nr, sar[j].nr);
                }
            }
        }
    }
}

void rezz(int g, int b, zmog girls[], zmog boys[])
{
    ofstream fout("U2rez.txt");
    fout << "Merginos" << endl;
    for(int i=0; i<g; i++)
    {
        fout << girls[i].nr << " " << girls[i].name << " ";
        fout << girls[i].laikas/3600 << " " << girls[i].laikas/60 << " " << girls[i].laikas%60 << endl;
    }
    fout << "Vaikinai" << endl;
    for(int i=0; i<b; i++)
    {
        fout << boys[i].nr << " " << boys[i].name << " ";
        fout << boys[i].laikas/3600 << " " << boys[i].laikas/60 << " " << boys[i].laikas%60 << endl;
    }
}

int main()
{
    int n, m;
    int b=0, g=0;
    zmog boys[31];
    zmog girls[31];
    zmog star[31];
    zmog fn[31];
    skait(n, m, star, fn);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(fn[i].nr == star[j].nr)
            {
                int startas = (star[i].h*3600) + (star[i].mini*60) + star[i].sec;
                int finish = (fn[i].h*3600) + (fn[i].mini*60) + fn[i].sec;
                fn[i].laikas = finish - startas;
                fn[i].name = star[j].name;
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        if(fn[i].lytis == 1)
        {
            girls[g] = fn[i];
            g++;
        }
        if(fn[i].lytis == 2)
        {
            boys[b] = fn[i];
            b++;
        }
    }

    for(int i=0; i<g; i++)
    {
        girls[i].laikas += ((10 - girls[i].sov)*60);
    }
    for(int i=0; i<b; i++)
    {
        boys[i].laikas += ((20 - boys[i].sov)*60);
    }

    sorti(g, girls);
    sorti(b, boys);
    rezz(g, b, girls, boys);

    int time1 = (15*3600)+ (50*60) + 10;
    int time2 = (15*3600) + (20*60) + 0;
    int time3 = (time1 - time2) + ((20-12)*60); 
    //cout << time3/3600 << " " << time3/60 << " " << time3%60;
    return 0;
}