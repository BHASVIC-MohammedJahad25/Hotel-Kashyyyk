#include <stdio.h>

void booktable();

char bookingIDs[20][6];
int boardType[6];
int endor[2];
int naboo[2];
int tattooine[2];
int adultGuests[6];
int childGuests[6];



int main(void) {
    void booktable(); {

        char ID[20];
        int IDvalid = 0;
        int index = 0;
        int table = 0;
        int partysize = 0;


        printf(" please enter your booking id");
        scanf("%s", ID);
        for (int i = 0; i < 6; i++) {
            if (bookingIDs[i] == ID) {
                IDvalid = 1;
                index = i;
                partysize = (adultGuests[index] + childGuests[index]);
            }
            else{
                IDvalid = 0;
            }

        }
        if (IDvalid == 1) {
            if (boardType[index] == 2) {

                printf("7pm: \n1. Naboo: %d seats\n2. Endor: %d seats\n3. Tattooine: %d seats", naboo[0], endor[0], tattooine[0]);
                printf("9pm: \n4. Naboo: %d seats\n5. Endor: %d seats\n6. Tattooine: %d seats", naboo[1], endor[1], tattooine[1]);
                printf("please pick an option with more than %d free seats", partysize);
                scanf("%d", &table);

                switch (table) {

                    case 1: {
                        if (endor[0] >= partysize) {
                            endor[0] -= partysize;
                            printf("your table is booked at endor for 7pm");
                        }
                        else {
                            printf("sorry, your party is too large for this table at this time");
                        }
                    }

                    case 2: {
                        if (naboo[0] >= partysize) {
                            naboo[0] -= partysize;
                            printf("your table is booked at naboo for 7pm");
                        }
                        else {
                            printf("sorry, your party is too large for this table at this time");
                        }
                    }
                    case 3: {
                        if (tattooine[0] >= partysize) {
                            tattooine[0] -= partysize;
                            printf("your table is booked at tattooine for 7pm");
                        }
                        else {
                            printf("sorry, your party is too large for this table at this time");
                        }

                    }
                    case 4: {
                        if (endor[1] >= partysize) {
                            endor[1] -= partysize;
                            printf("your table is booked at endor for 9pm");
                        }
                        else {
                            printf("sorry, your party is too large for this table at this time");
                        }

                    }
                    case 5: {
                        if (naboo[1] >= partysize) {
                            naboo[1] -= partysize;
                            printf("your table is booked at naboo for 9pm");
                        }
                        else {
                            printf("sorry, your party is too large for this table at this time");
                        }

                    }
                    case 6: {
                        if (tattooine[1] >= partysize) {
                            tattooine[1] -= partysize;
                            printf("your table is booked at tattooine for 9pm");
                        }
                        else {
                            printf("sorry, your party is too large for this table at this time");
                        }

                    }
                }
            }
        }
    }
}