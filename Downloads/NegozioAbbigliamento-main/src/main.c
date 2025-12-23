#include "navigation.h"
#include "interface.h"
#include "checksAndUtils.h"
#include "app_state.h"
#include "ui.h"

int main() {
    AppState state;
    initAppState(&state);

    emptyFile("cart.csv");
    logo();
    loading();
    refreshPage();
    control(&state, state.navigationMap[0][0]);
    return 0;
}