#include "checksAndUtils.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define loadTime1 20 // tempo di sospensione utilizzato nei caricamenti


/**La funzione loading() mostra una simulazione di caricamento utilizzando una barra di avanzamento.*/

void loading() {
    unsigned short int i;
    printf("\n\nCaricamento in corso... ");
    for (i = 0; i < loadTime1; i++) {
        Sleep(loadTime1);          // sospende l'esecuzione del programma per loadTime1 (solo per Windows)
        printf("%c", 219);      //stampa il carattere ASCII 219 (un quadrato nero) su stdout
    }
    printf(" completato!\n");
}


/**refresh della pagina */

void refreshPage() {
    system("cls");      // serve solo a dare un nome più significativo per il programma programma
}

/**La funzione emptyString() fa un refresh della pagina */

int emptyString (const char* string) {
    if (!string[0]) { // Controlla se la stringa è vuota
        puts("\n\t\t\t\tIl campo non puo' essere lasciato vuoto\n");
        return 0; // Stringa non valida perchè vuota
    }
    return 1; // Stringa valida
}

/**La funzione checkEmailFirstChar() controlla se il primo carattere della mail è un numero o no */

int checkEmailFirstChar(const char *string) {
    if (isdigit(string[0])) {
        return 1;  // il primo carattere è un numero
    } else {
        return 0;  //  il primo carattere non è un numero
    }
}

/**La funzione checkEmailNameLength() controlla controlla la lunghezza della mail */

int checkEmailNameLength(const char *string) {
    int length = 0;  // quanti caratteri ci sono prima della @
    int i = 0;

    // va avanti finche non trova una @ oppure alla fine della stringa
    while (string[i] != '\0' && string[i] != '@') {
        length++;
        i++;
    }
    return length;
}

/**La funzione checkEmailDomain() controlla  il dominio della mail se corrisponde ad uno di quelli predefiniti */

int checkEmailDomain(char email[]) {
    if(checkEmailNameLength(email) < MIN_EMAIL_LENGHT){
        puts("\n\t\t\t\tLa mail oltre al dominio deve avere lunghezza minima di 1");
        return 1;
    }
    checkEmailNameLength(email);
    char gmail[] = "moc.liamg@";
    char hotmail[] = "moc.liamtoh@";
    char alice[] = "ti.ecila@";
    char libero[] = "ti.orebil@";
    char yahoo[] = "moc.oohay@";
    char outlook[] = "moc.kooltuo@";
    char virgilio[] = "ti.oiligriv@";
    char uniba[] = "ti.abinu@";
    char studentiuniba[] = "ti.abinu.itneduts@";
    strrev(email);
//capovolgo l email in modo da controllare il provider dell'email
    if (strncmp(gmail, email, 10) == 0) {
        strrev(email);
        return 1;
    } else if (strncmp(hotmail, email, 11) == 0) {
        strrev(email);
        return 1;
    } else if (strncmp(uniba, email, 9) == 0) {
        strrev(email);
        return 1;
    } else if (strncmp(studentiuniba, email, 18) == 0) {
        strrev(email);
        return 1;
    } else if (strncmp(alice, email, 9) == 0) {
        strrev(email);
        return 1;
    } else if (strncmp(libero, email, 10) == 0) {
        strrev(email);
        return 1;
    } else if (strncmp(yahoo, email, 10) == 0) {
        strrev(email);
        return 1;
    } else if (strncmp(outlook, email, 12) == 0) {
        strrev(email);
        return 1;
    } else if (strncmp(virgilio, email, 12) == 0) {
        strrev(email);
        return 1;
    } else {
        printf("\n\t\t\t\tProvider e-mail non valido, utilizzare solo quelli autorizzati!\n");
        return 0;
    }
}


/**La funzione isEmailTaken() controlla se la mail è già stata usata perchè nella registrazione non si possono avere due mail uguali  */

int isEmailTaken(const char* email) {
    FILE *file = fopen("users.csv", "r");

    if (file == NULL) {
        printf("\n\t\t\t\tErrore nell'apertura del file.");
        return 0;
    }
    char line[MAX_EMAIL_LENGTH + MAX_NAME_SURNAME_LENGTH + MAX_NAME_SURNAME_LENGTH + MAX_PASSWORD_LENGTH + 4];

    while (fgets(line, sizeof(line), file) != NULL) {
        char *savedEmail = strtok(line, ",");
        // printf("%s",savedEmail);
        if (savedEmail != NULL && strcmp(savedEmail, email) == 0) {  // se le mail sono uguali ritorna 1

            fclose(file);
            return 1; // L'email esiste già
        }
    }

    fclose(file);
    return 0; // L'email non esiste
}

/**La funzione checkEmailNameDomain() verifica se un indirizzo email è valido.  */

int checkEmailNameDomain(char email[]) {
    char emailcpy[MAX_EMAIL_LENGTH];
    const char* specialChars = "!@#$%^&*()_+{}[]|\\:;<>,?/~`'=""°£-§";
    strcpy(emailcpy, email);
    const char s[2] = "@";  // elemento separatore
    char *domain;
    int atCounter = 0;
    bool atFound = false;

    size_t length = strlen(emailcpy);
    if (length > 49) {
        printf("\n\t\t\t\tLA MAIL E' TROPPO LUNGA\n");     // controllo la lunghezza della mail
        return 0;
    }

    if (isalnum(emailcpy[0]) == 0) {
        printf("\n\t\t\t\tIL PRIMO CARATTERE DEVE ESSERE UNA LETTERA O UN NUMERO\n");
        return 0;
    }

    for (int i = 0; i < length - 1; i++) {
        if (emailcpy[i] == '.' && emailcpy[i + 1] == '.') {
            printf("\n\t\t\t\tNON CI POSSONO ESSERE DUE PUNTI DI FILA\n");
            return 0;
        }
    }

    // Controllo dei caratteri "@" nell'indirizzo email
    for (int i = 0; i < length; i++) {
        if (emailcpy[i] == '@') {
            if (atFound) {
                printf("\n\t\t\tNON SI POSSONO INSERIRE PIU' @\n");
                return 0;
            }
            atFound = true;
            atCounter++;
        }
    }

    if (!atFound || atCounter > 1) {
        printf("INDIRIZZO EMAIL NON VALIDO\n");

        return 0;
    }

    // Controllo dell'ultimo carattere prima del carattere "@"
    domain = strtok(emailcpy, s);
    if (domain[strlen(domain) - 1] == '.') {
        printf("\n\t\t\t\tL'ULTIMO CARATTERE PRIMA DELLA @ NON PUO' ESSERE UN PUNTO\n");

        return 0;
    }

    for(int i = 0; i < strlen(domain); i++){
        if (strchr(specialChars, domain[i]) != NULL) {
            puts("\n\t\t\t\tNON POSSONO ESSERE PRESENTI CARATTERI SPECIALI\n\t\t\t\tAD ECCEZIONE DEL PUNTO MA NON PRIMA DELLA CHIOCCIOLA \n\t\t\t\tE NON DUE PUNTI DI FILA");
            return 0;
        }
    }


    // Controlla il dominio della mail
    int domainCheck = checkEmailDomain(email);
    if (domainCheck == 0) {
        return 0;
    }

    return 1;
}


/**La funzione checkNameSurname()verifica se una stringa rappresenta un nome o un cognome valido.  */

int checkNameSurname(const char* string) {
    size_t length = strlen(string);
    if (length > 38) {
        printf("\n\t\t\t\tIl nome o il cognome e' troppo lungo!\n");
        return 0;
    }

    if(emptyString(string) == 1) {
        for (int i = 0; string[i] != '\0'; i++) {
            if (isalpha(string[i]) == 0) {
                puts("\n\t\t\tIL NOME E IL COGNOME DEVONO CONTENERE SOLO CARATTERI ALFABETICI E NON DEVONO ESSERE VUOTI\n");
                return 0; // Stringa non valida perchè sono presenti non solo caratteri dell'alfabeto
            }
        }
    }else{
        return 0; //stringa vuota
    }
    return 1; // Stringa valida
}

/**La funzione isLeapYear() verifica se un dato anno è bisestile.  */

int isLeapYear(unsigned short int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1; // Anno bisestile
    } else {
        return 0; // Anno non bisestile
    }
}

/**La funzione isValidDate() verifica se una data rappresentata da un giorno, un mese e un anno è valida.  */

int isValidDate(unsigned short int day, unsigned short int month, unsigned short int year) {

    if (month < 1 || month > 12) {
        printf("\n\t\t\t\tIL MESE DEVE ESSERE COMPRESO TRA GENNAIO E DICEMBRE\n");
        return 0; // Mese non valido
    }

    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // controlla il 29 dell'anno bisestile

    if (day < 1 || day > daysInMonth[month - 1]) {
        printf("\n\t\t\t\tIL GIORNO NON E' VALIDO\n");// controlla i giorni rispetto ai mesi
        return 0; // Giorno non valido
    }

    return 1; // Data valida
}

/**La funzione isAgeValid() verifica se una data rappresenta un'età valida, in base a una data di nascita.  */

int isAgeValid(unsigned short int day, unsigned short int month, unsigned short int year) {
    unsigned short int currentDay, currentMonth, currentYear; // data corrente

    // Ottieni il tempo corrente
    time_t currentTime = time(NULL);

    // Converti il tempo corrente in una struttura tm definita in tim.h usata per informazioni di data e di ora
    struct tm *localTime = localtime(&currentTime);

    // Estrai i componenti della data dalla struttura tm
    currentYear = localTime->tm_year + 1900;   // Aggiungi 1900 per ottenere l'anno corrente
    currentMonth = localTime->tm_mon + 1;      // Aggiungi 1 perché i mesi sono indicizzati da 0 a 11
    currentDay = localTime->tm_mday;           // Giorno del mese

    // Calcola l'età
    if (currentYear - year < 14 || currentYear - year > 112) {
        printf("\n\t\t\t\tLA DATA INSERITA NON E' VALIDA\n");
        return 0; // Età non valida
    } else if (currentYear - year == 14) {
        if (currentMonth < month) {
            printf("\n\t\t\t\tLA DATA INSERITA NON E' VALIDA\n");
            return 0; // Età non valida
        } else if (currentMonth == month && currentDay < day) {
            printf("\n\t\t\t\tLA DATA INSERITA NON E' VALIDA\n");
            return 0; // Età non valida
        }
    }
    return 1; // Età valida
}

/**La funzione isNumber() verifica se una stringa passata come argomento rappresenta un numero intero. Quindi per es. 'a' non è un numero '1' si  */

int isNumber(const char* str){
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        // Verifica se il carattere corrente non è un numero
        if (!isdigit(str[i])) {
            printf("\n\t\t\t\tNON PUO' CONTENERE LETTERE, CARATTERI SPECIALI O SPAZI\n");
            return 0;
        }
    }
    return 1;
}

/**La funzione checkPhoneNumber() controlla se una stringa rappresenta un numero di telefono valido.
 * 303852014' valido '2165das/' non valido */

int checkPhoneNumber(const char PhoneNumber[]) {
    size_t phoneNumberLength = strlen(PhoneNumber);

    if (phoneNumberLength > 10) {
        printf("\n\t\t\t\tIL NUMERO DI TELEFONO E' TROPPO LUNGO!\n");

    }

    // Ciclo per controllare ogni carattere del numero di telefono
    for (int i = 0; i < phoneNumberLength; i++) {
        // Verifica se il carattere corrente non è un numero
        if (!isdigit(PhoneNumber[i])) {
            printf("\n\t\t\t\tIL NUMERO NON PUO' CONTENERE LETTERE O CARATTERI SPECIALI\n");
            return 0;
        }
    }

    // Controlla se il numero di telefono inizia con 0
    if (PhoneNumber[0] == '0') {
        printf("\n\t\t\t\tIL NUMERO NON PUO' INIZIARE CON 0\n");
        return 0;
    }

    // Controlla se la lunghezza del numero di telefono è diversa da 9
    if (phoneNumberLength != MAX_PHONENUMBER_LENGTH - 2) {
        printf("\n\t\t\t\tNUMERO NON VALIDO\n");
        return 0;
    }

    // Se tutte le condizioni sono soddisfatte, il numero di telefono è valido
    return 1;
}


/**La funzione checkAddress()  verifica se una stringa rappresenta un indirizzo valido.
 * viale degli aranci' valido '/via si9 ldl,a' non valido */

int checkAddress(const char *address) {
    // Controlla se l'indirizzo è una stringa vuota
    if (emptyString(address) == 0) {
        return 0;
    }

    size_t addressLength = strlen(address);

    if (addressLength > 78) {
        printf("\n\t\t\t\tE' TROPPO LUNGO!\n");
        return 0;
    }

    // Scorri ogni carattere dell'indirizzo
    for (int i = 0; i < addressLength; i++) {
        // Verifica se il carattere corrente non è una lettera o uno spazio
        if (!isalpha(address[i]) && address[i] != ' ') {
            printf("\n\t\t\t\tNON PUO' CONTENERE NUMERI O CARATTERI SPECIALI\n");
        }
    }

    // L'indirizzo è valido, non contiene caratteri speciali o numeri
    return 1;
}


/**La funzione checkAddressNumber()  verifica se una stringa rappresenta un numero civico valido per un indirizzo.
 * '89' valido '8.6' NON valido */

int checkAddressNumber(const char *addressNumber) {
    size_t addressNumberLength = strlen(addressNumber);

    if (addressNumberLength > 8) {
        printf("\n\t\t\t\tIL NUMERO CIVICO E' TROPPO LUNGO!\n");
        return 0;
    }

    for (int i = 0; i < strlen(addressNumber); i++) {
        // Verifica se il carattere corrente non è un numero
        if (!isdigit(addressNumber[i])) {
            printf("\n\t\t\t\tIL NUMERO CIVICO NON PUO' CONTENERE LETTERE O CARATTERI SPECIALI O SPAZI\n");
            return 0;
        }
    }
    int numero = atoi(addressNumber);
    if (numero >= 1 && numero <= 14115 ) {          // 14115 è il numero civico in italia più alto
        return 1;       //civico esistente
    } else {
        puts("\n\t\t\t\tCIVICO NON ESISTENTE");
        return 0;        //civico non esistente
    }
}

/**La funzione checkPassword() verifica se una stringa rappresenta una password valida.
 * 'ciao.Ciao4' valido 'ciao' NON valido */

int checkPassword(const char *password) {
    const char* specialChars = "!@#$%^&*()_+{}[]|\\:;<>,?/~.`'=""°£-§";
    int passwordLength = strlen(password);
    bool requirementsMet[4] = { false }; // Indici 0: minuscolo, 1: maiuscolo, 2: numero, 3: carattere speciale

    // Verifica la lunghezza della password
    if (passwordLength < 6 || passwordLength > 20) {
        printf("\n\t\t\t\tLUNGHEZZA PASSWORD NON VALIDA\n");
        return 0;
    }

    // Verifica la presenza di spazi nella password
    if (strpbrk(password, " ") != NULL) {
        printf("\n\t\t\t\tNON POSSONO ESSERCI SPAZI\n");
        return 0;
    }

    // Verifica i requisiti della password
    for (int i = 0; i < passwordLength; i++) {
        char currentChar = password[i];

        if (islower(currentChar)) {
            requirementsMet[0] = true; // Carattere minuscolo
        } else if (isupper(currentChar)) {
            requirementsMet[1] = true; // Carattere maiuscolo
        } else if (isdigit(currentChar)) {
            requirementsMet[2] = true; // Numero
        } else if (strchr(specialChars, currentChar) != NULL) {
            requirementsMet[3] = true; // Carattere speciale
        }
    }

    // Verifica i requisiti mancanti
    if (!requirementsMet[0]) {
        printf("\n\t\t\t\tLA PASSWORD DEVE CONTENERE ALMENO UN CARATTERE MINUSCOLO\n");

        return 0;
    }

    if (!requirementsMet[1]) {
        printf("\n\t\t\t\tLA PASSWORD DEVE CONTENERE ALMENO UN CARATTERE MAIUSCOLO\n");
        return 0;
    }

    if (!requirementsMet[2]) {
        printf("\n\t\t\t\tLA PASSWORD DEVE CONTENERE ALMENO UN NUMERO\n");
        return 0;
    }

    if (!requirementsMet[3]) {
        printf("\n\t\t\t\tLA PASSWORD DEVE CONTENERE ALMENO UN CARATTERE SPECIALE\n");
        return 0;
    }

    // Tutti i requisiti sono soddisfatti
    return 1;
}

/**La funzione emptyFile()  svuota un file specificato.
 * gli viene passato il file che si vuole svuotare e viene svuotato se il file viene trovato */

void emptyFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {             // lo apro in w ma non scrive nulla serve solo a svuotarlo
        printf("Impossibile aprire il file.\n");
        return;
    }

    fclose(file);
}

/**La funzione checkQuantity() verifica se una quantità specificata è valida rispetto a una quantità disponibile per un determinato articolo e anche la validità come numero.
 * '8' valido 'ciao' NON valido */

int checkQuantity(const char *qty, const int itemQty) {
    int length = strlen(qty);
    int qtyInt;
    if (length > 3 || emptyString(qty) == 0) {
        printf("\n\t\t\t\tIL NUMERO NON E' VALIDO\n");
        return 0; // La lunghezza supera i 3 caratteri
    }

    for (int i = 0; i < length; i++) {
        if (isdigit(qty[i]) == 0) {
            printf("\n\t\t\t\tDEVE CONTENERE SOLO NUMERI\n");
            return 0; // Trovato un carattere non numerico
        }
    }
    qtyInt = atoi(qty);
    if(qtyInt > itemQty) {
        puts("\n\tPRODOTTI NON SUFFICIENTI O ESAURITI ");
        return 0;
    }
    return 1;
}


/**La funzione checkCardDate() verifica se una data di scadenza di una carta di credito è valida.
 * '2027' valido '2000' NON valido */

int checkCardDate(const int month, const int year){
    if (month < 1 || month > 12) {
        printf("\n\t\t\t\tIL MESE DEVE ESSERE COMPRESO TRA GENNAIO E DICEMBRE\n");
        return 0; // Mese non valido
    }

    if (year < 2023 || year > 2030) {
        printf("\n\t\t\t\tANNO NON VALIDO\n");
        return 0; // Anno non valido
    }

    if(year == 2023 && month <= 6){
        printf("\n\t\t\t\tCARTA SCADUTA\n");
        return 0; // Anno non valido
    }
    return 1;
}

/**La funzione cardNumberCheck() verifica se un numero di carta di credito è valido.
 * '1234567891234567' valido '20005151a' NON valido */

int cardNumberCheck(const char *str) {
    size_t length = strlen(str);

    if (length != 16 || emptyString(str) == 0) {
        printf("\n\t\t\t\tIl numero di carta di credito non valido\n");
        return 0; // La lunghezza supera i 16 caratteri
    }

    for (int i = 0; i < length; i++) {
        if (isdigit(str[i]) == 0) {
            printf("\n\t\t\t\tIl numero di carta di credito deve contenere solo numeri\n");
            return 0; // Trovato un carattere non numerico
        }
    }
    return 1; // La stringa è valida
}



/**La funzione checkCVV() verifica se un numero CVV di una carta di credito è valido.
 * '150' valido '20005151a' NON valido */

int checkCVV(const char* number){
    int length = strlen(number);

    if (length != 3 || emptyString(number) == 0) {
        printf("\n\t\t\t\tIl CVV della carta di credito non e' valido\n");
        return 0; // La lunghezza deve essere 3
    }

    for (int i = 0; i < length; i++) {
        if (isdigit(number[i]) == 0) {
            printf("\n\t\t\t\tIl numero di carta di credito deve contenere solo numeri\n");
            return 0; // Trovato un carattere non numerico
        }
    }
    return 1; //tutto ok
}


/**La funzione checkCAP() verifica se un codice CAP è valido.
 * '74065' valido '20005151a' NON valido */

int checkCAP(const char* CAP){
    int CAPlength = strlen(CAP);

    if (CAPlength != 5 || emptyString(CAP) == 0) {
        printf("\n\t\t\t\tIl CAP  non e' valido deve essere lungo 5\n");
        return 0; //  La lunghezza deve essere 5
    }

    for (int i = 0; i < CAPlength; i++) {
        if (isdigit(CAP[i]) == 0) {
            printf("\n\t\t\t\tIl CAP deve contenere solo numeri\n");
            return 0; // Trovato un carattere non numerico
        }
    }
    return 1; // tutto ok
}


/**La funzione getStatus() restituisce una stringa che rappresenta lo stato associato a un determinato codice di stato.
 * serve per la generazione casuale di stati dell'ordine
 * '2' valido '6' NON valido */

char* getStatus(unsigned short int status) {
    switch (status) {
        case 1:
            return "In lavorazione";
        case 2:
            return "In consegna";
        case 3:
            return "Consegnato";
        default:
            return "Stato non valido";
    }
}

/**La funzione checkAdmin() verifica se un determinato indirizzo email corrisponde a un utente amministratore. andando a controllare l'ulitmo dato della struct degli utenti
 * '1' admin '0' NON admin */

int checkAdmin(const char *email) {
    char *lastValue = NULL;
    FILE *file = fopen("users.csv", "r");
    if (file == NULL) {
        printf("Impossibile aprire il file.\n");
        return -1;
    }

    char line[MAX_LINE_LENGTH];  //riga da estrarre

    while (fgets(line, sizeof(line), file) != NULL) {
        char *savedEmail = strtok(line, ",");
        if (savedEmail != NULL && strcmp(savedEmail, email) == 0) {
            char *token = strtok(NULL, ",");
            while (token != NULL) {
                lastValue = token;                  //salta finche arriva all'ultimo valore
                token = strtok(NULL, ",");
            }
            fclose(file);
            break;
        }
    }

    if (lastValue != NULL) {
        printf("%s\n", lastValue);
        if (strcmp(lastValue, "0\n") == 0) {        //se è uguale a 0 non è un adimn se 1 è un admin
            return 0;
        } else {
            return 1;
        }
    } else {
        printf("L'utente non è presente nel file.\n");
        fclose(file);
        return -1;
    }
}

/**La funzione checkPercentage() verifica se una determinata percentuale, rappresentata come carattere, è valida.
 * '20' valido '500' NON valido */

int checkPercentage(const char coupon){
    if(coupon<5 || coupon>100){
        printf("Percentuale non valida");
        return 0;
    }

    return 1;
}

/**La funzione checkItemSize() verifica se una determinata taglia, rappresentata come stringa, è valida.
 * 'M' valido 'ssj41' NON valido */

int checkItemSize(const char size[]){
    if(strcmp(size, "XS") == 0){
        return 1;
    }else    if(strcmp(size, "S") == 0){
        return 1;
    }else    if(strcmp(size, "M") == 0){
        return 1;
    }else    if(strcmp(size, "L") == 0){
        return 1;
    }else    if(strcmp(size, "XL") == 0){
        return 1;
    }else    if(strcmp(size, "XXL") == 0){
        return 1;
    }else {
        return 0;
    }
}

/**La funzione isDouble() verifica se una stringa rappresenta un numero di tipo double, restituendo 1 se è valido e 0 altrimenti.
 * '20.50' valido 'ssj41' NON valido */

int isDouble(const char price[]){
    double number;
    char* endptr;

    number = strtod(price, &endptr);
    /*La funzione strtod converte una stringa in un valore di tipo double e restituisce il risultato della conversione.
     * Tuttavia, essa può anche fornire informazioni sulla posizione del primo carattere non convertibile all'interno della stringa di input.
     * Questa informazione è restituita tramite un puntatore di tipo char* passato come secondo argomento a strtod,
     * che di solito viene chiamato endptr.*/

    if (*endptr != '\0') {
        printf("Input non valido: il testo inserito non rappresenta un numero.\n");
        return 0;
    }

    return 1;
}

