#include <string.h>

#include <stdio.h>
#include <switch.h>

int main(int argc, char **argv)
{
    // Initialize console. Using NULL as the second argument tells the console
    // library to use the internal console structure as current one.
    consoleInit(NULL);

    // Configure our supported input layout: a single player with standard
    // controller styles.
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well
    // as the first connected controller).
    PadState pad;
    padInitializeDefault(&pad);

    // Move the cursor to row 16 and column 20 before printing the message.
    // "\x1b[16;20H" is an ANSI escape code: 16 is the screen row, 20 is
    // the screen column, and H tells the console to move the cursor there.
    // "\x1b[31m" changes the text color to red. The number 31 is the
    // ANSI color code for red foreground text.
    // "\x1b[1m" turns on bold/bright text, which makes the console text
    // look just a pinch bigger and easier to see.
    // "\x1b[0m" resets the style after the message so later text is normal.
    printf("\x1b[16;20H\x1b[31m\x1b[1mHello from TestNX!\x1b[0m");

    while (appletMainLoop()) {
        // Scan the gamepad. This should be done once for each frame.
        padUpdate(&pad);

        // padGetButtonsDown returns the set of buttons that have been newly
        // pressed in this frame compared to the previous one.
        u64 kDown = padGetButtonsDown(&pad);
        if (kDown & HidNpadButton_Plus) {
            break;
        }

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
