#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <stdbool.h>

// Costanti per i tasti
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_ENTER 13

// Dichiarazioni delle funzioni
void control(unsigned short int location);
void option(unsigned short int location, unsigned short int selectedOption);

#endif /* NAVIGATION_H */
