#include "interface.h"
#include "checksAndUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include "catalog.h"
#include <string.h>

extern char tempName[]; // nome dell'utente loggato
extern double finalPrice; // prezzo finale dello scontrino


/**La funzione menu2() stampa un logo a forma di testo nel terminale.
 * Il logo rappresenta una grafica ASCII che può essere utilizzata per scopi decorativi o per creare un menu grafico.  */

void menu2() {
    printf(    "  ______    ______   ________         ______   __    __   ______   _______  \n"
               " /      \\  /      \\ |        \\       /      \\ |  \\  |  \\ /      \\ |       \\ \n"
               "|  $$$$$$\\|  $$$$$$\\| $$$$$$$$      |  $$$$$$\\| $$  | $$|  $$$$$$\\| $$$$$$$\\\n"
               "| $$ __\\$$| $$__| $$| $$__          | $$___\\$$| $$__| $$| $$  | $$| $$__/ $$\n"
               "| $$|    \\| $$    $$| $$  \\          \\$$    \\ | $$    $$| $$  | $$| $$    $$\n"
               "| $$ \\$$$$| $$$$$$$$| $$$$$          _\\$$$$$$\\| $$$$$$$$| $$  | $$| $$$$$$$ \n"
               "| $$__| $$| $$  | $$| $$            |  \\__| $$| $$  | $$| $$__/ $$| $$      \n"
               " \\$$$$$$  \\$$   \\$$ \\$$              \\$$$$$$  \\$$   \\$$  \\$$$$$$  \\$$      \n"
               "   ________________||_______________________||_____________\n"
               "  |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_||\n"
               "  |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|| /|\n"
               "  |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|||/|\n"
               "  |_|_|_|_|_|_|_|_|_|     _      _     |_|_|_|_|_|_|_|_|_|_|/||\n"
               "  |_|               |    (_)    (_)    |                 |_|/||\n"
               "  |_|.              |__________________|     (^^)  .     |_||/|\n"
               "  |_|*`.            |_|      ||      |_|     _)(_  I`.   |_|/||\n"
               "  |_| S `.          |_|      || push |_|    /()()\\/| ;   |_||/|\n"
               "  |_|`. A `.        |_|      ||  in  |_|   // )_\\\\/      |_|/||\n"
               "  |_|  `. L `.      |_|     [||]     |_|   \\|.//_)       |_||/|\n"
               "  |_|    `. E `.    |_|      ||      |_|     // /        |_|/||\n"
               "  |_|______`__*_`___|_|      ||      |_|_____\\\\|_________|_||/|\n"
               "  |_|_|_|_|_|_|_|_|_|_|______||______|_|_|_|_|_|_|_|_|_|_|_|/||\n"
               "__|_|_|_|_|_|_|_|_|_|_|______||______|_|_|_|_|_|_|_|_|_|_|_||/________\n"
               " /     /     /     /     /     /     /     /     /     /     /     /\n"
               "/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/\n");
}


/**La funzione logo() stampa un logo a forma di testo nel terminale.
 * Il logo rappresenta una grafica ASCII che può essere utilizzata per scopi decorativi o per creare un menu grafico.  */

void logo () {
    printf("______                                 _   _       _       \n"
           "| ___ \\                               | | (_)     | |      \n"
           "| |_/ / ___ _ ____   _____ _ __  _   _| |_ _    __| | __ _ \n"
           "| ___ \\/ _ \\ '_ \\ \\ / / _ \\ '_ \\| | | | __| |  / _` |/ _` |\n"
           "| |_/ /  __/ | | \\ V /  __/ | | | |_| | |_| | | (_| | (_| |\n"
           "\\____/ \\___|_| |_|\\_/ \\___|_| |_|\\__,_|\\__|_|  \\__,_|\\__,_|\n");
    puts("           ______    ______   ________         ______   __    __   ______   _______  \n"
         "          /      \\  /      \\ |        \\       /      \\ |  \\  |  \\ /      \\ |       \\ \n"
         "          |  $$$$$$\\|  $$$$$$\\| $$$$$$$$      |  $$$$$$\\| $$  | $$|  $$$$$$\\| $$$$$$$\\\n"
         "          | $$ __\\$$| $$__| $$| $$__          | $$___\\$$| $$__| $$| $$  | $$| $$__/ $$\n"
         "          | $$|    \\| $$    $$| $$  \\          \\$$    \\ | $$    $$| $$  | $$| $$    $$\n"
         "          | $$ \\$$$$| $$$$$$$$| $$$$$          _\\$$$$$$\\| $$$$$$$$| $$  | $$| $$$$$$$ \n"
         "          | $$__| $$| $$  | $$| $$            |  \\__| $$| $$  | $$| $$__/ $$| $$      \n"
         "           \\$$    $$| $$  | $$| $$             \\$$    $$| $$  | $$ \\$$    $$| $$      \n"
         "            \\$$$$$$  \\$$   \\$$ \\$$              \\$$$$$$  \\$$   \\$$  \\$$$$$$  \\$$      \n");
    puts(
            "        (q\\_/p)\n"
            "         /. .\\         __\n"
            "  ,__   =\\_t_/=      .'o O'-.\n"
            "     )   /   \\      / O o_.-`|   \n"
            "    (   ((   ))    /O_.-'  O |  (q\\_/p)\n"
            "     \\  /\\) (/\\    | o   o  o|   /. .\\.-\"\"\"\"\"-.     ___,\n"
            "      `-\\  Y  /    |o   o O.-`  =\\_t_/=     /  `\\  (\n"
            "         nn^nn     | O _.-'       )\\ ))__ __\\   |___)\n"
            "                   '--`          (/-(/`  `nn---'");
}


/**La funzione logo() stampa un menu a forma di testo nel terminale.
 * Il logo rappresenta una grafica ASCII che può essere utilizzata per scopi decorativi o per creare un menu grafico.  */

void displayMenu1(unsigned short int selectedOption) {
    refreshPage();
    menu();

    printf(            "        HAI GIA' UN ACCOUNT O VUOI CREARNE UNO?:\n"
                       "    -----------------------------------------------------\n"
                       "    |                                                   |\n"
                       "    |                   %c ESPLORA                       |\n"
                       "    |                                                   |\n"
                       "    |                   %c LOGIN                         |\n"
                       "    |                                                   |\n"
                       "    |                   %c REGISTRATI                    |\n"
                       "    |                                                   |\n"
                       "    -----------------------------------------------------\n",
                       (selectedOption == 0) ? '>' : ' ',(selectedOption == 1) ? '>' : ' ',
                       (selectedOption == 2) ? '>' : ' ');

    /*l' operatore ternario controlla il valore della selectedOption grazie alla funzione control in navigation.c. se il valore corrisponde al numero
    allora viene visuallizzata una freccia sennò viene lasciato lo spazio vuoto. questo grazie ad un continuo refresh della pagina
     fa sembrare che ci si può spostare con le freccette attraverso i vari campi*/
}

/**La funzione displayMenu1_1() stampa un menu a forma di testo nel terminale.
 * Il menu rappresenta una grafica ASCII che può essere utilizzata per scopi decorativi o per creare un menu grafico.  */

void displayMenu1_1(unsigned short int selectedOption) {
    refreshPage();
    menu();
    printf("\n\n\t\t\t BENVENUTO %s\n",tempName); // nome dell'utente loggato

    printf("    -----------------------------------------------------\n"
            "    |                                                   |\n"
            "    |                   %c ESPLORA                       |\n"
            "    |                                                   |\n"
            "    |                   %c PROFILO                       |\n"
            "    |                                                   |\n"
            "    |                   %c CARRELLO                      |\n"
           "    |                                                   |\n"
           "    |                   %c ORDINI                        |\n"
           "    |                                                   |\n"
            "    |                   %c LOGOUT                        |\n"
            "    |                                                   |\n"
           "    |                   %c RIMBORSO                      |\n"
           "    |                                                   |\n"
            "    -----------------------------------------------------\n",
            (selectedOption == 0) ? '>' : ' ', (selectedOption == 1) ? '>' : ' ',
            (selectedOption == 2) ? '>' : ' ', (selectedOption == 3) ? '>' : ' '
            , (selectedOption == 4) ? '>' : ' ', (selectedOption == 5) ? '>' : ' ');

    /*l' operatore ternario controlla il valore della selectedOption grazie alla funzione control in navigation.c. se il valore corrisponde al numero
allora viene visuallizzata una freccia sennò viene lasciato lo spazio vuoto. questo grazie ad un continuo refresh della pagina
 fa sembrare che ci si può spostare con le freccette attraverso i vari campi*/
}


/**La funzione displayMenuAdmin() stampa un menu a forma di testo nel terminale.
 * Il menu rappresenta una grafica ASCII che può essere utilizzata per scopi decorativi o per creare un menu grafico.  */

void displayMenuAdmin(unsigned short int selectedOption) {
    refreshPage();
    menu();
    printf("\n\n\t\t\t BENVENUTO %s\n",tempName); // nome dell'utente loggato

    printf("    -----------------------------------------------------\n"
           "    |                                                   |\n"
           "    |                   %c ESPLORA                       |\n"
           "    |                                                   |\n"
           "    |                   %c PROFILO                       |\n"
           "    |                                                   |\n"
           "    |                   %c CARRELLO                      |\n"
           "    |                                                   |\n"
           "    |                   %c ORDINI                        |\n"
           "    |                                                   |\n"
           "    |                   %c LOGOUT                        |\n"
           "    |                                                   |\n"
           "    |                   %c RIMBORSO                      |\n"
           "    |                                                   |\n"
           "    |                   %c GESTIONE                      |\n"
           "    |                                                   |\n"
           "    -----------------------------------------------------\n",
           (selectedOption == 0) ? '>' : ' ', (selectedOption == 1) ? '>' : ' ',
           (selectedOption == 2) ? '>' : ' ', (selectedOption == 3) ? '>' : ' ',
           (selectedOption == 4) ? '>' : ' ',(selectedOption == 5) ? '>' : ' '
           ,(selectedOption == 6) ? '>' : ' ');
    /*l' operatore ternario controlla il valore della selectedOption grazie alla funzione control in navigation.c. se il valore corrisponde al numero
allora viene visuallizzata una freccia sennò viene lasciato lo spazio vuoto. questo grazie ad un continuo refresh della pagina
fa sembrare che ci si può spostare con le freccette attraverso i vari campi*/
}


/**La funzione displayMenuAdmin2() stampa un menu a forma di testo nel terminale.
 * Il menu rappresenta una grafica ASCII che può essere utilizzata per scopi decorativi o per creare un menu grafico.  */

void displayMenuAdmin2(unsigned short int selectedOption) {
    refreshPage();
    menu();
    printf("\n\n\t\t\t BENVENUTO %s\n",tempName);

    printf("    -----------------------------------------------------\n"
           "    |                                                   |\n"
           "    |                   %c MODIFICA                      |\n"
           "    |                                                   |\n"
           "    |                   %c COUPON                        |\n"
           "    |                                                   |\n"
           "    |                   %c PROFILI                       |\n"
           "    |                                                   |\n"
           "    |                   %c ORDINI                        |\n"
           "    |                                                   |\n"
           "    |                   %c INDIETRO                      |\n"
           "    |                                                   |\n"
           "    -----------------------------------------------------\n",
           (selectedOption == 0) ? '>' : ' ', (selectedOption == 1) ? '>' : ' ',
           (selectedOption == 2) ? '>' : ' ', (selectedOption == 3) ? '>' : ' ',
           (selectedOption == 4) ? '>' : ' ' , (selectedOption == 5) ? '>' : ' ');
    /*l' operatore ternario controlla il valore della selectedOption grazie alla funzione control in navigation.c. se il valore corrisponde al numero
allora viene visuallizzata una freccia sennò viene lasciato lo spazio vuoto. questo grazie ad un continuo refresh della pagina
fa sembrare che ci si può spostare con le freccette attraverso i vari campi*/
}


/**La funzione displayMenu2() stampa un menu a forma di testo nel terminale.
 * Il menu rappresenta una grafica ASCII che può essere utilizzata per scopi decorativi o per creare un menu grafico.  */

void displayMenu2(unsigned short int selectedOption) {
    refreshPage();
    menu2();

    printf(            "\n        SELEZIONA IL TIPO DI PRODOTTO CHE TI INTERESSA:\n"
                       "    -----------------------------------------------------\n"
                       "    |                                                   |\n"
                       "    |                  %c VEDI TUTTO                     |\n"
                       "    |                                                   |\n"
                       "    |    %c MAGLIE      %c  VESTITI    %c OCCHIALI         |\n"
                       "    |                                                   |\n"
                       "    |    %c PANTALONI   %c CAPPELLI   %c INDIETRO          |\n"
                       "    |                                                   |\n"
                       "    -----------------------------------------------------\n",
                       (selectedOption == 0) ? '>' : ' ',(selectedOption == 1) ? '>' : ' ',
                       (selectedOption == 2) ? '>' : ' ',(selectedOption == 3) ? '>' : ' ',
                       (selectedOption == 4) ? '>' : ' ',(selectedOption == 5) ? '>' : ' ',
                       (selectedOption == 6) ? '>' : ' ');
    /*l' operatore ternario controlla il valore della selectedOption grazie alla funzione control in navigation.c. se il valore corrisponde al numero
allora viene visuallizzata una freccia sennò viene lasciato lo spazio vuoto. questo grazie ad un continuo refresh della pagina
fa sembrare che ci si può spostare con le freccette attraverso i vari campi*/

}



/**La funzione menu() stampa un logo a forma di testo nel terminale.
 * Il logo rappresenta una grafica ASCII che può essere utilizzata per scopi decorativi o per creare un menu grafico.  */


    void menu () {
        printf("             __\n"
               "          __/  \\\n"
               "         /  \\-./\n"
               "         \\_   66\\_\n"
               "           \\  ____)o\n"
               "            )_(_________\n"
               "   .-.     /|  W I L L  |\n"
               "(_/   \\   / |  W O R K  ()\n"
               "       |  \\ \\   F O R   |\n"
               "        \\  \\_)C A C H E |\n"
               "         '-'/ \\\"\\\"\"\"\"\"\"`\n"
               "           / / \\ \\/^)\n"
               "          (  \\  \\  /\n"
               "           \\__)  \"`\n");
        printf(
                "  ______    ______   ________         ______   __    __   ______   _______  \n"
                " /      \\  /      \\ |        \\       /      \\ |  \\  |  \\ /      \\ |       \\ \n"
                "|  $$$$$$\\|  $$$$$$\\| $$$$$$$$      |  $$$$$$\\| $$  | $$|  $$$$$$\\| $$$$$$$\\\n"
                "| $$ __\\$$| $$__| $$| $$__          | $$___\\$$| $$__| $$| $$  | $$| $$__/ $$\n"
                "| $$|    \\| $$    $$| $$  \\          \\$$    \\ | $$    $$| $$  | $$| $$    $$\n"
                "| $$ \\$$$$| $$$$$$$$| $$$$$          _\\$$$$$$\\| $$$$$$$$| $$  | $$| $$$$$$$ \n"
                "| $$__| $$| $$  | $$| $$            |  \\__| $$| $$  | $$| $$__/ $$| $$      \n"
                " \\$$$$$$  \\$$   \\$$ \\$$              \\$$$$$$  \\$$   \\$$  \\$$$$$$  \\$$      \n"
                "\n");
    }


/**La funzione cloth() stampa i vestiti singolarmente a forma di testo nel terminale con i relativi dati del vestito.  */

    void cloth(unsigned short int a) {
        FILE* file = fopen("clothes.csv", "r");
        if (file == NULL) {
            printf("Errore nell'apertura del file\n");
        }

        char line[MAX_CLOTHINGITEM_LENGTH];
        while (fgets(line, MAX_CLOTHINGITEM_LENGTH, file) != NULL) {
            ClothingItem item;
            sscanf(line, "%hu,%[^,],%[^,],%[^,],%[^,],%lf,%d", &item.code, item.name, item.brand,item.description, item.size, &item.price, &item.quantity);

            if (item.code == a) { // Se il codice è uguale a quello passato allora stampa i dati del vestito che si cerca
                //printf("Name: %s\n", item.code);
                printf("Name: %s\n", item.name);
                printf("Brand: %s\n", item.brand);
                printf("Description: %s\n",item.description);
                printf("Size: %s\n", item.size);
                printf("Price: %.2lf\n", item.price);
                printf("--------------------------\n");
            }
        }
        fclose(file);
    puts("\n");
     switch (a) {
            case 9:
                printf("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                 ______                 ||      \n"
                     "          ||               /  `-'   \\               ||     \n"
                     "          ||              / |      | \\              ||     \n"
                     "          ||             /__|      |__\\             ||     \n"
                     "          ||                |      |                ||      \n"
                     "          ||                |      |                ||      \n"
                     "          ||                |      |                ||      \n"
                     "          ||                |______|                ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n");
                break;

            case 10:
                puts("          ++========================================++      \n"
                "          ||                                        ||      \n"
                "          ||                                        ||      \n"
                "          ||                                        ||      \n"
                "          ||                ___ ___                 ||      \n"
                "          ||              /| |/|\\| |\\               ||      \n"
                "          ||             /_|   |.  |_\\              ||      \n"
                "          ||               |   |.  |                ||      \n"
                "          ||               |   |.  |                ||        \n"
                "          ||               |   |.  |                ||      \n"
                "          ||               |   |.  |                ||      \n"
                "          ||               |___|.__|                ||      \n"
                "          ||                                        ||      \n"
                "          ||                                        ||      \n"
                "          ||                                        ||      \n"
                "          ++========================================++      \n");
                break;

            case 11:
                puts("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||               __   __                  ||      \n"
                     "          ||             /|   -   |\\                ||      \n"
                     "          ||            /_|  o.o  |_\\               ||      \n"
                     "          ||              | o o o |                 ||      \n"
                     "          ||              |  o^o  |                 ||         \n"
                     "          ||              |  o.o  |                 ||      \n"
                     "          ||              | o o o |                 ||      \n"
                     "          ||              |_______|                 ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n");
                break;

            case 12:
                puts("          ++========================================++ \n "
                      "         ||                                        ||      \n"
                      "          ||             **,*,#(((#*/*,,            ||      \n"
                      "          ||            .*/*,      */(              ||      \n"
                      "          ||                /*   //                 ||      \n"
                      "          ||                ,*, ,,,                 ||      \n"
                      "          ||               ,*/   ,*,                ||      \n"
                      "          ||             ,,**       **              ||      \n"
                      "          ||            **           **             ||      \n"
                      "          ||          **              *(,           ||      \n"
                      "          ||         **                *(,          ||      \n"
                      "          ||       **                     **        ||      \n"
                      "          ||      */                      /*,       ||      \n"
                      "          ||     *(*/(                     */*      ||      \n"
                      "          ||         /***((***(***(/*((**#(         ||      \n"
                      "          ++========================================++      \n");
                break;

            case 13:
                puts("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                 // \\\\                  ||      \n"
                     "          ||                 (`~')                  ||      \n"
                     "          ||                 |   |                  ||      \n"
                     "          ||                 |   |                  ||      \n"
                     "          ||                 /   \\                  ||      \n"
                     "          ||               .'`~~~'`.                ||      \n"
                     "          ||              /    :    \\               ||      \n"
                     "          ||              . .' | `. .               ||       \n"
                     "          ||             /     :     \\              ||      \n"
                     "          ||             .  .' | `.  .              ||      \n"
                     "          ||            /             \\             ||      \n"
                     "          ||            `~~..._:_...~~'             ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n ");
                break;

            case 14:
                puts("         ++========================================++      \n"
                     "          ||             \\ ___   ___                ||      \n"
                     "          ||               '~~(`v')~~`              ||      \n"
                     "          ||                  |   |                 ||      \n"
                     "          ||                  /   \\                 ||      \n"
                     "          ||                .'`~~~'`.               ||      \n"
                     "          ||              /   /\"\\   \\               ||      \n"
                     "          ||             .   / | \\   .              ||      \n"
                     "          ||            /   .  .  .     \\           ||      \n"
                     "          ||           .   /   |   \\   .            ||      \n"
                     "          ||          /   .    |    .     \\         ||      \n"
                     "          ||         :   /     .    \\     :         ||      \n"
                     "          ||          `~.:.     |     .:.~'         ||      \n"
                     "          ||               `````\"'''''              ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n");
                break;

            case 15:
                puts("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||         ________     ________          ||      \n"
                     "          ||    .  ~|        |-^-|        |~  .     ||      \n"
                     "          ||  {     |        |   |        |      }  ||      \n"
                     "          ||         `.____.'     `.____.'          ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++        ");
                break;

            case 16:
                puts("       \n          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||          _,--,                _        ||      \n"
                     "          ||         ___,-'____| ___      /' |      ||      \n"
                     "          ||       /'   `\\,--,/'   `\\  /'   |       ||      \n"
                     "          ||      (       )  (       )'             ||      \n"
                     "          ||      \\_   _/'  `\\_   _/                ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++        ");
                break;

            case 17:
                puts("     \n          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||            __         __               ||      \n"
                     "          ||           /.-'       `-.\\              ||      \n"
                     "          ||          //              \\             ||      \n"
                     "          ||         /j_______________j\\            ||      \n"
                     "          ||        /o.-==-. .-. .-==-.o\\           ||      \n"
                     "          ||       ||      ))  ((      ||           ||      \n"
                     "          ||        \\____//      \\____//            ||      \n"
                     "          ||         `-==-'       `-==-'            ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n");
                break;

            case 18:
                puts("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||              ,===c===.                 ||      \n"
                     "          ||              |__ | __|                 ||      \n"
                     "          ||              | | | | |                 ||      \n"
                     "          ||              |   |   |                 ||      \n"
                     "          ||              |   |   |                 ||      \n"
                     "          ||              |__ | __|                 ||      \n"
                     "          ||              |   |   |                 ||      \n"
                     "          ||              |   |   |                 ||      \n"
                     "          ||              |__ | __|                 ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n");
                break;

            case 19:
                puts("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||            [_I_I[L]=_I_I_]             ||      \n"
                     "          ||            /     | :     \\             ||      \n"
                     "          ||            |    /|  \\   |              ||      \n"
                     "          ||            |   | '-  |   |             ||      \n"
                     "          ||             \\  | /^\\ |  /              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             \\  | | | |  /              ||      \n"
                     "          ||             / -|-| |-|- \\              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             |__|_| |_|__|              ||      \n"
                     "          ||             [____] [____]              ||      \n"
                     "          ++========================================++      \n");
                break;

            case 20:
                puts("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||              .________.                ||      \n"
                     "          ||              |________|                ||      \n"
                     "          ||              |.., . ,,|                ||      \n"
                     "          ||              |...  , .|                ||      \n"
                     "          ||             /.  ..  . ,\\               ||      \n"
                     "          ||             |... /\\ ...|               ||      \n"
                     "          ||             |... /\\ ....|              ||      \n"
                     "          ||            /.... /\\  ...,\\             ||     \n"
                     "          ||           |.....,/\\ .....|             ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n");
                break;

            case 21:
                puts("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||               ,~'''~.                  ||      \n"
                     "          ||          ,---/       \\---.             ||      \n"
                     "          ||        .' '`.--_____--.'`  '.          ||      \n"
                     "          ||        `-._           _,-' -`          ||      \n"
                     "          ||            `---....---'                ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n"
                     );
                break;

            case 22:
                puts("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||             .~~~~~~~~~\\                ||      \n"
                     "          ||            ;       ~~ \\                ||      \n"
                     "          ||            |           ;               ||      \n"
                     "          ||        ,--------,______|---.           ||      \n"
                     "          ||       /          \\-----`    \\          ||      \n"
                     "          ||       `.__________`-_______-'          ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n");
                break;

            case 23:
                puts("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                _.--._                  ||      \n"
                     "          ||            _.-.'      `.-._            ||      \n"
                     "          ||          .' ./`--...--' \\  `.          ||      \n"
                     "          ||          `.'.`--.._..--'   .'          ||      \n"
                     "          ||          ( (-..__    __..-'            ||      \n"
                     "          ||           ) )    ````                  ||      \n"
                     "          ||          / /                           ||      \n"
                     "          ||        .'.'                            ||      \n"
                     "          ||        `.`.                            ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n");
                break;
        }
        puts("\n");
    }

/**La funzione clothes() stampa i vestiti a gruppi di 3 a forma di testo nel terminale.  */

    void clothes(unsigned short int i,unsigned short int selectedOption) {
        switch (i) {
            case 1:
                printf("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                 ______                 ||      \n"
                     "          ||               /  `-'   \\               ||     \n"
                     "          ||              / |      | \\              ||     \n"
                     "          ||             /__|      |__\\             ||     \n"
                     "          ||                |      |                ||%c    \n"
                     "          ||                |      |                ||      \n"
                     "          ||                |      |                ||      \n"
                     "          ||                |______|                ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n"

                     "          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                ___ ___                 ||      \n"
                     "          ||              /| |/|\\| |\\               ||      \n"
                     "          ||             /_|   |.  |_\\              ||      \n"
                     "          ||               |   |.  |                ||      \n"
                     "          ||               |   |.  |                ||%c      \n"
                     "          ||               |   |.  |                ||      \n"
                     "          ||               |   |.  |                ||      \n"
                     "          ||               |___|.__|                ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n"

                     "          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||               __   __                  ||      \n"
                     "          ||             /|   -   |\\                ||      \n"
                     "          ||            /_|  o.o  |_\\               ||      \n"
                     "          ||              | o o o |                 ||      \n"
                     "          ||              |  o^o  |                 ||%c       \n"
                     "          ||              |  o.o  |                 ||      \n"
                     "          ||              | o o o |                 ||      \n"
                     "          ||              |_______|                 ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n",
                       (selectedOption == 0) ? '<' : ' ',(selectedOption == 1) ? '<' : ' ',
                       (selectedOption == 2) ? '<' : ' ');
                break;
            case 2:

                printf("          ++========================================++ \n "
                     "         ||                                        ||      \n"
                     "          ||             **,*,#(((#*/*,,            ||      \n"
                     "          ||            .*/*,      */(              ||      \n"
                     "          ||                /*   //                 ||      \n"
                     "          ||                ,*, ,,,                 ||      \n"
                     "          ||               ,*/   ,*,                ||      \n"
                     "          ||             ,,**       **              ||      \n"
                     "          ||            **           **             ||      \n"
                     "          ||          **              *(,           ||%c    \n"
                     "          ||         **                *(,          ||      \n"
                     "          ||       **                     **        ||      \n"
                     "          ||      */                      /*,       ||      \n"
                     "          ||     *(*/(                     */*      ||      \n"
                     "          ||         /***((***(***(/*((**#(         ||      \n"
                     "          ++========================================++      \n"

                     "          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                 // \\\\                  ||      \n"
                     "          ||                 (`~')                  ||      \n"
                     "          ||                 |   |                  ||      \n"
                     "          ||                 |   |                  ||      \n"
                     "          ||                 /   \\                  ||      \n"
                     "          ||               .'`~~~'`.                ||      \n"
                     "          ||              /    :    \\               ||      \n"
                     "          ||              . .' | `. .               || %c    \n"
                     "          ||             /     :     \\              ||      \n"
                     "          ||             .  .' | `.  .              ||      \n"
                     "          ||            /             \\             ||      \n"
                     "          ||            `~~..._:_...~~'             ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n "

                     "         ++========================================++      \n"
                     "          ||             \\ ___   ___                ||      \n"
                     "          ||               '~~(`v')~~`              ||      \n"
                     "          ||                  |   |                 ||      \n"
                     "          ||                  /   \\                 ||      \n"
                     "          ||                .'`~~~'`.               ||      \n"
                     "          ||              /   /\"\\   \\               ||      \n"
                     "          ||             .   / | \\   .              ||      \n"
                     "          ||            /   .  .  .     \\           ||      \n"
                     "          ||           .   /   |   \\   .            ||%c    \n"
                     "          ||          /   .    |    .     \\         ||      \n"
                     "          ||         :   /     .    \\     :         ||      \n"
                     "          ||          `~.:.     |     .:.~'         ||      \n"
                     "          ||               `````\"'''''              ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n",
                     (selectedOption == 0) ? '<' : ' ',(selectedOption == 1) ? '<' : ' ',
                     (selectedOption == 2) ? '<' : ' ');
                break;

            case 3:
               printf("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||         ________     ________          ||      \n"
                     "          ||    .  ~|        |-^-|        |~  .     ||      \n"
                     "          ||  {     |        |   |        |      }  ||      \n"
                     "          ||         `.____.'     `.____.'          ||%c    \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++        "

                     "       \n          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||          _,--,                _        ||      \n"
                     "          ||         ___,-'____| ___      /' |      ||      \n"
                     "          ||       /'   `\\,--,/'   `\\  /'   |       ||      \n"
                     "          ||      (       )  (       )'             ||      \n"
                     "          ||      \\_   _/'  `\\_   _/                ||%c    \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++        "


                     "     \n          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||            __         __               ||      \n"
                     "          ||           /.-'       `-.\\              ||      \n"
                     "          ||          //              \\             ||      \n"
                     "          ||         /j_______________j\\            ||      \n"
                     "          ||        /o.-==-. .-. .-==-.o\\           ||      \n"
                     "          ||       ||      ))  ((      ||           || %c   \n"
                     "          ||        \\____//      \\____//            ||      \n"
                     "          ||         `-==-'       `-==-'            ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n",
                     (selectedOption == 0) ? '<' : ' ',(selectedOption == 1) ? '<' : ' ',
                     (selectedOption == 2) ? '<' : ' ');

                break;
            case 4:
                printf("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||              ,===c===.                 ||      \n"
                     "          ||              |__ | __|                 ||      \n"
                     "          ||              | | | | |                 ||      \n"
                     "          ||              |   |   |                 ||      \n"
                     "          ||              |   |   |                 ||%c    \n"
                     "          ||              |__ | __|                 ||      \n"
                     "          ||              |   |   |                 ||      \n"
                     "          ||              |   |   |                 ||      \n"
                     "          ||              |__ | __|                 ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n"

                     "          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||            [_I_I[L]=_I_I_]             ||      \n"
                     "          ||            /     | :     \\             ||      \n"
                     "          ||            |    /|  \\   |              ||      \n"
                     "          ||            |   | '-  |   |             ||      \n"
                     "          ||             \\  | /^\\ |  /              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             |  | | | |  |              ||%c    \n"
                     "          ||             \\  | | | |  /              ||      \n"
                     "          ||             / -|-| |-|- \\              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             |  | | | |  |              ||      \n"
                     "          ||             |__|_| |_|__|              ||      \n"
                     "          ||             [____] [____]              ||      \n"
                     "          ++========================================++      \n"

                     "          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||              .________.                ||      \n"
                     "          ||              |________|                ||      \n"
                     "          ||              |.., . ,,|                ||      \n"
                     "          ||              |...  , .|                ||      \n"
                     "          ||             /.  ..  . ,\\               ||      \n"
                     "          ||             |... /\\ ...|               ||      \n"
                     "          ||             |... /\\ ....|              ||      \n"
                     "          ||            /.... /\\  ...,\\             ||%c   \n"
                     "          ||           |.....,/\\ .....|             ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n",
                     (selectedOption == 0) ? '<' : ' ',(selectedOption == 1) ? '<' : ' ',
                     (selectedOption == 2) ? '<' : ' ');
                break;
            case 5:
                printf("          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||               ,~'''~.                  ||      \n"
                     "          ||          ,---/       \\---.             ||      \n"
                     "          ||        .' '`.--_____--.'`  '.          ||      \n"
                     "          ||        `-._           _,-' -`          ||%c    \n"
                     "          ||            `---....---'                ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n"

                     "          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||             .~~~~~~~~~\\                ||      \n"
                     "          ||            ;       ~~ \\                ||      \n"
                     "          ||            |           ;               ||      \n"
                     "          ||        ,--------,______|---.           ||%c    \n"
                     "          ||       /          \\-----`    \\          ||      \n"
                     "          ||       `.__________`-_______-'          ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n"

                     "          ++========================================++      \n"
                     "          ||                                        ||      \n"
                     "          ||                                        ||      \n"
                     "          ||                _.--._                  ||      \n"
                     "          ||            _.-.'      `.-._            ||      \n"
                     "          ||          .' ./`--...--' \\  `.          ||      \n"
                     "          ||          `.'.`--.._..--'   .'          ||      \n"
                     "          ||          ( (-..__    __..-'            ||%c    \n"
                     "          ||           ) )    ````                  ||      \n"
                     "          ||          / /                           ||      \n"
                     "          ||        .'.'                            ||      \n"
                     "          ||        `.`.                            ||      \n"
                     "          ||                                        ||      \n"
                     "          ++========================================++      \n",
                     (selectedOption == 0) ? '<' : ' ',(selectedOption == 1) ? '<' : ' ',
                     (selectedOption == 2) ? '<' : ' ');
                break;
        }
        /* le selectedOption sono usate per lo stesso motivo che nei menu*/
    }




/**La funzione buttons() stampa i bottoni a forma di testo nel terminale. vengono selezionati tramite selectOption da control()
 * in baso al loro utillizzo ne vengono chiesti di diversi*/
    void buttons(unsigned short int selectedOption,unsigned short int a) {
        switch (a) {
            case 1:
                printf("\n     _______________         _______________\n"
                       "    |               |       |               |\n"
                       "   %c|   INDIETRO    |      %c|     AVANTI    |\n"
                       "    |_______________|       |_______________|",
                       (selectedOption == 0) ? '>' : ' ', (selectedOption == 1) ? '>' : ' ');
                break;
            case 2:
                printf("\n     _______________         ________________________\n"
                       "    |               |       |                        |\n"
                       "   %c|   INDIETRO    |      %c|   AGGIUNGI CARRELLO    |\n"
                       "    |_______________|       |________________________|",
                       (selectedOption == 0) ? '>' : ' ', (selectedOption == 1) ? '>' : ' ');
                break;
            case 3:
                printf("\n     _______________         _______________        ________________________\n"
                       "    |               |       |               |      |                        |\n"
                       "   %c|   INDIETRO    |      %c|     COMPRA    |     %c|     SVUOTA CARRELLO    |\n"
                       "    |_______________|       |_______________|      |________________________|",
                       (selectedOption == 0) ? '>' : ' ', (selectedOption == 1) ? '>' : ' ', (selectedOption == 2) ? '>' : ' ');
                break;
            case 4:
                printf("\n     _______________         _______________\n"
                       "    |               |       |               |\n"
                       "   %c|   INDIETRO    |      %c|     COMPRA    |\n"
                       "    |_______________|       |_______________|",
                       (selectedOption == 0) ? '>' : ' ', (selectedOption == 1) ? '>' : ' ');
                break;
            case 5:
                printf("\n     ______________________         _______________\n"
                       "    |                      |       |               |\n"
                       "   %c|   CARTA DI CREDITO   |      %c| ALLA CONSEGNA |\n"
                       "    |______________________|       |_______________|",
                       (selectedOption == 0) ? '>' : ' ', (selectedOption == 1) ? '>' : ' ');
                break;
            case 6:
                printf("\n     _______________\n"
                       "    |               |\n"
                       "   %c|   INDIETRO    |\n"
                       "    |_______________|\n",
                       (selectedOption == 3) ? '>' : ' ');
                break;
            case 7:
                printf("\n     _______________\n"
                       "    |               |\n"
                       "   %c|   INDIETRO    |\n"
                       "    |_______________|\n",
                       (selectedOption == 0) ? '>' : ' ');
                break;
            case 8:
                printf("\n     _______________         _______________\n"
                       "    |               |       |               |\n"
                       "   %c|   INDIETRO    |      %c|     AVANTI    |\n"
                       "    |_______________|       |_______________|",
                       (selectedOption == 3) ? '>' : ' ', (selectedOption == 4) ? '>' : ' ');
                break;
        }
}


/**La funzione topheadLog() stampa una scritta per la grafica del login*/

void topheadLog()
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("\n");
    }
    printf("\n++=============================================================================================================++\n");
    printf("||      ______    ______   ________        __        ______    ______         ______  __    __                 ||\n"
           "||     /      \\  /      \\ |        \\      |  \\      /      \\  /      \\       |      \\|  \\  |  \\                ||\n"
           "||    |  $$$$$$\\|  $$$$$$\\| $$$$$$$$      | $$     |  $$$$$$\\|  $$$$$$\\       \\$$$$$$| $$\\ | $$                ||\n"
           "||    | $$ __\\$$| $$__| $$| $$__          | $$     | $$  | $$| $$ __\\$$        | $$  | $$$\\| $$                ||\n"
           "||    | $$|    \\| $$    $$| $$  \\         | $$     | $$  | $$| $$|    \\        | $$  | $$$$\\ $$                ||\n"
           "||    | $$ \\$$$$| $$$$$$$$| $$$$$         | $$     | $$  | $$| $$ \\$$$$        | $$  | $$\\$$ $$                ||\n"
           "||    | $$__| $$| $$  | $$| $$            | $$_____| $$__/ $$| $$__| $$       _| $$_ | $$ \\$$$$                ||\n"
           "||     \\$$    $$| $$  | $$| $$            | $$     \\\\$$    $$ \\$$    $$      |   $$ \\| $$  \\$$$                ||\n"
           "||      \\$$$$$$  \\$$   \\$$ \\$$             \\$$$$$$$$ \\$$$$$$   \\$$$$$$        \\$$$$$$ \\$$   \\$$                ||\n");
    printf("++=============================================================================================================++");
    for(i=0;i<5;i++)
    {
        printf("\n");
    }

}

/**La funzione topheadReg() stampa una scritta per la grafica della registrazione*/

void topheadReg()
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("\n");
    }
    printf("\n++=============================================================================================================++\n");
    printf("||   ______    ______   ________        ______   ______   ______   __    __        __    __  _______           ||\n"
           "||  /      \\  /      \\ |        \\      /      \\ |      \\ /      \\ |  \\  |  \\      |  \\  |  \\|                  ||\n"
           "|| |  $$$$$$\\|  $$$$$$\\| $$$$$$$$     |  $$$$$$\\ \\$$$$$$|  $$$$$$\\| $$\\ | $$      | $$  | $$| $$$$$$$\\         ||\n"
           "|| | $$ __\\$$| $$__| $$| $$__         | $$___\\$$  | $$  | $$ __\\$$| $$$\\| $$      | $$  | $$| $$__/ $$         ||\n"
           "|| | $$|    \\| $$    $$| $$  \\         \\$$    \\   | $$  | $$|    \\| $$$$\\ $$      | $$  | $$| $$    $$         ||\n"
           "|| | $$ \\$$$$| $$$$$$$$| $$$$$         _\\$$$$$$\\  | $$  | $$ \\$$$$| $$\\$$ $$      | $$  | $$| $$$$$$$          ||\n"
           "|| | $$__| $$| $$  | $$| $$           |  \\__| $$ _| $$_ | $$__| $$| $$ \\$$$$      | $$__/ $$| $$               ||\n"
           "||  \\$$    $$| $$  | $$| $$            \\$$    $$|   $$ \\ \\$$    $$| $$  \\$$$       \\$$    $$| $$               ||\n"
           "||   \\$$$$$$  \\$$   \\$$ \\$$             \\$$$$$$  \\$$$$$$  \\$$$$$$  \\$$   \\$$        \\$$$$$$  \\$$               ||\n");
    printf("++=============================================================================================================++");
    for(i=0;i<5;i++)
    {
        printf("\n");
    }

}


/**La funzione tophead() stampa una scritta per la grafica del profile*/

void tophead()
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("\n");
    }
    printf("\n++=============================================================================================================++\n");
    printf("||      ______    ______   ________        _______   _______    ______   ________  ______  __        ________  ||\n"
           "||     /      \\  /      \\ |        \\      |       \\ |       \\  /      \\ |        \\|      \\|  \\      |        \\ ||\n"
           "||    |  $$$$$$\\|  $$$$$$\\| $$$$$$$$      | $$$$$$$\\| $$$$$$$\\|  $$$$$$\\| $$$$$$$$ \\$$$$$$| $$      | $$$$$$$$ ||\n"
           "||    | $$ __\\$$| $$__| $$| $$__          | $$__/ $$| $$__| $$| $$  | $$| $$__      | $$  | $$      | $$       ||\n"
           "||    | $$|    \\| $$    $$| $$  \\         | $$    $$| $$    $$| $$  | $$| $$  \\     | $$  | $$      | $$  \\    ||\n"
           "||    | $$ \\$$$$| $$$$$$$$| $$$$$         | $$$$$$$ | $$$$$$$\\| $$  | $$| $$$$$     | $$  | $$      | $$$$$    ||\n"
           "||    | $$__| $$| $$  | $$| $$            | $$      | $$  | $$| $$__/ $$| $$       _| $$_ | $$_____ | $$_____  ||\n"
           "||     \\$$$$$$  \\$$   \\$$ \\$$             | $$      | $$  | $$ \\$$    $$| $$      |   $$ \\| $$     \\| $$     \\ ||\n"
           "||                                        \\$$       \\$$   \\$$  \\$$$$$$  \\$$       \\$$$$$$ \\$$$$$$$$ \\$$$$$$$$  ||\n" );
    printf("++=============================================================================================================++");
    for(i=0;i<5;i++)
    {
        printf("\n");
    }

}


/**La funzione cartTophead() stampa una scritta per la grafica del carrello*/

void cartTophead() {
    int i;
    for(i=0;i<4;i++)
    {
        printf("\n");
    }
    printf("\n++=========================================================================================++\n");
    printf("||      ______    ______   ________        ______    ______   _______   ________           ||\n"
           "||     /      \\  /      \\ |        \\      /      \\  /      \\ /       \\ /        |          ||\n"
           "||    |  $$$$$$\\|  $$$$$$\\| $$$$$$$$      /$$$$$$  |/$$$$$$  |$$$$$$$  |$$$$$$$$/          ||\n"
           "||    | $$ __\\$$| $$__| $$| $$__          $$ |  $$/ $$ |__$$ |$$ |__$$ |   $$ |            ||\n"
           "||    | $$|    \\| $$    $$| $$  \\         $$ |      $$    $$ |$$    $$<    $$ |            ||\n"
           "||    | $$ \\$$$$| $$$$$$$$| $$$$$         $$ |   __ $$$$$$$$ |$$$$$$$  |   $$ |            ||\n"
           "||    | $$__| $$| $$  | $$| $$            $$ \\__/  |$$ |  $$ |$$ |  $$ |   $$ |            ||\n"
           "||     \\$$$$$$  \\$$   \\$$ \\$$             $$    $$/ $$ |  $$ |$$ |  $$ |   $$ |            ||\n"
           "||                                        $$$$$$/  $$/   $$/ $$/   $$/    $$/              ||\n" );
    printf("++=========================================================================================++");
    for(i=0;i<5;i++)
    {
        printf("\n");
    }
}


/**La funzione cartTotal() stampa una scritta per la grafica dello scontrino*/

void cartTotal () {
    printf("\n++=========================================================================================++\n");
    printf("||                                                                                         ||\n");
    printf("||                                                                                         ||\n");
    printf("||      TOTALE SPESA: \t%.2lf                                                             ||\n",finalPrice);
    printf("++=========================================================================================++");
}

/**La funzione creditCardMenu() stampa una scritta per la grafica della carta di credito*/


void creditCardMenu(){
    printf("\n++=========================================================================================++\n");
    printf("    Inserire le informazioni della carta di credito\n");
    printf("\n++=========================================================================================++\n");
}

/**La funzione shippingAddressMenu() stampa una scritta per la grafica della spedizione*/


void shippingAddressMenu (){
    printf("\n++=========================================================================================++\n");
    printf("    Inserire indirizzo per la spedizione dell'ordine\n");
    printf("\n++=========================================================================================++\n");
 }


/**La funzione confirmOrder() stampa una scritta per la grafica della spedizione*/

 void confirmOrder(){
     printf("\n++=========================================================================================++\n");
     printf("    \nOrdine Confermato\n");
     printf("\n++=========================================================================================++\n");
     system("pause");
}

/**La funzione showUserOrdersMenu() stampa una scritta per la grafica degli ordini*/


void showUserOrdersMenu(unsigned short int idOrder,unsigned short int status, unsigned short int idProduct, unsigned short int productQuantity){
    char strStatus[MAX_STATUS_WORD_LENGTH];
    strcpy(strStatus, getStatus(status));
    cloth(idProduct);
    printf("\n++=========================================================================================++\n");
    printf("    \nOrdine ID %hu\n", idOrder);
    printf("\n++=========================================================================================++\n");
    printf("     Stato ordine: %s                                                                                    \n\n",strStatus);
    puts("");
    printf("     Quantita': %hu\n\n", productQuantity);
    printf("\n++=========================================================================================++\n\n\n\n\n");
}


/**La funzione topheadOrd() stampa una scritta per la grafica degli ordini*/


void topheadOrd()
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("\n");
    }
    printf("\n++=============================================================================================================++\n");
    printf("||      ______    ______   ________        ______   _______   _______   ________  _______    ______            ||\n"
           "||     /      \\  /      \\ |        \\      /      \\ |       \\ |       \\ |        \\|       \\  /      \\           ||\n"
           "||    |  $$$$$$\\|  $$$$$$\\| $$$$$$$$      |  $$$$$$\\| $$$$$$$\\| $$$$$$$\\| $$$$$$$$| $$$$$$$\\|  $$$$$$\\         ||\n"
           "||    | $$ __\\$$| $$__| $$| $$__          | $$  | $$| $$__| $$| $$  | $$| $$__    | $$__| $$| $$___\\$$         ||\n"
           "||    | $$|    \\| $$    $$| $$  \\         | $$  | $$| $$    $$| $$  | $$| $$  \\   | $$    $$ \\$$    \\          ||\n"
           "||    | $$ \\$$$$| $$$$$$$$| $$$$$         | $$  | $$| $$$$$$$\\| $$  | $$| $$$$$   | $$$$$$$\\ _\\$$$$$$\\         ||\n"
           "||    | $$__| $$| $$  | $$| $$            | $$__/ $$| $$  | $$| $$__/ $$| $$_____ | $$  | $$|  \\__| $$         ||\n"
           "||     \\$$    $$| $$  | $$| $$            \\$$    $$| $$  | $$| $$    $$| $$     \\| $$  | $$ \\$$    $$          ||\n"
           "||      \\$$$$$$  \\$$   \\$$ \\$$             \\$$$$$$  \\$$   \\$$ \\$$$$$$$  \\$$$$$$$$ \\$$   \\$$  \\$$$$$$           ||\n");
    printf("++=============================================================================================================++");
    for(i=0;i<5;i++)
    {
        printf("\n");
    }

}

/**La funzione topheadOrd() stampa una scritta per la grafica degli admin*/

void topheadAdmin()
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("\n");
    }
    printf("\n++=====================================================================================================++\n");
    printf("||   ______    ______   ________        ______   _______   __       __  ______  __    __               ||\n"
           "||  /      \\  /      \\ |        \\      /      \\ |       \\ |  \\     /  \\|      \\|  \\  |  \\              ||\n"
           "|| |  $$$$$$\\|  $$$$$$\\| $$$$$$$$     |  $$$$$$\\| $$$$$$$\\| $$\\   /  $$ \\$$$$$$| $$\\ | $$              ||\n"
           "|| | $$ __\\$$| $$__| $$| $$__         | $$__| $$| $$  | $$| $$$\\ /  $$$  | $$  | $$$\\| $$              ||\n"
           "|| | $$|    \\| $$    $$| $$  \\        | $$    $$| $$  | $$| $$$$\\  $$$$  | $$  | $$$$\\ $$              ||\n"
           "|| | $$ \\$$$$| $$$$$$$$| $$$$$        | $$$$$$$$| $$  | $$| $$\\$$ $$ $$  | $$  | $$\\$$ $$              ||\n"
           "|| | $$__| $$| $$  | $$| $$           | $$  | $$| $$__/ $$| $$ \\$$$| $$ _| $$_ | $$ \\$$$$              ||\n"
           "||  \\$$    $$| $$  | $$| $$           | $$  | $$| $$    $$| $$  \\$ | $$|   $$ \\| $$  \\$$$              ||\n"
           "||   \\$$$$$$  \\$$   \\$$ \\$$            \\$$   \\$$ \\$$$$$$$  \\$$      \\$$ \\$$$$$$ \\$$   \\$$              ||\n");
    printf("++=====================================================================================================++");
    for(i=0;i<5;i++)
    {
        printf("\n");
    }

}