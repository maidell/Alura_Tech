#include <stdio.h>
#include <string.h>

int right = 0;
int hanged = 0;

char kicks[26];
int try = 0;
char secret_w[20];

void header()
{
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void cap_kick(char kicks[26], int try)
{
        char kick;
        printf("Qual letra? ");
        scanf(" %c", &kick);

        kicks[try] = kick;
        try++;
}

int main() 
{
    header      ();
    cap_kick    ()

    sprintf(secret_w, "MELANCIA");


    do {

        for(int i = 0; i < strlen(secret_w); i++) {
            int found = 0;

            for(int j = 0; j < try; j++) {
                if(kicks[j] == secret_w[i]) {
                    found = 1;
                    break;
                }
            }

            if(found) {
                printf("%c ", secret_w[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

    cap_kick (kicks,try);

    } while (!right && !hanged);

}
