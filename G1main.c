#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ligne = 0;
    int colonne = ligne;
    int l;
    int nbr_arc = 0;
    int caractereActuel = 0;
    int valeurArc = 0;
    int i = 0;
    int j = 0;
    int compteur = 0;
    int saisie = 0;

    FILE * fichier = NULL;

    fichier = fopen("G1_Archive_PTG.txt", "r");
    if(fichier != NULL){
        fseek(fichier, 0, SEEK_SET);//curseur init
        while(compteur < sasie){
            fscanf(fichier, "%d",&caractereActuel);
            if(compteur == 0){
                ligne = caractereActuel;
                colonne = ligne;
                int **matrice;
                matrice = (int *)malloc(ligne);
                for (l = 0; l< ligne; l++){
                matrice[l] = (int) malloc(colonne);
                }
                //matrice[ligne][colonne] = {{0},{0}};
            }
            else if(compteur == 1){
                nbr_arc = caractereActuel;
            }
            else if (compteur > 1){
                fseek(fichier, 2, SEEK_SET); // place le curseur 2 caractères plus loin
                fscanf(fichier, "%d","%d","%d", &i ,&j, &valeurArc);
                printf("\n%d, %d ,%d ",i ,j ,valeurArc);
                matrice[i][j] = 1;
            }
            compteur ++;
        }
        fclose(fichier);
    }


    printf("\nDimension de la matrice adjacente: %d, %d\n", ligne, colonne);
    printf("Nombre d'arc: %d\n", nbr_arc);
    printf("%d", matrice);

    return 0;
}
