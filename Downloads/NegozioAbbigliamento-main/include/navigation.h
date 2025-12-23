#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <stdbool.h>
#include "config.h"

#include "app_state.h"

// Dichiarazioni delle funzioni
void control(AppState* state, unsigned short int location);
void option(AppState* state, unsigned short int location, unsigned short int selectedOption);

#endif /* NAVIGATION_H */
