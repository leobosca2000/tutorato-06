/***********************************************************************
 * 
 * TUTORATO 6: Stringhe
 * ====================
 * 
 *
 * Primo esercizio: codifica di un messaggio
 * -----------------------------------------
 *
 * 1) Completa il file inserendo il corpo della funzione
 *    "codifica_messaggio".  Potrebbe essere opportuno
 *    definire ulteriori funzioni di appoggio.
 * 
 * 2) Compila il programma con il comando:
 * 
 *      gcc -Wall -o cesare cesare.c
 *    
 * 3) Esegui il programma digitando al terminale:
 * 
 *      ./cesare
 *
 * 4) Verifica la correttezza del programma con il comando:
 *     
 *      ./pvcheck ./cesare
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

  /* COMPLETA LA FUNZIONE */
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


int main(int argc, char *argv[])
{
  int chiave;
  /* +1 per il terminatore */
  char messaggio[LUNGHEZZA_MAX + 1];

  /* Si inizia leggendo il messaggio da elaborare */
  leggi_messaggio(messaggio);

  if (argc != 2) {
    printf("Errore: specificare la chiave di cifratura\n");
  } else {
    /* La chiave e` una stringa passata come primo parametro dalla
       riga di comando. La funzione atoi converte il testo in un
       numero intero. */
    chiave = atoi(argv[1]);
    codifica_messaggio(messaggio, chiave);

    printf("[CIFRATO]\n");
    printf("%s\n", messaggio);
  } 

  /* Fine: tutto ok */
  return 0;
  
}
