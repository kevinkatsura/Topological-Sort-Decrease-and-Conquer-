#include "stdio.h"
#include "string.h"
#include "data.h"

//DEKLARASI PROCEDURE DecreaseNConquer
void DecreaseNConquer (address1 A1, int i); // Fungsi ini didefinisikan di bawah fungsi main.

int main(){
    // Deklarasi array of char dan inputFile
    FILE *inputFile;
    char namaFile[50]; // Penyimpanan nama dari file tanpa path
    char path[100]; // Penyimpanan 'data_uji/' + namaFile

    // Input Nama File di folder 'data_uji' tanpa menggunakan ekstensi .txt
    printf("Masukkan nama file pada folder 'data_uji' (tanpa ekstensi .txt) : ");
    scanf("%123s",namaFile);
    //concat nama file dengan ekstensi .txt
    strcat(namaFile,".txt");

    // assign ('data_uji/' + nama file) ke dalam path
    snprintf(path, sizeof(path), "data_uji/%s", namaFile);

    //Buka file dan assign ke dalam variabel 'inputFile'
    inputFile=fopen(path,"r");

    // Membaca huruf pertama dari file dan di-assign ke dalam CC


    char buffer1[100]; // 
    char buffer2[20];
    List L ;

    // Masukkan data ke dalam list dynamic
    int index,count,baris = 0;
    char CC ;
    int jumlahCourse = 0;
    address1 A1,A2 ;
    address2 P2,P3,PFirst ;
    // fscanf(inputFile,"%c",&CC);

    // fgets(buffer1, 50, inputFile);
    
    

    CC = getc(inputFile);
    do{
        if (CC==','){
            jumlahCourse++ ;
            P2 = AlokasiCourse(buffer2,count);
            if (jumlahCourse == 1){
                PFirst =  P2 ;
            }
            else{
                Next(P3) = P2 ;
            }
            P3 = P2 ;
            count = 0 ;
        }
        else if (CC == '.')
        {
            if (jumlahCourse>= 1)
            {
                P2 = AlokasiCourse(buffer2,count);
                Next(P3) = P2 ;
            }
            else{
                PFirst = AlokasiCourse(buffer2,count);
            }

            A1 = AlokasiListCourse(PFirst);
            if (baris==0){
                First(L) = A1 ;
            }
            else{
                Next(A2) = A1 ;
            }
            A2 = A1;
            count = 0 ;
            jumlahCourse = 0 ;
            baris++;
        }
        else{
            buffer2[count] = CC;
            count++ ;
        }
        CC = getc(inputFile);
        if (CC == '\n' || CC == ' ')
        {
            CC = getc(inputFile);
        }
    }while(CC != EOF);
    


    

    //  MEMBENTUK GRAF SEMPURNA
    address1 A3 ;
    A1 = First(L);
    P2 = Next(Course(A1));
    while (A1 != Nil){
        while (P2 != Nil){ 
            A2 = First(L);
            boolean sama = false;
            while (!sama && A2 != Nil){
                sama = Compare2Courses(Course(A2),P2);
                if (sama) {
                    A3 = A2;
                    while (Requisites(A3) != Nil)
                    {
                        A3 = Requisites(A3);
                    }
                    Requisites(A3) = AlokasiListCourse(Nil);
                    Next(Requisites(A3)) = A1 ;
                    Masuk(A1)++ ;
                }
                else{
                    A2 = Next(A2);
                }
            }
            P2 = Next(P2);
        }
        A1 = Next(A1);
        if (A1 !=Nil){
            P2 = Next(Course(A1));
        }
    }


    // MAIN SECTION
    // DECREASE AND CONQUER
    
    // Mencari Course dengan Busur yang masuk adalah 0
    A1 = First(L);
    while (Masuk(A1)!=0)
    {
        A1 = Next(A1);
    }
    DecreaseNConquer(A1,1);

    // DESTRUKTOR
    A1 = First(L);
    P2 = Course(A1);
    while (A1 != Nil)
    {
        A3 = Requisites(A1) ;
        while (A3 != Nil){
            A2 = A3;
            A3 = Requisites(A3);
            DealokasiListCourse(&A2);
        }
        
        while (P2 != Nil){
            P3 = P2 ;
            P2 = Next(P2);
            DealokasiCourse(&P3);
        }
        A2 = A1 ;
        A1 = Next(A1);
        if (A1 !=Nil)
        {
            P2   = Course(A1);
        }
        DealokasiListCourse(&A2);
    }


    // Menutup file yang telah dibuka dengan fopen
    fclose(inputFile);
}

// FUNGSI DECREASE AND CONQUER
/*  Prin
*/

void DecreaseNConquer (address1 A1, int i){
    Visited(A1) = true ;
    if (Requisites(A1) == Nil ) {
        printf("Semester %d : ",i);
        PrintCourse(Course(A1));
    }
    else{
        int count ;
        address1 A2 ;
        printf("Semester %d : ",i);
        PrintCourse((Course(A1)));
        A2 = Requisites(A1) ;
        while (A2 != Nil)
        {
            Masuk(Next(A2))-- ;
            A2 = Requisites(A2);
        }
        i++ ;
        A2 = Requisites(A1);
        while (A2 != Nil)
        {
            if (Masuk(Next(A2)) == 0 && !Visited(Next(A2)))
            {
                DecreaseNConquer(Next(A2),i);
            }
            A2 = Requisites(A2);
        }
    }
}