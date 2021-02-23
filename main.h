#ifndef __DATA__
#define __DATA__

#include "stdio.h"

#define NMax 50
#define BLANK ' '

typedef struct {
	char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int Length;
} Kata;

void InputUser (Kata *K);

#endif