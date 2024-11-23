// Определяем адрес видеопамяти
#define VIDEO_MEMORY 0xB8000
#define WHITE_ON_BLACK 0x07

// Функция для вывода строки на экран
void print_string(const char *str) {
    char *vidptr = (char *)VIDEO_MEMORY; // Указатель на видеопамять
    unsigned int i = 0;

    // Заполняем видеопамять
    while (str[i] != '\0') {
        vidptr[i * 2] = str[i];      // Символ
        vidptr[i * 2 + 1] = WHITE_ON_BLACK; // Атрибут (светлый текст на темном фоне)
        i++;
    }
}

// Основная функция ядра
void kernel_main() {
    print_string("Hello from the kernel!");
    print_stirng("8086-kernel 0.0.3")

    // Бесконечный цикл
    while (1) {}
}
