/***********************************************************************
 * 
 * TUTORATO 6: Stringhe
 * ====================
 * 
 *
 * Secondo esercizio: decodifica di un messaggio
 * -----------------------------------------
 *
 * 0) Copia la funzione "codifica_messaggio" sviluppata per l'esercizio
 *    precedente.
 *
 * 1) Completa il file inserendo il corpo della funzione
 *    "trova_chiave".  Potrebbe essere opportuno definire ulteriori
 *    funzioni di appoggio.
 * 
 * 2) Compila il programma con il comando:
 * 
 *      gcc -Wall -o cesare2 cesare2.c
 *    
 * 3) Esegui il programma digitando al terminale:
 * 
 *      ./cesare2
 *
 * 4) Verifica la correttezza del programma con il comando:
 *     
 *      ./pvcheck -f cesare2.test ./cesare2
 *
 *    Se i test hanno rilevato errori cerca di capirne
 *    la causa, correggi il problema e riprova finche' il programma
 *    non passa tutti i test.
 * 
 ***********************************************************************/


#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* atoi */
#include <ctype.h>		/* isalpha, isupper, toupper */

/* Lunghezza massima del messaggio da elaborare, senza
   contare il terminatore. */
#define LUNGHEZZA_MAX 4000


/* Trasforma il messaggio in chiaro nella sua versione cifrata
   utilizzando la chiave data. */
void codifica_messaggio(char *messaggio, int chiave)
{
  /* Completa la funzione, eventualmente copiandola dall'esercizio
     precedente.*/
     int i;  
    int d;
  
    for(i=0 ; i< LUNGHEZZA_MAX+1; i++){
       if(isalpha(messaggio[i])){ 
                if(islower(messaggio[i])){
                     d=(messaggio[i] + chiave - 'a') % 24;
                     messaggio[i]= 'a'+ d;
                }else{
                    d=(messaggio[i] + chiave - 'A') % 24;
                    messaggio[i]= 'A'+ d;
                }   
         }else{
             messaggio[i]= messaggio[i];
         }
     }
}

int cifra_frequente(char *messaggio)
{
    int i;
    int contatore[26];
    int n;
    
    
    for(i=0; i<26; i++){
        contatore[i]=0;
    }
    
    int max= contatore[0];
    
    for(i=0; i<LUNGHEZZA_MAX+1; i++){
        if(isalpha(messaggio[i])){
                n= (messaggio[i] -'a');
                contatore[n]++;
        }
    }
    
    
    for(i=0; i<26; i++){
            if(contatore[i]>max){
                max= (int)contatore[i];
            }  
   
    }
    return max;
}





/* Indovina la chiave di cifratura che e` stata usata per codificare
   il messaggio. */
int trova_chiave(char *messaggio)
{
    int chiave;
    int l;
    int max;
    
    max= (int)cifra_frequente;
    
    l= max + 'a';
    chiave= l-'e';
    
    return chiave;
  /* Completa la funzione. */
}


/* Decifra il messaggio tramite un'analisi delle
   occorrenze delle lettere.  La funzione restituisce la
   chiave di cifratura. */
int decifra_messaggio(char *messaggio)
{
  int chiave;

  chiave = trova_chiave(messaggio);
  
  /* Si decifra il messaggio usando l'opposto della
     chiave */
  codifica_messaggio(messaggio, -chiave);

  return chiave;
}

/* Legge il messaggio inserito da terminale e lo memorizza 
   nella stringa `messaggio'.  */
void leggi_messaggio(char *messaggio)
{
  char c;
  int i = 0;  /* Indica il numero di caratteri gia` letti */
  int letto;

  do {
    /* legge un carattere */
    letto = scanf("%c", &c);

    /* letto < 1 quando la lettura fallisce (ad esempio perche'
       l'input si e` esaurito. */
    if (letto == 1) {
      messaggio[i] = c;
      i++;
    }

    /* Continua finche' non si raggiunge la lunghezza
       limite e non si incontra il punto (o la fine
       dell'input). */
  } while (letto == 1 && i < LUNGHEZZA_MAX && c != '.');

  /* Imposta il terminatore della stringa */
  messaggio[i] = '\0';
}


int main()
{
  int chiave;
  /* +1 per il terminatore */
  char messaggio[LUNGHEZZA_MAX + 1];

  /* Si inizia leggendo il messaggio da elaborare */
  leggi_messaggio(messaggio);

  chiave = decifra_messaggio(messaggio);

  printf("[CHIAVE]\n");
  printf("%d\n\n", chiave);
  printf("[DECIFRATO]\n");
  printf("%s\n", messaggio);

  /* Fine: tutto ok */
  return 0;
}
