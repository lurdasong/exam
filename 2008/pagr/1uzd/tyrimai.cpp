#include <iostream>
#include <fstream>
using namespace std;

void skait(int &n, int kiekt[], int kiekn[])
{
    int nr, x;
    ifstream fin("U1.txt");
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> nr >> x;

        if (x>0)
        {
        kiekt[nr]=kiekt[nr]+x;
        }
        else
        {
        kiekn[nr] = kiekn[nr] + x;
        }
    }
}

int didi(int kiekt[])
{
    int vieta = 0;
    for(int i=0; i<100; i++)
    {
        if(kiekt[i] > kiekt[vieta])
        {
            vieta = i;
        }
    }
    return vieta;
}

int main()
{
    int n;
    int kiekt[100] = {0};
    int kiekn[100] = {0};

    skait(n, kiekt, kiekn);
    int did = didi(kiekt);

    for(int i=0; i<100; i++)
    {
        if(kiekt[i] != 0 || kiekn[i] != 0)
        {
            if(i <= 9)
            {
                cout << "  " << i << "   ";
            }
            else
            {
                cout << " " << i << "   ";
            }
        }
    }
    cout << endl;
    for(int i=0; i<100; i++)
    {
        if(kiekt[i] != 0 || kiekn[i] != 0)
        {
            if(kiekt[i] <= 9)
            {
                cout << "  " << kiekt[i] << "   ";
            }
            else
            {
                cout << " " << kiekt[i] << "   ";
            }
        }
    }
    cout << endl;
    for(int i=0; i<100; i++)
    {
        if(kiekt[i] != 0 || kiekn[i] != 0)
        {
            if(kiekn[i] >= -9)
            {
                cout << kiekn[i] << "    ";
            }
            else if(kiekn[i] == 0)
            {
                cout << "  " << kiekn[i] << "    ";
            }
            else
            {
                cout << kiekn[i] << "    ";
            }
        }
    }
    cout << endl;
    cout << did << endl;

    return 0;
}
