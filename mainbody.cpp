#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>


using namespace std;

int jumlahmaksimumkursi = 25;

class Datapembeli
{
private:
    string nama;
    char pilihKOLOMkursi;
    int pilihBARISkursi;
public:
    void setKolomkursi(char kk)
    {
        pilihKOLOMkursi = kk;
    }
    char getKolomkursi()
    {
        return pilihKOLOMkursi;
    }

    void setBariskursi(int bk)
    {
        pilihBARISkursi = bk;
    }
    int getBariskursi()
    {
        return pilihBARISkursi;
    }

    void setNama(string n)
    {
        nama = n;
    }
    string getNama()
    {
        return nama;
    }    
};


void layar()
{
    char kolomkursipembeli;
    int bariskursipembeli;
    string kursi[6][6] = {{"X","A","B","C","D","E"},{"1","0","0","0","0","0"},{"2","0","0","0","0","0"},{"3","0","0","0","0","0"},{"4","0","0","0","0","0"},{"5","0","0","0","0","0"}};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << kursi[i][j] << " ";
            if (j == 5)
            {
            cout << "\n";
            }
        }
    }
}

class Film
{
public:
    string film;
void pemilihan()
    {
        int jumlahmaksimumkursi = 25;
        Datapembeli pembeli[jumlahmaksimumkursi];
        string namapembeli;
        char kolomkursipembeli = 'X';
        int bariskursipembeli = 0;
        int baris;
        int kolom;
        int opsi;
        int tampilan;

        menu:
        cout << film << "\n";
        cout << "1. Input\n2. Lihat daftar\n";
        cin >> opsi;
        cin.ignore();

        if (opsi == 1)
        {
            string kursi[6][6] = {{"X","A","B","C","D","E"},{"1","0","0","0","0","0"},{"2","0","0","0","0","0"},{"3","0","0","0","0","0"},{"4","0","0","0","0","0"},{"5","0","0","0","0","0"}};
            for (int j = 0; j < 6; j++)
            {
                cout << setw(25);
                for (int k = 0; k < 6; k++)
                {
                    cout << kursi[j][k] << " ";
                    if (k == 5)
                    {
                    cout << "\n";
                    }
                }
            }

            if (film == "VENOM: Return")
            {
                cout << "\n" << setw(36);
                cout << film << "\n";
            } else if (film == "Spiderman")
            {
                cout << "\n" << setw(34);
                cout << film << "\n";
            }
            
            int i = 0;
            while(i < jumlahmaksimumkursi)
            {
                cout << i+1 << ".";
                cout << "Nama: ";
                getline(cin, namapembeli, '\n');
                pembeli[i].setNama(namapembeli);

                do
                {
                    cout << "Kolom kursi: ";
                    cin >> kolomkursipembeli;
                    kolom = kolomkursipembeli;
                    kolom-=64;
                } while (kolomkursipembeli == !('A'||'B'||'C'||'D'||'E'));

                pembeli[i].setKolomkursi(kolomkursipembeli);

                do
                {
                    cout << "Baris kursi: ";
                    cin >> bariskursipembeli;
                    baris = bariskursipembeli; 
                } while (bariskursipembeli <= 0 || bariskursipembeli > 6);
                
                pembeli[i].setBariskursi(bariskursipembeli);
                cin.get();

                if (kursi[baris][kolom] == "0")
                {
                    cout << "Kursi tersedia";
                    kursi[baris][kolom] = "x";

                    cout << "\n";
                    
                    system("CLS");
                    
                    for (int j = 0; j < 6; j++)
                    {
                        for (int k = 0; k < 6; k++)
                        {
                            cout << kursi[j][k] << " ";
                            if (k == 5)
                            {
                            cout << "\n";
                            }
                        }
                    }

                    cout << "\n";
                    i++;
                    char opsi;
                    
                    do
                    {
                        cout << "Apakah masih akan menginput data(Y/N)?\n";
                        cin >> opsi;
                    } while (!(opsi == 'Y' || opsi == 'N'));
                    
                    if (opsi == 'N')
                    {
                        goto menu;
                    }

                    if (i == 25)
                    {
                        break;
                    }

                    tampilan = i;
                    cin.ignore();
                }else
                    {
                        cout << "Kursi tidak tersedia, mohon pilih kursi lain.\n\n";
                    }
            }
        }else if (opsi == 2)
        {
            tampilan;
            for (int j = 0; j <= tampilan; j++)
            {
                cout << "Kursi: " << pembeli[j].getKolomkursi() << pembeli[j].getBariskursi() << "\n";
                cout << "Nama pembeli: " <<pembeli[j].getNama() << "\n\n";
            }  
        }else
        {
            cout << "Isikan opsi yang benar, program akan berakhir dalam 5 detik.\n";
            for (int i = 5; i >= 1; i--)
            {
                cout << "..." << i;
                Sleep(1000);
            }
            system("CLS");
            terminate;
        }  
    }
};

int main()
{
    cout << "PILIH FILM\n";
    cout << "1. VENOM: Return\n";
    cout << "2. Spiderman\n";
    
    cout << "\nMENU LAIN\n";
    cout << "99. EXIT\n";
    cout << "\nPilih opsi: ";
    
    int pilih;
    cin >> pilih;
    cin.ignore();
    
    system("CLS");
    
    switch (pilih)
    {
    case 1:
        {
        Film no1;
        no1.film = "VENOM: Return";
        no1.pemilihan();
        break;
        }
    case 2:
        {
        Film no2;
        no2.film = "Spiderman";
        no2.pemilihan();
        }
        break;
    case 99:
        {
          terminate;   
        }
    default:
        break;
    }
}
