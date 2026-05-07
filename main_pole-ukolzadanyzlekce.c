#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    /* Inicializace vstupního pole */
    int pole[20] = { 1, 5, 9, 8, 7, 66, 22, 4, 155, 44,
                    147, 772, 77, 25, 91, 27, 14, 95, 47, 30 };

    /* Prohledávání pole - hledáme hodnotu 15 nebo 20 */
    for (int i = 0; i <= 19; i++) {                    // i < 20 je preferovaný zápis

        /* Pokud najdeme hledanou hodnotu */
        if (pole[i] == 15 || pole[i] == 20) {
            printf("1\n");                            // Ano, hodnota existuje
            return 0;                                 // Úspěšné ukončení programu
        }
    }

    /* Pokud se cyklus dokončí bez nalezení hodnoty */
    printf("0\n");                                    // Ne, hodnota v poli není

    return 0;                                         // Úspěšné ukončení programu
}

//Napiš program, který zkontroluje, že pole o velikosti 20 prvků obsahuje buď číslo 15, nebo číslo 20
