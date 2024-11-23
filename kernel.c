#include <stdint.h>

#if defined(__i386__) || defined(__x86_64__) // Для 32-битных и 64-битных систем
#include <stdio.h>
#include <stdlib.h>

// Функция для вывода строки на экран в 32-битной/64-битной системе
void print_string(const char *str) {
    // В современных системах используем стандартный вывод
    printf("%s\n", str);
}

#else // Для 16-битных систем

#define VIDEO_MEMORY 0xB8000
#define WHITE_ON_BLACK 0x07
#define MAX_COLS 80
#define MAX_ROWS 25

unsigned int cursor_x = 0;
unsigned int cursor_y = 0;

// Функция для вывода строки на экран в 16-битной системе
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

#endif

// Основная функция
int main() {
    print_string("Hello from the kernel!");

    #if defined(__i386__) || defined(__x86_64__)
    print_string("This is a 32-bit or 64-bit system.");
    #else
    print_string("This is a 16-bit system.");
    #endif

    return 0;
}
