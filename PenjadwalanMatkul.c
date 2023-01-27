#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jadwal {
    char matkul[100];
    char ruangan[100];
    char jam[100];
    char hari[100];
    char id[100];
};

void tambahJadwal(struct jadwal jadwalBaru) {
    FILE *matakuliahITTS;
    matakuliahITTS = fopen("jadwal.txt", "a");

    if (matakuliahITTS == NULL) {
        printf("File tidak dapat dibuka");
        exit(1);
    }

    fprintf(matakuliahITTS, "%s %s %s %s %s\n", jadwalBaru.hari, jadwalBaru.id, jadwalBaru.matkul, jadwalBaru.ruangan, jadwalBaru.jam);
    fclose(matakuliahITTS);

    printf("\nMata Kuliah berhasil di tambahkan!\n");
}

void lihatJadwal() {

    printf("Membuka File Mata Kuliah: \n\n");

    FILE *matakuliahITTS;
    matakuliahITTS = fopen("jadwal.txt", "r");

    if (matakuliahITTS == NULL) {
        printf("File tidak dapat dibuka");
        exit(1);
    }

    struct jadwal jadwalBaca;
    while (fscanf(matakuliahITTS, "%s %s %s %s %s", jadwalBaca.hari, jadwalBaca.id, jadwalBaca.matkul, jadwalBaca.ruangan, jadwalBaca.jam) != EOF) {
        printf("Hari: %s\nID: %s\nMata Kuliah: %s\nRuangan: %s\nJam: %s\n\n",jadwalBaca.hari, jadwalBaca.id, jadwalBaca.matkul, jadwalBaca.ruangan, jadwalBaca.jam);
    }

    fclose(matakuliahITTS);
    
}

void urutJadwal () {
    FILE *matakuliahITTS;
    struct jadwal mapel[100];
    int jumlah = 0;

    matakuliahITTS = fopen("jadwal.txt", "r");
    if (matakuliahITTS == NULL) {
        printf("File tidak ditemukan!\n");
    }

    while (fscanf(matakuliahITTS, "%s %s %s %s %s",mapel[jumlah].hari, mapel[jumlah].id, mapel[jumlah].matkul, mapel[jumlah].ruangan, mapel[jumlah].jam) != EOF) {
        jumlah++;
    }

    for (int i = 0; i < jumlah-1; i++) {
        for (int j = i+1; j > jumlah; j++) {
            if (strcmp(mapel[i].id, mapel[j].id) < 0) {
                struct jadwal temp = mapel[i];
                mapel[i] = mapel[j];
                mapel[j] = temp;
            }
        }
    }

    printf("Data mata kuliah yang telah diurutkan berdasarkan hari: \n\n");
    for (int i = 0; i < jumlah; i++) {  
        printf("Hari: %s\nID: %s\nMata Kuliah: %s\nRuangan: %s\nJam: %s\n\n", mapel[i].hari, mapel[jumlah].id, mapel[i].matkul, mapel[i].ruangan, mapel[i].jam);
    }

    fclose(matakuliahITTS);

    
}

void cariJadwal() {
    char keyword[50];
    printf("Masukkan Mata Kuliah yang ingin dicari: ");
    scanf("%s", keyword);

    FILE *matakuliahITTS;
    char str[200];
    int ketemu=0;

    matakuliahITTS = fopen("jadwal.txt", "r");
    if (matakuliahITTS == NULL) {
        printf("File tidak ditemukan!\n");
    }

    while (fgets(str, 200, matakuliahITTS) != NULL) { 
        if (strstr(str, keyword) != NULL) { 
            ketemu = 1;
            printf("Mata Kuliah ditemukan: %s", str);
        }
    }
    if (ketemu==0)
    {
        printf("\nMata Kuliah tidak ada\n");
        printf("=========================\n");
    }

    fclose(matakuliahITTS);
}

void ubahJadwal () {
    FILE *matakuliahITTS;
    struct jadwal mapel[100];
    int jumlah = 0;

    matakuliahITTS = fopen("jadwal.txt", "r+");
    if (matakuliahITTS == NULL) {
        printf("File tidak ditemukan!\n");
    }

    while (fscanf(matakuliahITTS, "%s %s %s %s %s",mapel[jumlah].hari, mapel[jumlah].id, mapel[jumlah].matkul, mapel[jumlah].ruangan, mapel[jumlah].jam) != EOF) {
        jumlah++;
    }
        char c;
        printf("Masukkan matkul yang ingin di update : ");
        scanf("%s",c);

        printf("----------\n");
        printf("Masukkan hari baru     : ");
        scanf(" %[^\n]s",mapel->hari);
        printf("Masukkan ruangan baru  : ");
        scanf(" %[^\n]s",mapel->ruangan);
        printf("Masukkan jam baru : ");
        scanf(" %[^\n]s",mapel->jam);

        printf("Matkul Berhasil di ubah\n");
    
}

int main() {
    int menu;
    do {
        printf("Menu:\n");
        printf("1. Tambah Mata Kuliah\n");
        printf("2. Lihat Mata Kuliah\n");
        printf("3. Cari Mata Kuliah\n");
        printf("4. Urutkan Jadwal dari Hari\n");
        printf("5. Edit Mata Kuliah\n");
        printf("6. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &menu);
        printf("==================================\n");

        switch (menu) {
            case 1: {
                struct jadwal jadwalBaru;
                    printf("Masukkan Hari: ");
                    scanf("%s", jadwalBaru.hari);
                    printf("Masukkan ID: ");
                    scanf("%s", jadwalBaru.id);
                    printf("Masukkan Mata Kuliah: ");
                    scanf("%s", jadwalBaru.matkul);
                    printf("Masukkan Ruangan: ");
                    scanf("%s", jadwalBaru.ruangan);
                    printf("Masukkan Jam: ");
                    scanf("%s", jadwalBaru.jam);
                    
                    tambahJadwal(jadwalBaru);

                break;
            }
            case 2: {
                lihatJadwal();
                break;
            }
            case 3: {
                cariJadwal();
                break;
                
            }
            case 4: {
                urutJadwal();
                break;
            }
            case 5: {
                ubahJadwal();
                break;
            }
        }
    } while (menu != 6);
    printf("Terima Kasih!\n");

    return 0;
}