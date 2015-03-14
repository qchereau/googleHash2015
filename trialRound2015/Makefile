all: lit_tableau range_servers


lit_tableau: lit_tableau.c lit_tab.o tab.h
	cc -o lit_tableau lit_tableau.c lit_tab.o -ll

lit_tab.o: lit_tab.l tab.h
	lex -o lit_tab.c lit_tab.l
	cc -c lit_tab.c
	rm -f lit_tab.c

range_servers: range_servers.c localisation.o repartition.o positionnement.o lit_tab.o tab.h optimizer.o
	cc -o range_servers range_servers.c localisation.o repartition.o positionnement.o lit_tab.o optimizer.o -ll

localisation.o: localisation.c tab.h
	cc -c localisation.c

repartition.o: repartition.c tab.h
	cc -c repartition.c

positionnement.o: positionnement.c tab.h
	cc -c positionnement.c

optimizer.o: optimizer.c tab.h
	cc -c optimizer.c

