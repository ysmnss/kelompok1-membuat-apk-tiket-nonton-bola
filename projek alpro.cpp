#include <iostream>
#include <iomanip>

using namespace std;

const int JUMLAH_KURSI = 50; 
bool kursiTerisi[JUMLAH_KURSI] = {false}; 

const double HARGA_VIP_UTARA = 100000.0;
const double HARGA_TIMUR = 40000.0;
const double HARGA_BARAT = 50000.0;
const double HARGA_VIP_SELATAN = 100000.0;


double hitungBiayaTiket(int tribun, int jumlahTiket);

int main() {
  
  cout << "Selamat datang di Pemesanan Tiket Nonton Bola" << endl;
  cout << "Harga tiket per kursi:" << endl;

  
  cout << "Pilihan Tribun:\n";
  cout << "1. VIP Utara\n";
  cout << "2. Timur\n";
  cout << "3. Barat\n";
  cout << "4. VIP Selatan\n";

  int tribun;
  cout << "Masukkan nomor tribun yang dipilih: ";
  cin >> tribun;

  int jumlahTiket;
  cout << "Masukkan jumlah tiket yang ingin dipesan: ";
  cin >> jumlahTiket;

  
  if (jumlahTiket > 0 && jumlahTiket <= JUMLAH_KURSI) {
    
    cout << "Kursi yang tersedia: ";
    for (int i = 0; i < JUMLAH_KURSI; ++i) {
      if (!kursiTerisi[i]) {
        cout << i + 1 << " ";
      }
    }

    cout << endl;

    
    int nomorKursi;
    cout << "Masukkan nomor kursi yang ingin dipesan: ";
    cin >> nomorKursi;

    
    if (nomorKursi >= 1 && nomorKursi <= JUMLAH_KURSI && !kursiTerisi[nomorKursi - 1]) {
      
      kursiTerisi[nomorKursi - 1] = true;

      
      double totalBiaya = hitungBiayaTiket(tribun, jumlahTiket);

      
      cout << "\n--- Struk Pembayaran ---" << endl;
      cout << "Jumlah Tiket: " << jumlahTiket << endl;
      cout << "Nomor Kursi: " << nomorKursi << endl;
      cout << fixed << setprecision(2);
      cout << "Total Biaya: Rp" << totalBiaya << endl;
    } else {
      cout << "Nomor kursi tidak valid atau sudah terisi. Pembelian dibatalkan." << endl;
    }
  } else {
    cout << "Jumlah tiket tidak valid. Pembelian dibatalkan." << endl;
  }

  
  cout << endl;
  cout << "Jumlah tiket yang tersisa: " << JUMLAH_KURSI - jumlahTiket << endl;
  cout << "Tribun yang tersisa: ";
  for (int i = 0; i < JUMLAH_KURSI; ++i) {
    if (!kursiTerisi[i]) {
      cout << i + 1 << " ";
    }
  }

  return 0;
}


double hitungBiayaTiket(int tribun, int jumlahTiket) {
  double hargaTiket = 0.0;

  switch (tribun) {
    case 1:
      hargaTiket = HARGA_VIP_UTARA;
      break;
    case 2:
      hargaTiket = HARGA_TIMUR;
      break;
    case 3:
      hargaTiket = HARGA_BARAT;
      break;
    case 4:
      hargaTiket = HARGA_VIP_SELATAN;
      break;
    default:
      break;
  }

  return jumlahTiket * hargaTiket;
}
