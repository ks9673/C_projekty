#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int cislo, cislo1,sum,rozdil,soucin,podil;
    float prumer;

    while (scanf("%d", &cislo) == 1) {
        
        if (cislo < -10000 || cislo > 10000) {
            printf("Error: Vstup je mimo interval!");
            return 100;
        }
        cislo++;

    }
    
    return 0;
}