//
//  main.c
//  projet
//
//  Created by Karl Saint-Martin on 07/11/2019.
//  Copyright © 2019 Karl Saint-Martin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{

    int acces ;
    int remplissage ;
    int normale;
    int priority;
    float poids;


}stats;



typedef struct
{
    int abs;
    char visa[10];
    char nom[20];
    char prenom[20];
    int num;
    char nationalite[20];
    int naiss;
    char passeport[20];
    int dest;
    int registre;
    int priority;
    int bagages;
    float poids1;
    float poids2;
    int place;
    int front;
    int secu;
    int embarqbag;
    int embarqu;


}client;

void frontiere (client ***base, int *N, int **compteur, int**finish, int** ok)
{

    char test[20];
    int test2;
    int rep, rep2, rep4,rep5, i, j, k, l, g;
    i = 0;
    j = 0;
    l = 0;
    g = 0;
    rep2 = 0;
    rep = 0;
    rep4 = 0;

    printf("Vous entrez le numéro(1) ou le nom du passager(2)?");
    scanf("%d", &rep);
    if(*ok == 0)rep = 4;
    if (rep!=4)
    {
    if (rep == 1)
    {
        printf("\nEntrez le numéro");
        scanf("%d", &test2);

            while (rep2 == 0 && j < *N)
            {
                k = 0;
                while (rep2 == 0 && k < (*compteur)[j])
                {
                    if (test2 == (*base)[j][k].num)
                    {
                        rep2 = 1;
                        l = j;
                        g = k;
                    }
                    k = k+1;
                }
                j = j+1;
        }
    }
    if (rep == 2)
    {
        printf("\nEntrez le nom");
         scanf("%s", test);

                 while (rep2 == 0 && j < *N)
                {
                    k = 0;
                    while (rep2 == 0 && k < (*compteur)[j])
                    {
                        if (strcmp(test, (*base)[j][k].nom) == 0)
                        {
                            rep2 = 1;
                            l = j;
                            g = k;
                        }
                        k = k+1;
                    }
                    j = j+1;
                }
    }
     while (rep4 == 0 ){
         printf("\nEst-ce bien vous ?: (oui = 1; non = 0)\n");
         printf("\nNOM : %s \n", (*base)[l][g].nom);
         printf("\nPRENOM : %s \n", (*base)[l][g].prenom);
         printf("NUMERO : %d \n", (*base)[l][g].num);
         scanf("%d", &rep4);

        rep5 = rep4;
        if (rep5 == 0)
        {
            rep2 = 0;
            j = l;
            k = g + 1;
            if (rep == 1)
             {
                     while (rep2 == 0 && j < *N)
                     {
                         k = g + 1;
                         while (rep2 == 0 && k < (*compteur)[j])
                         {
                             if (test2 == (*base)[j][k].num)
                             {
                                 rep2 = 1;
                                 l = j;
                                 g = k;
                                 rep5 = 1;
                             }
                             k = k+1;
                         }
                         j = j+1;
                         k = 0;
                    }
             }
             if (rep == 2)
             {
                          while (rep2 == 0 && j < 20)
                         {
                             k = g + 1;
                             while (rep2 == 0 && k < (*compteur)[j])
                             {
                                 if (strcmp(test, (*base)[j][k].nom) == 0)
                                 {
                                     rep2 = 1;
                                     l = j;
                                     g = k;
                                     rep5 = 1;
                                 }
                                 k = k+1;
                             }
                             j = j+1;
                             k = 0;
                         }
            }
        }
             if (j == *N && rep2 == 0 )rep4 = 1;
     }
    }
    if (rep != 4 || rep2 == 1)
    {
            if((*finish)[l] == 0)
            {
                    if ((*base)[l][g].registre == 1  )
                    {

                        printf("Le passager est-il européen ? 1  = non , 0 = oui \n");
                        scanf("%d", &rep);
                        if ( rep == 0)
                        {
                            printf("le pasager vas-t-il en europe ? 1 = non, 0 = oui\n");
                            scanf("%d", &rep2);
                            if (rep2 == 0)
                            {
                                printf("pas besoin de visa\n ");

                            }
                            if (rep2 == 1)
                            {

                                printf("Prendre le visa \n");
                                scanf("%s", (*base)[l][g].visa);
                            }
                        }
                        if (rep == 1)
                        {
                            printf("Prendre le visa");
                            scanf("%s", (*base)[l][g].visa);
                        }

                        (*base)[l][g].front = 1;
                    }
            }
   }
    if(rep != 4)
    {
    if ( (*base)[l][g].registre == 0 )
   {
       printf("Veuillez enregistrer votre billet");

   }

   if ((*finish)[l] == 1)printf("L'avion à déjà décolé désolé ");
    }
      if(*ok == 0) printf("Allez vous acheter un billet");
   }




void save(client*** base, int *N, int **compteur,char*** vol, int*** place, int** finish, int **ok)
{
    char test[20];
    int test2;
    FILE *ptr;
    char name[20], name2[20], name3[20];
    int rep, rep2, rep3, rep4,rep5, i, j, k, l, g, c;
    i = 0;
    j = 0;
    l = 0;
    g = 0;
    rep2 = 0;
    rep = 0;
    rep4 = 0;
    printf("Vous entrez le numéro(1) ou le nom du passager(2)?");
    scanf("%d", &rep);
    if (*ok == 0) rep = 4;
    if (rep == 1)
    {
        printf("\nEntrez le numéro");
        scanf("%d", &test2);

            while (rep2 == 0 && j < *N)
            {
                k = 0;
                while (rep2 == 0 && k < (*compteur)[j])
                {
                    if (test2 == (*base)[j][k].num)
                    {
                        rep2 = 1;
                        l = j;
                        g = k;
                    }

                    k = k+1;
                }
                j = j+1;
        }

    }
    if (rep == 2)
    {
        printf("\nEntrez le nom");
         scanf("%s", test);

                 while (rep2 == 0 && j < *N)
                {
                    k = 0;
                    while (rep2 == 0 && k < (*compteur)[j])
                    {
                        if (strcmp(test, (*base)[j][k].nom) == 0)
                        {
                            rep2 = 1;
                            l = j;
                            g = k;
                        }

                        k = k+1;
                    }
                    j = j+1;

            }
        }
    if (rep2 == 1)
            {

            while (rep4 == 0){
                printf("\nEst-ce bien vous ?: (oui = 1; non = 0)\n");
                printf("\nNOM : %s \n", (*base)[l][g].nom);
                printf("\nPRENOM : %s \n", (*base)[l][g].prenom);
                printf("NUMERO : %d \n", (*base)[l][g].num);
                scanf("%d", &rep4);

                rep5 = rep4;
                if (rep5 == 0)
                    {
                        rep2 = 0;
                        j = l;
                        k = g + 1;
                        if (rep == 1)
                         {
                                 while (rep2 == 0 && j < *N)
                                 {
                                     while (rep2 == 0 && k < (*compteur)[j])
                                     {
                                         if (test2 == (*base)[j][k].num)
                                         {
                                             rep2 = 1;
                                             l = j;
                                             g = k;
                                             rep5 = 1;
                                         }
                                         k = k+1;
                                         i = i + 1;
                                     }
                                     j = j+1;
                                     k = 0;
                             }
                         }

                         if (rep == 2)
                         {
                                      while (rep2 == 0 && j < *N)
                                     {
                                         while (rep2 == 0 && k < (*compteur)[j])
                                         {
                                             if (strcmp(test, (*base)[j][k].nom) == 0)
                                             {
                                                 rep2 = 1;
                                                 l = j;
                                                 g = k;
                                                 rep5 = 1;

                                             }
                                             k = k+1;
                                         }
                                         j = j+1;
                                         k = 0;
                                     }
                             }
                    }
                if (j == *N && rep2 == 0 )rep4 = 1;
            }
            }
    if (rep2 == 0)printf("Vous n'avez pas acheté votre billet\n ");


    if (rep2 == 1)
    {


        if ( (*base)[l][g].registre == 1)
        {
            printf("Vous avez dejà un billet");
            rep2 = 0;
        }

        if ((*finish)[l] == 0 && rep2 ==1)
        {
            (*base)[l][g].secu = 0;
            sprintf(name,"passager%d%d.txt",l,g);

            ptr =  fopen(name, "w+");
            fprintf(ptr, "Numéro : %d", (*base)[l][g].num );
            fprintf(ptr, "\n");
            fprintf(ptr, "Nom : %s", (*base)[l][g].nom);
            fprintf(ptr, "\n");
            fprintf(ptr, "Prénom : %s", (*base)[l][g].prenom);
            fprintf(ptr, "\n");
            fprintf(ptr, "Nationalité : %s", (*base)[l][g].nationalite);
            fprintf(ptr, "\n");
            fprintf(ptr, "Date de naissance : %d", (*base)[l][g].naiss);
            fprintf(ptr, "\n");
            fprintf(ptr, "Passeport : %s", (*base)[l][g].passeport);
            fprintf(ptr, "\n");
            fprintf(ptr, "Destination : %s", *vol[((*base)[l][g].dest)] );
            fprintf(ptr, "\n");
            printf("\nVoulez vous une place spécifique  dans l'avion : 0 = oui ; 1 = non?");
            scanf("%d", &rep);
            if (rep == 0)
            {
                lol:  printf("\nQuelle place voulez vous ?");
                scanf("%d", &c);
                if ((*place)[l][c] == 0)
                {
                    (*place)[l][c] = 1;
                }
                else
                {
                    printf("\nla place est prise veuillez en choisir une autre, parmis les suivantes: ");
                    for (i = 0; i < 50 ; i++)
                    {
                        if ((*place)[l][i] == 0)printf("\n%d", i);
                    }
                    goto lol;}
            }
            else
            {
                rep3 = 0;
                while (rep3 == 0)
                {
                    c = (rand()%49);
                    if ((*place)[l][c] == 0) rep3 = 1;
                }
            }
        (*place)[l][c] = 1;
        (*base)[l][g].place = c;
        fprintf(ptr, "Numéro de place : %d", c);
        fprintf(ptr, "\n");
        fprintf(ptr, "Priority:");
        if((*base)[l][g].priority == 0)fprintf(ptr, "OUI");
        if((*base)[l][g].priority == 1) fprintf(ptr, "NON");
        fprintf(ptr, "\n");
        fprintf(ptr, "Nombre de bagage: %d",(*base)[l][g].bagages);
        fclose(ptr);
        if ((*base)[l][g].bagages == 1)
        {
            sprintf(name2,"bagages(1)%d%d.txt",l,g);
            ptr =  fopen(name2, "w+");
            if((*base)[l][g].priority == 0) fprintf(ptr, "Priority");
            fclose(ptr);
        }
        if ((*base)[l][g].bagages == 2)
            {
                     sprintf(name2,"bagages(1)%d%d.txt",l,g);
                     ptr =  fopen(name2, "w+");
                     if((*base)[l][g].priority == 0) fprintf(ptr, "Priority");
                     fclose(ptr);
                    sprintf(name3,"bagages(2)%d%d.txt",l,g);
                    ptr =  fopen(name3, "w+");
                    if((*base)[l][g].priority == 0) fprintf(ptr, "Priority");
                    fclose(ptr);
            }
    (*base)[l][g].registre = 1;
    }
        if ((*finish)[l] == 1)printf("L'avion à déja décollé ");
    }

}



void achat(client*** base, int *N, int **compteur, int **finish, int**ok)
{
    int rep;
    int rep2 = 0;

    printf("Entrez la destiniation (numéro) :");
    scanf("%d", &rep);
    if (rep <= *N)
        {

        if ((*finish)[rep - 1] == 0)
            {
            if (compteur[rep - 1] == 0)
            {
                client *bose = (client*)malloc(sizeof(client));
                (*base)[rep - 1] = bose ;
            }
            if (compteur[rep - 1] > 0)
            {
                client *bose  = realloc(*(*base + rep - 1), ((*compteur)[rep - 1] + 1)  * sizeof(client));
                (*base)[rep - 1] = bose;
            }
            if ((*compteur)[rep - 1] < 50)
            {
                 (*base)[rep - 1][(*compteur)[rep - 1]].abs = 1 ;
                *ok = *ok + 1;
                (*base)[rep - 1][ (*compteur)[rep - 1] ].dest = rep - 1;
                printf("nom?");
                scanf("%s", (*base)[rep - 1][ (*compteur)[rep - 1] ].nom );
                printf("Prenom?");
                scanf("%s", (*base)[rep - 1][ (*compteur)[rep - 1] ].prenom );
                printf("Date de naissance");
                scanf("%d",&(*base)[rep - 1][ (*compteur)[rep - 1] ].naiss ) ;
                printf("nationalité?");
                scanf("%s", (*base)[rep - 1][ (*compteur)[rep - 1] ].nationalite );


                while (rep2 == 0)
                {
                    printf("Combien de bagages ");
                    scanf("%d", (&(*base)[rep - 1][ (*compteur)[rep - 1]].bagages));

                    if ((*base)[rep - 1][ (*compteur)[rep - 1]].bagages > 1 && (*base)[rep - 1][(*compteur)[rep - 1]].bagages < 3 )

                    {
                        printf("Voulez vous être priority car vous etes obligé , plus de 2 bagages (oui = 0 ; non = 1) ?");
                        scanf("%d", &(*base)[rep - 1][(*compteur)[rep - 1]].priority);

                    }
                    else
                    {
                        printf("Voulez vous être priority (oui = 0 ; non = 1 )?");
                        scanf("%d", &(*base)[rep - 1][(*compteur)[rep - 1]].priority   );
                    }
                    if(((*base)[rep - 1][ (*compteur)[rep - 1]].bagages > 1 && (*base)[rep - 1][(*compteur)[rep - 1]].priority == 1) ||  (*base)[rep - 1][(*compteur)[rep - 1]].bagages > 2  )

                    {
                        printf("Trop de bagages, retirer un bagage ou devenez priority");
                    }

                    else rep2 = 1;


                }

                printf("passeport :");
                 (*base)[rep - 1][(*compteur)[rep - 1]].abs = 1 ;
                scanf("%s", (*base)[rep - 1][(*compteur)[rep - 1]].passeport);

                (*base)[rep - 1][(*compteur)[rep-1]].num = (*base)[rep - 1][(*compteur)[rep-1]].nom[0] +(*base)[rep - 1][(*compteur)[rep-1]].prenom[0] +(*base)[rep - 1][(*compteur)[rep-1]].naiss + (*base)[rep - 1][(*compteur)[rep-1]].nationalite[0]+ (*base)[rep - 1][(*compteur)[rep-1]].nationalite[1] + (*base)[rep - 1][(*compteur)[rep-1]].bagages + (*base)[rep - 1][(*compteur)[rep-1]].priority + (*base)[rep - 1][(*compteur)[rep-1]].passeport[0] + (*base)[rep - 1][(*compteur)[rep-1]].passeport[1]+ (*base)[rep - 1][(*compteur)[rep-1]].passeport[2] + (*base)[rep - 1][(*compteur)[rep-1]].passeport[3] + (*base)[rep - 1][(*compteur)[rep-1]].passeport[4];



                printf("Votre billet : \n");
                printf("Identité : %s %s \n", (*base)[rep - 1][(*compteur)[rep - 1]].nom , (*base)[rep - 1][(*compteur)[rep - 1]].prenom );
                printf("Date de naissance : %d \n", (*base)[rep - 1][(*compteur)[rep - 1]].naiss);
                printf("Nationalité : %s \n", (*base)[rep - 1][(*compteur)[rep - 1]].nationalite);
                printf("Passeport : %s \n", (*base)[rep - 1][(*compteur)[rep - 1]].passeport);
                printf("Bagages %d \n", (*base)[rep - 1][(*compteur)[rep - 1]].bagages);
                if ((*base)[rep - 1][(*compteur)[rep - 1]].priority == 0) {printf("Priroty \n");}
                else {printf("Non priority \n");}
                (*base)[rep - 1][(*compteur)[rep-1]].registre = 0;
                printf("Numéro : %d \n", (*base)[rep - 1][(*compteur)[rep-1]].num );
                (*compteur)[rep -1] = (*compteur)[rep -1] + 1;
                (*base)[rep - 1][(*compteur)[rep-1]].secu = 0;
                (*base)[rep - 1][(*compteur)[rep-1]].front = 0;
                (*base)[rep - 1][(*compteur)[rep-1]].embarqu = 0;
                (*base)[rep - 1][(*compteur)[rep-1]].embarqbag = 0;

                (*base)[rep - 1][(*compteur)[rep - 1]].abs = 1 ;
        }
            else
            {
                printf("Il n'y a plus de place dans cette avion désolé");
            }
    }
        if ((*finish)[rep - 1] == 1)printf("Cet avion à déjà décolé, désole");
}

    if (rep > *N)printf("Ce vol n'existe pas");
}

void vole(char*** vol, client*** base, int *N, int ***place, int **compteur, int **finish, stats **infos)
{
    int plus;
    int i , j;
    int inter;
    printf("Combien de vol voulez vous ajouter?");
    scanf("%d", &plus);
    if (*N != 0) //Ici si un ou plusieurs vols ont été ajouté on rentre dans cette boucle.
    {

             inter = *N  ;
             *N = *N + plus ; //On ajoute donc le nombre de vol ajouté à l'ancien nombre de vol afin de le mettre à jour.

             char **voile = realloc(*vol, *N * (10 * sizeof( char*)));
             *vol = voile; //Ici on augmente la taille du tableau dynamique de vol pour avoir un tableau contenant le nouveaux nombre de vols , on passe par une autre variable afin d'éviter les bugs mémoirs.

             client **based = realloc(*base , *N * sizeof(client*));
             *base = based;//Ici on augmente la taille de la première dimensons du tableau de clients afin d'avoir le nombre de vol possible pour les ranger correspondant aux nouveaux nombres de vol.

             stats *ino = realloc(*infos, *N * sizeof(stats));
             *infos = ino;//Ici on augmente la taille du tableau dynamique de statistique afin que chaque vol puisse avoir ses statistiques sans aucun problèmes.

             for (i = inter ; i<*N ; i++)
             {
                      (*infos)[i].acces = 0;
                      (*infos)[i].priority = 0;
                      (*infos)[i].normale = 0;
                      (*infos)[i].poids = 0.0;

                  }//on incrémente 0 pour l'acces  , également pour les autres infos afin déviter les bugs, cela servira dans la partie statistiques afin que l'on ne puisse pas avoir accèes au statistiques d'un vol qui n'a pas décollé (lorsqu'il décolle pendant l'embarquement on lui donnera la valeur 1)
             int *compte = realloc(*compteur , *N * sizeof(int));
             *compteur = compte;//on augmente la taille du tableau dynamique permettant de compter le nombre de personne ayant acheté un billet sur chaque vol.
        for (i = inter ; i < *N ; i++ ) (*compteur)[*N] = 0;//On donne la valeur 0 à chaque vol ajouté car personne n'a encore acheté de billet pour le nouveau vol.

             int *finis = realloc(*finish , *N * sizeof(int));
             *finish = finis;//On augmente la taille du tableau dynamique permettant de savoir si un vol à décolé ou non.
        for(i = inter ; i< *N ; i++) (*finish)[*N] = 0;//On donne la valeur 0 car ces vols n'ont pas décollé , une fois qu'ils auront décollés ils auront la valeur de 1.

             int **pace = realloc(*place, *N *  sizeof(int*));
             *place = pace;//On augemnte la taille de la première dimensions du tableau dynamique à deux dimensions  permettant de savoir si une place est disponible sur un vol.La premiere dimensions dimension correspond au vols d'ou le fait qu'on lui administre une taille *N.
             for (i = (inter)  ; i < *N ; i++)
                  {
                      (*place)[i]  = (int*)malloc(50 * sizeof(int));
                      for (j = 0; j < 50 ; j ++)(*place)[i][j] = 0; // Pour chaque vol ajouté on augmente la taille de la deuxième dimensions du tableau dynamique de 50, car il y a 50 place dans chaque vol.
                      (*vol)[i] = (char*)malloc(10 * sizeof(char));//vol étant un tableaux dynamique à deux dimensions la deuxièmee dimensions sert à stocker les caractère pour écrire le nom de chaque vol ainsi pour chaque vol ajouté on alloue 10 carractère.
                      printf("Entrez  destination du vol %d", i + 1);
                      scanf("%s", *(*vol + i));
                  }

    }
    if (*N == 0) //Aucun vol n'a encore été ajouté donc on rentre dans cette boucle
    {
        *N = plus;
        //On créer dynamiquement tout les tableaux dont l'on aura besoin avec malloc,  ce sont les même que l'on a vue juste avant dans le code .
        stats *ino = (stats*)malloc(plus * sizeof(stats));
        *infos = ino;
        for (i = 0 ; i<*N ; i++)
        {
            (*infos)[i].acces = 0;
            (*infos)[i].priority = 0;
            (*infos)[i].normale = 0;
            (*infos)[i].poids = 0.0;

        }
        char   **voile = (char**)malloc(plus * (10 * sizeof(char*)));
        *vol = voile;
        for (i = 0 ; i < plus ; i++) *(*vol + i) = (char*)malloc(10 * sizeof(char));
        int **pace = (int**)malloc( plus *  sizeof(int*));
        *place = pace;

        int *compte = (int*)malloc(plus * sizeof(int));
        *compteur = compte;
        (*compteur)[0] = 0 ;

        int *finis = (int*)malloc(plus * sizeof(int));
        *finish = finis;
        (*finish)[0] = 0 ;
        client **bose = (client**)malloc(plus * sizeof(client*));
        *base = bose;
        for (i = 0 ; i < plus ; i++)
        {
            (*place)[i]  = (int*)malloc(50 * sizeof(int));
            for (j = 0; j < 50 ; j ++)(*place)[i][j] = 0;
            printf("Entrez la destination du vol %d", i + 1);
            scanf("%s", *(*vol + i));
        }
    }
}

void securite (client ***base, int *N, int **compteur, int**finish, int** ok)
{
    char test[20];
    int test2, objet;
    int rep, rep2, rep4,rep5, i, j, k, l, g;
    i = 0;
    j = 0;
    l = 0;
    g = 0;
    rep2 = 0;
    rep = 0;
    rep4 = 0;

    printf("Vous entrez le numéro(1) ou le nom du passager(2)?");
    scanf("%d", &rep);
    if(*ok == 0)rep = 4;
    if (rep != 4)
    {
    if (rep == 1)
    {
        printf("\nEntrez le numéro");
        scanf("%d", &test2);

        while (rep2 == 0 && j < *N)
            {
                k = 0;
                while (rep2 == 0 && k < (*compteur)[j])
                {
                        if (test2 == (*base)[j][k].num)
                        {
                            rep2 = 1;
                            l = j;
                            g = k;
                        }
                        k = k+1;
                }
                j = j+1;
             }
    }
    if (rep == 2)
    {
         printf("\nEntrez le nom");
         scanf("%s", test);

         while (rep2 == 0 && j < *N)
                {
                    k = 0;
                    while (rep2 == 0 && k < (*compteur)[j])
                    {
                        if (strcmp(test, (*base)[j][k].nom) == 0)
                        {
                            rep2 = 1;
                            l = j;
                            g = k;
                        }
                        k = k+1;
                    }
                    j = j+1;
                   }
        }
     while (rep4 == 0 ){
         printf("\nEst-ce bien vous ?: (oui = 1; non = 0)\n");
         printf("\nNOM : %s \n", (*base)[l][g].nom);
         printf("\nPRENOM : %s \n", (*base)[l][g].prenom);
         printf("NUMERO : %d \n", (*base)[l][g].num);
         scanf("%d", &rep4);

         rep5 = rep4;
         if (rep5 == 0)
         {
            rep2 = 0;
            j = l;
            k = g + 1;
            if (rep == 1)
            {
                     while (rep2 == 0 && j < *N)
                     {
                         k = g + 1;
                         while (rep2 == 0 && k < (*compteur)[j])
                         {
                             if (test2 == (*base)[j][k].num)
                             {
                                 rep2 = 1;
                                 l = j;
                                 g = k;
                                 rep5 = 1;
                             }
                             k = k+1;
                         }
                         j = j+1;
                         k = 0;
                 }

             }
             if (rep == 2)
             {
                     while (rep2 == 0 && j < 20)
                         {
                             k = g + 1;
                             while (rep2 == 0 && k < (*compteur)[j])
                             {
                                 if (strcmp(test, (*base)[j][k].nom) == 0)
                                 {
                                     rep2 = 1;
                                     l = j;
                                     g = k;
                                     rep5 = 1;
                                 }
                                 k = k+1;
                             }
                             j = j+1;
                             k = 0;
                         }
                     }

        }
             if (j == *N && rep2 == 0 )rep4 = 1;
     }
    if ( (*base)[l][g].registre == 0 )
           {
               printf("Veuillez enregistrer votre billet");

           }
    if ((*base)[l][g].secu == 1 )

           {
               printf("Vous êtes déjà passé par la sécurité");

           }
    if ((*base)[l][g].front == 0)
           {

               printf("veuillez passer par la frontière avant");
           }
    if (rep != 4 || rep2 == 1)
    {

        if((*finish)[l] == 0)
            {

                if ((*base)[l][g].registre == 1 && (*base)[l][g].secu == 0 && (*base)[l][g].front == 1 )
                {

                    int tabobjet[7];

                    for (i=0; i<7 ;i++) tabobjet[i]=0;

                    char tab2[][50] = {
                    "liquide plus de 100ml",
                    "armes",
                    "instrument tranchant",
                    "substance explosive",
                    "appareil paralysant",
                    "outil travail",
                    "objet contondant",
                    };


                    panneau : printf("Que possedez vous ? \n");

                    printf("1. liquide plus de 100ml\n");
                    printf("2. armes a feu\n");
                    printf("3. instrument tranchants\n");
                    printf("4. subtance explosive\n");
                    printf("5. appareil a effet paralysant\n");
                    printf("6. outil travail\n");
                    printf("7. objet contondants\n");
                    printf("8. FIN");

                    scanf("%d", &objet);

                    switch (objet)
                    {

                        case 1 : printf("objet interdit");
                        tabobjet[0] = tabobjet[0] + 1;
                        goto panneau;
                        case 2 : printf("objet interdit");
                        tabobjet[1] = tabobjet[1] + 1;
                        goto panneau;
                        case 3 : printf("objet interdit");
                        tabobjet[2] = tabobjet[2] + 1;
                        goto panneau;
                        case 4 : printf("objet interdit");
                        tabobjet[3] = tabobjet[3] + 1;
                        goto panneau;
                        case 5 : printf("objet interdit");
                        tabobjet[4] = tabobjet[4] + 1;
                        goto panneau;
                        case 6 : printf("objet interdit");
                        tabobjet[5] = tabobjet[5] + 1;
                        goto panneau;

                        case 7 :printf("objet interdit");
                            tabobjet[6] = tabobjet[6] + 1;
                        goto panneau;

                        case 8 :
                            break;
                    }

                    for (i=0 ; i<7; i++)
                    {
                        if(tabobjet[i]>0) printf("Il y a %d %s\n", tabobjet[i], tab2[i]);
                    }

                    if((*base)[l][g].bagages == 1)
                    {
                        printf("poids bagage : ");
                        scanf("%f", &(*base)[l][g].poids1);
                    }
                    if ((*base)[l][g].bagages == 2)
                    {
                        printf("poids bagage 1 : ");
                        scanf("%f", &(*base)[l][g].poids1);
                        printf("\npoids bagage 2 :");
                        scanf("%f", &(*base)[l][g].poids2);

                    }

                    (*base)[l][g].secu =1;
                    (*base)[l][g].abs = 0;

                }

        }

    }
    if ((*finish)[l] == 1)printf("L'avion à déjà décolé désolé ");
    }
       if(*ok == 0) printf("Allez vous acheter un billet");
}




void embarquement(client*** base, int *N, int **compteur,char*** vol, int*** place, int**finish, stats **infos){

    int rep,rep2,rep3,test2 ,a,b,i, j, k, l, g, rep4, rep5,rep6, rep7,rep8, c,d,e;
    char test[20];
    k = 0;
    j = 0;
    a = 0;
    rep2 = 0;
    rep4 = 0;
    b = 0;
    c=0;
    d=0;

    printf("\nPour quelle vol voulez vous faire l'embarquement (Plus personnes ne pourras acheter de billet pour ce vol)");
    scanf("%d", &rep);
    rep = rep - 1;
    if (rep >= *N ) printf("\nCe vol n'existe pas\n");
    if (rep < *N)
    {
        if ((*finish)[rep] == 1 )printf("L'avion a déjà décollé ");
        if ((*finish)[rep] == 0)
        {

            finish: for (i = 0; i< (*compteur)[rep]; i++)
            {
                if ((*base)[rep][i].abs == 0 )
                {
                    a = a + 1;
                }
            }
            if (a < (*compteur)[rep]){printf("\nTous les passagers n'ont pas remplis les étapes avant de pouvoir embarquer, veuiller vous assurer que tout est faits avant d'embarquer tout le monde, y'a t'il des gens qui ne comptent pas venir ?(oui = 0; non = 1)");

            scanf("%d",&rep3);
                if (rep3 == 1) goto end;
            if (rep3 == 0)
            {
                    back: printf("\nVoulez vous saisir le nom (2)ou le numéro (1) du passager comptant s'absenter ");

                    scanf("%d", &rep6);

                    if (rep6 == 1)
                    {
                        printf("\nEntrez le numéro");
                        scanf("%d", &test2);

                            while (rep2 == 0 && j < *N)
                            {
                                k = 0;
                                while (rep2 == 0 && k < (*compteur)[j])
                                {
                                    if (test2 == (*base)[j][k].num)
                                    {
                                        rep2 = 1;
                                        l = j;
                                        g = k;
                                    }
                                    k = k+1;
                                }
                                j = j+1;
                        }

                    }
                    if (rep6 == 2)
                    {
                        printf("\nEntrez le nom");
                         scanf("%s", test);

                                 while (rep2 == 0 && j < *N)
                                {
                                    k = 0;
                                    while (rep2 == 0 && k < (*compteur)[j])
                                    {
                                        if (strcmp(test, (*base)[j][k].nom) == 0)
                                        {
                                            rep2 = 1;
                                            l = j;
                                            g = k;
                                        }
                                        k = k+1;
                                    }
                                    j = j+1;
                                }
                            }
                        }
                    while (rep4 == 0 ){
                        printf("\nEst-ce bien vous ?: (oui = 1; non = 0)\n");
                        printf("\nNOM : %s \n", (*base)[l][g].nom);
                        printf("\nPRENOM : %s \n", (*base)[l][g].prenom);
                        printf("NUMERO : %d \n", (*base)[l][g].num);
                        scanf("%d", &rep4);

                        rep5 = rep4;
                        if (rep5 == 0)
                        {
                            rep2 = 0;
                            j = j-1;
                            if (rep6 == 1)
                             {
                                     while (rep2 == 0 && j < *N)
                                     {
                                         while (rep2 == 0 && k < (*compteur)[j])
                                         {
                                             if (test2 == (*base)[j][k].num)
                                             {
                                                 rep2 = 1;
                                                 l = j;
                                                 g = k;
                                                 rep5 = 1;
                                             }
                                             k = k+1;
                                         }
                                         j = j+1;
                                         k = 0;
                                 }
                             }

                             if (rep6 == 2)
                             {
                                          while (rep2 == 0 && j < 20)
                                         {

                                             while (rep2 == 0 && k < (*compteur)[j])
                                             {
                                                 if (strcmp(test, (*base)[j][k].nom) == 0)
                                                 {
                                                     rep2 = 1;
                                                     l = j;
                                                     g = k;
                                                     rep5 = 1;
                                                 }
                                                 k = k+1;
                                             }
                                             j = j+1;
                                             k = 0;
                                         }
                                     }
                                 }
                        if (j == *N && rep2 == 0 )rep4 = 1;
                    }

                    for (i = (k - 1); (i + 1) < (*compteur)[rep]; i ++)
                    {

                         (*base)[rep][i] = (*base)[rep][i + 1];
                    }
                e = (*compteur)[rep];
                e = e - 1;
                (*compteur)[rep] = e;

                    printf("\nY'a t'il un autre passager ne venant pas 1 = oui; 0 = non ?");
                    scanf("%d", &rep7);
                    if (rep7 == 1) goto back;
                    if (rep7 == 0) goto finish;
                }


            }

         if (a == (*compteur)[rep])
         {
            nope:  printf("\nTout le monde est bien devant la porte d'embarquation ? oui = 1; non = 0");
            scanf("%d", &rep2);
            if (rep2 == 0) goto nope;
            printf("\nTrès bien tout le monde est là, nous allons en premier lieux embarquer les passagers priority");

             for (i = 0; i < (*compteur)[rep]; i ++)
             {
                 if((*base)[rep][i].priority == 0)
                 {
                     (*infos)[rep].priority =  (*infos)[rep].priority + 1;
                     (*base)[rep][i].embarqu = 1;
                 }
             }
              printf("\nTrès bien tout les passagers non priority peuvent maintenant embarquer");
             for (i = 0; i < (*compteur)[rep]; i ++)
                     {
                         if((*base)[rep][i].priority == 1)
                         {
                             (*infos)[rep].normale =  (*infos)[rep].normale + 1;
                             (*base)[rep][i].embarqu = 1;
                         }
                     }

             printf("\nTrès bien désormais on va charger les bagages  ");

             for (i = 0; i < (*compteur)[rep]; i ++)
                           {
                               if((*base)[rep][i].bagages == 1)
                               {
                                   b = b + 1;
                                   (*infos)[rep].poids =  (*infos)[rep].poids + (*base)[rep][i].poids1;

                               }
                               if((*base)[rep][i].bagages == 2)
                               {
                                   b = b + 2;
                                   (*infos)[rep].poids =  (*infos)[rep].poids + (*base)[rep][i].poids1 + (*base)[rep][i].poids2 ;
                               }
                               (*base)[rep][i].embarqbag = 1 ;

                           }

             printf("Le programme verifie que tout le monde est bien a bord ");

             for (i = 0; i < (*compteur)[rep]; i ++)
                                      {
                                          if((*base)[rep][i].embarqbag == 1 )

                                          {
                                              if((*base)[rep][i].bagages == 1) c = c + 1;
                                              if((*base)[rep][i].bagages == 2) c = c + 2;
                                          }

                                          if((*base)[rep][i].embarqu == 1)d = d+1;
                                      }
             if (c == b || d == (*compteur)[rep])
             {

                 (*infos)[rep].poids = (*infos)[rep].poids / c;
                 (*infos)[rep].remplissage = (*compteur)[rep] * 2 ;
                 (*infos)[rep].acces = 1;
                 azy: printf("Tout est bon pour lancer le vol voulez vous lancer le vol ? (oui = 0;non = 1)");
                 scanf("%d", &rep8);
                 if (rep8 == 0)
                 {
                     (*finish)[rep] = 1;
                     printf("L'avion à bien décolé ");
                 }
                 if (rep8 == 1)goto azy;
                 end : printf("\n");
             }
        }
    }
    }


void statistiques(stats **infos, int **compteur, int *N){
    int rep;
    float priority, normale ;
    printf("Pour quelle vol voulez vous voir les statistiques (il faut que ce vol ai décolé )");
    scanf("%d", &rep);

    rep = rep - 1;
    if (rep < *N)
    {
    if ((*infos)[rep].acces == 1)
    {
        if ((*infos)[rep].priority > 0)
        {
        priority = ((*infos)[rep].priority * 100 ) / ((*compteur)[rep]);
        }
        else priority = 0;
        if ((*infos)[rep].normale > 0)
        {
        normale = ((*infos)[rep].normale * 100 ) / ((*compteur)[rep]);
        }
        else normale = 0;
        printf("\nLe vol était remplis de %d passagers priority, soit %f pourcent du vol", (*infos)[rep].priority, priority);
        printf("\nLe vol était remplis de %d passagers NON priority, soit %f pourcent du vol", (*infos)[rep].normale, normale);
        printf("\n Ce vol contenait %d personne sur 50 places disponible, l'avion était remplis à %d pourcent ", (*compteur)[rep], (*infos)[rep].remplissage);
        printf("\n Le poids moyen des bagages était de %f KG", (*infos)[rep].poids);


    }
    if ((*infos)[rep].acces == 0)printf("L'avion n'a pas décollé");
    }
    else printf("Ce vol n'existe pas ");
}


int main(int argc, const char * argv[]) {
    int rep;
    int *ok ;
    ok = 0;
    int i;
    stats *infos;
    int *compteur;
    client **base = NULL ;
    char** vol = NULL ;
    int ** place = NULL;
    int * finish = NULL;
    int N;
    int J;
    N = 0;
    J = 0;

    affichage : printf(" 1.Ajouter Vol\n 2.Achat\n 3.Enregitrer\n 4.Frontière\n 5.Sécurité\n 6.Embarquement \n 7.Vol Disponible\n 8.Statistique");
    scanf("%d", &rep);
    switch (rep) {
        case 1:
            vole(&vol, &base, &N, &place,&compteur,&finish, &infos) ;


            goto affichage;

            case 2:

            achat(&base, &N, &compteur, &finish, &ok);


            goto affichage;
            case 3:
            save(&base, &N, &compteur,&vol, &place, &finish, &ok);
            goto affichage;
            case 4:
            frontiere(&base, &N, &compteur, &finish, &ok);
            goto affichage;
            case 5:
            securite(&base, &N, &compteur, &finish, &ok);

            goto affichage;
            case 6:
            embarquement(&base, &N, &compteur,&vol, &place, &finish, &infos);
            goto affichage;
            case 7:
            for (i = 0 ; i < N ; i ++)
            {

                    printf("\n %d .%s \n",i + 1, vol[i]);
                    printf("place dispo = %d", (compteur)[i - 1]);

            }
            goto affichage;

            case 8:
            statistiques(&infos, &compteur, &N);
            goto affichage;

        default:
            printf("Veuillez entrer une option disponible");
            goto affichage;
    }
    return 0;
}
