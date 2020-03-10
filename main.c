//
//  main.c
//  TerminalClock
//
//  Created by Leo Hofer on 05.03.20.
//  Copyright © 2020 Leo Hofer. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "clock.h"

short int output[11] = {0, 11, 0, 10, 0, 11, 0, 10, 0, 11, 0};
short int sec_before;



int main() {
    while (1) {
        time_t T = time(NULL);
        struct tm tm = *localtime(&T);
        
        if(sec_before != tm.tm_sec) {
            output[0] = tm.tm_hour / 10;
            output[2] = tm.tm_hour % 10;
            output[4] = tm.tm_min / 10;
            output[6] = tm.tm_min % 10;
            output[8] = tm.tm_sec / 10;
            output[10] = tm.tm_sec % 10;
            
            system("clear");
            
            for(int i = 0; i < 5; i++) {
                for(int j = 0;j < 11; j++) {
                    printf("%s", characters[output[j]][i]);
                }
                printf("\n");
            }
            sec_before = tm.tm_sec;
        }
    }
}
