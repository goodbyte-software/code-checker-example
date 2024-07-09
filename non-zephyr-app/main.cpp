#include <chrono>
#include <iostream>
#include <thread>

namespace {
    const auto BLINK_DURATION = std::chrono::milliseconds(1000);

    void blink_led() {
        std::cout << "LED blinks" << std::endl;

        std::this_thread::sleep_for(BLINK_DURATION);
    }
}

int main(void)
{
    while (1) blink_led();

    return 0;
}
