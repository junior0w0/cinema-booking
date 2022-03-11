#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <cctype>

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

class Film
{
public:
    string film;
    string waktu;
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
        int tampilan = 0;
        int terakhir = 0;
        string kursi[6][6] = {{"X","A","B","C","D","E"},{"1","0","0","0","0","0"},{"2","0","0","0","0","0"},{"3","0","0","0","0","0"},{"4","0","0","0","0","0"},{"5","0","0","0","0","0"}};

        menu:
        cout << "Film: " << film << "\n";
        cout << "Waktu tayang: " << waktu << "\n";
        cout << "Kursi tersedia: 25\n\n";
        cout << "1. Input\n2. Lihat daftar\n3. Kembali ke menu\n";
        cin >> opsi;
        system("CLS");
        cin.ignore();

        if (opsi == 1)
        {
            penampilnamafilm();
            
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

            int i = terakhir;
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
                    int tempkolom;
                    tempkolom = toupper(kolomkursipembeli);
                    kolom = tempkolom;
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
                    
                    penampilnamafilm();
                    
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
                    cout << "\n";
                    i++;
                    char opsi;
                    tampilan = i;
                    terakhir = i;

                    do
                    {
                        cout << "Apakah masih akan menginput data(Y/N)?\n";
                        char tempopsi;
                        cin >> tempopsi;
                        opsi = toupper(tempopsi);
                    } while (!(opsi == 'Y' || opsi == 'N'));
                    
                    if (opsi == 'N')
                    {
                        system("CLS");
                        goto menu;
                    }

                    if (i == 25)
                    {
                        break;
                    }
                    
                    cin.ignore();
                }else
                {
                    cout << "Kursi tidak tersedia, mohon pilih kursi lain.\n\n";
                }
            }
        }else if (opsi == 2)
        {
            if (tampilan == 0)
            {
                cout << "Tidak ada data\n";
            }
            else if (tampilan > 0)
            {
                for (int j = 0; j < tampilan; j++)
                {
                cout << "Kursi: " << pembeli[j].getKolomkursi() << pembeli[j].getBariskursi() << "\n";
                cout << "Nama pembeli: " <<pembeli[j].getNama() << "\n\n";
                }
            }
            else
            {
                system("CLS");
                terminate;
            }

            do
            {
                cout << "Apakah masih akan menginput data(Y/N)?\n";
                char tempopsi;
                cin >> tempopsi;
                opsi = toupper(tempopsi);
            } while (!(opsi == 'Y' || opsi == 'N'));
            
            if (opsi == 'Y')
            {
                system("CLS");
                goto menu;
            }
             
        }else if (opsi == 3)
        {
            system("CLS");
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

void penampilnamafilm()
    {
            if (film == "VENOM: Return")
            {
                cout << "\n" << setw(36);
            } else if (film == "Spiderman")
            {
                cout << "\n" << setw(34);
            }

            cout << film << "\n";
            
    }
};

int main()
{
    menu2:
    cout << "FILM\n";
    cout << "1. VENOM: Return\n";
    cout << "2. Spiderman\n";
    
    cout << "\nLAINNYA\n";
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
            no1.waktu = "20.00 - 21.45";
            no1.pemilihan();

            char opsi;
            do
            {
                cout << "Kembali ke menu utama(hal ini akan mereset input film, mengetik 'N' akan mengakhiri program)?(Y/N)?\n";
                char tempopsi;
                cin >> tempopsi;
                opsi = toupper(tempopsi);
            } while (!(opsi == 'Y' || opsi == 'N'));
            if (opsi == 'Y')
            {
                system("CLS");
                goto menu2;
            } else
            {
                system("CLS");
                break;
            }
        }
    case 2:
        {
            Film no2;
            no2.film = "Spiderman";
            no2.waktu = "12.00 - 14.00";
            no2.pemilihan();

            char opsi;
            do
            {
                cout << "Kembali ke menu utama(hal ini akan mereset input film, mengetik 'N' akan mengakhiri program)?(Y/N)?\n";
                char tempopsi;
                cin >> tempopsi;
                opsi = toupper(tempopsi);
            } while (!(opsi == 'Y' || opsi == 'N'));
            if (opsi == 'Y')
            {
                system("CLS");
                goto menu2;
            } else
            {
                system("CLS");
                break;
            }
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

// 愛を込めて4人のグループによって作成されました。 私は下手ですよ、まだまだ勉強します。難しいけど、私たちが頑張ろう！ꦥꦏ꧀ꦩꦗꦶꦢ꧀꧈​ꦏꦸꦭꦺꦴ​ꦉꦩꦼꦤ꧀ꦏꦭꦶꦪꦤ꧀ꦥꦚ꧀ꦗꦼꦤꦼꦔꦤ꧀꧉​
