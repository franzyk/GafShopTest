#include <stdio.h>
#include <string.h>
#include "checksAndUtils.h"
#include "navigation.h"
#include "authentication.h"
#include <stdlib.h>

#define NUMBER_OF_LOCATION 30
#define NUMBER_OF_CHOICE 2

extern const unsigned short int global_location[NUMBER_OF_LOCATION][NUMBER_OF_CHOICE]; // spiegata nel main
char tempName[MAX_NAME_SURNAME_LENGTH]; // nome dell'utente da far apparire nei menu.
char tempEmail[MAX_EMAIL_LENGTH]; // email dell'utente loggato
bool logged; // variabile bool che è 1 se un utente è loggato


/** La funzione registerUser consente di registrare un nuovo utente nel file "users.csv".*/

void registerUser() {
    User user;
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;

    puts("BENVENUTO PROCEDI NELLA REGISTRAZIONE ");
    printf("------------------------------------------------------------------------------------");

    do{
        printf("\n\n\t\tEMAIL: ");
        fflush(stdin);
        scanf_s("%50[^\n]",user.email,MAX_EMAIL_LENGTH);
        user.email[strcspn(user.email, "\n")] = '\0';                       //EMAIL
        if(isEmailTaken(user.email) == 1){
            printf("la mail e' gia' stato utilizzata. Si prega di sceglierne un altra.\n");
        }
    }while (isEmailTaken(user.email) == 1 || (checkEmailNameDomain(user.email)) == 0);

    do {
        printf("\n\t\tNOME: ");
        fflush(stdin);
        scanf_s("%39[^\n]",user.name,MAX_NAME_SURNAME_LENGTH);                 //NAME
        user.name[strcspn(user.name, "\n")] = '\0';
    } while(checkNameSurname(user.name) == 0);

    do {
        printf("\n\t\tCOGNOME: ");
        fflush(stdin);
        scanf_s("%39[^\n]",user.surname,MAX_NAME_SURNAME_LENGTH);                   //SURNAME
        user.surname[strcspn(user.surname, "\n")] = '\0';
    } while(checkNameSurname(user.surname) == 0);

    do {
        printf("\n\t\tPASSWORD: ");
        fflush(stdin);
        scanf_s("%21[^\n]",user.password,MAX_PASSWORD_LENGTH);               //PASSWORD
        user.password[strcspn(user.password, "\n")] = '\0';
    } while(emptyString(user.password) == 0 || checkPassword(user.password) == 0);

    do {
        printf("\n\t\tNUMERO DI TELEFONO: ");
        fflush(stdin);
        scanf_s("%11[^\n]",user.phoneNumber,MAX_PHONENUMBER_LENGTH);             //PHONE NUMBER
        user.phoneNumber[strcspn(user.phoneNumber, "\n")] = '\0';
    } while(emptyString(user.phoneNumber) == 0 || checkPhoneNumber(user.phoneNumber) == 0);

    do {
        printf("\n\t\tINDIRIZZO (via/Viale ... SENZA NUMERI): ");
        fflush(stdin);
        scanf_s("%79[^\n]",user.address,MAX_ADDRESS_LENGTH);
        user.address[strcspn(user.address, "\n")] = '\0';
    } while(emptyString(user.address) == 0 || checkAddress(user.address) == 0);     //INDIRIZZO

    do {
        printf("\n\t\tNUMERO CIVICO: ");
        fflush(stdin);
        scanf_s("%9[^\n]",user.addressNumber,MAX_ADDRESSNUMBER_LENGTH);             //ADDRESS NUMBER
        user.addressNumber[strcspn(user.addressNumber, "\n")] = '\0';

    } while(emptyString(user.addressNumber) == 0 || checkAddressNumber(user.addressNumber) == 0);
    printf("\n\t\tINSERIRE LA DATA DI NASCITA UN CAMPO ALLA VOLTA:\n");

    do {
        do {
            printf("\n\t\tGIORNO: ");
            fflush(stdin);
            scanf_s("%3s", user.dob.day, (unsigned)_countof(user.dob.day));
        } while (emptyString(user.dob.day) == 0 || isNumber(user.dob.day) == 0);
        day = atoi(user.dob.day);

        do {
            printf("\n\t\tMESE: ");
            fflush(stdin);
            scanf_s("%3s", user.dob.month, (unsigned)_countof(user.dob.month));
        } while (emptyString(user.dob.month) == 0 || isNumber(user.dob.month) == 0);
        month = atoi(user.dob.month);

        do {
            printf("\n\t\tANNO: ");
            fflush(stdin);
            scanf_s("%5s", user.dob.year, (unsigned)_countof(user.dob.year));
        } while (emptyString(user.dob.year) == 0 || isNumber(user.dob.year) == 0);
        year = atoi(user.dob.year);

    } while (isValidDate(day, month, year) == 0 || isAgeValid(day, month, year) == 0);

    FILE *file = fopen(USERS_FILE, "a");
    if (file == NULL) {
        printf("Errore nell'apertura del file.");
        return;
    }

    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d\n", user.email, user.password, user.name, user.surname, user.phoneNumber, user.address, user.addressNumber, user.dob.day, user.dob.month, user.dob.year, 0);
    //scrivo sul file l'utente registrato

    fclose(file);

    printf("REGISTRAZIONE COMPLETATA CON SUCCESSO.\n");
    loading();
    refreshPage();              // grafica
    topheadLog();
    login();    // una volta registrato si va nel login
}


/** La funzione login() gestisce il processo di accesso degli utenti.*/

int login() {
    logged = 0;  // mette a 0 perchè l'utente non si è ancora loggato
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    puts("BENVENUTO PROCEDI NEL LOGIN ");
    printf("------------------------------------------------------------------------------------");

    fflush(stdin);
    printf("\n\n\t\tEMAIL: ");
    fgets(email, sizeof(email), stdin);     // EMAIL DA INSERIRE NEL LOGIN
    email[strcspn(email, "\n")] = '\0';

    fflush(stdin);
    printf("\n\t\tPASSWORD: ");
    fgets(password, sizeof(password), stdin);       // PASSWORD DA INSERIRE NEL LOGIN
    password[strcspn(password, "\n")] = '\0';

    FILE *file = fopen(USERS_FILE, "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 0;
    }

    char line[MAX_LINE_LENGTH]; // linea con la grandezza massima nel file

    while (fgets(line, sizeof(line), file) != NULL) {
        char *savedEmail = strtok(line, ",");       // divide la stringa tramite la virgola
        char *savedPassword = strtok(NULL, ",");
        if (savedEmail != NULL && strcmp(savedEmail, email) == 0) {
            if (savedPassword != NULL && strcmp(savedPassword, password) == 0) {
                printf("\n Accesso Effetuato \n");// La variabile savedPassword contiene la password associata all'email corrente
                logged = 1; // ora è loggato
                } else {                                   // Controlla se la password corrisponde alla password inserita
                   // printf("\nPassword o Email errata!\n");
                }
            fclose(file);
            break; // Esci dal ciclo poiché hai trovato l'email corrispondente
            }
    }
    fclose(file);
    if (logged == 1){           // se si è effettuato il login correttamente procede con il salvarsi tutti i dati dell'utente loggato.
        loading();
        refreshPage();
        printf("%s",email) ;
        saveUserData(email);
    }else {
        printf("\n\n ACCESSO NON RIUSCITO RITENTA\n \n");
        login();    // se non si è effettuato il login correttamente si ripete.
    }
}


/** La funzione saveUserData() gestisce il salvataggio dei dati dell'utente in un file CSV separato chiamato "profile.csv".*/

void saveUserData(const char* email) {
    FILE* file = fopen(USERS_FILE, "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    char line[MAX_EMAIL_LENGTH + MAX_PASSWORD_LENGTH + MAX_NAME_SURNAME_LENGTH + MAX_NAME_SURNAME_LENGTH + MAX_PHONENUMBER_LENGTH + MAX_ADDRESS_LENGTH + MAX_ADDRESSNUMBER_LENGTH + MAX_GG_MM_LENGTH + MAX_GG_MM_LENGTH + MAX_AAAA_LENGTH + 10]; // Dichiarazione di una variabile per contenere una riga letta dal file

    User user; // Dichiarazione di una variabile di tipo User per memorizzare i dati utente

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) { // Legge ogni riga del file finché non raggiunge la fine
        char* savedEmail = strtok(line, ","); // Esegue il parsing della riga utilizzando la virgola come delimitatore e ottiene l'email salvata
        if (savedEmail != NULL && strcmp(savedEmail, email) == 0) { // Controlla se l'email corrisponde all'email fornita come parametro
            // Trovati i dati dell'utente
            // È possibile estrarre e memorizzare i campi richiesti qui
            strcpy(user.email, savedEmail); // Copia l'email nella struttura User
            strcpy(user.password, strtok(NULL, ",")); // Copia la password
            strcpy(user.name, strtok(NULL, ",")); // Copia il nome
            strcpy(user.surname, strtok(NULL, ",")); // Copia il cognome
            strcpy(user.phoneNumber, strtok(NULL, ",")); // Copia il numero di telefono
            strcpy(user.address, strtok(NULL, ","));
            strcpy(user.addressNumber, strtok(NULL, ","));
            strcpy(user.dob.day, strtok(NULL, ","));
            strcpy(user.dob.month, strtok(NULL, ","));
            strcpy(user.dob.year, strtok(NULL, ","));
            strcpy(tempName, user.name);
            strcpy(tempEmail, user.email);
            logged = 1;

            FILE* profile = fopen(PROFILE_FILE, "w");
            if (profile == NULL) {
                printf("Errore nell'apertura del file di output.\n");
                return;
            }

            fprintf(profile, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
                    user.email, user.password, user.name, user.surname, user.phoneNumber,
                    user.address, user.addressNumber, user.dob.day, user.dob.month, user.dob.year);

            fclose(profile);
            break;
        }
    }

    fclose(file); // Chiude il file "users.csv"
    control(global_location[24][0]); // fa vedere il menu del profilo
}

/** La funzione printProfileData() stampa i dati del profilo dell'utente prelevati dal file "profile.csv".*/

void printProfileData() {
    refreshPage(); // Richiama la funzione refreshPage() per aggiornare la pagina

    FILE* file = fopen(PROFILE_FILE, "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH]; // Dichiarazione di una variabile per contenere una riga letta dal file

    while (fgets(line, sizeof(line), file) != NULL) { // Legge ogni riga del file finché non raggiunge la fine
        User userData; // Dichiarazione di una variabile di tipo User per memorizzare i dati utente

        int result = sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                            userData.email, userData.password, userData.name, userData.surname, userData.phoneNumber,
                            userData.address, userData.addressNumber, userData.dob.day, userData.dob.month, userData.dob.year);

        if (result == 10) {
            tophead();
            printf("----------------------------------------\n");
            printf("| Dati del Profilo \n");
            printf("----------------------------------------\n");
            printf("| Email: %s\n", userData.email);
            puts("|");
            printf("| Password: %s\n", userData.password);
            puts("|");
            printf("| Nome: %s\n", userData.name);
            puts("|");
            printf("| Cognome: %s\n", userData.surname);
            puts("|");
            printf("| Numero di Telefono: %s\n", userData.phoneNumber);
            puts("|");
            printf("| Indirizzo: %s\n", userData.address);
            puts("|");
            printf("| Numero Civico: %s\n", userData.addressNumber);
            puts("|");
            printf("| Data di Nascita: %s/%s/%s\n", userData.dob.day, userData.dob.month, userData.dob.year);
            puts("|");
            printf("----------------------------------------\n");
        }
    }

    fclose(file); // Chiude il file
}

