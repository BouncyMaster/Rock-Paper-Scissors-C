#include <stdio.h> // puts() NULL printf() scanf() fopen()
#include <strings.h> // strcasecmp()
#include <string.h> // strchr()
#include <time.h> // time()
#include <stdlib.h> // srand() rand()
#include <unistd.h> // sleep() access()

int main() {
  char pinput[8], data[255], *e, cwins;
  int player, computer, wins, loses, draws, lindex, dindex;
  FILE *fp;

  // If there is a file named "data" in the process folder,
  // and if we have read and write permissions for it.
  if (access("./data", R_OK|W_OK) != -1) { // TODO: implement more ifs with different errors if file has read but no write permission etc.

    fp = fopen("./data", "r");
    fgets(data, 255, (FILE*)fp);
    fclose(fp);


    e = strchr(data, 'l');
    lindex = (int)(e - data);
    printf("%d\n", lindex);

    e = strchr(data, 'd');
    dindex = (int)(e - data);
    printf("%d\n", dindex);


    //strncpy(cwins, data+2, 5); // invalid conversion from ‘char’ to ‘char*’ [-fpermissive]

  } else {
    fp = fopen("./data", "w+");
    fputs("w=0 l=0 d=0", fp);
    fclose(fp);
    wins = 0; loses = 0; draws = 0;
  }

  printf("Choose Rock, Paper or Scissors:");
  scanf("%8s", pinput);

  if ((strcasecmp(pinput, "rock") == 0) ||
      (strcasecmp(pinput, "r") == 0)) {
    puts("You have chosen Rock");
    player = 1;
  }

  else if ((strcasecmp(pinput, "paper") == 0) ||
           (strcasecmp(pinput, "p") == 0)) {
    puts("You have chosen Paper");
    player = 2;
  }

  else if ((strcasecmp(pinput, "scissors") == 0) ||
           (strcasecmp(pinput, "s") == 0)) {
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
  } else if ((player == 1) && (computer == 2)) {
    puts("Computer has won!");
  } else if ((player == 1) && (computer == 3)) {
    puts("You have won!");
  } else if ((player == 2) && (computer == 1)) {
    puts("You have won!");
  } else if ((player == 3) && (computer == 1)) {
    puts("Computer has won!");
  } else if ((player == 2) && (computer == 3)) {
    puts("Computer has won!");
  } else if ((player == 3) && (computer == 2)) {
    puts("You have won!");
  }
}
