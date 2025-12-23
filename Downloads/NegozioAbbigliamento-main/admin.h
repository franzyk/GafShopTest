#ifndef NEGOZIOABBIGLIAMENTO_ADMIN_H
#define NEGOZIOABBIGLIAMENTO_ADMIN_H


    void generate_coupon(int percentage);
    void saveCoupon(const char* coupon, int percentage);
    void readCoupon(const char userCoupon[]);
    void addCoupon();
    void showAllProfiles();
    void editClothInfo(unsigned short int idCloth);
    void showAllUserOrders();

#endif
