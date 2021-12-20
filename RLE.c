#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaration des variables globales
int i, j, c, taille;

//Declaration de deux tableaux
char chaine[100], compress[100]; 

 //Fonction qui permet d'afficher la chaine
 void ecriture(char chaine[], int N){
    printf("\nSaisir les donnees textuelles : ");
    scanf("%s", chaine);
    printf("\n");
    taille = strlen(chaine);
 }

//Fonction qui lit la chaine de caracteres
void lecture(char chaine[], int N)
{
    printf("\nAffichage de la chaine initiale : ");
    for(i=0; i < N; i++){
        printf("%c", chaine[i]);
    }   
}

// Fonction de la compression
void compressionRLE(){
    i=0, j=0;
    printf("\n\nAffichage de la chaine compress : "); 
    while(i < taille){
        c = 1;
        //Tant que les caracteres se ressemblent et que ce n'est pas la fin du tableau
        while(chaine[i] == chaine[i+1] && i < taille){
            //On incremente le compteur
            c++;
            i++;
        }
        compress[j+1] = chaine[i];
        printf("%c", compress[j+1]);
        compress[j] = c;
        printf("%d", compress[j]);
        j = j+2;
        i++;

    }
}

// Fonction de la decompression
void decompressionRLE(){
    i = 0, j=0;
    printf("\n\nAffichage de la chaine decompresse : ");
    while(i < strlen(compress)){
        c = compress[i];
        for(j = 1; j <= c; j++){
            printf("%c", compress[i+1]);
        }
        i = i + 2;
    }
}

int main(){
    //Appel des differentes fonctions du programme
    printf("=====COMPRESSEUR DE DONNEES TEXTUELLES=====");
    ecriture(chaine,taille);
    lecture(chaine,taille);
    compressionRLE();
    decompressionRLE();
return 0;
}
