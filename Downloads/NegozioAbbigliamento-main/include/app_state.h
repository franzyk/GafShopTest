#ifndef NEGOZIO_ABBIGLIAMENTO_APP_STATE_H
#define NEGOZIO_ABBIGLIAMENTO_APP_STATE_H

#include <stdbool.h>

#define NUMBER_OF_LOCATIONS 30
#define NUMBER_OF_CHOICES 2

typedef struct {
    bool loggedIn;
    unsigned short int navigationMap[NUMBER_OF_LOCATIONS][NUMBER_OF_CHOICES];
} AppState;

void initAppState(AppState* state);

#endif //NEGOZIO_ABBIGLIAMENTO_APP_STATE_H
