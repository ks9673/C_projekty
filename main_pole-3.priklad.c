#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    /* Inicializace dat */
    int i;                                          // řídicí proměnná cyklu
    int pole[10] = { 4, 1, 2, 9, 10, 5, 7, 8, 2, 4 }; // vstupní pole celých čísel
    int soucet = 0;                                 // akumulátor součtu (musí být inicializován na 0!)

    /* Výpočet součtu všech prvků pole */
    for (i = 0; i < 10; i++) {
        soucet += pole[i];                          // přičteme aktuální prvek k celkovému součtu
    }

    /* Výpis výsledku */
    printf("Soucet vsech prvku ulozenych v poli je : %d\n", soucet);

    return 0;                                       // úspěšné ukončení programu
}