#include <iostream>
#include <string>
using namespace std;

// Data pengguna
const int MAX_USERS = 5;
string userData[MAX_USERS][3] = {
    {"user1", "pass1", "100000"},
    {"user2", "pass2", "200000"},
    {"user3", "pass3", "300000"},
    {"user4", "pass4", "400000"},
    {"user5", "pass5", "500000"}
};

// Fungsi untuk login dan menampilkan data pengguna
void showUserdata() {
    string inputName, inputPassword;
    bool isAuthenticated = false;
    int attempts = 0; // Counter untuk login gagal

    while (attempts < 3 && !isAuthenticated) {
        cout << "Masukan Nama: ";
        cin >> inputName;

        cout << "Masukan Password: ";
        cin >> inputPassword;

        // Cek data di array userData
        for (int i = 0; i < MAX_USERS; i++) {
            if (userData[i][0] == inputName && userData[i][1] == inputPassword) {
                // Jika cocok, tampilkan nama dan saldo
                cout << "\nLogin berhasil!" << endl;
                cout << "Nama User: " << userData[i][0] << endl;
                cout << "Saldo: Rp" << userData[i][2] << endl;
                isAuthenticated = true;
                break;
            }
        }

        if (!isAuthenticated) {
            attempts++;
            if (attempts < 3) {
                cout << "\nNama atau password salah. Anda memiliki " << (3 - attempts) 
                    << " kesempatan lagi.\n" << endl;
            } else {
                cout << "\nAkun Anda telah diblokir.\n" << endl;
            }
        }
    }
}

int main() {
    // Memanggil fungsi login
    showUserdata();

    return 0;
}
