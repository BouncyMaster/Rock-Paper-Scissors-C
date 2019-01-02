#include <stdio.h> // puts() NULL printf() scanf() fopen() fgets() fclose()
                   // fprintf()
#include <strings.h> // strcasecmp()
#include <string.h> // strchr() strlen()
#include <time.h> // time()
#include <stdlib.h> // srand() rand() atoi()
#include <unistd.h> // sleep() access()

int main(void) {

  char pInput[8], data[255], chWins[255], chLoses[255], chDraws[255], *e;
  int player, computer, wins, loses, draws, lIndex, dIndex;
  FILE *fp;

  // If there is a file named "data" in the process folder
  // and if we have read and write permissions for it.
  if (access("./data", R_OK|W_OK) != -1) { // TODO: implement more ifs with different errors if file has read but no write permission etc.

    fp = fopen("./data", "r");
    fgets(data, 255, (FILE*)fp);
    fclose(fp);

    e = strchr(data, 'l'); // Find the index of 'l' in char data
    lIndex = (int)(e - data);

    e = strchr(data, 'd'); // Find the index of 'd' in char data
    dIndex = (int)(e - data);

    strncpy(chWins, data + 1, lIndex - 1); // Copy the part of the char data
                                           // Which says the amount of wins
    strncpy(chLoses, (data + lIndex + 1), (dIndex - lIndex) - 1);
    strncpy(chDraws, (data + dIndex + 1), (strlen(data) - dIndex) - 2);

    // ASCII To Int
    wins = atoi(chWins); loses = atoi(chLoses); draws = atoi(chDraws);

  } else {

    fp = fopen("./data", "w+");
    fputs("w0l0d0", fp);
    fclose(fp);
    wins = 0; loses = 0; draws = 0;

  }

  printf("Choose Rock, Paper or Scissors:");
  scanf("%8s", pInput);

  if ((strcasecmp(pInput, "rock") == 0) ||
      (strcasecmp(pInput, "r") == 0)) {
    puts("You have chosen Rock");
    player = 1;
  }

  else if ((strcasecmp(pInput, "paper") == 0) ||
           (strcasecmp(pInput, "p") == 0)) {
    puts("You have chosen Paper");
    player = 2;
  }

  else if ((strcasecmp(pInput, "scissors") == 0) ||
           (strcasecmp(pInput, "s") == 0)) {
    puts("You have chosen Scissors");
    player = 3;
  }

  else
    puts("Error: Incorrect Input");

  sleep(1);

  // random seed based on time
  srand(time(NULL));
  // random integer 1-3
  computer = rand() % 3 + 1;
  if (computer == 1)
    puts("Computer has chosen Rock");
  else if (computer == 2)
    puts("Computer has chosen Paper");
  else
    puts("Computer has chosen Scissors");

  if (player == computer) {
    puts("It's a draw!");
    draws++;
  } else if ((player == 1) && (computer == 2)) {
    puts("Computer has won!");
    loses++;
  } else if ((player == 1) && (computer == 3)) {
    puts("You have won!");
    wins++;
  } else if ((player == 2) && (computer == 1)) {
    puts("You have won!");
    wins++;
  } else if ((player == 3) && (computer == 1)) {
    puts("Computer has won!");
    loses++;
  } else if ((player == 2) && (computer == 3)) {
    puts("Computer has won!");
    loses++;
  } else if ((player == 3) && (computer == 2)) {
    puts("You have won!");
    wins++;
  }

  fp = fopen("./data", "w+");
  fprintf(fp, "w%dl%dd%d\n", wins, loses, draws);
  fclose(fp);

  printf("\n"
"=========================\n"
"You have %d total wins\n"
"You have %d total loses\n"
"You have %d total draws\n"
"\n"
"You have played %d times\n"
"=========================\n"
  , wins, loses, draws, wins+loses+draws);

}
