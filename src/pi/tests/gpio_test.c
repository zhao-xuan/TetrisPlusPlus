#include <stdio.h>
#include <wiringPi.h>
#include "gpio_input.h"
#include "state.h"

#define INPUT_DELAY 20

int main(void) {
  init_gpio(PI_SPORTS);
  while (1) {
    operator_t input = gpio_input(PI_SPORTS);
    if (input != NONE) {
      printf("%d\n",input); 
    }
    delay(INPUT_DELAY);
  }  

  return 0;
}
