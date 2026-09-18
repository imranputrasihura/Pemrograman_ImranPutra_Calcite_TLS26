#include <iostream>

using namespace std;

int hitungPanjang(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char pesan[1000];
    char pesan_sandi[1000];

    cout << "Masukkan pesan asli (Huruf Kapital Tanpa Spasi): ";
    cin >> pesan;

    int panjang = hitungPanjang(pesan);

    if (panjang > 0) {
        
        pesan_sandi[0] = pesan[0];

        for (int i = 1; i < panjang; i++) {
            int val_curr = pesan[i] - 'A' + 1;     
            int val_prev = pesan[i - 1] - 'A' + 1; 

            int total = (val_curr + val_prev - 1) % 26 + 1;
            pesan_sandi[i] = (char)(total + 'A' - 1);
        }

        pesan_sandi[panjang] = '\0';

        cout << "Hasil Pesan Sandi: " << pesan_sandi << endl;
    }

    return 0;
}
