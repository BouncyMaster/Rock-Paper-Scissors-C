#include <stdio.h> // puts() NULL printf() scanf()
#include <strings.h> // strcasecmp()
#include <time.h> // time()
#include <stdlib.h> // srand() rand()
#include <unistd.h> // sleep()

int main() {

  char pinput[8];
  int player, computer;


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
