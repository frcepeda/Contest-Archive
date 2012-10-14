//
//  main.c
//  Contest Timing
//
//  Created by Freddy Roman Cepeda on 11/13/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

#define minsInDay 24*60
#define minsInHour 60

FILE *in;
FILE *out;

int main (int argc, const char * argv[])
{
    in = fopen("ctiming.in", "r");
    out = fopen("ctiming.out", "w");
    
    int day, hour, min, total = 0;
    fscanf(in, "%d %d %d", &day, &hour, &min);
    
    if (day > 11 || (day == 11 && (hour > 11 || (hour == 11 && min >= 11)))) {
        total += (day - 11) * minsInDay;
        total += (hour - 11) * minsInHour;
        total += (min - 11);
    } else {
        total = -1;
    }
    
    fprintf(out, "%d\n", total);
    
    return 0;
}

