#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
void create_dot(Graphe *graphe){
	FILE *f;
	f = fopen("graphique.dot","wb+");
	if (graphe->oriente != 1)
	{
		fprintf(f, "graph premier_graph {\n");
	}
	else{
		fprintf(f, "digraph premier_graph {\n"); // write to file
	}

	for (int i = 1; i < (graphe->nb_sommets)+1; ++i)
	{
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
