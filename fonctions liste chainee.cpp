//Application de fonctions sur les listes doublement chainées 

#include<stdio.h>
#include<stdlib.h>

// Définition de la structure de la boîte
struct BOX{
    int data;            // Donnée stockée dans la boîte
    struct BOX* next;    // Pointeur vers la prochaine boîte
    struct BOX* prev;	 // Pointeur vers la boîte précédante 
};
typedef struct BOX BOX;

BOX* CreationBoite (int element){
	BOX* b; // Déclaration d'un pointeur de boîte
    
    b=(BOX*)malloc(sizeof(BOX)); // Allocation de mémoire pour une nouvelle boîte
    
    if (b==NULL){ // Vérification de l'allocation réussie
        printf("erreur de l'allocation");
        exit (-1); // Quitter le programme avec un code d'erreur
    }
    
    b->data = element; // Assigner la valeur à la boîte créée
    // initialiser les pointeurs à NULL
    b->next =NULL; 
    b->prev = NULL; 
    
	return b;
}

void AfficheChaine (BOX* p){
	if (p->next == NULL){
		printf("la chaine est vide");
		return ; //quitter
	}
	while (p!= NULL){
		printf("%d --> ",p->data);
		p= p->next;
	}
	printf("NULL\n");
}


BOX* AjouterAuDebut (BOX* debut , int element){
	BOX* b= CreationBoite (element);
	    
	b->next = debut; 
	if(debut != NULL){
		debut->prev = b;
	}   
	
	//il s'execule soit la liste est vide ou non
	debut = b;
	return debut;  
    
}

BOX* AjouterFin (BOX* debut , int element){
	BOX* b= CreationBoite (element);
    
    if (debut->next == NULL){
    	debut = b ;
	}
    
    //Recherche du dernier element 
    BOX* p1 = debut;
    while (p1->next != NULL){
    	p1=p1->next;
	}
	b->prev = p1;
	p1->next = b;

	return b;
}



BOX* AjouterAuMilieu (BOX* debut, int element , int c){
	
	BOX* p1 = debut;
	while (p1->data != c  &&  p1->next != NULL){
		p1=p1->next;
	}
	
	BOX* b= CreationBoite (element);
	
	BOX* p2 = p1->next;
	b->next =p2;
	b->prev = p1;
	p2->prev=b;
        p1->next=b;

	return b;
}

int main (){
	BOX* p=NULL;
	
	//remplissage de la premiere boite
	p=(BOX*)malloc(sizeof(BOX));
	if (p==NULL){
		printf("erreur de l'allocation");
		return 1;
	}
	printf ("donnee de la boite 1 : ");
	scanf("%d",&p->data);
	p->next = NULL;
	
	//Remplissage du reste de la liste chainee
	BOX* p1=p;  // Utilisation de p1 pour garder une référence à la tête de la liste 
	for (int i=0; i<3; i++){
		p1->next=(BOX*)malloc(sizeof(BOX));
		if (p1->next==NULL){
			printf("erreur de l'allocation");
			return 1;
		}
		p1=p1->next; //avancer p1
		printf("donnee de la boite %d : ",i+2);
		scanf("%d",&p1->data);
		p1->next = NULL; //pour la derniere boite	
	}
	
	//ajouter un element au debut
	int d1;
	printf("donnee de la boite a ajouter au debut :");
	scanf("%d",&d1);
	p=AjouterAuDebut(p,d1);
	
	
	//ajouter un element a la fin 
	int d2;
	printf("donnee de la boite a ajouter a la fin :");
	scanf("%d",&d2);
	BOX* p2=AjouterFin(p,d2);
	
	//ajouter un element au milieu
	int d3; int c;
	printf("donnez le contenu de la boite apres laquelle vous voulez ajouter un element :");
	scanf("%d",&c);
	printf("donnee de la boite a ajouter au milieu :");
	scanf("%d",&d3);
	BOX* p3=AjouterAuMilieu (p,d3,c);
	
	//affichage de la liste chainee avant modification
	AfficheChaine (p);
	
	return 0;
}
  
	
