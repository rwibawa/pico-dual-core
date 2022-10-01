#include "pico/stdlib.h"
#include "pico/multicore.h"

#define GPIO_ON   1
#define GPIO_OFF  0

#define GREEN_LED 15
#define RED_LED 16

void second_core_code()
{
  while (true)
  {
    // wait on fifo
    uint32_t led = multicore_fifo_pop_blocking();
    gpio_put(led, GPIO_ON);
    sleep_ms(250);
    gpio_put(led, GPIO_OFF);
    sleep_ms(250);

    multicore_fifo_push_blocking(RED_LED);
  }
  
}
int main()
{
  // it start on core0, and call code on core1
  multicore_launch_core1(second_core_code);

  gpio_init(GREEN_LED);               // initialize GPIO 15
  gpio_set_dir(GREEN_LED, GPIO_OUT);  // set it as output pin

  gpio_init(RED_LED);               // initialize GPIO 16
  gpio_set_dir(RED_LED, GPIO_OUT);  // set it as output pin

  while (true)
  {
    multicore_fifo_push_blocking(GREEN_LED);

    // wait on fifo
    uint32_t led = multicore_fifo_pop_blocking();
    gpio_put(led, GPIO_ON);
    sleep_ms(250);
    gpio_put(led, GPIO_OFF);
    sleep_ms(250);
  }
  
}