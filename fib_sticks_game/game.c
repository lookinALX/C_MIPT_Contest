#include <stdio.h>
#include <stdlib.h>

int random_first_turn(){
  while(1){
    int value = rand()%(6+1);
    printf("Computer throws: %d\n", value);
    int user_value = rand()%(6+1);
    printf("User throws: %d\n", user_value);
    if (user_value == value){
      continue;
    } else {
      if (user_value > value){
        printf("User goes first\n");
        return 0;
      } else if (user_value < value) {
        printf("User goes second\n");
        return 1;
      }
    }
  }
  return EXIT_FAILURE;
}

unsigned int count_next_fibonacci(unsigned int stiks_number, int previously_taken){
  if (previously_taken == 0){
    return 1;
  }
  int limit = previously_taken*2;
  unsigned int next_fib = 0;
  unsigned int last_fib = 1;
  unsigned int fibonacci[] = {1,1};
  while(1){
    next_fib = fibonacci[1] + fibonacci[0];
    if(next_fib > limit){
      next_fib = last_fib;
      break;
    }
    fibonacci[0] = fibonacci[1];
    fibonacci[1] = next_fib;
    last_fib = next_fib;
  }
  return next_fib;
}

int start_game(int how_first, unsigned int stiks_number){
  int previously_taken = 0;
  unsigned int initinal_stiks_number = stiks_number;
  while (stiks_number > 1) {
    int stiks_taken = 0;
    if (how_first == 0){
      printf("How many sticks you'd like to take? You can take maximum 2 times more as %d\n", previously_taken);
      printf("If it was 0 taken, you can take not more as %d. Type your value: ", initinal_stiks_number-1);
      if (scanf("%d\n", &stiks_taken) < 1) {
        return EXIT_FAILURE;
      } else if (stiks_taken > 2* previously_taken) {
        return EXIT_FAILURE;
      } else {
        how_first += 1;
        previously_taken = stiks_taken;
      }
    } else if (how_first == 1) {
      stiks_taken = count_next_fibonacci(stiks_number, previously_taken);
      printf("Computer takes %d stiks\n", stiks_taken);
      previously_taken = stiks_taken;
      how_first -= 1;
    }
    stiks_number -= stiks_taken;
    printf("Stiks left: %d\n", stiks_number);
  }
  return 0;
}

int main() {
  unsigned int stiks_number = 0;
  printf("How many sticks you'd like to have in the game? Type:\n");
  if (scanf("%d", &stiks_number) != 1) {
    return EXIT_FAILURE;
  }
  int how_first = random_first_turn();
  return start_game(how_first, stiks_number);
}