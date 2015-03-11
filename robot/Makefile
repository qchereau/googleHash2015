all: lit_tableau lit_brutal lit_genere correctionGoogle1



lit_tableau: lit_tableau.c lit_tab.o tab.h
	cc -o lit_tableau lit_tableau.c lit_tab.o -ll

lit_generev2: lit_genere.c lit_tab.o tab.h detecter_champ.o
	cc -o lit_genere lit_genere.c lit_tab.o detecter_champ.o -ll

lit_genere: lit_genere.c lit_tab.o tab.h lch.h identifier_champ.o lch.o identifier_champ_5_7.o
	cc -o lit_genere lit_genere.c lit_tab.o identifier_champ.o lch.o identifier_champ_5_7.o -ll


lit_tab.o: lit_tab.l tab.h
	lex -o lit_tab.c lit_tab.l
	cc -c lit_tab.c
	rm -f lit_tab.c

lit_brutal:  lit_brutal.l tab.h
	lex  -t lit_brutal.l > lit_brutal.c
	cc   lit_brutal.c   -o lit_brutal -ll

correctionGoogle1: correctionGoogle1.c tab.h
	cc -o correctionGoogle1 correctionGoogle1.c


detecter_champ.o: detecter_champ.c tab.h
	cc -c detecter_champ.c

lch.o: lch.c lch.h
	cc -c lch.c

