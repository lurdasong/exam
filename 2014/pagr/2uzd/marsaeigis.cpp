#include<bits/stdc++.h>
using namespace std;

struct sekos
{
    int kiek;
    int sek[31];
};

struct result
{
    string kaip;
    vector<int> kmd;
    int kiek = 0;
};

void skait(int &n, int st[], int fn[], sekos s[])
{
    ifstream fin("U2.txt");
    fin >> st[0] >> st[1];
    fin >> fn[0] >> fn[1];
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> s[i].kiek;
        for(int j=0; j<s[i].kiek; j++)
        {
            fin >> s[i].sek[j];
        }
    }
}

void moves(int n, int st[], int fn[], sekos s[], result rez[])
{
    int a = st[0];
    int b = st[1];
    for(int i=0; i<n; i++)
    {
        st[0] = a;
        st[1] = b;
        for(int j=0; j<s[i].kiek; j++)
        {
            if(s[i].sek[j] == 1)
            {
                st[1]++;
            }
            else if(s[i].sek[j] == 2)
            {
                st[0]++;
            }
            else if(s[i].sek[j] == 3)
            {
                st[1]--;
            }
            else if(s[i].sek[j] == 4)
            {
                st[0]--;
            }

            rez[i].kmd.push_back(s[i].sek[j]);
            rez[i].kiek++;

            if(st[0] == fn[0] && st[1] == fn[1])
            {
                rez[i].kaip = "pasiektas tikslas   ";
            }
            else if(rez[i].kiek == s[i].kiek)
            {
                rez[i].kaip = "sekos pabaiga       ";
            }
        }
    }
}

int main()
{
    int st[2];
    int fn[2];
    int n;
    sekos s[11];
    result rez[11];

    skait(n, st, fn, s);
    moves(n, st, fn, s, rez);

    ofstream fout("U2rez.txt");
    for(int i=0; i<n; i++)
    {
        fout << rez[i].kaip << " ";
        for(int j=0; j<rez[i].kiek; j++)
        {
            fout << rez[i].kmd[j] << " ";
        }
        fout << rez[i].kiek << endl;
    }

    return 0;
}