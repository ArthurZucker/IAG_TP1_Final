#include "create_sommet.h"
// Cette fonction va permettre d'ajouter un sommet à un graphique
// A partir des données d'un sommet, il parcour la structure graphe
// Re alloue de la mémoire à la liste d'adjacence pour lui donner une nouvelle entrée
// Mon nouveau sommet.
void create_sommet(Graphe *mon_graphique, int nom, int successeur){
	(mon_graphique -> liste_adjacence)[nom][successeur] = 1;
	if (mon_graphique -> oriente != 1)
	{
		mon_graphique -> liste_adjacence[successeur][nom] = 1;
	}
}
