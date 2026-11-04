#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  {      // Letadla- může tam být i nemusí
	double x,y;       // datový typ pro desetinná čísla
	char jmeno[200]; // char- datový typ pro uložení názvu(textu nebo řetězce), tady se jedná o součást patřící do struktury,[200]- má mít nejvýše 199 znaků, 200 je ukončovací znak '\0'
	
}Letadla;


int main() {
	
	Letadla l;     //  Letadla *letadla = NULL;
	int pocet = 0;              //int pocet = 0;             - alternativa
	double min_vzdalenost = 1e300;
	int pocet_dvojic = 0;
	
	Letadla *pole = NULL;  // vytváříš pointer, ale nevíš, kam bude ukazovat
	int nova_kapacita = 30;
	
	printf("Velikost struktury: %d\n", sizeof(Letadla));
	printf("Pozice letadel: \n"); //
	
	

	pole = realloc(pole,nova_kapacita *sizeof(Letadla));

	while (1) {
		if (scanf("%lf,%lf:%199s", &pole[pocet].x, &pole[pocet].y, &pole[pocet].jmeno)== EOF) {
			break;
		}
		printf("%lf,%lf:%s\n", pole[pocet].x, pole[pocet].y, pole[pocet].jmeno);

		pocet++;
		



		if (pocet >= nova_kapacita) {
			
			nova_kapacita *= 2;
			
			Letadla *nove=realloc(pole, nova_kapacita *sizeof(Letadla));

			if (nove == NULL) {
				free(pole);
				return 1;
			}
			pole = nove;
		}// kontrolovat, jestli počet letadel není větší nebo roven kapacitě pole. Pokud je,, tak musíme zvýšit hodnotu proměnné nova_kapacita a následně použít realloc
	};
	
	for (int i = 0; i < pocet;i++) {
		for (int j = i+1;j < pocet; j++) {
			double dx = pole[i].x - pole[j].x;
			double dy = pole[i].y - pole[j].y;
			double vzdalenost = sqrt(dx*dx + dy*dy);
			if (vzdalenost < min_vzdalenost)
				min_vzdalenost = vzdalenost;
			
		}
		
		
	}
	printf("Vzdalenost nejblizsih letadel: %lf", min_vzdalenost);

	for (int i = 0; i < pocet; i++) {
		for (int j = i + 1; j < pocet; j++) {
			double dx = pole[i].x - pole[j].x;
			double dy = pole[i].y - pole[j].y;
			double vzdalenost = sqrt(dx * dx + dy * dy);
			if (vzdalenost == min_vzdalenost)
				pocet_dvojic++;

		}
		

	}
	printf("Nalezenych dvojic: %d\n", pocet_dvojic);
	
	for (int i = 0; i < pocet; i++) {
		for (int j = i + 1; j < pocet; j++) {

			double dx = pole[i].x - pole[j].x;
			double dy = pole[i].y - pole[j].y;

			double vzdalenost = sqrt(dx * dx + dy * dy);

			if (vzdalenost == min_vzdalenost) {
				printf("%s - %s\n",
					pole[i].jmeno,
					pole[j].jmeno);
			}
		}
	}

	return 0; // vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného, hlásil by chybu.
}
