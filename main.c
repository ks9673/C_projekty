#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

    // Deklarace promìnných pro naèítání èísel, minimum a maximum
    int cislo, max, min;

    // Promìnné pro prùmìr a procentuální statistiky
    float prumer, procento_kladne, procento_zaporne;
    float procento_sude, procento_liche;

    // Poèítadla jednotlivých kategorií èísel
    int pocet = 0;
    int kladne = 0;
    int zaporne = 0;
    int sude = 0;
    int liche = 0;

    // Souèet všech naètených èísel pro výpoèet prùmìru
    int suma = 0;


    // Cyklus naèítá celá èísla, dokud je scanf úspìšnì naèítá
    // scanf vrací 1 pøi úspìšném naètení jednoho celého èísla
    while (scanf("%d", &cislo) == 1) {

        // Kontrola, zda èíslo leží v povoleném intervalu
        // Operátor || znamená logické NEBO
        if (cislo < -10000 || cislo > 10000) {
            printf("\nError: Vstup je mimo interval!\n");
            return 100; // Ukonèení programu s chybovým kódem 100
        }

        // Hledání maximální hodnoty
        // První èíslo nastavíme jako poèáteèní maximum
        if (pocet == 0) {
            max = cislo;
        }
        // Pokud je další èíslo vìtší, aktualizujeme maximum
        else if (cislo > max) {
            max = cislo;
        }

        // Hledání minimální hodnoty
        // První èíslo nastavíme jako poèáteèní minimum
        if (pocet == 0) {
            min = cislo;
        }
        // Pokud je další èíslo menší, aktualizujeme minimum
        else if (cislo < min) {
            min = cislo;
        }

        // Výpis èísel oddìlených èárkou
        // První èíslo vypíšeme bez èárky
        if (pocet == 0) {
            printf("%d", cislo);
        }
        else {
            printf(", %d", cislo);
        }

        // Zvýšení celkového poètu naètených èísel
        pocet++;

        // Kontrola, zda je èíslo kladné
        // Nula není kladná ani záporná
        if (cislo > 0) {
            kladne++;
        }

        // Kontrola, zda je èíslo záporné
        if (cislo < 0) {
            zaporne++;
        }

        // Zjištìní parity èísla pomocí zbytku po dìlení
        // Pokud zbytek po dìlení dvìma není 0, èíslo je liché
        if (cislo % 2 != 0) {
            liche++;
        }
        else {
            sude++; // Nula se také poèítá mezi sudá èísla
        }

        // Pøiètení aktuálního èísla k celkovému souètu
        suma += cislo;
    }
    // Kontrola, zda bylo naèteno alespoò jedno èíslo
    if (pocet == 0) {
        return 0;
    }
    // Výpoèet procentuálních podílù jednotlivých kategorií
    // Pøetypování na float zabrání celoèíselnému dìlení
    procento_kladne = (kladne / (float)pocet) * 100;
    procento_zaporne = (zaporne / (float)pocet) * 100;
    procento_sude = (sude / (float)pocet) * 100;
    procento_liche = (liche / (float)pocet) * 100;

    // Aritmetický prùmìr = souèet èísel / poèet èísel
    prumer = suma / (float)pocet;


    // Výpis vypoèítaných statistik
    // %.2f vypisuje desetinné èíslo na dvì desetinná místa

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

    // Úspìšné ukonèení programu
    return 0;
}