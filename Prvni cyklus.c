#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

    // Deklarace proměnných pro načítání čísel, minimum a maximum
    int cislo, max, min;

    // Proměnné pro průměr a procentuální statistiky
    float prumer, procento_kladne, procento_zaporne;
    float procento_sude, procento_liche;

    // Počítadla jednotlivých kategorií čísel
    int pocet = 0;
    int kladne = 0;
    int zaporne = 0;
    int sude = 0;
    int liche = 0;

    // Součet všech načtených čísel pro výpočet průměru
    int suma = 0;


    // Cyklus načítá celá čísla, dokud je scanf úspěšně načítá
    // scanf vrací 1 při úspěšném načtení jednoho celého čísla
    while (scanf("%d", &cislo) == 1) {

        // Kontrola, zda číslo leží v povoleném intervalu
        // Operátor || znamená logické NEBO
        if (cislo < -10000 || cislo > 10000) {
            printf("\nError: Vstup je mimo interval!\n");
            return 100; // Ukončení programu s chybovým kódem 100
        }

        // Hledání maximální hodnoty
        // První číslo nastavíme jako počáteční maximum
        if (pocet == 0) {
            max = cislo;
        }
        // Pokud je další číslo větší, aktualizujeme maximum
        else if (cislo > max) {
            max = cislo;
        }

        // Hledání minimální hodnoty
        // První číslo nastavíme jako počáteční minimum
        if (pocet == 0) {
            min = cislo;
        }
        // Pokud je další číslo menší, aktualizujeme minimum
        else if (cislo < min) {
            min = cislo;
        }

        // Výpis čísel oddělených čárkou
        // První číslo vypíšeme bez čárky
        if (pocet == 0) {
            printf("%d", cislo);
        }
        else {
            printf(", %d", cislo);
        }

        // Zvýšení celkového počtu načtených čísel
        pocet++;

        // Kontrola, zda je číslo kladné
        // Nula není kladná ani záporná
        if (cislo > 0) {
            kladne++;
        }

        // Kontrola, zda je číslo záporné
        if (cislo < 0) {
            zaporne++;
        }

        // Zjištění parity čísla pomocí zbytku po dělení
        // Pokud zbytek po dělení dvěma není 0, číslo je liché
        if (cislo % 2 != 0) {
            liche++;
        }
        else {
            sude++; // Nula se také počítá mezi sudá čísla
        }

        // Přičtení aktuálního čísla k celkovému součtu
        suma += cislo;
    }
    // Kontrola, zda bylo načteno alespoň jedno číslo
    if (pocet == 0) {
        return 0;
    }
    // Výpočet procentuálních podílů jednotlivých kategorií
    // Přetypování na float zabrání celočíselnému dělení
    procento_kladne = (kladne / (float)pocet) * 100;
    procento_zaporne = (zaporne / (float)pocet) * 100;
    procento_sude = (sude / (float)pocet) * 100;
    procento_liche = (liche / (float)pocet) * 100;

    // Aritmetický průměr = součet čísel / počet čísel
    prumer = suma / (float)pocet;


    // Výpis vypočítaných statistik
    // %.2f vypisuje desetinné číslo na dvě desetinná místa

    printf("\nPocet cisel: %d\n", pocet);
    printf("Pocet kladnych: %d\n", kladne);
    printf("Pocet zapornych: %d\n", zaporne);

    printf("Procento zapornych: %.2f\n", procento_zaporne);
    printf("Procento kladnych: %.2f\n", procento_kladne);

    printf("Pocet sudych: %d\n", sude);
    printf("Pocet lichych: %d\n", liche);

    printf("Procento sudych: %.2f\n", procento_sude);
    printf("Procento lichych: %.2f\n", procento_liche);

    printf("Prumer: %.2f\n", prumer);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    // Úspěšné ukončení programu
    return 0;
}
