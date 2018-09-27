 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <windows.h>

 int main(){
    printf("\t\t\t\t\t=====================================\n");
    printf("\t\t\t\t\tWelcome to Car Park Management System\n");
    printf("\t\t\t\t\t=====================================\n");
    Sleep(3000);
    system("cls");

    int slotCount;

    printf("\nEnter the size of the car park you need : ");
    scanf("%d",&slotCount);
    system("cls");

    typedef struct carSlot slot;
     struct carSlot{
        int reserved;
        char customerName[256];
        char carNumber[10];
     };

     slot slotSet[slotCount];

    int i;
    for(i=0; i<slotCount; i++){
        slotSet[i].reserved = 0;
    }

    int action = 0;

    while(action!=-1){
            printf("\nCAR PARK SIZE IS %d\n",slotCount);
        printf("\n\t\t\t\t\t0. Drive In\n");
        printf("\t\t\t\t\t1. Drive Out\n");
        printf("\t\t\t\t\t2. View available spaces\n");
        printf("\t\t\t\t\t3. RESET car park\n");
        printf("\t\t\t\t\t4. Parked car Details\n");
        printf("\t\t\t\t\t5. EXIT\n");

        printf("Enter Command : ");
        scanf("%d",&action);

        switch(action){
            case 0:{
                system("cls");
                printf("Enter slot number to reserve : ");
                int slotNum;
                scanf("%d",&slotNum);

                if(slotSet[slotNum-1].reserved==0){
                    printf("Enter customer name : ");
                    scanf("%s",&slotSet[slotNum-1].customerName);
                    printf("Enter vehicle number : ");
                    scanf("%s",&slotSet[slotNum-1].carNumber);
                    slotSet[slotNum-1].reserved=1;
                    system("cls");
                    printf("Successfully reserved!\nPress any key to continue...\n");
                    getch();
                }else{
                    system("cls");
                    printf("Slot not available!\nPress any key to continue...\n");
                    getch();
                }
                break;
            }

            case 1:{
                system("cls");
                printf("Enter slot number to free : ");
                int slotNum;
                scanf("%d",&slotNum);
                if(slotSet[slotNum-1].reserved!=0){
                    slotSet[slotNum-1].reserved=0;
                    system("cls");
                    printf("Slot freed successfully!\nPress any key to continue...");
                    getch();
                }else{
                    system("cls");
                    printf("Slot is already free! Press any key to continue...");
                    getch();
                }
                break;
            }

            case 2:{
                    system("cls");
                    printf("Available Slots : \n");
                    for(i=0; i<slotCount; i++){
                        if(slotSet[i].reserved==0)
                            printf("\t%d\n",(i+1));
                    }
                    printf("Press any key to continue...");
                    getch();
                    break;
                }

            case 3:{
                system("cls");
                printf("All data will be lost.Are you sure?(y/n)");
                char answer;
                scanf(" %c",&answer);
                if(answer=='y'){
                    for(i=0; i<slotCount; i++){
                        slotSet[i].reserved=0;
                    }
                }else if(answer=='n'){
                    break;
                }else{
                    printf("Invalid Entry! Enter any key to continue...");
                    getch();
                }
                break;
            }

            case 4:{
                system("cls");
                printf("Used Slots\n");
                for(i=0; i<slotCount; i++){
                    if(slotSet[i].reserved){
                        printf("Slot %d \n",(i+1));
                        printf("\tCustomer Name : %s\n",slotSet[i].customerName);
                        printf("\tCar Number : %s\n",slotSet[i].carNumber);
                    }
                }
                printf("Enter any key to continue ");
                getch();
                break;
            }

            case 5:{
                char ans;
                while(ans!='y' || ans!='n'){
                    system("cls");
                    printf("All data will be lost! Are you sure?(y/n): ");
                    scanf("%c",&ans);
                    if(ans=='y'){
                        return;
                    }else if(ans=='n'){
                        action=0;
                        break;
                    }
                }
                break;
            }

            default:{
                system("cls");
                printf("Invalid Command! Press any key to Continue...\n");
                getch();
                break;
            }
        }

        system("cls");
    }

    return 0;
 }
