
#include <windows.h>
#include <stdio.h>

HANDLE hConsole;

void set_color(int fg, int bg) {
    SetConsoleTextAttribute(hConsole, (bg << 4) | fg);
}

void process_ansi(const char *str) {
    while (*str) {
        if (*str == 27 && *(str+1) == '[') {
            str += 2;
            int fg = 7, bg = 0;

            while (*str && *str != 'm') {
                int code = atoi(str);

                if (code >= 30 && code <= 37)
                    fg = code - 30;
                if (code >= 40 && code <= 47)
                    bg = code - 40;

                while (*str && *str != ';' && *str != 'm') str++;
                if (*str == ';') str++;
            }

            if (*str == 'm') {
                set_color(fg, bg);
                str++;
            }
        } else {
            putchar(*str);
            str++;
        }
    }
}

int main() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), stdin)) {
        process_ansi(buffer);
    }

    return 0;
}