#include "main.h"

void InputUser (Kata *K)
/* Memasukkan inputan user ke dalam Kata K*/
{
	char c;
	int i = 0;
	scanf("%c",&c);
	while (c != '\n')
	{
		(*K).TabKata[i] = c;
		++i;
		scanf("%c",&c);
	}
	(*K).Length = i;
}

void PrintKata (Kata K)
/* Menampilkan Kata K ke layar */
{
	int i = 0;
	while (i<K.Length)
	{
		printf("%c", K.TabKata[i]);
		i++;
	}
    printf("\n");
}