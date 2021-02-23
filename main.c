#include "stdio.h"
#include "string.h"
#include "main.h"
#include "kata.c"
#include "mesinkar.c"

int main(){
    // Deklarasi array of char dan inputFile
    FILE *inputFile;
    char namaFile[50]; // Penyimpanan nama dari file tanpa path
    char buffer[100]; // 
    char path[100]; // Penyimpanan 'data_uji/' + namaFile

    // Input Nama File di folder 'data_uji' tanpa menggunakan ekstensi .txt
    printf("Masukkan nama file pada folder 'data_uji' (tanpa ekstensi .txt) : ");
    scanf("%123s",namaFile);
    START(namaFile);

    //concat nama file dengan ekstensi .txt
    strcat(namaFile,".txt");

    // assign ('data_uji/' + nama file) ke dalam path
    snprintf(path, sizeof(path), "data_uji/%s", namaFile);

    //Gunakan mesinkar untuk membuka file
    START(path);
    
    

    fclose(inputFile);
}



