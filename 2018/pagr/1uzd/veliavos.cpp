#include<iostream>
#include<fstream>
using namespace std;

void skait(int &n, int sp[])
{
    int k;
    char s;
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> s >> k;
        if(s == 'G')
        {
            sp[0] += k;
        }
        if(s == 'Z')
        {
            sp[1] += k;
        }
        if(s == 'R')
        {
            sp[2] += k;
        }
    }
}

int skaic(int sp[])
{
    int mini = 100;
    for(int i=0; i<3; i++)
    {
        if(sp[i] < mini)
        {
            mini = sp[i];
        }
    }
    return mini/2;
}

int main()
{
    int n;
    int sp[31] = {0};
    skait(n, sp);
    int vel = skaic(sp);
    for(int i=0; i<3; i++)
    {
        sp[i] = sp[i] - 2*vel;
    }
    ofstream fout("U1rez.txt");
    fout << vel << endl;
    fout << "G = " << sp[0] << endl;
    fout << "Z = " << sp[1] << endl;
    fout << "R = " << sp[2] << endl;
    return 0;
}