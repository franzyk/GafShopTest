#ifndef NEGOZIO_ABBIGLIAMENTO_CONFIG_H
#define NEGOZIO_ABBIGLIAMENTO_CONFIG_H

// User related constants
#define MAX_NAME_SURNAME_LENGTH 40
#define MAX_EMAIL_LENGTH 51
#define MIN_EMAIL_LENGTH 1
#define MAX_PASSWORD_LENGTH 22
#define MAX_PHONENUMBER_LENGTH 12
#define MAX_ADDRESS_LENGTH 80
#define MAX_ADDRESSNUMBER_LENGTH 10
#define MAX_GG_MM_LENGTH 4
#define MAX_AAAA_LENGTH 6

// Product related constants
#define MAX_PRODUCT_NAME 50
#define MAX_PRODUCT_BRAND 30
#define MAX_PRODUCT_DESCRIPTION 500
#define MAX_PRODUCT_SIZE 10
#define MAX_CLOTHINGITEM_LENGTH (MAX_PRODUCT_NAME + MAX_PRODUCT_BRAND + MAX_PRODUCT_SIZE + 4) // Added space for separators

// Cart related constants
#define CART_ITEMS 20

// Order related constants
#define MAX_STATUS_WORD_LENGTH 20
#define MAX_LINE_LENGTH (MAX_EMAIL_LENGTH + MAX_PASSWORD_LENGTH + 2 * MAX_NAME_SURNAME_LENGTH + MAX_PHONENUMBER_LENGTH + MAX_ADDRESS_LENGTH + MAX_ADDRESSNUMBER_LENGTH + 2 * MAX_GG_MM_LENGTH + MAX_AAAA_LENGTH + 12)

// Payment related constants
#define MAX_CARDNUMBER_LENGTH 18
#define MAX_CARDHOLDER_LENGTH 50
#define MAX_CARDCVV_LENGTH 5
#define MAX_CITY_LENGTH 80
#define MAX_ZIPCODE_LENGTH 10
#define MAX_PROVINCE_LENGTH 80

// Navigation keys
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_ENTER 13

// File paths
#define USERS_FILE "data/users.csv"
#define CLOTHES_FILE "data/clothes.csv"
#define CART_FILE "data/cart.csv"
#define ORDERS_FILE "data/orders.csv"
#define COUPON_FILE "data/coupon.csv"
#define PROFILE_FILE "data/profile.csv"
#define CLOTHES_TEMP_FILE "data/clothes_temp.csv"
#define ORDERS_TEMP_FILE "data/orders_temp.csv"

#endif //NEGOZIO_ABBIGLIAMENTO_CONFIG_H
