#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jadwal {
    char matkul[100];
    char ruangan[100];
    char jam[100];
    char hari[100];
};

void tambahJadwal(struct jadwal jadwalBaru) {
    FILE *matakuliahITTS;
    matakuliahITTS = fopen("jadwal.txt", "a");

    if (matakuliahITTS == NULL) {
        printf("File tidak dapat dibuka");
        exit(1);
    }

    fprintf(matakuliahITTS, "%s %s %s %s\n", jadwalBaru.hari, jadwalBaru.matkul, jadwalBaru.ruangan, jadwalBaru.jam);
    fclose(matakuliahITTS);

    printf("\nMata Kuliah berhasil di tambahkan!\n");
}

void lihatJadwal() {

    printf("Membukak File Mata Kuliah: \n\n");

    FILE *matakuliahITTS;
    matakuliahITTS = fopen("jadwal.txt", "r");

    if (matakuliahITTS == NULL) {
        printf("File tidak dapat dibuka");
        exit(1);
    }

    struct jadwal jadwalBaca;
    while (fscanf(matakuliahITTS, "%s %s %s %s", jadwalBaca.hari, jadwalBaca.matkul, jadwalBaca.ruangan, jadwalBaca.jam) != EOF) {
        printf("Hari: %s\nMata Kuliah: %s\nRuangan: %s\nJam: %s\n\n", jadwalBaca.hari, jadwalBaca.matkul, jadwalBaca.ruangan, jadwalBaca.jam);
    }

    fclose(matakuliahITTS);
    
}

void urutJadwal () {
    FILE *fptr;
    struct jadwal urut[100];
    int n = 0;
    int b, urutan;

    fptr = fopen("jadwal.txt", "r");
    while (fscanf(fptr, "%s %s %s %s\n", urut[n].hari, urut[n].matkul, urut[n].ruangan, urut[n].jam) != EOF)
    {
        n++;
    }
    fclose(fptr);
    
    int i = n;
    for (n = 0; n < i - 1; n++)
    {
        urutan = n;
        for (b = n + 1; b < i; b++)
        {
            if (strcmp(urut[b].matkul, urut[urutan].matkul) < 0)
            {
                urutan = b;
            }
        }
        struct jadwal temp = urut[urutan];
        urut[urutan] = urut[n];
        urut[n] =temp;
    }
    fptr = fopen("jadwal.txt", "w");
    for (int n = 0; n < b; n++)
    {
        fprintf(fptr, "%s %s %s %s\n", urut[n].hari, urut[n].matkul, urut[n].ruangan, urut[n].jam);
    }
    fclose(fptr);
    printf("Mata Kuliah berhasil diurutkan\n");
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
        printf("Mata Kuliah tidak ada\n");
        printf("=========================\n");
    }

    fclose(matakuliahITTS);
}

void ubahJadwal()
{
    FILE*fptr;
    struct jadwal ganti;
    char gantiJadwal[100];
    
    printf("Masukkan Nama Matkul yang akan diganti : ");
    scanf("%s", gantiJadwal);

    fptr = fopen ("jadwal.txt","r");  
    FILE*temp = fopen("temp.txt","w");
    while (fscanf(fptr, "%s %s %s %s", ganti.hari, ganti.matkul, ganti.ruangan, ganti.jam) != EOF)
    {
        if (strcmp(ganti.matkul, gantiJadwal) == 0 )
        {
            printf("Masukkan Hari baru : ");
            scanf("%s", ganti.hari);
            printf("Masukkan Ruangan baru :");
            scanf("%s", ganti.ruangan);
            printf("Masukkan Jam baru :");
            scanf("%s", ganti.jam);
        }
        fprintf(temp, "%s %s %s %s\n", ganti.hari, ganti.matkul, ganti.ruangan, ganti.jam);
    }
    fclose(fptr);
    fclose(temp);
    remove("jadwal.txt");
    rename("temp.txt", "jadwal.txt");
    printf("\nData berhasil diupdate\n");
}


int main() {
    int menu;
    do {
        printf("Menu:\n");
        printf("1. Tambah Mata Kuliah\n");
        printf("2. Lihat Mata Kuliah\n");
        printf("3. Edit Mata Kuliah\n");
        printf("4. Cari Mata Kuliah\n");
        printf("5. Urutkan Jadwal dari Hari\n");
        printf("6. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &menu);
        printf("==================================\n");

        switch (menu) {
            case 1: {
                struct jadwal jadwalBaru;
                    printf("Masukkan Hari: ");
                    scanf("%s", jadwalBaru.hari);
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
                ubahJadwal();
                break;
    
            }
            case 4: {
                cariJadwal();
                break;
            }
            case 5: {
                urutJadwal();
                break;
            }
        }
    } while (menu != 6);

    printf("Terima Kasih!\n");
    return 0;
}