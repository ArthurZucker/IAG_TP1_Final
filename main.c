#include "create_graph_from_file.h"
#include "structure.h"
#include "create_dot.h"
#include "dfs.h"
#include "afficher_mat.h"
#include "connexe2.h"
#include "inverser.h"
#include "composantes_fortement_connexes.h"
#include "initialize_all.h"
#include "afficher_liste_ordre.h"
#include "initialize_all.h"
#include "create_dot2.h"
int main(int argc, char const *argv[])
{
	char *nom_fichier;
	scanf("%s",&nom_fichier);
	Graphe *graphique = create_graph_from_file(&nom_fichier);
	Graphe *graphique2 = (Graphe *)malloc(sizeof(Graphe ));
	int taille = (graphique->nb_sommets);
	graphique2 ->nb_sommets =taille;
	graphique2 -> nb_aretes  =(graphique-> nb_aretes);
	graphique2 -> oriente = graphique -> oriente;
	graphique2->liste_adjacence = (int **)calloc(taille+1,(sizeof(int *)));
	for (size_t i = 0; i < taille+1; i++) {
		graphique2->liste_adjacence[i] = (int *)calloc(taille+1,(sizeof(int )));
	}
	for (int i = 0; i < taille +1; ++i)
	{
		(graphique2->liste_adjacence)[0][i] = i;
		(graphique2->liste_adjacence)[i][0] = i;
	}
	initialize_all(graphique);
	//Ok
	liste_ordre **tableau = (liste_ordre **)malloc((taille+1)*sizeof(liste_ordre *));
	int **sommet_marque_dugraphe = (int **)calloc((taille+1),sizeof(int *));
	for (int i = 0; i < taille; i++) {
		sommet_marque_dugraphe[i] = (int *)calloc((taille+1),sizeof(int));
	}
		char *nom_fichier2;
		nom_fichier2 = "digraph-1-predfs.dot";
	create_dot(graphique,nom_fichier2);
	printf("DFS\n" );
	dfs(graphique,graphique2,1,tableau,sommet_marque_dugraphe);
	// Ok
	char *nom_fichier3;
	nom_fichier3 = "digraph-1-postdfs.dot";
	initialize_all(graphique2);
	create_dot(graphique2,nom_fichier3);
	printf("On crée dot depuis graph2\n");
	printf("Ordres de parcours\n" );
	for (int i = 0; i < taille; i++) {
		if (tableau[i] != NULL) {

			printf("Ordre de parcours pour le sommer %d\n",i+1 );
			afficher_liste_ordre(tableau[i]);
		}
	}//Affichage des ordres de parcours
	printf("Tout vas bien jusqu\'ici\n" );
	printf("Ok\n" );
	printf("Connexite %d\n",connexe2(graphique,tableau));
	//afficher_mat(graphique->liste_adjacence,taille+1);
	printf("Invers\n");
	//inverser(graphique);
	//afficher_mat(graphique->liste_adjacence,taille+1);
	printf("composantes_fortement_connexes\n" );
	liste_ordre **composantes = (liste_ordre **)calloc((taille),sizeof(liste_ordre *));
	composantes_fortement_connexes(graphique, composantes);
	int nb=0;
	for (size_t i = 0; i < taille; i++) {
		if (composantes[i] != NULL) {
			afficher_liste_ordre(composantes[i]);
			nb ++;
		}
	}
	char *nom_fichier12;
	nom_fichier12 = "digraph-1-compo.dot";
	create_dot2(graphique,nom_fichier12,composantes,nb);
	return 0;
}
