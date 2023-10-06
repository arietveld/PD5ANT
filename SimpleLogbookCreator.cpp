#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <windows.h>
//rel. 2023-10-06 15:21
char filename[20];
char callsign[100];


// Clearscreen functie
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//wis bovenste tekstblok
void clearHigh() {
 int numberLines = 15;
 for (int i = 0; i < numberLines; i++)
 {
    printf("\e[K");
    if ( i < numberLines - 1)
    {
    printf("\e[B");
}
 }
printf("\e[H");
}

// Arrays met beschikbare opties
char bandOptions[][5] = {"160M", "80M", "40M", "20M", "15M", "10M", "ALL"};
int currentBandIndex = 2;

char operatorOptions[][10] = {"SINGLE-OP", "MULTI-OP"};
int currentOperatorIndex = 0;

char assistedOptions[][13] = {"ASSISTED", "NON-ASSISTED"};
int currentAssistedIndex = 1;

char modeOptions[][6] = {"CW", "SSB", "MIXED"};
int currentModeIndex = 1;

char powerOptions[][5] = {"HIGH", "LOW", "QRP"};
int currentPowerIndex = 2;

char stationOptions[][9] = {"FIXED", "MOBILE", "PORTABLE"};
int currentStationIndex = 3;

char timeOptions[][9] = {"6-HOURS", "8-HOURS", "12-HOURS", "24-HOURS"};
int currentTimeIndex = 3;

char overlayOptions[][8] = {"","CLASSIC", "ROOKIE", "YOUTH"};
int currentOverlayIndex = 0;

void printCurrentOverlay() {
    printf(overlayOptions[currentOverlayIndex]);
}

void printCurrentAssisted() {
    printf(assistedOptions[currentAssistedIndex]);
}

void printCurrentTime() {
    printf(timeOptions[currentTimeIndex]);
}

void printCurrentStation() {
    printf(stationOptions[currentStationIndex]);
}

void printCurrentMode() {
    printf(modeOptions[currentModeIndex]);
}

void printCurrentPower() {
    printf(powerOptions[currentPowerIndex]);
}

void printCurrentOperator() {
    printf(operatorOptions[currentOperatorIndex]);
}

void printCurrentBand() {
    printf(bandOptions[currentBandIndex]);
}

//functie voor het printen van het bestand
//void printLog();

//Functie voor het aanmaken van de Cabrillo Header
void makeHeader();

//functie voor het QSO menu
void makeQSO();

//functie om de logfile af te sluiten
void closeLog();

//functie om het logbook te laten zien
void showLog();

//Functie voor het startmenu
void makeMenu(){

    int choice;

    do {
        clearScreen();

        printf("Simple Logbook Creator rel. 0.1\n\n" );
        printf("Menu:\n");
        printf("1. Invoeren Cabrillo Header\n");
        printf("2. Invoeren QSO's\n");
        printf("3. Log afsluiten\n");
        printf("4. Laat logbook zien\n");
        //printf("5. Print het logboek\n");
        //printf("6. Instellingen\n");
        printf("0. Exit\n");
        printf("Keuze: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Vraag de gebruiker om de Header parameters in te vullen
                makeHeader();

                break;

            case 2:
                 // Vraag de gebruiker om de QSO parameters in te vullen
                makeQSO();
                
                break;

            case 3:
                //log afsluiten
                closeLog();

                break;
            
            case 4:
                //laat logbook zien
                showLog();

                break;

            /* case 5:
                //print het logboek
                printLog();

                break;
                
            case 6:
                //Bepaal de default parameters
                printf("Hier komt het instellingen menu");
                //settings();

                break;
            */
            case 0:
                printf("Programma wordt afgesloten.\n");

                return;

            default:
                printf("Ongeldige keuze. Probeer opnieuw.\n");
        }

        printf("\nDruk op Enter om door te gaan...");
        getchar(); // Wacht op Enter-toets
        getchar(); // Verbruik het newline-karakter in de buffer

    } while (choice != 0);
}

/*Functie voor default waarden

void setDefaultIfEmpty(char *input, const char *defaultValue) {
    if (strlen(input) <= 1 && input[0] == '\n') {
        strcpy(input, defaultValue + '\n');
    } 
}
*/
void makeHeader(){

FILE *file;
    char contest[100], category_operator[100], category_band[100];
    char category_power[100], category_mode[100], claimed_score[100], name[100];
    char address[100], address_city[100], address_postalcode[100], address_country[100];
    char operators[100], email[100], club[100];
    int bandChoice, assistedChoice, operatorChoice, powerChoice, stationChoice;
    int timeChoice, overlayChoice, modeChoice;

    fflush(stdin);

    if ( strlen(callsign) < 1){
        printf("CALLSIGN: ");
        fgets(callsign, sizeof(callsign), stdin);
    }
    else printf("CALLSIGN: %s\n", callsign);

        printf("CONTEST: ");
        fgets(contest, sizeof(contest), stdin);

        while (1) {
        printf("CATEGORY-OPERATOR: ");            
        printf("SINGLE-OP (0), MULTI-OP (1) ");
        scanf("%d", &operatorChoice);
        
        if (operatorChoice >= 0 && bandChoice <= 1) { 
            break; 
        } else {
            printf("Ongeldige keuze. Probeer opnieuw.\n");
        }
        }
        int currentOperatorIndex = operatorChoice;     
        

        while (1) { 
        printf("CATEGORY-BAND: ");
        printf("160M (0), 80M (1), 40M (2), 20M (3), 15M (4), 10M (5), ALL (6) ");
        scanf("%d", &bandChoice);
        
        if (bandChoice >= 0 && bandChoice <= 6) { 
            break; 
        } else {
            printf("Ongeldige keuze. Probeer opnieuw.\n");
        }
        }
             
        int currentBandIndex = bandChoice;
               
        while (1) {
        printf("CATEGORY-POWER: ");
        printf("HIGH (0), LOW (1), QRP (2) ");
        scanf("%d", &powerChoice);
        if (powerChoice >=0 && powerChoice <= 5) {
            break;
        }else {
           printf("Ongeldige keuze. Probeer opnieuw.\n"); 
        }
        }
        int currentPowerIndex = powerChoice;
        
        while (1) {
        printf("CATEGORY-STATION: ");
        printf("FIXED (0), MOBILE (1), PORTABLE (2) ");
        scanf("%d", &stationChoice);
        if (stationChoice >=0 && stationChoice <= 2) {
            break;
        }else {
           printf("Ongeldige keuze. Probeer opnieuw.\n"); 
        }
        }
        int currentStationIndex = stationChoice;
              
        while (1) {
        printf("CATEGORY-TIME: ");
        printf("6-HOURS (0), 8-HOURS (1), 12-HOURS (2), 24-HOURS (3) ");
        scanf("%d", &timeChoice);
        if (timeChoice >=0 && timeChoice <= 3) {
            break;
        }else {
           printf("Ongeldige keuze. Probeer opnieuw.\n"); 
        }
        }
        int currentTimeIndex = timeChoice;

while (1) {
        printf("CATEGORY-MODE: ");
        printf("CW (0), SSB (1), MIXED (2) ");
        scanf("%d", &modeChoice);
        if (modeChoice >=0 && modeChoice <= 2) {
            break;
        }else {
           printf("Ongeldige keuze. Probeer opnieuw.\n"); 
        }
        }
        int currentModeIndex = modeChoice;

while (1) {
        printf("CATEGORY-OVERLAY: ");
        printf("NONE (0), CLASSIC (1), ROOKIE (2), YOUTH (3) ");
        scanf("%d", &overlayChoice);
        if (overlayChoice >=0 && overlayChoice <= 3) {
            break;
        }else {
           printf("Ongeldige keuze. Probeer opnieuw.\n"); 
        }
        }
        int currentOverlayIndex = overlayChoice;

        printf("CLAIMED-SCORE: ");
        fgets(claimed_score, sizeof(claimed_score), stdin);

        printf("NAME: ");
        fgets(name, sizeof(name), stdin);

        printf("ADDRESS: ");
        fgets(address, sizeof(address), stdin);

        printf("ADDRESS-CITY: ");
        fgets(address_city, sizeof(address_city), stdin);

        printf("ADDRESS-POSTALCODE: ");
        fgets(address_postalcode, sizeof(address_postalcode), stdin);

        printf("ADDRESS-COUNTRY: ");
        fgets(address_country, sizeof(address_country), stdin);

        printf("OPERATORS: ");
        fgets(operators, sizeof(operators), stdin);

        printf("EMAIL: ");
        fgets(email, sizeof(email), stdin);

        printf("CLUB: ");
        fgets(club, sizeof(club), stdin);

        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Kan het bestand niet openen.\n");
            return;
        }

        fprintf(file,"START-OF-LOG: 3.0\n");
        fprintf(file, "CALLSIGN: %s\n", callsign);
        fprintf(file, "CONTEST: %s", contest);
        fprintf(file, "CATEGORY-ASSISTED: %s\n", assistedOptions[currentAssistedIndex]);
        fprintf(file, "CATEGORY-MODE: %s\n", modeOptions[currentModeIndex]);
        fprintf(file, "CATEGORY-OPERATOR: %s\n", operatorOptions[currentOperatorIndex]);
        fprintf(file, "CATEGORY-BAND: %s\n", bandOptions[currentBandIndex]);
        fprintf(file, "CATEGORY-POWER: %s\n", powerOptions[currentPowerIndex]);
        fprintf(file, "CATEGORY-STATION: %s\n", stationOptions[currentStationIndex]);
        fprintf(file, "CATEGORY-TIME: %s\n", timeOptions[currentTimeIndex]);
        fprintf(file, "CLAIMED-SCORE: %s", claimed_score);
        fprintf(file, "CATEGORY-OVERLAY: %s\n", overlayOptions[currentOverlayIndex]);
        fprintf(file, "NAME: %s", name);
        fprintf(file, "ADDRESS: %s", address);
        fprintf(file, "ADDRESS-CITY: %s", address_city);
        fprintf(file, "ADDRESS-POSTALCODE: %s", address_postalcode);
        fprintf(file, "ADDRESS-COUNTRY: %s", address_country);
        fprintf(file, "OPERATORS: %s", operators);
        fprintf(file, "EMAIL: %s", email);
        fprintf(file, "CLUB: %s", club);
        fprintf(file, "CREATED-BY: Simple Logbook Creator rel. 0.1\n");


        fclose(file);

        printf("Gegevens zijn opgeslagen in %s\n", filename);

        return;

}

void makeQSO(){

clearScreen();
/*
Each contact in the log is reported using the QSO tag. Some items on this line will be different for each contest depending on the exchange information.

QSO Data Example

                              --------info sent------- -------info rcvd--------
QSO:  freq mo date       time call          rst exch   call          rst exch   t
QSO: ***** ** yyyy-mm-dd nnnn ************* nnn ****** ************* nnn ****** n
QSO:  3799 PH 1999-03-06 0711 HC8N           59 700    W1AW           59 CT     0
QSO:  3799 PH 1999-03-06 0712 HC8N           59 700    N5KO           59 CA     0

*/

FILE *file;
    struct QSO {
    char frequencie[6];
    char mode[3];
    char date[11];
    char time[5];
    char callsent[14];
    char rstsent[4];
    char exchsent[7];
    char callrcvd[14];
    char rstrcvd[4];
    char exchrcvd[7];
    char transmitter[2];
    };

int numQSOs = 0;
    struct QSO *qsos = NULL;

    while (1) {
        printf("Voer de QSO information in of 'q' om af te sluiten:\n");
        
        // Reallocate memory for each new QSO
        qsos = (struct QSO *)realloc(qsos, (numQSOs + 1) * sizeof(struct QSO));
    
        file = fopen(filename, "a");
        if (file == NULL) {
            printf("Kan het bestand niet openen.\n");
            return;
        }

        // Input QSO information
        printf("Frequencie: ");
        scanf("%s", qsos[numQSOs].frequencie);
        if (qsos[numQSOs].frequencie[0] == 'q') {
            break;
        }
        // Presenteer laatste input, bij enter kan deze waarde worden herhaald
        if (numQSOs > 0){
        printf("Mode: %s", qsos[numQSOs - 1].mode);
        //scanf("%s", );
        }
        else printf("Mode: ");
        scanf("%s", qsos[numQSOs].mode);
        printf("Date: ");
        scanf("%s", qsos[numQSOs].date);
        printf("Time: ");
        scanf("%s", qsos[numQSOs].time);
        printf("Call Sent: ");
        scanf("%s", qsos[numQSOs].callsent);
        printf("RST Sent: ");
        scanf("%s", qsos[numQSOs].rstsent);
        printf("Exchange Sent: ");
        scanf("%s", qsos[numQSOs].exchsent);
        printf("Call Received: ");
        scanf("%s", qsos[numQSOs].callrcvd);
        printf("RST Received: ");
        scanf("%s", qsos[numQSOs].rstrcvd);
        printf("Exchange Received: ");
        scanf("%s", qsos[numQSOs].exchrcvd);
        printf("Transmitter: ");
        scanf("%s", qsos[numQSOs].transmitter);

        //voeg de QSO gegevens toe aan het bestand

        fprintf(file, "QSO: %-5s %-2s %-10s %-4s %-13s %-3s %-6s %-13s %-3s %-6s %-1s\n", qsos[numQSOs].frequencie, qsos[numQSOs].mode, qsos[numQSOs].date, 
        qsos[numQSOs].time, qsos[numQSOs].callsent, qsos[numQSOs].rstsent, qsos[numQSOs].exchsent,
        qsos[numQSOs].callrcvd, qsos[numQSOs].rstrcvd, qsos[numQSOs].exchrcvd, qsos[numQSOs].transmitter);
        
        //Toon de volledige QSO op het scherm
        //Kleur groen
        printf("\e[s");
        printf("\e[32m\e[25;1H                              --------info sent------- -------info rcvd--------\n");
        printf("QSO:  freq mo date       time call          rst exch   call          rst exch   t\n");
        printf("QSO: %-5s %-2s %-10s %-4s %-13s %-3s %-6s %-13s %-3s %-6s %-1s\n\n", qsos[numQSOs].frequencie, qsos[numQSOs].mode, qsos[numQSOs].date, 
        qsos[numQSOs].time, qsos[numQSOs].callsent, qsos[numQSOs].rstsent, qsos[numQSOs].exchsent,
        qsos[numQSOs].callrcvd, qsos[numQSOs].rstrcvd, qsos[numQSOs].exchrcvd, qsos[numQSOs].transmitter);
        
        printf("\e[0m\e[1;1H");
        clearHigh();
        numQSOs++;

        fclose(file);

        printf("Gegevens zijn opgeslagen in %s\n", filename);
        
    }


}


void closeLog(){
    FILE *file;
    file = fopen(filename, "a");
        if (file == NULL) {
            printf("Kan het bestand niet openen.\n");
            return;
        }

        fprintf(file,"END-OF-LOG:\n");

        fclose(file);

        printf("Gegevens zijn opgeslagen in %s\n", filename);

       
}

void showLog(){
    clearScreen();
    char c;
    FILE *file;

    file = fopen(filename, "r");
           if (file == NULL) {
            printf("Kan het bestand niet openen.\n");
            return;
        }

        c = fgetc(file);
        while (c != EOF)
        {
            printf ("%c",c);
            c = fgetc(file);
        }

        fclose(file);
        
        return;
}

/* void printLog(){
    clearScreen();
    char c;
    FILE *file;

    file = fopen(filename, "r");
           if (file == NULL) {
            printf("Kan het bestand niet openen.\n");
            return;
        }

    // Haal een handle voor de standaardprinter op
    HANDLE hPrinter;
    if (!OpenPrinter(NULL, &hPrinter, NULL)) {
        perror("Kan de printer niet openen");
        fclose(file);
        return;
    }

    // Stel de afdrukjob in
    if (StartDocPrinter(hPrinter, 1, NULL) == 0) {
        perror("Kan de afdruktaak niet starten");
        ClosePrinter(hPrinter);
        fclose(file);
        return;
    }

    // Stuur elke regel van het bestand naar de printer
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (!WritePrinter(hPrinter, buffer, strlen(buffer), NULL)) {
            perror("Kan niet naar de printer schrijven");
            EndDocPrinter(hPrinter);
            ClosePrinter(hPrinter);
            fclose(file);
            return;
        }
    }
   
    
    // Beëindig de afdruktaak
    EndDocPrinter(hPrinter);

    // Sluit de printer
    ClosePrinter(hPrinter);

    // Sluit het bestand
    fclose(file);

    return;
}
*/

/*void settings(){

//    char defaultCategory_power[] = "QRP";


}
*/

// Bij het starten van het programma kan de filename en callsign worden meegegeven

int main(int argc, char *argv[]){
    
//   clearScreen();


    
//    printf("QRP Logbook creator rel. 0.1\n\n" );


    if (argc == 3) {
    strcpy(filename, argv[1]);
    strcpy(callsign, argv[2]);
    }
    else {
        printf("Geef de naam van het bestand: \n");
        scanf("%s",filename);
    }
    
    
    fflush(stdin);

    makeMenu();
        
    return 0;
}