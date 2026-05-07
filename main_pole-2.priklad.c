#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    /* Inicializace dat */
    int i;                                          // řídicí proměnná pro cykly
    int pole[10] = { 4, 1, 2, 9, 10, 5, 7, 8, 2, 4 }; // statické pole 10 prvků

    /* Výpis pole v původním pořadí */
    printf("Hodnoty ulozene v poli jsou : ");

    for (i = 0; i < 10; i++) {
        printf("%d ", pole[i]);                     // výpis každého prvku + mezera
    }

    printf("\n");                                   // nový řádek po dokončení výpisu

    /* Výpis pole v reverzním (obráceném) pořadí */
    printf("Prvky v poli reverzne jsou : ");

    for (i = 9; i >= 0; i--) {                      // jdeme od posledního indexu zpět na 0
        printf("%d ", pole[i]);
    }

    printf("\n");

    return 0;                                       // úspěšné ukončení programu
}