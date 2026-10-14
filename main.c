#define _CRT_SECURE_NO_WARNINGS// říká překladači Visual Studia, ať nehlásí varování na starší funkce typu scanf a printf. Microsoft místo nich doporučuje bezpečnější varianty (scanf_s), ale pro školní úlohy se běžně používá tahle makra, aby šel kód přeložit bez úprav.
#include <stdio.h>// stdio.h je pro vstup a výstup (printf, scanf).
#include <math.h>//  je pro matematické funkce (fabs, mám  na porovnání obsahů).

int main() {// hlavní funkce, odsud program začíná

	double a,b,c,d,obdelnik1,obdelnik2;// deklarace proměnných
	const double eps = 1e-9;// tolerance pro porovnání desetinných čísel (kvůli zaokrouhlení), eps(epsilon)- používá se pro velmi malé číslo, které určuje toleranci
	

	if (scanf("%lf", &a) != 1) {// pokud vstup není číslo, 
		printf("Obdelnik #1:\nNespravny vstup.\n");// vypíše se mi zadaný výstup
		return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného než 0, signalizoval by chybu.
	}

	if (a <= 0) {// pokud je menší nebo roven nule
		printf("Obdelnik #1:\nNespravny vstup.\n");// vypíše se mi zadaný výstup
		return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného než 0, signalizoval by chybu.
	}
		
	

	if (scanf("%lf", &b) != 1) {// pokud vstup není číslo, 
		printf("Obdelnik #1:\nNespravny vstup.\n");// vypíše se mi zadaný výstup
		return 0;//  vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného než 0, signalizoval by chybu.
	}

	if (b <= 0) {// pokud je číslo menší,rovno 0,
		printf("Obdelnik #1:\nNespravny vstup.\n");// vypíše se mi zadaný výstup
		return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného než 0, signalizoval by chybu.
	}

	

	if (scanf("%lf", &c) != 1) {// pokud vstup není číslo,
		printf("Obdelnik #1:\nObdelnik #2:\nNespravny vstup.\n");// vypíše se mi zadaný výstup
		return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného než 0, signalizoval by chybu.
	}

	if (c <= 0) {// pokud je číslo menší,rovno 0,
		printf("Obdelnik #1:\nObdelnik #2:\nNespravny vstup.\n");// vypíše se mi zadaný výstup
		return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného než 0, signalizoval by chybu.
	}

	

	if (scanf("%lf", &d) != 1) {// pokud vstup není číslo,
		printf("Obdelnik #1:\nObdelnik #2:\nNespravny vstup.\n");// vypíše se mi zadaný výstup
		return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného než 0, signalizoval by chybu.
	}
    
	if (d <= 0) {// pokud je číslo menší,rovno 
		printf("Obdelnik #1:\nObdelnik #2:\nNespravny vstup.\n");// vypíše se mi zadaný výstup
		return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného než 0, signalizoval by chybu.
	}

	obdelnik1 = a * b; // provede se mi výpočet proměnných a a b

	obdelnik2 = c * d; // provede se mi výpočet proměnných c a d

	if (fabs(obdelnik1 - obdelnik2) < eps) {// pod podmínkou, že je rozdíl obdelníůků menší než epsilon,
		printf("Obdelnik #1:\nObdelnik #2:\nObdelniky maji stejny obsah.\n");// vypíše se mi zadaný výstup
	}
	else if (obdelnik1 < obdelnik2) {// pod podmínkou, že je obdelnik1 menší než obdelnik2
		printf("Obdelnik #1:\nObdelnik #2:\nObdelnik #1 ma mensi obsah.\n");// 
	}
	else {// pokud neplatí ani jedno, 
		printf("Obdelnik #1:\nObdelnik #2:\nObdelnik #2 ma mensi obsah.\n");// vypíše se mi zadaný výstup
	}

	return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného než 0, signalizoval by chybu.
}