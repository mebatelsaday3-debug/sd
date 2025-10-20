#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node *left;
    Node *right;
    Node(string n) : nama(n), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, string nama) {
    if (!root)
        return new Node(nama);

    if (nama < root->nama)
        root->left = insertNode(root->left, nama);
    else if (nama > root->nama)
        root->right = insertNode(root->right, nama);
    else
        cout << "Nama sudah terdaftar.\n";

    return root;
}

bool searchNode(Node* root, string nama) {
    if (!root)
        return false;
    if (root->nama == nama)
        return true;
    if (nama < root->nama)
        return searchNode(root->left, nama);
    return searchNode(root->right, nama);
}

void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->nama << "\n";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root)
        return;
    cout << root->nama << "\n";
    preorder(root->left);
    preorder(root->right);
}

string findMin(Node* root) {
    if (!root)
        return "(kosong)";
    while (root->left)
        root = root->left;
    return root->nama;
}

string findMax(Node* root) {
    if (!root)
        return "(kosong)";
    while (root->right)
        root = root->right;
    return root->nama;
}

int countNodes(Node* root) {
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih;
    string nama;

    do {
        cout << "\n=== SISTEM DATA NAMA SISWA (BST) ===\n";
        cout << "1. Tambah nama siswa\n";
        cout << "2. Cari nama siswa\n";
        cout << "3. Tampilkan daftar siswa (urut abjad)\n";
        cout << "4. Tampilkan urutan pendaftaran\n";
        cout << "5. Nama pertama (abjad terkecil)\n";
        cout << "6. Nama terakhir (abjad terbesar)\n";
        cout << "7. Jumlah siswa terdaftar\n";
        cout << "8. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1:
                cout << "Masukkan nama siswa: ";
                getline(cin, nama);
                root = insertNode(root, nama);
                break;
            case 2:
                cout << "Masukkan nama yang ingin dicari: ";
                getline(cin, nama);
                cout << (searchNode(root, nama) ? "Nama ditemukan.\n" : "Nama tidak ditemukan.\n");
                break;
            case 3:
                cout << "\nDaftar nama (urut abjad):\n";
                inorder(root);
                break;
            case 4:
                cout << "\nUrutan pendaftaran:\n";
                preorder(root);
                break;
            case 5:
                cout << "Nama pertama secara abjad: " << findMin(root) << "\n";
                break;
            case 6:
                cout << "Nama terakhir secara abjad: " << findMax(root) << "\n";
                break;
            case 7:
                cout << "Jumlah siswa terdaftar: " << countNodes(root) << "\n";
                break;
        }

    } while (pilih != 8);

    cout << "\nTerima kasih. Program selesai.\n";
    return 0;
}
