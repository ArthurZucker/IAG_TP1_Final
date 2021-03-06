#include "structure.h"
#include "dfss2.h"
#include <stdlib.h>
#include <stdio.h>
void dfs2(Graphe *graphe,int sommet_depart ,liste_ordre **ordre_par_sommet,liste_ordre **ordre_ancien_dfs){
	//La liste de sommet matquĂŠ est initialisĂŠe Ă  0 pour tous
  int *ancien_dfs = NULL;
  liste_ordre *ordre_courant = ordre_ancien_dfs[0];
  int nb_composantes =0;
  for (int i = 0; i < graphe->nb_sommets -1; i++) {
    if (ordre_courant != NULL) {
      while (ordre_courant -> suivant != NULL) {
        ancien_dfs = (int *)realloc(ancien_dfs,(nb_composantes+1)*sizeof(int));
        ancien_dfs[nb_composantes] = ordre_courant -> pre_ordre;
        nb_composantes ++;
        ordre_courant = ordre_courant -> suivant;

      }
      ancien_dfs = (int *)realloc(ancien_dfs,(nb_composantes+1)*sizeof(int));
      ancien_dfs[nb_composantes] = ordre_courant -> pre_ordre;
      nb_composantes ++;
    }
    ordre_courant = ordre_ancien_dfs[i+1];
  }
  int *new_dfs = (int *)malloc((nb_composantes)*sizeof(int));
  for (int i = 0; i < nb_composantes+1; i++) {
    new_dfs[i] = ancien_dfs[nb_composantes-i-1];
  }
  int taille = graphe -> nb_sommets;
	int *sommet_marque = (int *)calloc((taille+1),sizeof(int)); // sommet_marque[sommet] = 1 pour marquer un sommets
	for (int i = 1; i < nb_composantes+1 ; ++i)
	{
		liste_ordre *ordre = (liste_ordre *)malloc(sizeof(liste_ordre));
		if (sommet_marque[new_dfs[i-1]]==0) {
			sommet_marque[new_dfs[i-1]] = 1;
			ordre -> pre_ordre = new_dfs[i-1];
			ordre -> suivant = NULL;
			dfss2(graphe,new_dfs[i-1],sommet_marque,ordre);
			ordre_par_sommet[i-1] = ordre;
		}
		else{
			ordre -> suivant = NULL;
			ordre_par_sommet[i-1] = NULL;
		}
    free(ordre);
	}
  free(sommet_marque);
  free(new_dfs);
  free(ancien_dfs);
}
