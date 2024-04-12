#include <stdio.h>              //debut de l'inclusion des bibliotheques
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>        //fin de l'inclusion des bibliotheques
#define MAX 100                 // Super tableau de 100 elements pour les produits
#define LOGIN "diallo"
#define MDP "diallo"
#define ENTER 13         // code ASCII de la touche (Entree)
#define BKSP 8              //  code ASCII de la touche (BLACKSPACE)
#define TAB 9                // code ASCII de la touche (Tabulation)
#define SPACE 32

void gotoxy(int x,int y)        //fonction nous permettant de positioner le curseur //
{
    COORD a;
    a.X=x; a.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

typedef struct produit produit; //Données Sur le Projet
struct produit
{
    int code;
    char designation[25];
    int quantite;
    int prix;
    int smin;
    int smax;
};
static int nbp=1;
static produit T[MAX];

void efface()
{
    system("cls");
}
void pause()
{
    system("pause");
}
void ln()
{
    printf("\n");
}
void tableau()
{
    gotoxy(20,2);HO();LH(43);HF();
    gotoxy(20,3);LV();printf("           Informations du produit         ");LV();
    gotoxy(20,4);LIG();LH(22);LIH();LH(20);LID();
    gotoxy(20,5);LV();printf("Le Code du produit    ");LV();space(20);LV();
    gotoxy(20,6);LIG();LH(22);LIM();LH(20);LID();
    gotoxy(20,7);LV();printf("La designation        ");LV();space(20);LV();
    gotoxy(20,8);LIG();LH(22);LIM();LH(20);LID();
    gotoxy(20,9);LV();printf("Le Prix Unitaire      ");LV();space(20);LV();
    gotoxy(20,10);LIG();LH(22);LIM();LH(20);LID();
    gotoxy(20,11);LV();printf("Le Seuil Min          ");LV();space(20);LV();
    gotoxy(20,12);LIG();LH(22);LIM();LH(20);LID();
    gotoxy(20,13);LV();printf("Le Seuil Max          ");LV();space(20);LV();
    gotoxy(20,14);BO();LH(22);LIB();LH(20);BF();

}

void HO()
{
 char crt=201;
 printf("%c",crt);
}
void LH(int n)
{
    int i;
    char crt=205;
    for(i=1;i<=n;i++)
    {
        printf("%c",crt);
    }
}
void HF()
{
 char crt=187;
 printf("%c",crt);
}
void LV()
{
    char crt=186;
    printf("%c",crt);
}
void BO()
{
 char crt=200;
 printf("%c",crt);
}
void BF()
{
 char crt=188;
 printf("%c",crt);
}
void LIG()
{
 char crt=204;
 printf("%c",crt);
}
void LID()
{
 char crt=185;
 printf("%c",crt);
}
void LIM()
{
 char crt=206;
 printf("%c",crt);
}
void LIH()
{
 char crt=203;
 printf("%c",crt);
}
void LIB()
{
 char crt=202;
 printf("%c",crt);
}
 void u(int n)
{
    printf("%c",(char)n);
}
void m(int n,int f)
{
    int i;
    for(i=1;i<=f;i++)
    {
        printf("%c",(char)n);
    }
}
void space(int n)
{
    int i;
    char crt=' ';
    for(i=1;i<=n;i++)
    {
        printf("%c",crt);
    }
}

void connexion()
{
      int i;
     char nom_utilisateur[15];
     char mot_passe[15];
     char ch;
    efface();
     system("color 55");
    gotoxy(5,3);printf("Veuillez-vous  identifier  a  travers  vos  informations");
    gotoxy(20,5); HO();LH(20);LIH();LH(20);HF();
    gotoxy(20,6);LV();printf("Nom d'utilisateur"); gotoxy(41,6);LV();gotoxy(62,6);LV();
    gotoxy(20,7);LIG();LH(20);LIM();LH(20);LID();
    gotoxy(20,8);LV();printf("Mot de passe");gotoxy(41,8);LV();gotoxy(62,8);LV();
    gotoxy(20,9);BO();LH(20);LIB();LH(20);BF();
a: gotoxy(5,12);printf("Saisir le Nom d'utilisateur !         ");
    gotoxy(43,6);scanf("%s",&nom_utilisateur);

    if(strcmp(nom_utilisateur, LOGIN)!=0)
    {
        gotoxy(5,12);  printf("Nom d'utilisateur incorrect, reessayer");getch();
        gotoxy(43,6);printf("                 ");
        gotoxy(5,12);  printf("                                                                 ");
        goto a;
    }
    else
    {
        b: gotoxy(5,12);printf("Saisir le mot de passe                ");
        i=0;
        while (1)
        {
        gotoxy(43+i,8);ch=getch();
            if (ch==ENTER)
            {
                mot_passe[i]='\o';
                break;
            }
            else if (ch==BKSP)
            {
                if (i>0)
                {
                    if (i==1)
                    {
                        printf("\b\b");
                        i--;
                    }
                    else
                    {
                        printf("\b\b");
                        i--;
                    }
                }
            }
            else if ((ch==TAB) || (ch==TAB))
            {
                continue;
            }
            else
            {
                mot_passe[i]=ch;
                i++;
                gotoxy(43+i,8);printf("*");
            }
    }

        if (strcmp(mot_passe,MDP)!=0)
        {
            gotoxy(5,12);  printf("Mot de passe  incorrect,  reessayer");getch();
            gotoxy(43,8);printf("                   ");
            gotoxy(5,12);  printf("                                                                 ");
            goto b;
        }
        else
        {
            gotoxy(5,12);printf("Identification Correct"); getch();
            gotoxy(5,12);printf("                                       ");
        }
    }
}

 void presentation()
 {
    efface();
    system("color 2E");
    gotoxy(50,2);HO();LH(24);HF();
    gotoxy(50,3);LV();printf(" PRESENTATION DU PROJET ");LV();
    gotoxy(32,4);HO();LH(17);LIB();LH(24);LIB();LH(17);HF();
     gotoxy(32,5);LV();printf("   Le projet que vous allez decouvrir gere une Entreprise   ");LV();
     gotoxy(32,6);LV();printf("     commerciale ou chaque produit est connu par  :         ");LV();
     gotoxy(32,8);LV();printf("                         Code                               ");LV();
   gotoxy(32,10);LV();printf("                         Designation                        ");LV();
   gotoxy(32,12);LV();printf("                         Prix unitaire                      ");LV();
   gotoxy(32,14);LV();printf("                          Quantite                          ");LV();
   gotoxy(32,16);LV();printf("                          Seuil Min                         ");LV();
   gotoxy(32,18);LV();printf("                          Seuil Max                         ");LV();
   gotoxy(32,7);LIG();LH(60);LID();       gotoxy(32,9);LV();space(60);LV();        gotoxy(32,11);LV();space(60);LV();
   gotoxy(32,13);LV();space(60);LV();    gotoxy(32,15);LV();space(60);LV();        gotoxy(32,17);LV();space(60);LV();
    gotoxy(32,19);BO();LH(60);BF();
   gotoxy(55,8);u(4);   gotoxy(55,10);u(4);  gotoxy(55,12);u(4);   gotoxy(55,14);u(4);  gotoxy(55,16);u(4);  gotoxy(55,18);u(4);
   gotoxy(45,22);pause();
 }

 void saisie()
 {
    int i=1,j=1;
    char rep;
    efface();
    autre:tableau();
    gotoxy(58,3);printf("%d",j);
                T[i].code=i;
            if (i>=1)
            {
                gotoxy(46,5);printf("P000%d",T[i].code);
            }
             else if (i>9)
            {
               gotoxy(46,5);printf("P00%d",T[i].code);
            }
            else if (i>99)
            {
                gotoxy(46,5);printf("P0%d",T[i].code);
            }
    gotoxy(46,7);scanf("%s",&T[i].designation);

    p:gotoxy(46,9);scanf("%d",&T[i].prix);
       if ((T[i].prix<=0) || ( (scanf("%d",&T[i].prix) )!=1))
    {
            gotoxy(46,9);printf("Erreur, recommencez !!!");getch();
            gotoxy(46,9);printf("                                   ");goto p;
            fflush(stdin);
    }

    s1:gotoxy(46,11);scanf("%d",&T[i].smin);
        if ((T[i].smin<=0) || ( (scanf("%d",&T[i].smin )!=1)))
    {
            gotoxy(46,11);printf("Erreur, recommencez !!!");getch();
            gotoxy(46,11);printf("                                   ");goto s1;
            fflush(stdin);
    }

    s2:gotoxy(46,13); scanf("%d",&T[i].smax);
        if ( (T[i].smax<=0) || ( (scanf("%d", &T[i].smax) !=1)))
    {
            gotoxy(46,13);printf("Erreur, recommencez !!!");getch();
            gotoxy(46,13);printf("                                   ");goto s2;
            fflush(stdin);
    }

    r:gotoxy(20,20);printf("Vouliez vous ajouter un autre produit <<O pour Oui  et  Npour non>>:  [    ] \n");
    gotoxy(92,20);scanf("%c",&rep);

            if((rep=='o') || (rep=='O'))
            {
                i++;j++;nbp++;
                while((rep=='o') || (rep=='O'))
                {
                    efface();
                    goto autre;
                }
            }
            else if((rep=='n') || (rep=='N'))
            {
                efface();
                gotoxy(25,10);printf(" FIN DE LA SAISIE DES PRODUITS");
                gotoxy(25,22);pause();
            }
            else
            {
                gotoxy(45,36);printf("Erreur, respecter le menu !!!");getch();
                gotoxy(45,36);printf("                                          ");gotoxy(74,34);printf("  ");
                goto r;
            }

    gotoxy(35,35);pause();

 }

 void affichage()
 {
      int i,j;
gotoxy(10,3);HO();LH(15);LIH();LH(29);LIH();LH(15);LIH();LH(15);LIH();LH(11);HF();
gotoxy(10,4);LV();printf("   Code    ");space(4);LV();space(5);printf("   Designation      ");  space(4);LV();printf(" Prix Unitaire ");LV();printf(" Seuil Min     ");LV();printf(" Seuil Max ");LV();
gotoxy(10,5);LIG();LH(15);LIM();LH(29);LIM();LH(15);LIM();LH(15);LIM();LH(11);LID();
     for(i=1;i<=2*nbp-1;i+=2)
     {
         gotoxy(10,5+i);LV();space(15);LV();space(29);LV();space(15);LV();space(15);LV();space(11);LV();
     }
     for(i=1;i<=2*nbp-1;i+=2)
     {
        gotoxy(10,6+i);LIG();LH(15);LIM();LH(29);LIM();LH(15);LIM();LH(15);LIM();LH(11);LID();

     }

i=1;j=1;
    while(i<=2*nbp)
    {
                    T[j].code=j;
                    if (j>99)
                    {
                        gotoxy(12,5+i);printf("P0%d",T[j].code);
                    }
                    else if (j>9)
                    {
                        gotoxy(12,5+i);printf("P00%d",T[j].code);
                    }
                    else if (j>=1)
                    {
                        gotoxy(12,5+i);printf("P000%d",T[j].code);
                    }
                    j++;i+=2;

    }
            gotoxy(10,4+i);BO();LH(15);LIB();LH(29);LIB();LH(15);LIB();LH(15);LIB();LH(11);BF();
            i=1;j=1;
            while(i<=2*nbp)
            {
                  gotoxy(28,5+i);printf("%s",T[j].designation);
                gotoxy(60,5+i);printf("%d",T[j].prix);
                gotoxy(78,5+i);printf("%d",T[j].smin);
                gotoxy(89,5+i);printf("%d",T[j].smax);
                i+=2;j++;
            }
            gotoxy(40,35);system("pause");
 }

 void main()
 {

       presentation();
         saisie();
        affichage();
 }
