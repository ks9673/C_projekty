#define _CRT_SECURE_NO_WARNINGS// říká překladači Visual Studia, ať nehlásí varování na starší funkce typu scanf a printf. Microsoft místo nich doporučuje bezpečnější varianty (scanf_s), ale pro školní úlohy se běžně používá tahle makra, aby šel kód přeložit bez úprav.
#include <stdio.h>// stdio.h je pro vstup a výstup (printf, scanf)
#include <math.h>//  pro fabs

int najedneprimce(double ax, double ay, double bx, double by, double cx, double cy) { // pojmenování funkce a deklarace proměnných

	const double eps = 1e-9;// tolerance pro porovnání( kvůli zaokrouhlování v double)
	double obsah = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);// vektorový vzorec pro výpočet kolinearity; dvojnásobek obsahu trojúhelníku
	return fabs(obsah) < eps;// pokud je obsah menší než eps, je podmínka kolinearity splněna, poté je hodnota = 1, jinak je hodnota = 0; alternativní řešení spočívá v použití podmínky if; 1 = leží na přímce, 0 = neleží 
}

int vypocetctvrtehobodu(double ax, double ay, double bx, double by, double cx, double cy, double *d1x, double *d1y, double *d2x, double *d2y, double *d3x, double *d3y ) {// pojmenování funkce a deklarace proměnných; byly použity ukazatele, aby proměnné mohly být použity ve funkce main
	// protože u rovnoběžníku platí AB=CD, poté můžeme získat D pomocí úpravy -> D=A+C-B, s úpravou pro jiné polohy D
	*d1x = ax + cx - bx;   // první možná poloha čtvrtého bodu
	*d1y = ay + cy - by;

	*d2x = ax + bx - cx;   // druhá možná poloha čtvrtého bodu
	*d2y = ay + by - cy;

	*d3x = bx + cx - ax;   // třetí možná poloha čtvrtého bodu
	*d3y = by + cy - ay;
	return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného, hlásil by chybu.
}

void druhrovnobezniku(double ux, double uy, double vx, double vy) {// pojmenování funkce a deklarace proměnných; protože je místo int void, není třeba na konci return
	const double eps = 1e-9;                    // tolerance pro porovnání
	double delka_u = sqrt(ux * ux + uy * uy);   // délka prvního vektoru
	double delka_v = sqrt(vx * vx + vy * vy);   // délka druhého vektoru
	double skalarni = ux * vx + uy * vy;        // skalární součin (0 = kolmé)

	if (fabs(delka_u - delka_v) < eps && fabs(skalarni) < eps)  // stejné délky a kolmé
		printf("Je to ctverec\n");
	else if (fabs(skalarni) < eps)                              // jen kolmé
		printf("Je to obdelnik\n");
	else if (fabs(delka_u - delka_v) < eps)                     // jen stejné délky
		printf("Je to kosoctverec\n");
	else                                                        // ani jedno
		printf("Je to rovnobeznik\n");
}

int main() {// hlavní funkce, odtud program začíná


	double a, b, c, d, e, f;// deklarace proměnných s desetinným číslem

	if (scanf(" [%lf,%lf]", &a, &b) != 2) {// mezera na začátku přeskočí bílé znaky před [
		printf("Neplatny vstup\n");// vypíše mi tento výstup, když vstup nesplňuje zadání
		return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného než 0, hlásil by chybu.
	}

	if (scanf(" [%lf,%lf]", &c, &d) != 2) {// mezera na začátku přeskočí bílé znaky před [
		printf("Neplatny vstup\n");// vypíše mi tento výstup, když vstup nesplňuje zadání
		return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby, Když bys vrátil něco jiného než 0, hlásil by chybu.
	}

	if (scanf(" [%lf,%lf]", &e, &f) != 2) {// mezera na začátku přeskočí bílé znaky před [
		printf("Neplatny vstup\n");// vypíše mi tento výstup, když vstup nesplňuje zadání
		return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby, Když bys vrátil něco jiného než 0, hlásil by chybu.
	}

	if (najedneprimce(a, b, c, d, e, f)) {// volání 1. funkce; jestli jsou body na jedné přímce či tvoří rovnoběžník
		printf("Jsou na jedne primce\n");// podmínka, zda platí či ne
		return 0;//  vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného, hlásil by chybu.
	}
	// deklarace proměnných
	double dx1;
	double dy1;
	double dx2;
	double dy2;
	double dx3;
	double dy3;

	vypocetctvrtehobodu(a, b, c, d, e, f, &dx1, &dy1, &dx2, &dy2, &dx3, &dy3);// volání 2. funkce; výpočet polohy čtvrtého bodu

	// varianta 1: D1 = A + C - B  → strany AB a AD1
	double u1x = c - a, u1y = d - b;          // AB
	double v1x = dx1 - a, v1y = dy1 - b;      // AD1
	druhrovnobezniku(u1x, u1y, v1x, v1y);// volání 3.funkce; jaký je rovnoběžník, čtverec, obdelník, kosočtverec či obecný rovnoběžník

	// varianta 2: D2 = A + B - C  → strany AC a AD2
	double u2x = e - a, u2y = f - b;          // AC
	double v2x = dx2 - a, v2y = dy2 - b;      // AD2
	druhrovnobezniku(u2x, u2y, v2x, v2y);// volání 3.funkce; jaký je rovnoběžník, čtverec, obdelník, kosočtverec či obecný rovnoběžník

	// varianta 3: D3 = B + C - A  → strany AB a AC
	double u3x = c - a, u3y = d - b;          // AB
	double v3x = e - a, v3y = f - b;          // AC
	druhrovnobezniku(u3x, u3y, v3x, v3y);// volání 3.funkce; jaký je rovnoběžník, čtverec, obdelník, kosočtverec či obecný rovnoběžník

	return 0;// vrací operačnímu systému kód 0, což znamená, že program skončil bez chyby. Když bys vrátil něco jiného, hlásil by chybu.
}
