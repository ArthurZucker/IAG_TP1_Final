#include "structure.h"
#include "pont_graph.h"
#include "create_dot.h"
#include "afficher_liste_ordre.h"
#include "dfs5.h"
#include "free_graphique.h"
#include "free_ordre.h"
#include "composantes_fortement_connexes.h"
#include "afficher_mat.h"
#include "initialize_all.h"
#include "create_dot2.h"
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
      printf("Orientons le graphe\n" );
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
      int **arretes_marque_dugraphe = (int **)calloc(2*(taille+1),sizeof(int *));
    	for (int i = 0; i < 2*taille; i++) {
    		arretes_marque_dugraphe[i] = (int *)calloc((2),sizeof(int));
    	}
      //Le dfs qui est effectué doit prendre en compte la remontée, pour indiquer que l'on remonte
      dfs5(graphe,1,tableau,sommet_marque_dugraphe);
      liste_ordre *ordre_c = tableau[0];
      afficher_liste_ordre(ordre_c);
      int i =0;
      while (ordre_c != NULL) {
        if (ordre_c->post_ordre != 0) {
          graphique2 ->liste_adjacence[ordre_c->post_ordre][(ordre_c)->pre_ordre] = 1;
          arretes_marque_dugraphe[i][0] = ordre_c->post_ordre;
          arretes_marque_dugraphe[i][1] = ordre_c->pre_ordre;
          i++;
        }
        ordre_c = ordre_c -> suivant;
      }
      //On a orienté toutes les arretes dans le sens inverse de la racine
      //On a aussi marqué toutes les arretes visitées
      //Il ne reste plus qu'à orienter les arretes restantes
      for (int k = 1; k < (taille+1); k++) {
        for (int  ii = 1; ii < taille ; ii++) {
          int ok = 0;
          for (int j = 0; j < i+1; j++) {
            if ((arretes_marque_dugraphe[j][0] == k &&  arretes_marque_dugraphe[j][1] == ii)) {
              ok = 1 ; //Si les arretes ont été orienté par le dfs on ne doit pas les reprendre
            }
            if ((arretes_marque_dugraphe[j][1] == k &&  arretes_marque_dugraphe[j][0] == ii )) {
              ok = 1 ;
            }
          }
          if (ok == 0) {
            if (graphe -> liste_adjacence[k][ii] == 1 || graphe -> liste_adjacence[ii][k] == 1) {
              if (ii<k) {
                printf("Lisaison que l'on construit : %d -> %i\n", k,ii);
                graphique2 -> liste_adjacence[k][ii] = 1;
                i++;
                arretes_marque_dugraphe[i][0] = k;
                arretes_marque_dugraphe[i][1] = ii;
                printf("On a bien marqué les sommets\n");
              }
              else if (ii>k && k>taille/2) {
                printf("Lisaison que l'on construit : %d -> %i\n", ii,k);
                graphique2 -> liste_adjacence[k][ii] = 1;
                i++;
                arretes_marque_dugraphe[i][0] = k;
                arretes_marque_dugraphe[i][1] = ii;
                printf("On a bien marqué les sommets\n");
              }
            }
          }
        }
      }
      initialize_all(graphique2); // On initialise pour les dfs
      afficher_mat(graphique2 -> liste_adjacence,taille+1);
      char *nom_fichier;
    	nom_fichier = "digraph-1-strong_orientation.dot";
      create_dot(graphique2,nom_fichier);
      printf("On vérifie que le graphe est bien fortement connexe\n" );
      liste_ordre **composantes = (liste_ordre **)malloc((taille)*sizeof(liste_ordre *));
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
