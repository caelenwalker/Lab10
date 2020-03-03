#include <stdio.h>

struct _Player {
    char LastName[16];
    char FirstName[16];
    char Team[16];
    int Year;
    float BA;
    float OBP;
    float SLUG;
};

typedef struct _Player Player;

void PrintPlayers(Player players[], int count) {
    int i;

    printf("      First Name        Last Name             Team  Year    BA   OBP  SLUG\n");
    for(i = 0; i < count; i++) {
        printf("%16s %16s %16s %5d %.3f %.3f %.3f\n",
            players[i].FirstName,
            players[i].LastName,
            players[i].Team,
            players[i].Year,
            players[i].BA,
            players[i].OBP,
            players[i].SLUG);
    }
}

void SortBA(Player players[], int count) {
    int pass;
    int j;

    for(pass = 1; pass < count-1; pass++) {
        for(j = 0; j < count-1; j++) {
            Player temp;
            if(players[j].BA < players[j+1].BA) {
                temp = players[j];
                players[j] = players [j+1];
                players[j+1] = temp;
            }
        }
    }
}

void SortOBP(Player players[], int count) {
    int pass;
    int j;

    for(pass = 1; pass < count-1; pass++) {
        for(j = 0; j < count-1; j++) {
            Player temp;
            if(players[j].OBP < players[j+1].OBP) {
                temp = players[j];
                players[j] = players [j+1];
                players[j+1] = temp;
            }
 
        }
    }
}

void SortSLUG(Player players[], int count) {
    int pass;
    int j;

    for(pass = 1; pass < count-1; pass++) {
        for(j = 0; j < count-1; j++) {
            Player temp;
            if(players[j].SLUG < players[j+1].SLUG) {
                temp = players[j];
                players[j] = players [j+1];
                players[j+1] = temp;
            }
        }
    }
}

void SortYear(Player players[], int count) {
    int i;
    
    printf("Enter the filter year: ");
    scanf("%d", &i);

    if(i < 2017 || i > 2019) {
        printf("\n*** Error: Invalid filter specified. No filter set. ***\n");
    }
    if(i == 2017 || i == 2018 || i == 2019) {
        PrintPlayers(players,count);
    }
}

int Menu() {
    int i = -1;
    while(i < 1 || i > 6) {
    printf("\n*************************\n");
    printf("* Menu                  *\n");
    printf("*************************\n");
    
    printf("\n1. Print Player Records\n");
    printf("2. Sort by Batting Average\n");
    printf("3. Sort by On-base Percentage\n");
    printf("4. Sort by Slugging Percentage\n");
    printf("5. Filter by Year\n");
    printf("6. Exit\n");

    printf("Enter a selection: ");
    scanf("%d", &i);

    if(i < 1 || i > 6) {
        printf("\n*** Error: selection must be 1-6 ***\n");
        }
    }
    return i;
}

int main(void) {
    int i;
    FILE * fp;
    Player players[24];
    int count = 0;

    fp = fopen("lab10.dat", "r");
    if (fp) {
        //reads all of the records into the array
        while(!feof(fp)) {
            if (7 == fscanf(fp, "%s %s %d %s %f %f %f",
                players[count].LastName,
                players[count].FirstName,
                &(players[count].Year),
                players[count].Team,
                &(players[count].BA),
                &(players[count].OBP),
                &(players[count].SLUG)))
        {
            count++;
        }
    }
    printf("*** Initially:\n");
    PrintPlayers(players,count);


    while(i != 6) {
        i = Menu();
        switch(i) {
            case 1:
            PrintPlayers(players,count);
            break;

            case 2:
            SortBA(players,count);
            break;

            case 3:
            SortOBP(players,count);
            break;

            case 4:
            SortSLUG(players,count);
            break;

            case 5:
            SortYear(players,count);
            break;

            default:
            break;
        }
    }
    printf("\nThanks for playing!\n");
 
    return 0;
    
    fclose(fp);
    }
}
