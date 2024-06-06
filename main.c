#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maksimal jumlah pasien yang bisa di-load
#define MAX_PASIEN 1000

// Struktur untuk menyimpan data pasien
typedef struct {
    int No;
    char Nama_Lengkap[50];
    char Alamat[100];
    char Kota[50];
    char Tempat_Lahir[50];
    char Tanggal_Lahir[30];
    int Umur;
    long long No_BPJS;
    char ID_Pasien[20];
} Data_Pasien;

// Struktur untuk menyimpan riwayat medis pasien
typedef struct {
    int No;
    char Tanggal[20];
    char ID_Pasien[20];
    char Diagnosis[50];
    char Tindakan[50];
    char Kontrol[20];
    double Biaya;
} Riwayat_Medis_Pasien;

// Struktur untuk menyimpan rincian biaya tindakan
typedef struct {
    int No;
    char Aktivitas[50];
    double Biaya;
} Biaya_Tindakan;

// Deklarasi fungsi-fungsi
Data_Pasien* readDataPasien(const char* filename, int* count);
Riwayat_Medis_Pasien* readRiwayatMedis(const char* filename, int* count);
Biaya_Tindakan* readBiayaTindakan(const char* filename, int* count);
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
int bacaDataPasienDariExcel(Data_Pasien *pasien, int maxPasien, const char *filename);
void tampilkanDataPasien(Data_Pasien *pasien, int jumlahPasien);

int main() {
    int pilihan;
    Data_Pasien pasien[MAX_PASIEN];
    int jumlahPasien;

    // Load data pasien dari file CSV
    int count;
    Data_Pasien* dataPasien = readDataPasien("Data Pasien.csv", &count);
    Riwayat_Medis_Pasien* riwayatMedis = readRiwayatMedis("Riwayat Medis Pasien.csv", &count);
    Biaya_Tindakan* biayaTindakan = readBiayaTindakan("Biaya Tindakan.csv", &count);

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

// Fungsi untuk membaca file CSV "Data Pasien.csv"
Data_Pasien* readDataPasien(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    Data_Pasien* dataPasien = (Data_Pasien*)malloc(sizeof(Data_Pasien) * 100); // allocate memory for 100 records
    *count = 0;

    char line[1024];
    fgets(line, 1024, file); // skip header
    while (fgets(line, 1024, file)) {
        char* token = strtok(line, ";");
        Data_Pasien pasien;
        pasien.No = atoi(token);
        token = strtok(NULL, ";");
        strcpy(pasien.Nama_Lengkap, token);
        token = strtok(NULL, ";");
        strcpy(pasien.Alamat, token);
        token = strtok(NULL, ";");
        strcpy(pasien.Kota, token);
        token = strtok(NULL, ";");
        strcpy(pasien.Tempat_Lahir, token);
        token = strtok(NULL, ";");
        strcpy(pasien.Tanggal_Lahir, token);
        token = strtok(NULL, ";");
        pasien.Umur = atoi(token);
        token = strtok(NULL, ";");
        pasien.No_BPJS = atoll(token);
        token = strtok(NULL, "\n");
        strcpy(pasien.ID_Pasien, token);

        dataPasien[(*count)++] = pasien;
    }

    fclose(file);
    return dataPasien;
}

// Fungsi untuk membaca file CSV "Riwayat Medis Pasien.csv"
Riwayat_Medis_Pasien* readRiwayatMedis(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    Riwayat_Medis_Pasien* riwayatMedis = (Riwayat_Medis_Pasien*)malloc(sizeof(Riwayat_Medis_Pasien) * 100); // allocate memory for 100 records
    *count = 0;

    char line[1024];
    fgets(line, 1024, file); // skip header
    while (fgets(line, 1024, file)) {
        char* token = strtok(line, ";");
        Riwayat_Medis_Pasien riwayat;
        riwayat.No = atoi(token);
        token = strtok(NULL, ";");
        strcpy(riwayat.Tanggal, token);
        token = strtok(NULL, ";");
        strcpy(riwayat.ID_Pasien, token);
        token = strtok(NULL, ";");
        strcpy(riwayat.Diagnosis, token);
        token = strtok(NULL, ";");
        strcpy(riwayat.Tindakan, token);
        token = strtok(NULL, ";");
        strcpy(riwayat.Kontrol, token);
        token = strtok(NULL, "\n");
        riwayat.Biaya = atof(token);

        riwayatMedis[(*count)++] = riwayat;
    }

    fclose(file);
    return riwayatMedis;
}

// Fungsi untuk membaca file CSV "Biaya Tindakan.csv"
Biaya_Tindakan* readBiayaTindakan(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    Biaya_Tindakan* biayaTindakan = (Biaya_Tindakan*)malloc(sizeof(Biaya_Tindakan) * 100); // allocate memory for 100 records
    *count = 0;

    char line[1024];
    fgets(line, 1024, file); // skip header
    while (fgets(line, 1024, file)) {
        char* token = strtok(line, ";");
        Biaya_Tindakan biaya;
        biaya.No = atoi(token);
        token = strtok(NULL, ";");
        strcpy(biaya.Aktivitas, token);
        token = strtok(NULL, "\n");
        biaya.Biaya = atof(token);

        biayaTindakan[(*count)++] = biaya;
    }

    fclose(file);
    return biayaTindakan;
}

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