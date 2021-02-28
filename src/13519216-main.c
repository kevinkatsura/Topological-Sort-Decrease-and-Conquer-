// 13519216 Kevin Katsura Dani Sitanggang
// K04
// Tugas Kecil 2 Strategi Algoritma
// Penerapan Algoritma Decrease And Conquer dengan Topological Sort

#include "stdio.h"
#include "string.h"
#include "13519216-ADT.c"

//DEKLARASI PROCEDURE DecreaseNConquer
void DecreaseNConquer (address1 A1, int i); // Fungsi ini didefinisikan di bawah fungsi main.



// >>>>>>>>>>>>>>> MAIN FUNCTION <<<<<<<<<<<<<<<

int main(){
    // Deklarasi array of char dan inputFile
    FILE *inputFile;
    char namaFile[50]; // Penyimpanan nama dari file tanpa path
    char path[100]; // Penyimpanan path ke file ( 'data_uji/' + namaFile )

    // Input Nama File di folder 'data_uji' tanpa menggunakan ekstensi .txt
    printf("Masukkan nama file pada folder 'test' (tanpa ekstensi .txt) : ");
    scanf("%123s",namaFile); // input namafile dan assign ke 'namaFile'

    //concat nama file dengan ekstensi .txt
    strcat(namaFile,".txt");

    // assign ('data_uji/' + nama file) ke dalam path
    snprintf(path, sizeof(path), "../test/%s", namaFile);

    //Buka file dan assign ke dalam variabel 'inputFile'
    inputFile=fopen(path,"r");

    // Membaca huruf pertama dari file dan di-assign ke dalam CC

    //Deklarasi array buffer dan List L
    char buffer1[100]; 
    char buffer2[20];
    List L ;

    // Masukkan data ke dalam list dynamic
    int index,count,baris = 0;
    char CC ; // deklarasi variable CC untuk tempat peny
    int jumlahCourse = 0; // 
    address1 A1,A2 ;
    address2 P2,P3,PFirst ;
    

    // - >>>> KONSEP PROGRAM <<<< -
    /*
    KONSEP DARI LIST YANG DIBUAT ADALAH DENGAN MENGALOKASI LIST COURSE SEBAGAI PUSAT(ADT CourseList).
    NEXT YANG ADA PADA LIST INI AKAN MERUJUK KE ADT CourseList LAIN. 
    JADI SETIAP 'CourseList' INI MEREPRESENTASIKAN BANYAKNYA BARIS DALAM FILE TXT YANG DIBACA.
    KEMUDIAN DALAM SETIAP 'CourseList' AKAN MERUJUK PADA 'ADT COURSE' DIMANA ADT COURSE INI MEREPRESENTASIKAN SETIAP HURUF DALAM SETIAP BARIS.
    ELEMEN PERTAMA (ADT COURSE ) DALAM SETIAP 'CourseList' AKAN MERUJUK PADA KODE KULIAH SEDANGKAAN NEXT DARI 'ADT COURSE' INI SELANJUTNYA ADALAH PRASYARATNYA DARI KODE KULIAH TERSEBUT 
    */

    // Perintah 'getc' akan membaca isi dari file huruf demi huruf
    CC = getc(inputFile); // Pembacaan karakter pertama dalam file
    do{
        if (CC==','){ // Kondisi ketika karakter yang dibaca dari file adalah koma (,)
            jumlahCourse++ ; // jumlahCourse ini akan digunakan untuk mengecek apakah dialokasikan 'CourseList' yang baru (ADT CourseList dapat di lihat dalam 'data.h')
            P2 = AlokasiCourse(buffer2,count); // Alokasi P2 dengan pointer ke ADT COURSE (implementasi ADT COURSE terdapat di 'data.h)
            if (jumlahCourse == 1){ 
                PFirst =  P2 ; // Jika P2 yang dialokasikan adalah Kode Kuliah, maka PFirst diassign dengan Alokasi ADT COURSE di atas (P2)
            }
            else{
                Next(P3) = P2 ; //Jika P2 yang dialokasikan adalah prasyarat kode kuliah, maka Next dari P3 yang diassign sebelumnya akan diset menjadi P2
            }
            P3 = P2 ;
            count = 0 ;
        }
        else if (CC == '.') // Kondisi ketika karakter yang dibaca dari file adalah titik(.)
        {
            if (jumlahCourse>= 1)
            {
                P2 = AlokasiCourse(buffer2,count);  // Jika bukan elemen pertama pada COURSE dalam suatu lisCourseListt.
                Next(P3) = P2 ; // P3 yang telah ada sebelumnya di set next nya menjadi P2 yang baru saja dialokasikan
            }
            else{
                PFirst = AlokasiCourse(buffer2,count); // Jika elemen pertama dalam COURSE dalam suatu CourseList.
            }

            A1 = AlokasiListCourse(PFirst); // Dialokasikan CourseList dengan elemen kepada adalah PFirst dan di-assign ke A1
            if (baris==0){
                First(L) = A1 ; // Jika CourseList yang baru saja dialokasikan masih baris pertama dalam file txt, maka akan diset menjadi First dari List ( penanda elemen pertama CourseList)
            }
            else{
                Next(A2) = A1 ; // Jika telah dialokasikan CourseList lain sebelumnya, maka CourseList yang baru dialokasikan akan diset menjadi next dari CourseList sebelumnya
            }
            A2 = A1;
            count = 0 ;
            jumlahCourse = 0 ;
            baris++;
        }
        else{ // Jika yang karakter yang dibaca yang terdapat pada CC bukan titik maupun koma 
            buffer2[count] = CC; // Assign karakter yang terdapat dalam CC ke array buffer2 karakter demi karakter
            count++ ;
        }
        CC = getc(inputFile); // Membaca karakter selanjutnya dalam file
        if (CC == '\n' || CC == ' ') 
        {
            CC = getc(inputFile); // Jika yang dibaca adalah Newline atau SPASI maka akan diabaikan dan membaca karakter selanjutnya dalam file.
        }
    }while(CC != EOF); // Alokasi ini akan selesai jika CC adalah EOF
    


    /*
    SETELAH ALOKASI YANG SEBELUMNYA DILAKUKAN, MAKA AKAN DIALOKASIKAN LAGI LIST UNTUK MASING-MASING CourseList YANG TELAH DIALOKASIKAN.
    MASING-MASING CourseList INI AKAN MENUNJUK PADA CourseList LAIN YANG MEMILIKI PRASYARAT CourseList YANG SEDANG DIAKSES (KONSEP SAMA DENGAN GAMBAR GRAPH PADA SPEK TUGAS).
    */

    //  MEMBENTUK GRAF SEMPURNA
    address1 A3 ;
    A1 = First(L); // ASSIGN FIRST DARI CourseList
    P2 = Next(Course(A1)); // ASSIGN ELEMEN KEDUA(Prasyarat) DALAM CourseList pertama
    while (A1 != Nil){  // A1 terhadap CourseList
        while (P2 != Nil){  // P2 terhadap setiap Course pada CourseList yang sedang diakses
            A2 = First(L); 
            boolean sama = false;
            while (!sama && A2 != Nil){ // Mengakses CourseList dengan A2
                sama = Compare2Courses(Course(A2),P2); // Mencompare apakah nama dari Course(A2) dan nama dari P2 adalah sama 
                if (sama) { 
                    A3 = A2; // Akses CourseList A2 
                    while (Requisites(A3) != Nil) // Dicari posisi ujung dari Requisites dari elemen CourseList yang diakses untuk dialokasikan yang baru
                    {
                        A3 = Requisites(A3);
                    }
                    Requisites(A3) = AlokasiListCourse(Nil); // Mengalokasikan posisi terujung dari Requisites CourseList yang diakses dengan CourseList kosong (selanjutnya akan dialokasikan Next yang menunjuk ke CourseList utama yang memiliki prasyarakat courselist ini)
                    Next(Requisites(A3)) = A1 ; // Set Next dari CourseList yang baru dialokasikan dengan A1 (CourseList yang memiliki prasyarat A2)
                    Masuk(A1)++ ; // Mengincrement nilai dari simpul masuk
                }
                else{
                    A2 = Next(A2); // Jika tidak sama, maka akan diakses CourseList selanjutnya
                }
            }
            P2 = Next(P2); // Akses Course selanjutnya dari CourseList yang diakses
        }
        A1 = Next(A1); // Akses CourseList selanjutnya
        if (A1 !=Nil){
            P2 = Next(Course(A1)); // Jika memang A1 sekarang tidak nil, maka akan dialokasikan lagi P2 dengan COURSE Ke-2 pada A1
        }
    }


    // MAIN SECTION 
    // DECREASE AND CONQUER ( TOPOLOGICAL SORT )
    
    // Mencari Course dengan Busur yang masuk adalah 0
    A1 = First(L); // Akses Elemen pertama pada CourseList
    while (A1 != Nil){ // Akan berhenti sampai A1 == Nil
        if (Masuk(A1) == 0 && !Visited(A1)){
            DecreaseNConquer(A1,1); // Akan diakses semua course yang tidak memiliki prasyarat dan belum dikunjungi.
        } 
        A1 = Next(A1); // Mengakses CourseList selanjutnya
    }


    // DESTRUKTOR (DEALOKASI SEMUA ALOCATED DATA)
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
    return 0 ;
}



// >>>>>>>>>>>  FUNGSI DECREASE AND CONQUER  <<<<<<<<<<<

/*  KONSEP NYA SAMA SEPERTI SPEK. 
    DecreaseNConquer akan dipanggil seiring dengan penyempitan lingkup List yang dikunjungi
*/

void DecreaseNConquer (address1 A1, int i){
    Visited(A1) = true ; // Set bahwa CourseList yang sedang diakses (A1) telah dikunjungi
    if (Requisites(A1) == Nil ) { // Jika telah menemukan Simpul Ujung
        printf("Semester %d : ",i);
        PrintCourse(Course(A1));
    }
    else{
        int count ;
        address1 A2 ;
        printf("Semester %d : ",i); // Tampilkan terlebih dahulu Semester dari A1
        PrintCourse((Course(A1)));
        A2 = Requisites(A1);
        while (A2 != Nil) // Akses semua node yang ditunjuk oleh node A1
        {
            Masuk(Next(A2))-- ; // Mengurangi jumlah simpul masuk dari masing-masing node yang ditunjuk A1
            A2 = Requisites(A2); // Akses node yang ditunjuk selanjutnya
        }
        i++ ; // Mengincrement i sebagai indeks semester
        A2 = Requisites(A1);
        while (A2 != Nil) // Akses semua node yang ditunjuk oleh node A1 
        {
            if (Masuk(Next(A2)) == 0 && !Visited(Next(A2))) 
            {
                DecreaseNConquer(Next(A2),i);   //  Jika jumlah simpul masuk dari node yang diakses saat ini tidak sama dengan nol dan simpul tersebut belum dikunjungi),
                                                //  Maka akan rekursif ke simpul tersebut.
            }
            A2 = Requisites(A2); // Akses simpul yang ditunjuk selanjutnya
        }
    }
}