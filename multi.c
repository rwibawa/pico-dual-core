#include "pico/stdlib.h"
#include "pico/multicore.h"

#define GPIO_ON   1
#define GPIO_OFF  0

#define LED_PIN 25

void second_core_code()
{
  while (true)
  {
    sleep_ms(500);
    multicore_fifo_push_blocking(GPIO_ON);
    sleep_ms(500);
    multicore_fifo_push_blocking(GPIO_OFF);
  }
  
}
int main()
{
  // it start on core0, and call code on core1
  multicore_launch_core1(second_core_code);

  gpio_init(LED_PIN);               // initialize pin 25
  gpio_set_dir(LED_PIN, GPIO_OUT);  // set it as output pin

  while (true)
  {
    // wait on fifo
    uint32_t command = multicore_fifo_pop_blocking();
    gpio_put(LED_PIN, command);
  }
  
}