#include<bits/stdc++.h>
using namespace std;

struct sk
{
    int desimt[3];
};

void skait(int &n, int &m, sk a[])
{
    ifstream fin("U1.txt");
    fin >> n >> m;
    for(int i=0; i<(n*m); i++)
    {
        for(int j=0; j<3; j++)
        {
            fin >> a[i].desimt[j];
        }
    }
}

void convert(ofstream &fout, int nr)
{
    int x, y;
    x = nr / 16;
    y = nr % 16;
    if(x == 10) fout << 'A';
    else if(x == 11) fout << 'B';
    else if(x == 12) fout << 'C';
    else if(x == 13) fout << 'D';
    else if(x == 14) fout << 'E';
    else if(x == 15) fout << 'F';
    else fout << x;
    if(y == 10) fout << 'A';
    else if(y == 11) fout << 'B';
    else if(y == 12) fout << 'C';
    else if(y == 13) fout << 'D';
    else if(y == 14) fout << 'E';
    else if(y == 15) fout << 'F';
    else fout << y;
}

int main()
{
    int n, m;
    int q=0;
    sk a[100];
    skait(n, m, a);
    ofstream fout("U1rez.txt");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<3; k++)
            {
                convert(fout, a[q].desimt[k]);
            }
            if(j<m-1) fout << ";";
            else fout << endl;
            q++;
        }
    }
    return 0;
}
