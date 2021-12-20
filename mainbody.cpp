#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h> 
#include <windows.h>
#include <array>
#include <vector>

using namespace std;

class Film
{
  public:
  void PengisianFilm()
  { 
      int nomorfilmterakhir;
      int jumlahfilm;
      cout << "Isikan jumlah film: ";
      cin >> jumlahfilm;

      string film[jumlahfilm];
      int kuotafilm[jumlahfilm];
      string waktufilmmulai[jumlahfilm];
      string waktufilmselesai[jumlahfilm];

      if (nomorfilmterakhir != 0)
      {
        for (int i = nomorfilmterakhir+1; i < (jumlahfilm + nomorfilmterakhir); i++)
        {
          cout << "Isikan nama film no-" << i+1 << "\n";
          cin >> film[i];
          cout << "Kuota: ";
          cin >> kuotafilm[i];
          cout << "Waktu mulai: ";
          cin >> waktufilmmulai[i];
          cout << "Waktu selesai: ";
          cin >> waktufilmselesai[i];
        }
      } else
        {
          for (int i = 0; i < jumlahfilm; i++)
          {
              cout << "Isikan nama film no-" << i+1 << "\n";
              cin >> film[i];
              cout << "Kuota: ";
              cin >> kuotafilm[i];
              cout << "Waktu mulai: ";
              cin >> waktufilmmulai[i];
              cout << "Waktu selesai: ";
              cin >> waktufilmselesai[i];
          }        
        }

      cout << "Film tersedia:\n";
      for (int i = 0; i < jumlahfilm; i++)
      {
          cout << i+1 << ". " << film[i] << "\nJumlah kursi tersedia: " << kuotafilm[i] << "\nWaktu tayang: " << waktufilmmulai[i] << " sampai " << waktufilmselesai[i] << "\n";
      }
      int nomorfilmterakhir = sizeof(film)/sizeof(film[0]);

  }
};

class Pembeli
{     
  public:           
    char kolom;
    int baris;
    string nama;
  void PengisianDataPembeli()
  {
    //deklarasi vektor
    vector<Pembeli> IdentitasPembeli;
        bool lanjut = true;
    while (lanjut)
    {
      //Memanggil class
      Pembeli Pembeli1;
      cout << "Masukkan kolom: \n";
      cin >> Pembeli1.kolom;
      cout << "Masukkan baris: \n";
      cin >> Pembeli1.baris;
      cout << "Masukkan nama: \n";
      cin >> Pembeli1.nama;

      

    //Menambah variabel
      cout << "\nKursi: " << Pembeli1.kolom << Pembeli1.baris << "\nNama: " << Pembeli1.nama << endl;

    
    
    cout << "Tekan ENTER untuk melanjutkan";
    getch();
    system("CLS");
      
      IdentitasPembeli.push_back(Pembeli1);
      
      //Apakah mau lanjut atau tidak
      char opsi;
      do
      {
      cout << "Apakah masih akan menginput data(y/n)?\n";
      cin >> opsi;
      } while (!(opsi == 'y' || opsi == 'n'));
    
      if (opsi == 'n')
      {
      lanjut = false;
      }
    }
  }
};


int main()
{
 
}

