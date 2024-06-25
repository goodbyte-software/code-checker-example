#include "worker.hh"

#include <zephyr/kernel.h>

#define SLEEP_TIME_MS 1000

void blink_led()
{
    static bool led_state = true;

    led_state = !led_state;
    printf("LED state: %s\n", led_state ? "ON" : "OFF");
    k_msleep(SLEEP_TIME_MS);
}