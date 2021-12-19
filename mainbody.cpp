#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h> 
#include <windows.h>


using namespace std;

class Pembeli
{     
  public:           
    char kolom;
    int baris;
    string nama;
};

class Film
{
  public:
    void PengisianFilm()
    {
     int jumlahfilm;
     cin >> jumlahfilm;

     string film[jumlahfilm];
     
     for (int i = 0; i < jumlahfilm; i++)
     {
      cin >> film[i];
     }
     for (int i = 0; i < jumlahfilm; i++)
     {
      cout << film[i];
     }
    }
};


int main()
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
   cout << "Apakah masih mau lanjut(y/n)?\n";
   cin >> opsi;
  } while (!(opsi == 'y' || opsi == 'n'));
 
  if (opsi == 'n')
  {
   lanjut = false;
  }
 }
}
