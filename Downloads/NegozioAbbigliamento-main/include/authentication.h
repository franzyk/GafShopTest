#ifndef USER_REGISTRATION_H
#define USER_REGISTRATION_H

#include "config.h"
#include <stdbool.h>

typedef struct {
    char day[MAX_GG_MM_LENGTH];
    char month[MAX_GG_MM_LENGTH];
    char year[MAX_AAAA_LENGTH];
} DateOfBirth;

typedef struct {
    char name[MAX_NAME_SURNAME_LENGTH];
    char surname[MAX_NAME_SURNAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char phoneNumber[MAX_PHONENUMBER_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char addressNumber[MAX_ADDRESSNUMBER_LENGTH];
    DateOfBirth dob;
    bool isAdmin;
} User;


void registerUser();
int login();
void saveUserData(const char* email);
void printProfileData();

#endif /* USER_REGISTRATION_H */



