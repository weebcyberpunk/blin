#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * author GG weebcyberpunk@gmail.com
 * version 1.0.1
 * since Mar 11, 2022
 */

/*
 * Copyright 2022 © GG
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software and associated documentation files (the “Software”), to deal 
 * in the Software without restriction, including without limitation the rights to 
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
 * of the Software, and to permit persons to whom the Software is furnished to do 
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
 * SOFTWARE.
 */

// prints num chars from *bp
int print_buf(char *bp, unsigned long num, FILE *output) {
    for (unsigned long count = 0; count < num; count++)
        fprintf(output, "%c", bp[count]);

    return(0);
}

int main(int argc, char *argv[]) {

    char c;
    unsigned long lw;
    unsigned long length = 0;
    unsigned long wlength = 0;
    unsigned long last_blank = 0;
    char *lbuf;
    char *wbuf;
    short newline_from_before = 0;
    FILE *in;
    FILE *out;

    // get fw
    if (argc > 1) {
        lw = atoi(argv[1]);

    } else {
        fprintf(stderr, "Please specify line width.\n");
        return(1);

    }

    // get files
    in = stdin;
    out = stdout;

    if (argc >= 4) {
        if (strcmp(argv[2], "-") != 0) in = fopen(argv[2], "r");
        if (strcmp(argv[3], "-") != 0) out = fopen(argv[3], "w");

    } else if (argc == 3) {
        if (strcmp(argv[2], "-") != 0) in = fopen(argv[2], "r");

    }

    // alloc memory
    lbuf = malloc(lw);
    wbuf = malloc(lw);

    // main loop
    for (;;) {
        c = getc(in);

        if (c == '\n' || c == EOF) {
            if (c == '\n')
                if (newline_from_before) continue;

            // prints buffer and resets vars
            print_buf(lbuf, length, out);
            fprintf(out, "\n");
            length = 0;
            wlength = 0;
            last_blank = 0;

            if (c == EOF) break;

        } else if (c == ' ') {
            // sets last_blank and resets wlength,
            // increases length and adds new char
            last_blank = last_blank + wlength + 1;
            wlength = 0;

            lbuf[length] = c;
            length++;

        } else {
            // moves new char and increases vars
            wbuf[wlength] = c;
            wlength++;

            lbuf[length] = c;
            length++;
        }

        if ((length == lw) && (c != '\n')) {
            // if word > lw
            if (wlength == lw) {
                print_buf(lbuf, length, out);
                fprintf(out, "\n");
                newline_from_before = 1;

                length = 0;
                wlength = 0;
                last_blank = 0;

            // prints buffer
            } else {
                print_buf(lbuf, last_blank, out);
                fprintf(out, "\n");
                newline_from_before = 1;

                // resets vars
                length = 0;
                last_blank = 0;

                // adds word to lbuf
                for (int count = 0; count < wlength; count++) {
                    lbuf[count] = wbuf[count];
                    length++;

                }
            }

            continue;
        }

        newline_from_before = 0;
    }

    return(0);
}
