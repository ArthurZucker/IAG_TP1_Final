#include "create_graph_from_file.h"
#include "structure.h"
#include "create_dot.h"
#include "dfs.h"
#include "afficher_mat.h"
#include "connexe2.h"
#include "inverser.h"
#include "composantes_fortement_connexes.h"
#include "initialize_all.h"
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
	printf("DFS\n" );
	dfs(graphique,graphique2,1,tableau,sommet_marque_dugraphe);
	// Ok
	create_dot(graphique2);
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
	int *composantes = (int *)calloc((taille),sizeof(int));
	composantes_fortement_connexes(graphique, composantes);
	for (size_t i = 0; i < taille; i++) {
		if (composantes[i] != NULL) {
			afficher_liste_ordre(composantes[i]);
		}
	}
	return 0;
}
