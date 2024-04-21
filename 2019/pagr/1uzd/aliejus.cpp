#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("U1.txt");
    ofstream fout("U1rez.txt");
    int n1, n3, n5;
    int k;
    int al_kaina;
    int n1_kaina, n3_kaina, n5_kaina;

    fin >> n1 >> n3 >> n5 >> k;
    fin >> al_kaina >>  n1_kaina >> n3_kaina >> n5_kaina;

    

    int kiek_yra = n1*1 + n3*3 + n5*5;
    int kiek_liko = k - kiek_yra;
    
    if(kiek_liko >= 0)
    {
        int reikia_n5 = kiek_liko/5;
        int reikia_n3 = (kiek_liko%5)/3;
        int reikia_n1 = (kiek_liko%5)%3;
        fout << n1 << " " << n3 << " " << n5  << " "  << kiek_liko << endl;
        fout << 0 << " " << 0 << " " << 0 << endl;
        fout << reikia_n1 << " " << reikia_n3 << " " << reikia_n5 << endl;
        int pelnas1 = ((reikia_n5 + n5)*n5_kaina) + ((reikia_n3 + n3)*n3_kaina) + ((reikia_n1 + n1)*n1_kaina);
        int  pelnas = pelnas1 - al_kaina;
        fout << pelnas << endl;
    }
    else if(kiek_liko < 0)
    {
        int kiek_daug = kiek_yra - k;
        int daug_n5 = kiek_daug/5;
        int daug_n3 = (kiek_daug%5)/3;
        int daug_n1 = (kiek_daug%5)%3;
        fout << n1 - daug_n1 << " " << n3 - daug_n3 << " " << n5 - daug_n5 << endl;
        fout << daug_n1 << " " << daug_n3 << " " << daug_n5 << endl;
        fout << 0 << " " << 0 << " " << 0 << endl;
        int pelnas1 = (n1*n1_kaina) + (n3*n3_kaina) + (n5*n5_kaina);
        int  pelnas = pelnas1 - al_kaina;
        fout << pelnas << endl;
    }

    return 0;
}
