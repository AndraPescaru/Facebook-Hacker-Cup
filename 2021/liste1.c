/*
    Programmer : Anamaria Andra Pescaru
    11 : 25
*/
#include<stdio.h>
#include<stdlib.h>

typedef long long ll;
typedef struct node node;

struct node{
    int id;
    char *nume;
    char *prenume;
    node *next;
    node *prev;
};

typedef struct lista{
        node *caine;
        int nr_caini;
}lista;

int main(){
	
    FILE *input, *output;
    input = fopen("input.txt", "rt");
    output = fopen("output.txt", "wt");

    //Alocam dinamic lista

    lista *cursa = (lista*)malloc(sizeof(lista));
    cursa -> caine = (node*)malloc(sizeof(node));
    cursa -> nr_caini = 0;
    cursa -> caine -> nume = (char*)malloc(20 * sizeof(char));
    cursa -> caine -> prenume = (char*)malloc(20 * sizeof(char));
    cursa -> caine -> next = NULL;
    cursa -> caine -> prev = NULL;

    node *barcuta = cursa -> caine;

    //Citim componentele listei

    while(fscanf(input,"%s", barcuta->nume) != EOF){
        fscanf(input,"%s", barcuta->prenume);
        fscanf(input,"%d", &(barcuta->id));
        cursa -> nr_caini++;
        barcuta -> next = (node*)malloc(sizeof(node));
        barcuta -> next -> prev = barcuta;
        barcuta = barcuta -> next;
        barcuta -> next = NULL;
        barcuta -> nume = (char*)malloc(20 * sizeof(char));
        barcuta -> prenume = (char*)malloc(20 * sizeof(char));
    }

    //Prima cursa : câinii cu id par sunt scoși din joc în timp ce câinii cu id impar sunt sortati crescator și afișați

    //Stergem câinii cu id par
    barcuta = cursa -> caine;
    int i;
    for(i = 1;i <= cursa -> nr_caini; i++){
        if(((barcuta -> id)) % 2 == 0 ){
            if(i == 1){
                cursa -> caine = barcuta -> next;
                cursa -> nr_caini--;
                i = 0;
            }else{
                barcuta -> next -> prev = barcuta -> prev;
                barcuta -> prev -> next = barcuta -> next;
                cursa -> nr_caini --;
                i--;
            }
        }
        barcuta = barcuta -> next;
    }

    //Sortam crescator câinii în functie de id
    int ok = 1;
    while(ok){
        ok = 0;
        barcuta = cursa -> caine;
        for(i = 1;i <= cursa -> nr_caini; i++){
            if(i != 1)
            if(barcuta -> id < barcuta -> prev -> id){
              if(i == 2 || i == cursa -> nr_caini){
                  barcuta -> next -> prev = barcuta -> prev;
                  barcuta -> prev -> next = barcuta -> next;
                  barcuta -> next = barcuta -> prev;
                  barcuta -> next -> prev = barcuta;
                  ok = 1;
              }
              if(i != 2 && i != cursa -> nr_caini && i != 1){
                  barcuta ->prev -> prev -> next = barcuta;
                  barcuta -> prev -> next = barcuta -> next;
                  barcuta -> next -> prev =  barcuta -> prev;
                  barcuta -> prev = barcuta -> prev -> prev;
                  barcuta -> next = barcuta -> next -> prev;
                  barcuta -> next -> prev = barcuta;
                  ok = 1;
              }

            }
            barcuta = barcuta -> next;
        }
    }

    //Afisam cainii in orinea crescatoare a id ului
    barcuta = cursa -> caine;
    for(i = 1; i <= cursa -> nr_caini; i ++){
        printf("%s ", barcuta -> nume);
        printf("%s ", barcuta -> prenume);
        printf("%d\n", *(&(barcuta -> id)));
        barcuta = barcuta -> next;

    }

    //A doua cursa: eliminam 
    
	return 0;
}


