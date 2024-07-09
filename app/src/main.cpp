#include "worker.hh"

int main(void)
{
    // codechecker_confirmed [all] this code intentionally contains violations
    while (1) blink_led();

    return 0;
}
