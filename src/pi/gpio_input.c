/* Implements the functions that fetch operation from PI's GPIO ports */

#include <stdio.h>
#include "gpio_input.h"
#include "gpio_button.h"
#include "gpio_sports.h"

#define MODE_NUM 3

/* Function pointers arrrays used to simplify the code */
typedef operator_t (*gpio_inputs) (void);
typedef void (*gpio_inits) (void);
gpio_inputs input_selector[] = {NULL, get_button, get_sports};
gpio_inits init_selector[] = {NULL, init_gpio_but, init_gpio_sp};


operator_t gpio_input(inmode_t mode) {
  if ((mode == KEY_BOARD) || (mode >= MODE_NUM)) {
    fprintf(stderr, "Unknown input mode!");
    return NONE;
  }
  return input_selector[mode]();
}

void init_gpio(inmode_t mode) {
  if ((mode == KEY_BOARD) || (mode >= MODE_NUM)) {
    fprintf(stderr, "Unknown input mode!");
    return;
  }
  init_selector[mode]();
}
