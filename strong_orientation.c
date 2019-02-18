#include "structure.h"
#include "pont_graph.h"
#include "create_dot.h"
#include "afficher_liste_ordre.h"
#include "dfs4.h"
#include "free_graphique.h"
#include "free_ordre.h"
#include "composantes_fortement_connexes.h"
void strong_orientation(Graphe *graphe){
    //dfs puis orienter toutes les arretes du dfs en s'éloignant de la racine de l'arbre, orienter les
    //Autres arretes qui relient forcément un prédécesseur à un successeurs, dans le sens descendant -> ancetre
    if (pont_graph(graphe) != 0) {
      fprintf(stderr,"Le graphe possède des ponts, on ne peut pas l'orienter fortement\n");
    }
    if (graphe->oriente == 1) {
      fprintf(stderr,"Le graphe possède des ponest déja oreinté\n");
    }
    else{
      Graphe *graphique2 = (Graphe *)malloc(sizeof(Graphe ));
    	int taille = (graphe->nb_sommets);
    	graphique2 ->nb_sommets = taille;
    	graphique2 -> nb_aretes  = (graphe-> nb_aretes);
    	graphique2 -> oriente = 1;
    	graphique2->liste_adjacence = (int **)calloc(taille+1,(sizeof(int *)));
    	for (size_t i = 0; i < taille+1; i++) {
    		graphique2->liste_adjacence[i] = (int *)calloc(taille+1,(sizeof(int )));
    	}
    	for (int i = 0; i < taille +1; ++i)
    	{
    		(graphique2->liste_adjacence)[0][i] = i;
    		(graphique2->liste_adjacence)[i][0] = i;
    	}

      liste_ordre **tableau = (liste_ordre **)malloc((taille+1)*sizeof(liste_ordre *));
    	int **sommet_marque_dugraphe = (int **)calloc((taille+1),sizeof(int *));
    	for (int i = 0; i < taille; i++) {
    		sommet_marque_dugraphe[i] = (int *)calloc((taille+1),sizeof(int));
    	}
      int **arretes_marque_dugraphe = (int **)calloc((taille+1),sizeof(int *));
    	for (int i = 0; i < taille; i++) {
    		arretes_marque_dugraphe[i] = (int *)calloc((2),sizeof(int));
    	}
      dfs4(graphe,1,tableau,sommet_marque_dugraphe);
      liste_ordre *ordre_c = tableau[0];
      int i =0;
      while (ordre_c != NULL) {
        if (ordre_c -> suivant != NULL) {
          graphique2 ->liste_adjacence[ordre_c->pre_ordre][(ordre_c->suivant)->pre_ordre] = 1;
          arretes_marque_dugraphe[i][0] = ordre_c->pre_ordre;
          arretes_marque_dugraphe[i][1] = (ordre_c->suivant)->pre_ordre;
          i++;
        }
        ordre_c = ordre_c -> suivant;
      }
      //On a orienté toutes les arretes dans le sens inverse de la racine
      //On a aussi marqué toutes les arretes visitées
      //Il ne reste plus qu'à orienter les arretes restantes
      for (size_t k = 1; k < taille+1; k++) {
        for (size_t ii = 1; ii < k ; ii++) {
          int ok = 0;
          for (size_t j = 0; j < i; j++) {
            if ((arretes_marque_dugraphe[j][0] == k &&  arretes_marque_dugraphe[j][1] == ii) || (arretes_marque_dugraphe[j][1] == k &&  arretes_marque_dugraphe[j][0] == ii )) {
              ok = 1 ;
            }
          }
          if (ok == 0) {
            if (graphe->liste_adjacence[k][ii] ==1) {
              graphique2 ->liste_adjacence[k][ii] = 1;
            }

          }


        }
      }
      initialize_all(graphique2);
      char *nom_fichier;
    	nom_fichier = "digraph-1-strong_orientation.dot";
      create_dot(graphique2,nom_fichier);
      liste_ordre **composantes = (liste_ordre **)calloc((taille),sizeof(liste_ordre *));
    	composantes_fortement_connexes(graphique2, composantes);
      int nb=0;
    	for (size_t i = 0; i < taille; i++) {
    		if (composantes[i] != NULL) {
    			nb ++;
    		}
    	}
      char *nom_fichier12;
    	nom_fichier12 = "digraph-1-strong_orientationfc.dot";
    	create_dot2(graphique2,nom_fichier12,composantes,nb);
      free_graphique(graphique2);
      for (size_t i = 0; i < taille; i++) {
        free_ordre(tableau[i]);
        free_ordre(composantes[i]);
        free(sommet_marque_dugraphe[i]);
        free(arretes_marque_dugraphe[i]);
      }

    }

  }
