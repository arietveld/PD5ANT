#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <time.h>    // For default time and date



/* Dit programma is bedoeld als eenvoudige Contest logger die direct een output genereerd voor het 
indienen van het log in Cabrillo formaat.
We hebben gekozen voor een beperkt aantal tags. Eventueel kan achteraf in een texteditor altijd
een tag worden toegevoegd.


Voorbeeld

START-OF-LOG: 3.0
CONTEST: CQ-WPX-CW
CALLSIGN: AA1ZZZ
LOCATION: WMA
CATEGORY-OPERATOR: SINGLE-OP
CATEGORY-ASSISTED: NON-ASSISTED
CATEGORY-BAND: ALL
CATEGORY-POWER: HIGH
CATEGORY-MODE: CW
CATEGORY-TRANSMITTER: ONE
CATEGORY-OVERLAY: TB-WIRES
GRID-LOCATOR: 
CLAIMED-SCORE: 9447852
CLUB: Yankee Clipper Contest Club
CREATED-BY: WriteLog V10.72C
NAME: Randy Thompson
ADDRESS: 1 Main St
ADDRESS-CITY: Uxbridge
ADDRESS-STATE-PROVINCE: MA
ADDRESS-POSTALCODE: 01569
ADDRESS-COUNTRY: USA
OPERATORS: K5ZD
SOAPBOX: Put your comments here.
SOAPBOX: Use multiple lines if needed.
QSO: 7005 CW 2009-05-30 0002 AA1ZZZ 599 1 S50A 599 4
QSO: 7006 CW 2009-05-30 0015 AA1ZZZ 599 2 EF8M 599 34
END-OF-LOG:

de details voor Cabrillo zijn te vinden op: https://wwrof.org/cabrillo/



*/

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

        printf("QRP Logbook creator rel. 0.1\n\n" );
        printf("Menu:\n");
        printf("1. Invoeren Cabrillo Header\n");
        printf("2. Invoeren QSO's\n");
        printf("3. Log afsluiten\n");
        printf("4. Laat logbook zien\n");
        printf("5. Instellingen\n");
        printf("6. Exit\n");
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

            case 5:
                //Bepaal de default parameters
                printf("Hier komt het instellingen menu");
                //settings();

                break;
            case 6:
                printf("Programma wordt afgesloten.\n");

                return;

            default:
                printf("Ongeldige keuze. Probeer opnieuw.\n");
        }

        printf("\nDruk op Enter om door te gaan...");
        getchar(); // Wacht op Enter-toets
        getchar(); // Verbruik het newline-karakter in de buffer

    } while (choice != 6);
}

//Functie voor default waarden

void setDefaultIfEmpty(char *input, const char *defaultValue) {
    if (strlen(input) <= 1 && input[0] == '\n') {
        strcpy(input, defaultValue + '\n');
    } 
}

void makeHeader(){

FILE *file;
    char contest[100], category_operator[100], category_band[100];
    char category_power[100], category_mode[100], claimed_score[100], name[100];
    char address[100], address_city[100], address_postalcode[100], address_country[100];
    char operators[100], email[100], club[100];

    char defaultCategory_power[] = "QRP";

    fflush(stdin);

    if ( strlen(callsign) < 1){
        printf("CALLSIGN: ");
        fgets(callsign, sizeof(callsign), stdin);
    }
    else printf("CALLSIGN: %s\n", callsign);

        printf("CONTEST: ");
        fgets(contest, sizeof(contest), stdin);

        printf("CATEGORY-OPERATOR: ");
        fgets(category_operator, sizeof(category_operator), stdin);

        printf("CATEGORY-BAND: ");
        fgets(category_band, sizeof(category_band), stdin);

        printf("CATEGORY-POWER: [DEFAULT: %s]", defaultCategory_power);
        fgets(category_power, sizeof(category_power), stdin);
        setDefaultIfEmpty(category_power, defaultCategory_power);
      
        printf("CATEGORY-MODE: ");
        fgets(category_mode, sizeof(category_mode), stdin);

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
        fprintf(file, "CATEGORY-OPERATOR: %s", category_operator);
        fprintf(file, "CATEGORY-BAND: %s", category_band);
        fprintf(file, "CATEGORY-POWER: %s", category_power);
        fprintf(file, "CATEGORY-MODE: %s", category_mode);
        fprintf(file, "CLAIMED-SCORE: %s", claimed_score);
        fprintf(file, "NAME: %s", name);
        fprintf(file, "ADDRESS: %s", address);
        fprintf(file, "ADDRESS-CITY: %s", address_city);
        fprintf(file, "ADDRESS-POSTALCODE: %s", address_postalcode);
        fprintf(file, "ADDRESS-COUNTRY: %s", address_country);
        fprintf(file, "OPERATORS: %s", operators);
        fprintf(file, "EMAIL: %s", email);
        fprintf(file, "CLUB: %s", club);


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