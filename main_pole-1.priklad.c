#define _CRT_SECURE_NO_WARNINGS     // Vypnutí bezpečnostních varování ve Visual Studiu
#include <stdio.h>                  // Knihovna pro vstup/výstup (používáme printf)

int main(void)
{
    /* Deklarace a inicializace pole */
    int i;                                      // Řídicí proměnná cyklu (index)
    int pole[10] = { 4, 1, 2, 9, 10, 5, 7, 8, 2, 4 };  // Statické pole 10 celých čísel

    /* Výpis úvodního textu (pouze jednou před cyklem) */
    printf("Hodnoty uložené v poli jsou: ");

    /* Procházení pole a výpis všech prvků */
    for (i = 0; i < 10; i++)                    // i od 0 do 9 (10 prvků)
    {
        printf("%d ", pole[i]);                 // Výpis aktuálního prvku + mezera
    }

    /* Ukončení řádku pro lepší čitelnost výstupu */
    printf("\n");

    return 0;                                   // Úspěšné ukončení programu
}