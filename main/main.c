#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 11;
const int LED_PIN = 28;
const int BOBINA1 = 16;
const int BOBINA2 = 17;
const int BOBINA3 = 15;
const int BOBINA4 = 14;


int main() {
  stdio_init_all();


  gpio_init(BTN_PIN);
  gpio_init(BOBINA1);
  gpio_init(BOBINA2);
  gpio_init(BOBINA3);
  gpio_init(BOBINA4);
  gpio_init(LED_PIN);

  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  gpio_set_dir(BOBINA1, GPIO_OUT);
  gpio_set_dir(BOBINA2, GPIO_OUT);
  gpio_set_dir(BOBINA3, GPIO_OUT);
  gpio_set_dir(BOBINA4, GPIO_OUT);

  gpio_pull_up(BTN_PIN);

  while (true) {
    if (!gpio_get(BTN_PIN)){
      gpio_put(LED_PIN,1);
      for (int i = 0; i < 512; i++){
        gpio_put(BOBINA1, 1);
        sleep_ms(10);
        gpio_put(BOBINA1, 0);
        gpio_put(BOBINA2, 1);
        sleep_ms(10);
        gpio_put(BOBINA2, 0);
        gpio_put(BOBINA3, 1);
        sleep_ms(10);
        gpio_put(BOBINA3, 0);
        gpio_put(BOBINA4, 1);
        sleep_ms(10);
        gpio_put(BOBINA4, 0);
      }
      gpio_put(LED_PIN,0);
    }
  }
}