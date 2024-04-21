#include<iostream>
#include<fstream>
using namespace std;

// Apsirasyta struktura, kurioje laikoma vienos dienos info
struct diena
{
    int dienos_nr;
    int ryto_start;
    int ryto_finish;
    int vakaro_start;
    int vakaro_finish;
    int laikas;
    bool yra_nul = false;
};

// Skaitoma is failo, valados ir minutes paverciamos minutemis
void skait(int &n, diena laikai[])
{
    int val, min;
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> laikai[i].dienos_nr >> val >> min;
        laikai[i].ryto_start = (val*60)+min;
        if(laikai[i].ryto_start == 0) laikai[i].yra_nul = true;
        fin >> val >> min;
        laikai[i].ryto_finish = (val*60)+min;
        if(laikai[i].ryto_finish == 0) laikai[i].yra_nul = true;
        fin >> val >> min;
        laikai[i].vakaro_start = (val*60)+min;
        if(laikai[i].vakaro_start == 0) laikai[i].yra_nul = true;
        fin >> val >> min;
        laikai[i].vakaro_finish = (val*60)+min;
        if(laikai[i].vakaro_finish == 0) laikai[i].yra_nul = true;
    }
}

// Laiko, sugaisto begimui, skaiciavimas
void skaic(int n, diena laikai[])
{
    for(int i=0; i<n; i++)
    {
        int rytas = laikai[i].ryto_finish - laikai[i].ryto_start; 
        int vakaras = laikai[i].vakaro_finish - laikai[i].vakaro_start;
        laikai[i].laikas = rytas + vakaras;
    }
}

// Maziausio begimo, kai begama abi dienas, laiko skaiciavimas
int mini(int n, diena laikai[])
{
    int maz = 100; // Maziausias begimo laikas
    // Maizuausio begimo laiko paieska
    for(int i=0; i<n; i++) 
    {
        if(laikai[i].laikas < maz) 
        {
            // Tikrinama ar yra dienu, kada jis ryte ir vakare nebego
            if(laikai[i].yra_nul == 0) 
            {
                maz = laikai[i].laikas;
            }
        }
    }
    return maz;
}

// Rezultatu isvedimas i faila
void rez(int n, int maz, diena laikai[])
{
    cout << "Minimalus laikas" << endl;
    cout << maz << endl;
    cout << "Dienos" << endl;
    for(int i=0; i<n; i++)
    {
        // Tikrinama, ar yra dienu, kada maziausias begimo laikas sutapo
        if(laikai[i].laikas == maz)
        {
            cout << laikai[i].dienos_nr <<" ";
        }
    }
}

// Kintamuju apsirasymas, funkciju saukimas
int main()
{
    int n;
    diena laikai[50];
    skait(n, laikai);
    skaic(n, laikai);
    int maz = mini(n, laikai);
    rez(n, maz, laikai);
    return 0;
}