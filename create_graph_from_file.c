#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create_sommet.h"
#include "structure.h"
#include "afficher_mat.h"
Graphe *create_graph_from_file(char nom_de_fichier[]){
	FILE *f;
	f = fopen(nom_de_fichier,"r");
  	if (f  == NULL) //GĂŠrer les fichiers vides/inexistants
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier \"%s\"\n",nom_de_fichier);
      exit(1);
    }

    // On lit tous les caractĂ¨res du fichier
    Graphe *mon_graphique = (Graphe *)malloc(sizeof(Graphe));
    if (nom_de_fichier[0] == 'd')
    {
    	mon_graphique -> oriente = 1;
    }
    else{
    	mon_graphique -> oriente = 0;
    }
    size_t length;
    char *lecture1 ;
    lecture1 = (char *)malloc(32 * sizeof(char));
    char *lecture2 ;
    lecture2 = (char *)malloc(32 * sizeof(char));
    getline(&lecture1,&length,f);
    getline(&lecture2,&length,f);
    (mon_graphique -> nb_sommets )= atoi(lecture1);
    (mon_graphique -> nb_aretes )= atoi(lecture2);
    mon_graphique -> liste_adjacence = (int **)calloc(((mon_graphique -> nb_sommets)+1),sizeof(int *));
    for (int i = 0; i < ((mon_graphique -> nb_sommets )+1); ++i)
    {
    	(mon_graphique -> liste_adjacence)[i] = (int *)calloc(((mon_graphique -> nb_sommets)+1),sizeof(int ));
    }
    char *line = NULL;
    size_t length1;
    for (int i = 0; i < (mon_graphique -> nb_sommets ) +1; ++i)
    {
    	(mon_graphique->liste_adjacence)[0][i] = i;
			(mon_graphique->liste_adjacence)[i][0] = i;
    }
	while(getline(&line,&length1,f) != -1){
		const char s1[2] = " ";
		char *token1;
		char *token2;
		token1 = strtok(line, s1);
		token2 = strtok(NULL, s1);
		if (token2 != NULL) {
			create_sommet(mon_graphique ,atoi(token1),atoi(token2));
		}

	}
	fclose (f);
	free(line);
	free(lecture1);
	free(lecture2);
  return mon_graphique;
}
