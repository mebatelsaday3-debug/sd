#include<iostream>
using namespace std;

struct Vector{
  int* data;
  int capacity;
  int length;
};

void init(Vector& v){
  v.capacity = 2;   
  v.length = 0;
  v.data = new int[v.capacity];
}

void resize(Vector& v, int newCap){
  int * newData = new int[newCap];
  for (int i=0; i< v.length; i++){
    newData[i]=v.data[i];
  }
  delete[] v.data;
  v.data = newData;
  v.capacity=newCap;
}

void push_back(Vector& v, int value) { 
    if (v.length == v.capacity) { 
        resize(v, v.capacity * 2); 
    } 
    v.data[v.length] = value; 
    v.length++; 
}

void pop_front(Vector& v) { 
    if (v.length > 0) {
        for (int i=0; i<v.length-1; i++){
            v.data[i] = v.data[i+1];
        }
        v.length--; 
    } else {
        cout << "Antrian kosong, tidak ada yang bisa dihapus!\n";
    }
} 
 
int get(Vector& v, int index) { 
    if (index >= 0 && index < v.length) { 
        return v.data[index]; 
    } 
    return -1;
} 
void set(Vector& v, int index, int value) { 
    if (index >= 0 && index < v.length) { 
        v.data[index] = value;
    }
} 
 
int size(Vector& v) { 
    return v.length; 
} 

void display(Vector& v){
    if(v.length == 0){
        cout << "Antrian kosong!\n";
        return;
    }
    cout << "Daftar antrian: [";
    for (int i = 0; i < v.length; i++) {
        cout << v.data[i];
        if (i < v.length - 1) cout << ", ";
    } 
    cout << "]\n"; 
}

int main() {
    Vector antrian;
    init(antrian);
    int choice;
    int nomor = 1; 
    bool running = true;

    while(running){
        cout << "\n=== SISTEM ANTRIAN PARKIR ===\n";
        cout << "1. Ambil nomor antrian\n";
        cout << "2. Lihat daftar antrian\n";
        cout << "3. Panggil/Hapus antrian depan\n";
        cout << "4. Cek jumlah antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch(choice){
            case 1:
                push_back(antrian, nomor);
                cout << "Nomor antrian anda: " << nomor << endl;
                nomor++;
                break;
            case 2:
                display(antrian);
                break;
            case 3:
                cout << "Menghapus antrian paling depan...\n";
                pop_front(antrian);
                break;
            case 4:
                cout << "Jumlah antrian sekarang = " << size(antrian) << endl;
                break;
            case 5:
                running = false;
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
    return 0;
}
