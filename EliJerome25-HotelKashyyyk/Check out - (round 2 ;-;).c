#include <stdio.h>
char bookingIDs[20][6], guestNames[30][6], DoB[20][6], dailyNewspaper[6];
int roomAvailability[6] = {0,0,0,0,0}, stayLength[6], childGuests[6], adultGuests[6], userAge[6], roomPrices[6] = {100, 100, 85, 75, 75, 50}, boardType[6];

int check_out();
void clear_info(int roomNum);

int main2(){
    int roomNum = check_out();
    clear_info(roomNum);
    return 0;
}

int check_out(){
    char bookingId[20];
    int roomNum = 0;
    int booking_validity=0;
    float newspaperFee = 5.50;
    float totalCost=0;
    while (booking_validity == 0){
        printf("Enter booking ID");
        scanf("%s", bookingId);
        for (int x=0;x<6;x++){
            if (bookingIDs[x] == bookingId){
                roomNum=x;
                booking_validity=1;
            }
        }
    }
    float adultBoardCost = boardType[roomNum] * adultGuests[roomNum];
    float childBoardCost = boardType[roomNum] * childGuests[roomNum];
    childBoardCost = childBoardCost/2;
    float totalBoardCost = adultBoardCost + childBoardCost;
    float totalRoomCost = stayLength[roomNum] * roomPrices[roomNum];
    if (dailyNewspaper[roomNum] == 1){
        totalCost = totalCost + 5.50;
    }
    if (userAge[roomNum] >= 65){
        totalRoomCost = totalRoomCost * 0.9;
    }
    totalCost = totalCost + totalBoardCost + totalRoomCost;
    if (childGuests[roomNum]>0 && dailyNewspaper[roomNum] == 1){
        printf(" %s \n %s \n %f \n %f \n %f \n %f\n %f \n %f \n",bookingIDs[roomNum],guestNames[roomNum],adultBoardCost,childBoardCost,totalBoardCost,totalRoomCost,newspaperFee,totalCost);
    }
    if (childGuests[roomNum] == 0 && dailyNewspaper[roomNum] == 1){
        printf(" %s \n %s \n %f \n %f \n %f \n %f\n %f \n",bookingIDs[roomNum],guestNames[roomNum],adultBoardCost,totalBoardCost,totalRoomCost,newspaperFee,totalCost);
    }
    if (childGuests[roomNum]>0 && dailyNewspaper[roomNum] == 0){
        printf(" %s \n %s \n %f \n %f \n %f \n %f\n %f \n",bookingIDs[roomNum],guestNames[roomNum],adultBoardCost,childBoardCost,totalBoardCost,totalRoomCost,totalCost);
    }
    if (childGuests[roomNum] == 0 && dailyNewspaper[roomNum] == 0){
        printf(" %s \n %s \n %f \n %f \n %f \n %f \n",bookingIDs[roomNum],guestNames[roomNum],adultBoardCost,totalBoardCost,totalRoomCost,totalCost);
    }
    return roomNum;
}

void clear_info(int roomNum){
    for (int x=0;x<20;x++){
        bookingIDs[x][roomNum] = 32;
        DoB[x][roomNum] = 32;
    }
    for (int x=0;x<30;x++){
        guestNames[x][roomNum] = 32;
    }
    dailyNewspaper[roomNum]= 0;
    roomAvailability[roomNum] = 0;
    stayLength[roomNum] = 0;
    childGuests[roomNum] = 0;
    adultGuests[roomNum] = 0;
    userAge[roomNum] = 0;
    boardType[roomNum] = 0;
}