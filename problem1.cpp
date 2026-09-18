#include <iostream>

using namespace std;

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

    int astronot[1000];
    bool aktif[1000];

    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
        aktif[i] = true;
    }

    int sisa = N;
    int idx = 0;

    cout << "\n--- Urutan Eliminasi ---" << endl;

    while (sisa > 1) {
        int hitungan = 0;
        
        while (hitungan < K) {
            if (aktif[idx]) {
                hitungan++;
            }
            if (hitungan < K) {
                idx = (idx + 1) % N;
            }
        }

        aktif[idx] = false;
        int nomor_tereliminasi = astronot[idx];
        cout << "Astronot " << nomor_tereliminasi << " dieliminasi." << endl;
        sisa--;

        // Update nilai K sesuai aturan
        if (nomor_tereliminasi % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        if (K < 2) {
            K = 2;
        }

        // Cari astronot aktif berikutnya
        if (sisa > 1) {
            do {
                idx = (idx + 1) % N;
            } while (!aktif[idx]);
        }
    }

    cout << "\n--- Hasil Akhir ---" << endl;
    for (int i = 0; i < N; i++) {
        if (aktif[i]) {
            cout << "Astronot terakhir yang bertahan: " << astronot[i] << endl;
            break;
        }
    }

    return 0;
}
