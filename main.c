#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 //Escape code ascii colori
 #define RED "\x1b[31m"
 #define GREEN "\x1b[32m"
 #define YELLOW "\x1b[33m"
 #define BLUE "\x1b[34m"
 #define MAGENTA "\x1b[44m"
 #define CYAN "\x1b[36m"
 #define RESET "\x1b[0m"
 #define GRAY "\x1b[90m"

typedef struct nodo 
{
    char parola[100];
    struct nodo *next;

} nodo;

int menu();
void visualizza();
void push (nodo *head, char *parola);
void loadList(nodo **head, nodo **coda, char *sorgente);

int main()
{

	nodo *head;
	nodo *coda;
	nodo *app;
	head = NULL;
	coda = NULL;

	char nome_sorg[25];
	FILE *sorgente;
	int scelta;

	printf(YELLOW "\nInserire il nome del file dizionario. -> " RESET);
	fgets(nome_sorg, sizeof(nome_sorg), stdin);
	nome_sorg[strcspn(nome_sorg, "\n")] = 0;
	fflush(stdin);

	sorgente = fopen(nome_sorg, "r");
	

	if(sorgente == NULL)
	{
		perror(RED "\nSi e' verificato un errore durante l'apertura del file sorgente: " RESET);
		return -1;	
	}
	fclose(sorgente);

	loadList(&head, &coda, nome_sorg);


	do
	{
		scelta = menu();
		printf("\n %s", head);

		switch(scelta)
		{
			case 1:
	//			inserimento();
				break;
			case 2:
				visualizza(head);
				break;

			case 3:
				//cancella();
				break;
		}
	} while(scelta != 0);



}

void loadList(nodo **head, nodo **coda, char *sorgente)
{
	FILE *fp;
	nodo *app;
	int i;
	char parola[100];
	fp = fopen(sorgente, "rt");

	fscanf(fp,"%s", parola);
	printf("\n%s", parola);
	app = (nodo *) malloc(sizeof(nodo));
	strcpy(app->parola, parola);
 	app->next = NULL;

 	*head = app;
 	*coda = app;
	i = 0;
	while(fscanf(fp, "%s", parola) != EOF && strcmp(app->parola, parola) < 0)
	{
		printf("\n%s", app->parola);
		i++;
		app = (nodo *) malloc(sizeof(nodo));
		strcpy(app->parola,parola);
 		app->next = NULL;
 		(*coda)->next = app;
 		*coda = app;
		printf("\n %d", i);
	}
}

int menu() 
{

     int scelta;

	do 
	{
		printf(CYAN "\n************************");
    	printf("\n*1 Inserisci  parola   *");
    	printf("\n*2 Visualizza  lista   *");
    	printf("\n*3 Cancella una parola *");
   	 	printf("\n*0 Uscita    programma *");
    	printf("\n************************" RESET);
    	printf("\n Scegli cosa fare: ");
    	scanf("%d", & scelta);
    	getchar();

	} while (scelta < 0 || scelta > 3);

    return scelta;
}

void visualizza(nodo *head)
{
	int i;	
	i = 0;
	while (head != NULL)
	{
		printf(MAGENTA "\nHead parola %d:" GREEN " %s" RESET, i+1, head->parola);
		head = head->next;
		i++;	
	}

}

void insNod(nodo **head, nodo **coda)
{
	nodo *app;
	char parola[100];

	printf("\nQuale parola vuoi inserire? ");

	app = (nodo *) malloc(sizeof(nodo));
	strcpy(app->parola, parola);
 	app->next = NULL;


}
