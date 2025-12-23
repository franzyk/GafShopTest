#include "ui.h"
#include "interface.h"
#include "checksAndUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include "catalog.h"
#include <string.h>
#include <windows.h>

extern char tempName[];
extern double finalPrice;

void menu2() {
    printf("  ______    ______   ________         ______   __    __   ______   _______  \n"
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
}

void displayMenu1_1(unsigned short int selectedOption) {
    refreshPage();
    menu();
    printf("\n\n\t\t\t BENVENUTO %s\n",tempName);

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
}

void displayMenuAdmin(unsigned short int selectedOption) {
    refreshPage();
    menu();
    printf("\n\n\t\t\t BENVENUTO %s\n",tempName);

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
}

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
}

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
}

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

void cloth(unsigned short int a) {
    FILE* file = fopen("clothes.csv", "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file\n");
    }

    char line[MAX_CLOTHINGITEM_LENGTH];
    while (fgets(line, MAX_CLOTHINGITEM_LENGTH, file) != NULL) {
        Product item;
        sscanf(line, "%hu,%[^,],%[^,],%[^,],%[^,],%lf,%d", &item.code, item.name, item.brand,item.description, item.size, &item.price, &item.quantity);

        if (item.code == a) {
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
}

void clothes(unsigned short int i,unsigned short int selectedOption) {
// ... implementation of clothes ...
}

void buttons(unsigned short int selectedOption,unsigned short int a) {
// ... implementation of buttons ...
}

void topheadLog()
{
// ... implementation of topheadLog ...
}

void topheadReg()
{
// ... implementation of topheadReg ...
}

void tophead()
{
// ... implementation of tophead ...
}

void cartTophead() {
// ... implementation of cartTophead ...
}

void cartTotal () {
// ... implementation of cartTotal ...
}

void creditCardMenu(){
// ... implementation of creditCardMenu ...
}

void shippingAddressMenu (){
// ... implementation of shippingAddressMenu ...
}

void confirmOrder(){
// ... implementation of confirmOrder ...
}

void showUserOrdersMenu(unsigned short int idOrder,unsigned short int status, unsigned short int idProduct, unsigned short int productQuantity){
// ... implementation of showUserOrdersMenu ...
}

void topheadOrd()
{
// ... implementation of topheadOrd ...
}

void topheadAdmin()
{
// ... implementation of topheadAdmin ...
}
