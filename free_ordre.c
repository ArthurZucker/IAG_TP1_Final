#include "structure.h"
#include <stdio.h>
void free_ordre(liste_ordre *ordre){
 liste_ordre *ordre_courant = ordre;
 liste_ordre *ordre_courant2;
 while ( ordre_courant != NULL ) {
   ordre_courant2 = ordre_courant -> suivant;
   free(ordre_courant);
   ordre_courant = ordre_courant2;
 }
}
