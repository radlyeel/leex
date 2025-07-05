#include "io.h"

void main(void) {
    uart_init();
    uart_write_text("Hello from RPi\n");
    while (1);
}
