/*
    Time and Date using internal Pico RTC on 16x2 8bit interface LCD Displays
	using HD44780 chips on the Raspberry Pi Pico!
	"Copyright (c) 2021 Flo-riN (https://github.com/flo-rin/)

*/

#ifndef _PICO_TD_H
#define _PICO_TD_H

#include "pico.h"

void dt_to_str(char *buf, uint buf_size, const datetime_t *t);  // avoiding datetime.h SDK

#endif
