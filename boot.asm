[bits 16]
org 0x7C00

start:
    ; Устанавливаем сегмент данных
    xor ax, ax
    mov ds, ax

    ; Загружаем ядро в память
    mov si, kernel_data
    mov di, 0x1000       ; Загружаем ядро по адресу 0x1000
    mov cx, kernel_size  ; Количество байт для копирования
    rep movsb            ; Копируем наше ядро

    ; Переходим в защищенный режим/вызов C кода
    jmp 0x1000          ; Переход к ядру

kernel_data db 0       ; Раздел, где будет храниться данные ядра
kernel_size db 0       ; Размер ядра, необходимо установить на этапе загрузки

times 510 - ($ - $$) db 0
dw 0xAA55
