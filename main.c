#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xls.h>

// Maksimal jumlah pasien yang bisa di-load
#define MAX_PASIEN 1000

// Struktur untuk menyimpan data pasien
typedef struct {

} Pasien;

// Deklarasi fungsi-fungsi
void tampilkanMenuUtama();
void tambahDataPasien();
void ubahDataPasien();
void hapusDataPasien();
void cariDataPasien();
void tambahRiwayatMedis();
void ubahRiwayatMedis();
void hapusRiwayatMedis();
void cariRiwayatMedis();
void laporanKeuangan();
void analisisPasienPenyakit();
void informasiKontrolPasien();
int bacaDataPasienDariExcel(Pasien *pasien, int maxPasien, const char *filename);
void tampilkanDataPasien(Pasien *pasien, int jumlahPasien);

int main() {
    int pilihan;
    Pasien pasien[MAX_PASIEN];
    int jumlahPasien;

    // Load data pasien dari file Excel
    jumlahPasien = bacaDataPasienDariExcel(pasien, MAX_PASIEN, "/mnt/data/DataPMC20232024.xlsx");
    if (jumlahPasien < 0) {
        printf("Gagal membaca data pasien dari file Excel.\n");
        return 1;
    }

    while (1) {
        tampilkanMenuUtama();
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahDataPasien();
                break;
            case 2:
                ubahDataPasien();
                break;
            case 3:
                hapusDataPasien();
                break;
            case 4:
                cariDataPasien();
                break;
            case 5:
                tambahRiwayatMedis();
                break;
            case 6:
                ubahRiwayatMedis();
                break;
            case 7:
                hapusRiwayatMedis();
                break;
            case 8:
                cariRiwayatMedis();
                break;
            case 9:
                laporanKeuangan();
                break;
            case 10:
                analisisPasienPenyakit();
                break;
            case 11:
                informasiKontrolPasien();
                break;
            case 12:
                printf("Terima kasih telah menggunakan aplikasi ini.\n");
                exit(0);
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
    return 0;
}

// Fungsi untuk menampilkan menu utama
void tampilkanMenuUtama() {
    printf("=== Sistem Pencatatan Pasien Klinik X ===\n");
    printf("1. Tambah Data Pasien\n");
    printf("2. Ubah Data Pasien\n");
    printf("3. Hapus Data Pasien\n");
    printf("4. Cari Data Pasien\n");
    printf("5. Tambah Riwayat Medis\n");
    printf("6. Ubah Riwayat Medis\n");
    printf("7. Hapus Riwayat Medis\n");
    printf("8. Cari Riwayat Medis\n");
    printf("9. Laporan Keuangan\n");
    printf("10. Analisis Pasien dan Penyakit\n");
    printf("11. Informasi Kontrol Pasien\n");
    printf("12. Keluar\n");
}

// Placeholder functions for other features (need implementation)
void tambahDataPasien() {}
void ubahDataPasien() {}
void hapusDataPasien() {}
void cariDataPasien() {}
void tambahRiwayatMedis() {}
void ubahRiwayatMedis() {}
void hapusRiwayatMedis() {}
void cariRiwayatMedis() {}
void laporanKeuangan() {}
void analisisPasienPenyakit() {}
void informasiKontrolPasien() {}