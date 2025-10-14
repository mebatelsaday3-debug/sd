#include <iostream>
#include <string>
using namespace std;

const int MAX = 1005;
string qatm[MAX];
int frontIdx = 0, rearIdx = -1;

bool isEmpty(){
  return frontIdx > rearIdx;}

bool isFull(){
  return rearIdx == MAX - 1;
}

void enqueue(string nama){
  if (isFull())
  {
    cout << "Antrian Penuh!\n";
    return;
  }
  rearIdx++;
  qatm[rearIdx] = nama;
  cout << nama << "  Masuk Antrian ";
}

void dequeue(){
  if (isEmpty())
  {
    cout << "Antrian Kosong, tidak ada yang bisa dipanggil!\n ";
    return;
  }
  cout << qatm[frontIdx] << " sedang dilayani dan keluar dari antrian. \n";
  frontIdx++;
}
void peek(){
  if (isEmpty())
  {
    cout << "Antrian Kosong \n";
    return;
  }
  cout << "nasabah berikutnya : " << qatm[frontIdx] << '\n';
}

void display(){
  if (isEmpty()){
    cout << "Antrian Kosong ! \n";
    return;
  }
  cout << "Daftar Antrian : ";
  for (int i = frontIdx; i <= rearIdx; i++){
    cout << qatm[i] << " , ";
  }
  cout << '\n';
}

int main(){
  int pilih;
  string nama;
  do{
    cout << "\n=== ANTRIAN ATM ===\n 1. Tambah nasabah\n 2. Layani nasabah\n 3. Lihat nasabah berikutnya\n";
    cout << " 4. Tampilkan antrian\n 5. Keluar\n Pilih: ";
    cin >> pilih;
    cin.ignore();

    if (pilih == 1){
      cout << "Masukkan nama nasabah : " ;
      getline(cin, nama);
      enqueue(nama);
    }
    else if (pilih == 2)dequeue();
    else if (pilih == 3)peek();
    else if (pilih == 4)display();

  } while (pilih != 5);

  cout << "Program selesai. \n";
  return 0;

}
