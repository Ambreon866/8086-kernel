#include <stdint.h>
#define VIDEO_MEMORY 0xB8000
#define WHITE_ON_BLACK 0x07
#define MAX_COLS 80
#define MAX_ROWS 25

unsigned int cursor_x = 0;
unsigned int cursor_y = 0;

void print_string(const char *str) {
    char *vidptr = (char *)VIDEO_MEMORY;

    while (*str) {
        if (*str == '\n') {
            cursor_x = 0;
            cursor_y++;
        } else {
            vidptr[(cursor_y * MAX_COLS + cursor_x) * 2] = *str;
            vidptr[(cursor_y * MAX_COLS + cursor_x) * 2 + 1] = WHITE_ON_BLACK;
            cursor_x++;
        }

        if (cursor_x >= MAX_COLS) {
            cursor_x = 0;
            cursor_y++;
        }

        if (cursor_y >= MAX_ROWS) {
            cursor_y = 0; // Можно добавить логику для прокрутки вверх
        }

        str++;
    }
}

void main() {
    print_string("Hello from the kernel!");
    print_string("This is a 16-bit system.");
    print_string("8086-kernel 0.0.3.");
}
