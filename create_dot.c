#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
void create_dot(Graphe *graphe,char nom_de_fichier[]){
	FILE *f;
	f = fopen(nom_de_fichier,"wb+");
	if (graphe->oriente != 1)
	{
		fprintf(f, "graph premier_graph {\n");
	}
	else{
		fprintf(f, "digraph premier_graph {\n"); // write to file
	}
	int taille = (graphe->nb_sommets);
	/*for (size_t i = 0; i < taille; i++) {
		if ((graphe->liste_successeurs	)[i][0]==0) {
			fprintf(f, "%d",i);
		}
		for (size_t ii = 0; ii < taille; ii++) {
			if ((graphe->liste_successeurs)[i][ii] !=0) {
				if (graphe->oriente != 1 && ii>=i)
				{
				fprintf(f, "%d",i+1);
				fprintf(f, " -- ");
				fprintf(f, "%d ;\n",(graphe->liste_successeurs)[i][ii]);
				}
				else if (graphe->oriente == 1) {
					fprintf(f, "%d",i+1);
					fprintf(f, " -> ");
					fprintf(f, "%d ;\n",(graphe->liste_successeurs)[i][ii]);
				}
			}
		}
	}*/
	for (int i = 1; i < (graphe->nb_sommets)+1; ++i)
	{
		if ((graphe->liste_successeurs)[i-1][0] == 0) {
			fprintf(f, "%d;",i);
		}
		for (int ii = 1; ii < (graphe->nb_sommets)+1; ++ii)
		{
			if ( (graphe->liste_adjacence)[i][ii] == 1 )
			{
				if (graphe->oriente != 1 && ii>=i)
				{
				fprintf(f, "%d",i);
				fprintf(f, " -- ");
				fprintf(f, "%d ;\n",ii);
				}
				else if (graphe->oriente == 1) {
					fprintf(f, "%d",i);
					fprintf(f, " -> ");
					fprintf(f, "%d ;\n",ii);
				}

			}
		}
	}
	fprintf(f, "}");
}
