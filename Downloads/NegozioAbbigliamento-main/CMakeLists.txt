cmake_minimum_required(VERSION 3.23)
project(NegozioAbbigliamento C)

set(CMAKE_C_STANDARD 99)

add_executable(NegozioAbbigliamento main.c interface.c interface.h checksAndUtils.h checksAndUtils.c catalog.h catalog.c authentication.c authentication.h navigation.c navigation.h "admin.c" "admin.h" paymentDelivery.c paymentDelivery.h)
