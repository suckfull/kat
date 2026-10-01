/*
 * Kat - a cat clone that sucks more
 * Copyright (C) 2026 Goose
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#define _DEFAULT_SOURCE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int cycle(char x)
{
    printf("\nproceed?\n");
    char input[10];
    if (scanf("%9s", input) == 1 && strcmp(input, "yes") == 0) {
        fputc(x, stdout);
    }
    else if (strcmp(input, "no") == 0) {
        fprintf(stderr, "no has failed. manual intervention necessary\n");
        return 1;
    }
    else {
        fprintf(stderr, "invalid input");
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    bool cycle_flag = false;
    int rand_int = rand() % 5 + 1;
    char *file_path = "";

    if (argc < 2) {
        fprintf(stderr, "thinking...\n");
        sleep(10);
        fprintf(stderr, "Usage: %s <your file>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--cycle") == 0) {
            cycle_flag = true;
        }
        else if (argv[i][0] != '-') {
            file_path = argv[i];
        }
        else {
            fprintf(stderr, "Kat: ERROR: invalid flag\n");
            return 1;
        }
    }

    FILE *fptr = fopen(file_path, "r");
    if (fptr == NULL) {
        perror("Kat: ERROR: ");
        fprintf(stderr, "tip: consider visiting pointerpointer.com\n");
        return 1;
    }

    if (rand_int == 5) {
        fprintf(stderr, "Kat: ERROR: read deemed unnecessary\n");
        return 1;
    }

    if (cycle_flag) {
        char c;
        while (fread(&c, 1, 1, fptr) == 1) {
            cycle(c);
        }
    }
    else {
        char c;
        while (fread(&c, 1, 1, fptr) == 1) {
            fputc(c, stdout);
            usleep(10000);
        }
    }
    fclose(fptr);
    return 0;
}
