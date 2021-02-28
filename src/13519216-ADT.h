// 13519216 Kevin Katsura Dani Sitanggang
// K04
// Tugas Kecil 2 Strategi Algoritma
// Penerapan Algoritma Decrease And Conquer dengan Topological Sort

#ifndef _DATA_
#define _DATA_

#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#include "13519216-boolean.h"

#define Nil NULL


typedef struct tCOURSE * address2 ;
typedef struct tCourseList * address1 ;
typedef struct tCOURSE
{
    char nama[50] ;
    int length ;
    address2 next ;
} COURSE;

typedef struct tCourseList
{
    int masuk ;
    boolean visitedNode;
    address2 course ;
    address1 requisites;
    address1 next ;
}CourseList;

typedef struct {
	address1 First;
} List;

#define Course(P) (P)->course
#define Next(P) (P)->next
#define Nama(P) (P)->nama
#define panjangKata(P) (P)->length
#define First(L) ((L).First)
#define Requisites(P) ((P)->requisites)
#define Masuk(P) ((P)->masuk)
#define Visited(P) ((P)->visitedNode)


/****************** Manajemen Memori ******************/
address1 AlokasiListCourse (address2 theCourse);
address2 AlokasiCourse (char X[], int panjang);
void DealokasiListCourse (address1 *P);
void DealokasiCourse (address2 *P);
void PrintCourse(address2 P);
boolean Compare2Courses(address2 P,address2 P2);


#endif