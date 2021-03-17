#include "td.h"

// workaround for "pico/util/datetime.c" since we use a smaller 16x2 lcd and we need to fit the info

/*
        Time and Date using internal Pico RTC on 16x2 8bit interface LCD Displays
	using HD44780 chips on the Raspberry Pi Pico!
	"Copyright (c) 2021 Flo-riN (https://github.com/flo-rin/)
*/
#include <stdio.h>

static const char *DATETIME_MONTHS[12] = {
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec"
};

static const char *DATETIME_DOWS[7] = {
        "Sun",
        "Mon",
        "Tue",
        "Wed",
        "Thu",
        "Fri",
        "Sat",
};


void dt_to_str(char *buf, uint buf_size, const datetime_t *t) {
    snprintf(buf,
             buf_size,
             "    %02d:%02d:%02d     %s %02d %s %d", // 16x2 lcd only
             t->hour,
             t->min,
             t->sec,
             DATETIME_DOWS[t->dotw],
             t->day,
             DATETIME_MONTHS[t->month - 1],
             t->year);
};