#include <bcm2835.h>
#include <stdlib.h>
#include <stdio.h>

#define PIN RPI_GPIO_P1_15

int main(int argc, char **argv)
{
  if (!bcm2835_init())
   return 1;

  bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT);
  printf("Program has started running...\n");

  while(1)
  {
    if (bcm2835_gpio_lev(PIN))
  {
       system("raspistill -q 5 -o pic.jpg -t 1 -th 0:0:0");
       printf("Motion detected and picture has been taken!\n");
       while (bcm2835_gpio_lev(PIN));
  }
  bcm2835_delay(1000);
}
}
