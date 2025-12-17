// lyrics_styled.c
// Compile: gcc lyrics_styled.c -o lyrics.exe
// Run: chcp 65001 && .\lyrics.exe

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// 🪄 Function to print colored line with typing animation
void type_line_utf8(const char *utf8_line, int delay_ms, int color) {
    if (!utf8_line) return;

    // Convert UTF-8 to UTF-16
    int needed = MultiByteToWideChar(CP_UTF8, 0, utf8_line, -1, NULL, 0);
    if (needed <= 0) return;
    wchar_t *wbuf = (wchar_t*) malloc(sizeof(wchar_t) * needed);
    MultiByteToWideChar(CP_UTF8, 0, utf8_line, -1, wbuf, needed);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written = 0;

    // Set color
    SetConsoleTextAttribute(hOut, color);

    // Type out the line
    for (int i = 0; wbuf[i] != L'\0'; ++i) {
        WriteConsoleW(hOut, &wbuf[i], 1, &written, NULL);
        Sleep(delay_ms);
    }

    // Reset color and add newline
    SetConsoleTextAttribute(hOut, 7);
    wchar_t nl = L'\n';
    WriteConsoleW(hOut, &nl, 1, &written, NULL);

    free(wbuf);
}

// 🌟 Fancy center printing (title style)
void print_center(const char *text, int color) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int len = MultiByteToWideChar(CP_UTF8, 0, text, -1, NULL, 0) - 1;
    int pad = (width - len) / 2;
    for (int i = 0; i < pad; i++) printf(" ");

    SetConsoleTextAttribute(hOut, color);
    type_line_utf8(text, 1, color);
    SetConsoleTextAttribute(hOut, 7);
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const char *lyrics[] = {
        "Toke dekhi shunshaan raate",
        "Jwole asa chinta hotat e",
        "Shanto oshanto shomoye",
        "Tui keno thakis na saathe",
        "Borbaad hoyechi ami tor opekkhay",
        "Churmar kore de aaro kichu isharay",
        "Amake thakte de dube",
        "Daakte de tor naam dhore",
        "Amake rasta bol kono astana kono bondore",
        "Bole de.... Bol aamay",
        "Bole de.... Bol aamay"
    };

    int num_lines = sizeof(lyrics) / sizeof(lyrics[0]);
    int char_delay_ms = 35;
    int line_delays[] = {1500, 1200, 2000, 1800, 1500, 1600, 1500, 1800, 2000, 1800, 1500};

    // ✨ Title
    print_center("💫 Now Playing: Borbaad Hoyechi Ami 💫", 11); // light cyan
    Sleep(1500);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // 🎶 Animated Lyrics
    for (int i = 0; i < num_lines; ++i) {
        int color;
        // alternate colors for variety
        if (i % 3 == 0) color = 10;   // Green
        else if (i % 3 == 1) color = 14; // Yellow
        else color = 13;               // Magenta

        type_line_utf8(lyrics[i], char_delay_ms, color);
        Sleep(line_delays[i]);
    }

    // 🌙 Ending with fade-out
    Sleep(1000);
    print_center("✨ End of Song ✨", 12);
    Sleep(800);

    // Small sparkle animation
    for (int i = 0; i < 3; i++) {
        SetConsoleTextAttribute(hOut, 13 + i);
        printf("\r🎵 Thank you for listening 🎵   ");
        Sleep(400);
        printf("\r                          ");
        Sleep(400);
    }
    SetConsoleTextAttribute(hOut, 7);
    printf("\n\n");

    return 0;
}
