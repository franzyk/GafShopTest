#ifndef USER_REGISTRATION_H
#define USER_REGISTRATION_H

#include "catalog.h"

typedef struct {
    //nome, cognome,email, password, numero, indirizzo,n°civico, data di nascita.
    char name[MAX_NAME_SURNAME_LENGTH];
    char surname[MAX_NAME_SURNAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char phoneNumber[MAX_PHONENUMBER_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char addressNumber[MAX_ADDRESSNUMBER_LENGTH];
    char gg [MAX_GG_MM_LENGTH];
    char mm [MAX_GG_MM_LENGTH];
    char aaaa [MAX_AAAA_LENGTH];
    bool admin;
} User;


void registerUser();
int login();
void saveUserData(const char* email);
void printProfileData();

#endif /* USER_REGISTRATION_H */



