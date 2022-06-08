#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	int right;
	int counter = 1;
	int try;
	int guess;
	double points = 1000;
	int mode;

	int seconds = time(0);
	srand(seconds);
	int random_num = rand();
	int secret_num = random_num % 100;

	printf("   /\\                                                        /\\	\n");
	printf("  |  |                                                      |  |	\n");
	printf(" /----\\                  Seja bem vindo!                   /----\\	\n");
	printf("[______]        Ao jogo de adivinha de Mateus Maidel.      [______]	\n");
	printf(" |    |         _____                        _____         |    |	\n");
	printf(" |[]  |        [     ]                      [     ]        |  []|	\n");
	printf(" |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |	\n");
	printf(" |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |	\n");
	printf(" |             |     |/'    ____..____    '\\|     |             |	\n");
	printf("  \\  []        |     |    /'    ||    '\\    |     |        []  /	\n");
	printf("   |      []   |     |   |o     ||     o|   |     |  []       |		\n");
	printf("   |           |  _  |   |     _||_     |   |  _  |           |		\n");
	printf("   |   []      | (_) |   |    (_||_)    |   | (_) |       []  |		\n");
	printf("   |           |     |   |     (||)     |   |     |           |		\n");
	printf("   |           |     |   |      ||      |   |     |           |		\n");
	printf(" /''           |     |   |o     ||     o|   |     |           ''\\	\n");
	printf("[_____________[_______]--'------''------'--[_______]_____________]	\n");
	printf("\nVocê precisa adivinhar um número entre 0 e 100.\n					\n");


    //Number of tries
	printf ("Para começar, qual nível de dificuldade você deseja?\n");
	printf ("(1) Fácil, (2) Médio, (3) Difícil\n");
	printf ("Escolha:");
	scanf ("%d", &mode);
    	printf ("--------------------------------------\n");

	switch (mode)
	{
		case 1:
			try = 18;
			printf ("Você escolheu o modo FÁCIL, você terá %d tentativas\n", try); 
			
			break;
		case 2:
			try = 12;
			printf ("Você escolheu o modo MÉDIO, você terá %d tentativas\n", try);
			break;
		case 3:
			try = 6;
			printf ("Você escolheu o modo DIFÍCIL, você terá %d tentativas\n", try);
			break;
		default:
			printf ("Você só pode digitar 1, 2 ou 3, reinicie o jogo:\n");
	}

	
    while (guess != secret_num && counter <= try)
    {
	if (try == counter )
	{
		printf ("Essa é sua ultima tentativa, pense bem!\n");
	}
        
	//tries
        printf ("Tentativa %d de %d\n",counter, try);

        //Guess number
        printf ("Qual é o seu chute?\n");
        scanf("%d", &guess);
        printf ("Você chutou %d\n", guess);
	printf ("----------------------------------------------------\n");

        //Validation
	if (guess < 0)
	{
		printf ("Você não pode chutar um numero negativo\n");
		printf ("Tente novamente\n");
		printf ("----------------------------------------------------\n");
		continue;
	}

        else if (guess > secret_num && counter != try)
        {
            printf ("Seu chute foi maior que o numero secreto!\n");
            printf ("Você errou, tente novamente!\n");
            printf ("----------------------------------------------------\n");
        }
        
	else if (guess < secret_num && counter != try)
        {
            printf ("Seu chute foi menor que o numero secreto!\n");
            printf ("Você errou, tente novamente!\n");
            printf ("----------------------------------------------------\n");
        }
	
	else if (guess != secret_num && counter == try)
        {
		printf ("Você errou, jogue novamente outra partida!\n");
        	printf ("----------------------------------------------------\n");
        }
		double lostpoints = abs(guess - secret_num) / (double) 2;
		points = points - lostpoints;

    	counter++;
    }
	
	if (guess == secret_num)
	{
		counter--;
		printf ("Parabens, você acertou em %d tentativas!\n", counter);
	}
	else if(guess != secret_num)
	{
		printf("O número secreto era %d\n", secret_num);
	}
	printf ("Fim de jogo!\n");
	printf ("Total de pontos: %.1f\n", points);
}
