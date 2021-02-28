// 13519216 Kevin Katsura Dani Sitanggang
// K04
// Tugas Kecil 2 Strategi Algoritma
// Penerapan Algoritma Decrease And Conquer dengan Topological Sort

#include "data.h"

// ALOKASI CourseList dan assign nilainya dengan COURSE yang telah dialokasi
address1 AlokasiListCourse (address2 theCourse){
    address1 P1 = (address1) malloc (sizeof(CourseList));
    if (P1 != Nil){
        Course(P1) = theCourse; 
        Next(P1) = Nil;
    }
    Requisites(P1) = Nil;
    Masuk(P1) = 0;
    Visited(P1) = false ;
    return P1 ;
};


// Alokasi COURSE 
address2 AlokasiCourse (char X[], int panjang){
    address2 P = (address2) malloc (sizeof(COURSE));
    if (P != Nil)
    {
        int i;
        panjangKata(P) = panjang ;
        for (i = 0; i < panjang; i++)
        {
            Nama(P)[i] = X[i];
        }
        Next(P) = Nil ;
    }
    return P ;
};


// DEALOKASI COURSELIST
void DealokasiListCourse (address1 *P){
    Next(*P) = Nil ;
    Requisites(*P) = Nil ;
    Course(*P) = Nil;
    free(*P);
};

// DEALOKASI COURSE
void DealokasiCourse (address2 *P){
    Next(*P) = Nil ;
    free(*P);
};


// MENAMPILKAN KE LAYAR nama dari COURSE P
void PrintCourse(address2 P){
    for (int i = 0; i < panjangKata(P); i++)
    {
        printf("%c",Nama(P)[i]);
    }
    printf("\n");
};

// Membandingkan nama dari COURSE P1 dan P2 
boolean Compare2Courses(address2 P1,address2 P2){
    boolean sama = true;
    if (panjangKata(P1) == panjangKata(P2)){
        int i = 0 ;
        while (i < panjangKata(P1) && sama){
            if (Nama(P1)[i] == Nama(P2)[i]){
                i++;
            }
            else{   sama = false; }
        }
    }
    else{
        sama = false ;
    }
    return sama ;   
};