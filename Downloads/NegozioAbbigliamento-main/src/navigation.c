#include "navigation.h"
#include <conio.h>
#include <stdlib.h>
#include "checksAndUtils.h"
#include "ui.h"
#include "authentication.h"
#include "catalog.h"
#include "paymentDelivery.h"
#include "admin.h"
#define NUMBER_OF_LOCATION 30
#define NUMBER_OF_CHOICE 2

unsigned short int stato = 9;
bool controlFlag;

void control(AppState* state, unsigned short int location) {
        unsigned short int admin = checkAdmin(tempEmail);
        bool flag = 0;
        unsigned short int selectedOption = 0;
        int keyPressed;

        if (location == 1) {
            displayMenu1(selectedOption);   // primo menu  grafica
        }else if (location == 2 ) {
            displayMenu2(selectedOption);   //secondo menu grafica
        }  else if (location == 3) {
            clothes(1, selectedOption);   // da 3 a 7 stampa i vestiti a gruppi di 3  e il bottone indietro per tornare al menu
            buttons(selectedOption,6);
        } else if (location == 4) {
            clothes(2, selectedOption);
            buttons(selectedOption,6);
        } else if (location == 5) {
            clothes(3, selectedOption);
            buttons(selectedOption,6);
        } else if (location == 6) {
            clothes(4, selectedOption);
            buttons(selectedOption,6);
        } else if (location == 7) {
            clothes(5, selectedOption);
            buttons(selectedOption,6);
        } else if (location == 8) {                 // stampa tutti i vestiti ma se ci troviamo nella sezione admin e facciamo modifica
            refreshPage();                          // il controlFlag sarà uguale a 1 quindi darà due visualizzazioni diverse
            if (controlFlag == 1) {
                clothes(stato - 8,selectedOption);  // -8 perchè lo stato parte da 9 per la funzione cloth va bene mentre per clothes va riadattato partendo da 1
                buttons(selectedOption, 8);
            }else{
                cloth(stato);
                buttons(selectedOption, 1);
            }
        }else if (location >= 9 && location <= 23) {  // stampa i vestiti singolarmente
            refreshPage();
            cloth(location);
            if(state->loggedIn) {
                buttons(selectedOption, 2);
            }else{
                buttons(selectedOption,7);
            }
        }else if (location == 24){              // menu intermedio in cui l'utente può scegliere se vedere il profilo, ordini ecc...
            if (admin == 1){
                displayMenuAdmin(selectedOption);  // se si è admin si ha un impostazione di gestione in più
            }else{
                displayMenu1_1(selectedOption);
            }
        }else if (location == 25){   // scrive tutto il profilo con un bottone indietro
            printProfileData();
            buttons(selectedOption,7);
        }else if (location == 26){     // fa vedere il carrello
            refreshPage();
            cartTophead();
            idCartExtract();
            if(cartItems == 0){   // se il carrello è vuoto è presente solo il tasto indietro
                buttons(selectedOption,7);
            }else{
                buttons(selectedOption,3);
            }

        }else if (location == 27) { // mostra lo scontrino con il tasto finale compra oppure indietro per tornare al menu
            refreshPage();
            cartTophead();
            idCartExtract();
            cartTotal ();
            buttons(selectedOption,4);
        }else if (location == 28){  // chiede all'utente se si vuole pagare con la carta di credito o alla consegna
            refreshPage();
            cartTophead();
            buttons(selectedOption,5);
        }else if (location == 29){   // menu gestione dell'admin
            displayMenuAdmin2(selectedOption);
        }
        /*si entra in un ciclo while infinito in cui viene continuamente il refresh della pagina se vengono premute le frecce allora
         * la selectedOption cambia di valore premendo invio si chiama la funzione option*/
        while (1) {
            keyPressed = getch();

            if (keyPressed == 0 || keyPressed == 224) {
                // in molti sistemi sono codici speciali

                keyPressed = getch();

                if (keyPressed == KEY_RIGHT || keyPressed == KEY_DOWN) {
                    if(location >= 9 && location <= 23 && !state->loggedIn) {
                        selectedOption = (selectedOption + 1) % (state->navigationMap[location - 1][1] - 1);
                    } else if(location == 26 && cartItems == 0) {
                        selectedOption = (selectedOption + 1) % (state->navigationMap[location - 1][1] - 2);
                    } else if(location == 24 && admin == 1) {
                        selectedOption = (selectedOption + 1) % (state->navigationMap[location - 1][1] + 1);
                    } else if(location == 8 && controlFlag == 1) {
                        selectedOption = (selectedOption + 1) % (state->navigationMap[location - 1][1] + 3);
                    } else {
                        selectedOption = (selectedOption + 1) % state->navigationMap[location - 1][1];
                    }
                } else if (keyPressed == KEY_LEFT || keyPressed == KEY_UP) {
                    if(location >= 9 && location <= 23 && !state->loggedIn) {
                        selectedOption = (selectedOption - 1 + (state->navigationMap[location - 1][1] - 1)) % (state->navigationMap[location-1][1] - 1);
                    } else if(location == 26 && cartItems == 0) {
                        selectedOption = (selectedOption - 1 + (state->navigationMap[location - 1][1] - 2)) % (state->navigationMap[location-1][1] - 2);
                    } else if(location == 24 && admin == 1) {
                        selectedOption = (selectedOption - 1 + (state->navigationMap[location - 1][1] + 1)) % (state->navigationMap[location-1][1] + 1);
                    } else if(location == 8 && controlFlag == 1) {
                        selectedOption = (selectedOption - 1 + (state->navigationMap[location - 1][1] + 3)) % (state->navigationMap[location-1][1] + 3);
                    } else {
                        selectedOption = (selectedOption - 1 + state->navigationMap[location - 1][1]) % state->navigationMap[location-1][1];
                    }
                }
            } else if (keyPressed == KEY_ENTER) {
                option(state, location, selectedOption);
                flag = 1;
            }

            if (location == 1 && flag == 0) {
                displayMenu1(selectedOption);
            } else if (location == 2  && flag == 0) {
                displayMenu2(selectedOption);
            } else if (location == 3) {
                refreshPage();
                clothes(1,selectedOption);
                buttons(selectedOption,6);
            } else if (location == 4) {
                refreshPage();
                clothes(2,selectedOption);
                buttons(selectedOption,6);
            } else if (location == 5) {
                refreshPage();
                clothes(3,selectedOption);
                buttons(selectedOption,6);
            } else if (location == 6) {
                refreshPage();
                clothes(4,selectedOption);
                buttons(selectedOption,6);
            } else if (location == 7) {
                refreshPage();
                clothes(5,selectedOption);
                buttons(selectedOption,6);
            }else if (location == 8 ) {
                refreshPage();
                if (controlFlag == 1) {
                    clothes(stato - 8,selectedOption);
                    buttons(selectedOption, 8);
                }else{
                    cloth(stato);
                    buttons(selectedOption, 1);
                }
            }else if (location >= 9 && location <= 23) {
                refreshPage();
                cloth(location);
                if(logged == 1) {
                    buttons(selectedOption, 2);
                }else{
                    buttons(selectedOption,7);
                }
            }else if (location == 24){
                if (admin == 1){
                    displayMenuAdmin(selectedOption);
                }else{
                    displayMenu1_1(selectedOption);
                }
            }else if (location == 25){
                printProfileData();
                buttons(selectedOption,7);
            }else if (location == 26){
                refreshPage();
                cartTophead();
                idCartExtract();
                if(cartItems == 0){
                    buttons(selectedOption,7);
                }else{
                    buttons(selectedOption,3);
                }
            }else if (location == 27) {
                refreshPage();
                cartTophead();
                idCartExtract();
                cartTotal ();
                buttons(selectedOption,4);
            }else if (location == 28){
                refreshPage();
                cartTophead();
                buttons(selectedOption,5);
            }else if (location == 29){
                displayMenuAdmin2(selectedOption);
            }
        }
    }


/**La funzione option() controlla la logica per la selezione delle opzioni di menu in base alla posizione e all'opzione selezionata.*/

    void option(AppState* state, const unsigned short int location,const unsigned short int selectedOption) {

        if (location == 1) {
            loading();
            refreshPage();
            switch(selectedOption) {
                case 0:
                    control(state, state->navigationMap[1][0]);
                    break;
                case 1:
                    topheadLog();       //si entra nel login
                    login();
                    break;
                case 2:
                    topheadReg();           // si entra nella registrazione
                    registerUser();
                    break;
            }
        }else if (location == 2 && selectedOption >= 0) {
            catalog(selectedOption);            // mostra i vestiti
        }else if (location == 3) {
            switch (selectedOption) {
                case 0:
                    control(state, state->navigationMap[8][0]);
                    break;
                case 1:
                    control(state, state->navigationMap[9][0]);
                    break;
                case 2:
                    control(state, state->navigationMap[10][0]);
                    break;
            }
        }else if (location == 4) {
            switch (selectedOption) {
                case 0:
                    control(state, state->navigationMap[11][0]);
                    break;
                case 1:
                    control(state, state->navigationMap[12][0]);
                    break;
                case 2:
                    control(state, state->navigationMap[13][0]);
                    break;
            }
        }else if (location == 5) {
            switch (selectedOption) {
                case 0:
                    control(state, state->navigationMap[14][0]);
                    break;
                case 1:
                    control(state, state->navigationMap[15][0]);
                    break;
                case 2:
                    control(state, state->navigationMap[16][0]);
                    break;
            }
        }else if (location == 6) {
            switch (selectedOption) {
                case 0:
                    control(state, state->navigationMap[17][0]);
                    break;
                case 1:
                    control(state, state->navigationMap[18][0]);
                    break;
                case 2:
                    control(state, state->navigationMap[19][0]);
                    break;
            }
        } else if (location == 7) {
            switch (selectedOption) {
                case 0:
                    control(state, state->navigationMap[20][0]);
                    break;
                case 1:
                    control(state, state->navigationMap[21][0]);
                    break;
                case 2:
                    control(state, state->navigationMap[22][0]);
                    break;
            }
        }

        if ((location >= 3 && location <= 7) && selectedOption == 3) {
            control(state, state->navigationMap[1][0]);
        } else if (location == 8) {
            if(controlFlag == 1){
                switch (selectedOption) {
                    case 0:
                        if(stato == 9){
                            editClothInfo(9);
                        }else if(stato == 10){
                            editClothInfo(12);
                        }else if(stato == 11){
                            editClothInfo(15);
                        }else if(stato == 12){
                            editClothInfo(18);
                        }else if (stato == 13){
                            editClothInfo(21);
                        }
                        break;
                    case 1:
                        if(stato == 9){
                            editClothInfo(10);
                        }else if(stato == 10){
                            editClothInfo(13);
                        }else if(stato == 11){
                            editClothInfo(16);
                        }else if(stato == 12){
                            editClothInfo(19);
                        }else if (stato == 13){
                            editClothInfo(22);
                        }
                        break;
                    case 2:
                        if(stato == 9){
                            editClothInfo(11);
                        }else if(stato == 10){
                            editClothInfo(14);
                        }else if(stato == 11){
                            editClothInfo(17);
                        }else if(stato == 12){
                            editClothInfo(20);
                        }else if (stato == 13){
                            editClothInfo(23);
                        }
                        break;
                    case 3:
                        if (stato - 8 > 1) {
                            stato--;
                            printf("\n%d\n",stato);
                        }else {
                            control(state, state->navigationMap[28][0]);
                        }
                        break;
                    case 4:
                        if (stato - 8 < 5) {
                            stato++;
                            printf("\n%d\n",stato);
                        }
                        break;
                }
            }else {
                switch (selectedOption) {
                    case 0:
                        if (stato > 9) {
                            stato--;
                        } else {
                            control(state, state->navigationMap[1][0]);
                        }
                        break;
                    case 1:
                        if (stato < 23) {
                            stato++;
                        }
                        break;
                }
            }
        } else if (location >= 9 && location <= 11 && selectedOption == 0){
            catalog(1); // il catalogo delle maglie
        }else if (location >= 12 && location <= 14 && selectedOption == 0){
            catalog(2); // il catalogo delle maglie
        }else if (location >= 15 && location <= 17 && selectedOption == 0){
            catalog(3); // il catalogo delle maglie
        }else if (location >= 18 && location <= 20 && selectedOption == 0){
            catalog(4); // il catalogo delle maglie
        }else if (location >= 21 && location <= 23 && selectedOption == 0){
            catalog(5); // il catalogo delle maglie
        }else if (location == 24) {
            switch (selectedOption) {
                case 0:
                    control(state, state->navigationMap[1][0]);
                    break;
                case 1:
                    control(state, state->navigationMap[24][0]);
                    break;
                case 2:
                    control(state, state->navigationMap[25][0]);
                    break;
                case 3:
                    loading();
                    refreshPage();
                    topheadOrd();
                    showUserOrders(tempEmail);
                    puts("\n\n\n");
                    system("pause");
                    break;
                case 4:
                    state->loggedIn = false;
                    control(state, state->navigationMap[0][0]);
                    break;
                case 5:
                    loading();
                    refreshPage();
                    topheadOrd();
                    refundUserOrders(tempEmail);
                    break;
                case 6:
                    controlFlag = 1;
                    control(state, state->navigationMap[28][0]);
                    break;
            }
        }else if (location == 25 && selectedOption == 0){
            control(state, state->navigationMap[23][0]);
        }else if(location >= 9 && location <= 23 && selectedOption == 1){
            puts("\n\n\t\tPRODOTTO AGGIUNTO AL CARRELLO OPPURE E' STATO GIA' AGGIUNTO");
            system("pause");
            cart(location);
        }else if (location == 26) {
            switch (selectedOption) {
                case 0:
                    control(state, state->navigationMap[23][0]);
                    break;
                case 1:
                    cartManager();
                    break;
                case 2:
                    emptyFile("cart.csv");
                    cartItems = 0;
                    break;
            }
        }else if (location == 27){
            switch (selectedOption) {
                case 0:
                    control(state, state->navigationMap[23][0]);
                    break;
                case 1:
                    control(state, state->navigationMap[27][0]);
                    break;
            }
        }else if (location == 28){
            loading();
            refreshPage(); //Aggiorno la pagina e metto l'intestazione del carrello
            cartTophead();
            switch (selectedOption) {
                case 0:
                    // CARTA DI CREDITO
                    creditCardMenu();
                    inputCreditCard();
                    loading();
                    refreshPage();
                    inputDeliveryAddress();
                    cartTophead();
                    confirmOrder();
                    createOrder();
                    emptyFile("cart.csv");
                    control(state, state->navigationMap[23][0]);
                    break;
                case 1:
                    // PAGAMENTO ALLA CONSEGNA
                    inputDeliveryAddress();
                    cartTophead();
                    confirmOrder();
                    createOrder();
                    emptyFile("cart.csv");
                    control(state, state->navigationMap[23][0]);
                    break;
            }
        }else if (location == 29){
            loading();
            refreshPage(); //Aggiorno la pagina e metto l'intestazione del carrello
            switch (selectedOption) {
                case 0:
                    catalog(0);        // mostra i vestiti a gruppi di 3 per la selezione e la modifica
                    break;
                case 1:
                    addCoupon();         // crea i coupon
                    break;
                case 2:
                    showAllProfiles();        // mostra tutti gli utenti
                    break;
                case 3:
                    showAllUserOrders();
                    break;
                case 4:
                    controlFlag = 0;
                    control(state, state->navigationMap[23][0]);
                    break;
            }
        }
    }




