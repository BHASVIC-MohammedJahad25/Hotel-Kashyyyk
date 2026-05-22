#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char bookingIDs[6][20], boardName[6][4], guestNames[6][30], DoB[6][20], dailyNewspaper[6];
int endor[2] = {4,4}, naboo[2] = {4,4}, tattooine[2] = {4,4}, roomAvailability[6] = {0,0,0,0,0}, boardType[6], stayLength[6], childGuests[6], adultGuests[6], userAge[6], roomPrices[6] = {100, 100, 85, 75, 75, 50};
void check_in(), booktable(), checkout_main(), clear_info(int roomNum), board(int roomnum), handle_name(int roomnum), handle_date(int roomnum), newspaper(int roomnum), partysize(int roomnum), staylength(int roomnum);
int roomnumber(),check_out();

int main(void) {
    int whatdo;
    printf("---------------\n   Main Menu\n---------------\n(1) Check-in\n(2) Book Dinner\n(3) Check Out\n(4) Exit Program");
    printf("\n\nWhat would you like to do? (1-4):");
    fflush(stdin);
    scanf("%d",&whatdo);
    if (whatdo == 1) {
        check_in();
        main();
    }
    else if (whatdo == 2){
        booktable();
        main();

    }
    else if (whatdo == 3) {
        checkout_main();
        main();
    }
    else if (whatdo == 4) {
        char passwordinput[5];
        printf("Enter password to confirm exit: ");
        scanf("%s",&passwordinput);
        if (strcmp(passwordinput, "Yoda") == 0) {
            return 0;
        }
        else {
            printf("\nPassword incorrect. Returning to menu.\n\n");
            main();
        }
    }
    else {
        printf("Invalid Choice\n\n");
        main();
    }
}
int roomnumber() {
    char tempinp[5];
    int chosenroom;
    printf("These are our available rooms at this current time, all prices listed are charged nightly:\n\n");
    for (int counter = 0; counter < 6; counter++) {
        if (roomAvailability[counter] == 0) {
            printf("Room %d: $%d\n", counter+1, roomPrices[counter]);
        }
    }
    do {
        printf("\nPlease enter room number (1-6), or 'quit' to return to the main menu:");
        fflush(stdin);
        scanf("%s",&tempinp);
        chosenroom = atoi(tempinp);
        if (strcmp(tempinp, "quit") == 0) {
            printf("\nReturning to Menu\n\n");
            main();
        }
        if (chosenroom < 1 || chosenroom> 6) {
            printf("That room doesn't exist.\n");
        } else if (roomAvailability[chosenroom-1]==1) {
            printf("That room is already taken.\n");
        }
    } while (chosenroom < 1 || chosenroom > 6||roomAvailability[chosenroom-1]==1);
    return chosenroom;
}
void check_in() {
    printf("\n---------------\n   CHECK IN\n---------------\n");
    int temproomnum = roomnumber();
    printf("Room selected successfully!\n\n");
    roomAvailability[temproomnum-1]=1;
    handle_name(temproomnum-1);
    printf("Name accepted.\n\n");
    handle_date(temproomnum-1);
    printf("Date of birth accepted.\n\n");
    partysize(temproomnum-1);
    printf("Party size accepted.\n\n");
    staylength(temproomnum-1);
    printf("Length of stay accepted.\n\n");
    board(temproomnum-1);
    printf("Board type selected successfully.\n\n");
    newspaper(temproomnum-1);
    printf("Choice accepted.\n\n");
    char input[20];
    int check;
    do {
        printf("------------\nName: %s\n"
           "Date of Birth: %s\n"
           "Party size: %d (%dA, %dC)\n"
           "Stay length: %d\n"
           "Board type: %s\n"
           "Daily Newspaper: %c\n------------",
           guestNames[temproomnum-1], DoB[temproomnum-1], adultGuests[temproomnum-1]+childGuests[temproomnum-1], adultGuests[temproomnum-1], childGuests[temproomnum-1], stayLength[temproomnum-1], boardName[temproomnum-1], dailyNewspaper[temproomnum-1]);
        printf("\nPlease check your information. If correct, press enter. If incorrect, please input the category of information you wish to change:");
        fflush(stdin);
        gets(input);
        for (int counter = 0; counter <= strlen(input); counter++) {
            input[counter] = toupper(input[counter]);
        }
        if (strcmp(input, "NAME") == 0) {
            handle_name(temproomnum-1);
            printf("Name successfully changed\n\n");
            check = 1;
        }
        else if (strcmp(input, "DATE OF BIRTH") == 0) {
            handle_date(temproomnum-1);
            printf("Date successfully changed\n\n");
            check = 1;
        }
        else if (strcmp(input, "PARTY SIZE") == 0) {
            partysize(temproomnum-1);
            printf("Party size successfully changed\n\n");
            check = 1;
        }
        else if (strcmp(input, "STAY LENGTH") == 0) {
            staylength(temproomnum-1);
            printf("Stay length successfully changed\n\n");
            check = 1;
        }
        else if (strcmp(input, "BOARD TYPE") == 0) {
            board(temproomnum-1);
            printf("Board type successfully changed\n\n");
            check = 1;
        } else if (strcmp(input, "DAILY NEWSPAPER") == 0) {
            newspaper(temproomnum-1);
            printf("Daily Newspaper successfully changed\n\n");
            check = 1;
        }
        else {
            printf("Excellent!\n");
            check = 0;
        }
    } while (check == 1);
    printf("\nCheck-In Complete. Your booking ID is: %s\n\n",bookingIDs[temproomnum-1]);
}
void board(int roomnum) {
    int in;
    printf("(1) Full Board: $20 PPPD\n(2) Half Board: $15 PPPD\n(3) B&B: $5 PPPD\nPlease select your board type (1, 2, 3):");
    do {
        fflush(stdin);
        scanf("%d", &in);
        if (in == 1) {
            strcpy(boardName[roomnum], "FB");
            boardType[roomnum] = 20;
        } else if (in == 2) {
            strcpy(boardName[roomnum], "HB");
            boardType[roomnum] = 15;
        } else if (in == 3) {
            strcpy(boardName[roomnum], "B&B");
            boardType[roomnum] = 5;
        } else {
            printf("Enter a valid input:");
        }
    } while (in != 1 && in != 2 && in != 3);

}
void handle_name(int roomnum) {
    char temp[6][20];
    srand(time(NULL));
    bookingIDs[roomnum][0] = '\0';
    int randomnum = rand() % 100 + 1;
    int con;
    do {
        con = 0;
        printf("Please enter your forename:");
        fflush(stdin);
        gets(guestNames[roomnum]);
        if (strlen(guestNames[roomnum]) == 0) {
            con = 1;
        }
        for (int y = 0; y < strlen(guestNames[roomnum]); y++) {
            if (isalpha(guestNames[roomnum][y]) == 0) {
                con = 1;
            }
        }
        if (con == 1) {
            printf("Input not accepted.\n");
        }
    } while (con == 1);
    strcat(guestNames[roomnum], " ");
    do {
        con = 0;
        printf("Please enter your surname:");
        fflush(stdin);
        gets(temp[0]);
        if (strlen(temp[0]) == 0) {
            con = 1;
        }
        for (int y = 0; y < strlen(temp[0]); y++) {
            if (isalpha(temp[0][y]) == 0) {
                con = 1;
            }
        }
        if (con == 1) {
            printf("Input not accepted.\n");
        }
    } while (con == 1);
    strcat(guestNames[roomnum], temp);
    strcat(bookingIDs[roomnum], temp);
    sprintf(temp, "%d", randomnum);
    strcat(bookingIDs[roomnum], temp);
}

void handle_date(int roomnum) {
    int  x=0;
    char month[20], year[5], day[3] ;
    do {
        printf("Enter year of birth:");
        fflush(stdin);
        scanf("%s", &year);
        if (atoi(year) < 1910) {
            printf("Invalid input.\n");
        }else if (atoi(year) > 2007) {
            printf("Invalid input. You must be 18 to book.\n");
        }
    } while (atoi(year) < 1910 || atoi(year) > 2007);
    userAge[roomnum] = 2025 - atoi(year);
    do {
        printf("Enter month of birth (eg. April):");
        fflush(stdin);
        gets(month);
        for (int i = 0 ; i < strlen(month); i++) {
            month[i] = toupper(month[i]);
        }
        if (strcmp(month, "JANUARY") == 0 ||
        strcmp(month, "MARCH") == 0 ||
        strcmp(month, "MAY") == 0 ||
        strcmp(month, "JULY") == 0 ||
        strcmp(month, "AUGUST") == 0 ||
        strcmp(month, "OCTOBER") == 0 ||
        strcmp(month, "DECEMBER") == 0 ||
        strcmp(month, "JAN") == 0 ||
        strcmp(month, "MAR") == 0 ||
        strcmp(month, "AUG") == 0 ||
        strcmp(month, "OCT") == 0 ||
        strcmp(month, "DEC") == 0) {
            x = 31;
        }
        else if (strcmp(month, "JUNE") == 0 ||
            strcmp(month, "APRIL") == 0 ||
            strcmp(month, "SEPTEMBER") == 0 ||
            strcmp(month, "NOVEMBER") == 0 ||
            strcmp(month, "APR") == 0 ||
            strcmp(month, "SEP") == 0 ||
            strcmp(month, "NOV") == 0) {
            x = 30;
            }
        else if (strcmp(month, "FEBRUARY") == 0 || strcmp(month, "FEB") == 0) {
            if (atoi(year)%4 == 0) {
                x = 29;
            } else {
                x = 28;
            }
        }
        else {
            printf("Invalid input.\n");
        }
    } while (x == 0);
    do {
        printf("Enter day of birth (eg. 13):");
        fflush(stdin);
        scanf("%s", &day);
        if (atoi(day) > x || atoi(day) < 1) {
            printf("That day doesn't exist.\n");
        }
    } while (atoi(day) > x || atoi(day) < 1);
    strcat(DoB[roomnum], month);
    strcat(DoB[roomnum], " ");
    strcat(DoB[roomnum], day);
    strcat(DoB[roomnum], " ");
    strcat(DoB[roomnum], year);

}
void newspaper(int roomnum) {
    printf("Would you like a daily newspaper for a one-time fee of $5.50? (Yes/No):");
    int x1;
    do {
        char input2[4];
        x1 = 0;
        fflush(stdin);
        gets (input2);
        if (strcmp(input2, "No") == 0 || strcmp(input2, "no") == 0) {
            dailyNewspaper[roomnum]='N';
        } else if (strcmp(input2, "Yes") == 0 || strcmp(input2, "yes") == 0) {
            dailyNewspaper[roomnum]='Y';
        } else {
            printf("Invalid input. Please enter information again (Yes/No):");
            x1 = 1;
        }
    } while  (x1 == 1);
}

void partysize(int roomnum) {
    do {
        printf("Enter number of adults:");
        fflush(stdin);
        scanf("%d", &adultGuests[roomnum]);
        printf("Enter number of children:");
        fflush(stdin);
        scanf("%d", &childGuests[roomnum]);
        if (adultGuests[roomnum]+childGuests[roomnum]>4) {
            printf("Your party size is too large.\nPlease re-enter your information.\n");
        }
        else if (adultGuests[roomnum]+childGuests[roomnum]<=0 || adultGuests[roomnum] < 0 || childGuests[roomnum] < 0) {
            printf("Invalid input\nPlease re-enter your information.\n");
        }
    } while (adultGuests[roomnum]+childGuests[roomnum]>4 || adultGuests[roomnum]+childGuests[roomnum]<=0 || adultGuests[roomnum] < 0 || childGuests[roomnum] < 0);
}

void staylength(int roomnum) {
    do {
        printf("Enter length of stay (Days):");
        fflush(stdin);
        scanf("%d", &stayLength[roomnum]);
        if (stayLength[roomnum]<1) {
            printf("Error. Please re-enter information.\n");
        }
    } while (stayLength[roomnum] < 1);
}
void checkout_main(){
    printf("\n---------------\n   CHECK OUT\n---------------\n");
    int roomNum = check_out();
    clear_info(roomNum);
    printf("Successful checkout.\n\n");
}

int check_out(){
    char bookingId[20];
    char quitcheck[20];
    int roomNum = 0;
    int booking_validity=0;
    float newspaperFee = 5.50;
    float totalCost=0;
    while (booking_validity == 0){
        printf("Enter your Booking ID, or 'quit' to return to the menu:");
        scanf("%s",&bookingId);
        strcpy(quitcheck, bookingId);
        for (int x = 0; x < strlen(quitcheck);x++) {
            quitcheck[x] = toupper(quitcheck[x]);
        }
        if (strcmp(quitcheck, "QUIT")== 0) {
            printf("\nReturning to Menu\n\n");
            main();
        }
        for (int x=0;x<6;x++){
            if (strcmp(bookingIDs[x], bookingId) == 0){
                roomNum=x;
                booking_validity=1;
            }
        }
        if (booking_validity == 0) {
            printf("\nThis ID isn't in our system. Please check for errors.\n");
        }
    }
    printf("ID accepted.\n\n");
    float adultBoardCost = boardType[roomNum] * adultGuests[roomNum] * stayLength[roomNum];
    float childBoardCost = boardType[roomNum] * childGuests[roomNum] * stayLength[roomNum];
    childBoardCost = childBoardCost/2;
    float totalBoardCost = adultBoardCost + childBoardCost;
    float totalRoomCost = stayLength[roomNum] * roomPrices[roomNum];
    if (dailyNewspaper[roomNum] == 'Y'){
        totalCost = totalCost + 5.50;
    }
    if (userAge[roomNum] >= 65){
        totalRoomCost = totalRoomCost * 0.9;
    }
    totalCost = totalCost + totalBoardCost + totalRoomCost;
    if (childGuests[roomNum]>0 && dailyNewspaper[roomNum] == 'Y'){
        printf("Booking ID: %s\nName: %s\n\nDisplaying costs:\n--------------\nAdult Board Cost: $%.2f\nChild Board Cost: $%.2f\nTotal Board Cost: $%.2f\nTotal Room Cost: $%.2f\nNewspaper Fee: $%.2f\n--------------\nTotal Cost: $%.2f\n\n", bookingIDs[roomNum],guestNames[roomNum],adultBoardCost,childBoardCost,totalBoardCost,totalRoomCost,newspaperFee,totalCost);
    }
    if (childGuests[roomNum] == 0 && dailyNewspaper[roomNum] == 'Y'){
        printf("Booking ID: %s\nName: %s\n\nDisplaying costs:\n--------------\nAdult Board Cost: $%.2f\nTotal Board Cost: $%.2f\nTotal Room Cost: $%.2f\nNewspaper Fee: $%.2f\n--------------\nTotal Cost: $%.2f\n\n",bookingIDs[roomNum],guestNames[roomNum],adultBoardCost,totalBoardCost,totalRoomCost,newspaperFee,totalCost);
    }
    if (childGuests[roomNum]>0 && dailyNewspaper[roomNum] == 'N'){
        printf("Booking ID: %s\nName: %s\n\nDisplaying costs:\n--------------\nAdult Board Cost: $%.2f\nChild Board Cost: $%.2f\nTotal Board Cost: $%.2f\nTotal Room Cost: $%.2f\n--------------\nTotal Cost: $%.2f\n\n",bookingIDs[roomNum],guestNames[roomNum],adultBoardCost,childBoardCost,totalBoardCost,totalRoomCost,totalCost);
    }
    if (childGuests[roomNum] == 0 && dailyNewspaper[roomNum] == 'N'){
        printf("Booking ID: %s\nName: %s\n\nDisplaying costs:\n------------\nAdult Board Cost: $%.2f\nTotal Board Cost: $%.2f\nTotal Room Cost: $%.2f\n------------\nTotal Cost: $%.2f\n\n",bookingIDs[roomNum],guestNames[roomNum],adultBoardCost,totalBoardCost,totalRoomCost,totalCost);
    }
    return roomNum;
}

void clear_info(int roomNum){

    bookingIDs[roomNum][0] = '\0';
    DoB[roomNum][0] = '\0';
    guestNames[roomNum][0] = '\0';
    dailyNewspaper[roomNum]= 0;
    roomAvailability[roomNum] = 0;
    stayLength[roomNum] = 0;
    childGuests[roomNum] = 0;
    adultGuests[roomNum] = 0;
    userAge[roomNum] = 0;
    boardType[roomNum] = 0;
}
void booktable() {
    printf("\n---------------\n  Book Dinner  \n---------------\n");
    char ID[20];
    char quitcheck[20];
    int IDvalid = 0, index = 0, table = 0, partysize = 0;
    printf("Please enter your booking ID, or 'quit' to return to the menu:");
    scanf("%s", ID);
    strcpy(quitcheck, ID);
    for (int x = 0; x < strlen(quitcheck);x++) {
        quitcheck[x] = toupper(quitcheck[x]);
    }
    if (strcmp(quitcheck, "QUIT")== 0) {
        printf("\nReturning to Menu\n\n");
        main();
    }
    for (int i = 0; i < 6; i++) {
        if (strcmp(bookingIDs[i], ID) == 0) {
            IDvalid = 1;
            index = i;
            partysize = adultGuests[index] + childGuests[index];
            printf("ID accepted.\n\n---------------\n");
        }
    }
    if (IDvalid == 1) {
        if (boardType[index] == 20 || boardType[index] == 15) {
            int Break = 0;
            while (Break == 0){
                printf("7pm: \n(1) Endor: %d seats\n(2) Naboo: %d seats\n(3) Tattooine: %d seats", endor[0], naboo[0], tattooine[0]);
                printf("\n---------------\n9pm: \n(4) Endor: %d seats\n(5) Naboo: %d seats\n(6) Tattooine: %d seats", naboo[1], endor[1], tattooine[1]);
                printf("\n---------------\nYour party size is %d, so please select an option with %d or more free seats (1-6):", partysize, partysize);
                scanf("%d", &table);
                switch (table) {
                    case 1: {
                        if (endor[0] >= partysize) {
                            endor[0] -= partysize;
                            printf("\nSuccess, your table is booked at Endor for 7pm!\n\n");
                            Break = 1;
                        }
                        else {
                            printf("\nSorry, your party is too large for this table at this time");

                        }
                        break;
                    }
                    case 2: {
                        if (naboo[0] >= partysize) {
                            naboo[0] -= partysize;
                            printf("\nSuccess, your table is booked at naboo for 7pm!\n\n");
                            Break = 1;
                        }
                        else {
                            printf("\nSorry, your party is too large for this table at this time");

                        }
                        break;
                    }
                    case 3: {
                        if (tattooine[0] >= partysize) {
                            tattooine[0] -= partysize;
                            printf("\nSuccess, your table is booked at Tattooine for 7pm!\n\n");
                            Break = 1;
                        }
                        else {
                            printf("\nSorry, your party is too large for this table at this time");

                        }
                        break;
                    }
                    case 4: {
                        if (endor[1] >= partysize) {
                            endor[1] -= partysize;
                            printf("\nSuccess, your table is booked at Endor for 9pm!\n\n");
                            Break = 1;
                        }
                        else {
                            printf("\nSorry, your party is too large for this table at this time");

                        }
                        break;
                    }
                    case 5: {
                        if (naboo[1] >= partysize) {
                            naboo[1] -= partysize;
                            printf("\nSuccess, your table is booked at Naboo for 9pm!\n\n");
                            Break = 1;
                        }
                        else {
                            printf("\nSorry, your party is too large for this table at this time");

                        }
                        break;
                    }
                    case 6: {
                        if (tattooine[1] >= partysize) {
                            tattooine[1] -= partysize;
                            printf("\nSuccess, your table is booked at Tattooine for 9pm!\n\n");
                            Break = 1;
                        }
                        else {
                            printf("\nSorry, your party is too large for this table at this time");

                        }
                        break;
                    }
                    default: {
                        printf("Invalid input\n\n");
                    }
                }
            }
        }
        else {
            printf("You do not have the valid board type; returning to main menu.\n\n");
        }
    }
    else {
        printf("ID not accepted; returning to main menu.\n\n");
    }
}