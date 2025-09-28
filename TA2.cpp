#include <iostream>
using namespace std;

void tukar(int *x, int *y);
void tukarString(string *a, string *b);

int main() {
    int jumlah_penjualan[5];
    string produk[5] = {"half", "modular", "off road", "full face", "openface"};

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan jumlah terjual untuk jenis " << produk[i] << ": ";
        cin >> jumlah_penjualan[i];
    }

    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (jumlah_penjualan[j] < jumlah_penjualan[j + 1]) {
                tukar(&jumlah_penjualan[j], &jumlah_penjualan[j + 1]);
                tukarString(&produk[j], &produk[j + 1]);
            }
        }
    }

    cout << "\nHasil pengurutan helm (terbanyak ke tersedikit):\n";
    for (int i = 0; i < 5; i++) {
        cout << produk[i] << " : " << jumlah_penjualan[i] << endl;
    }

    return 0;
}

void tukar(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void tukarString(string *a, string *b) {
    string temp = *a;
    *a = *b;
    *b = temp;
}
