#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/rtc.h"
#include "pico/binary_info.h"
#include "pico/util/datetime.h"
#include "td.h" // workaround for pico/util/datetime.h to correctly displaying time and date on 16x2 LCD. (!)
#include "LCDops.h"
#include "generalOps.h"
#include "presetChars.h"


/*
	Time and Date using internal Pico RTC on 16x2 8bit interface LCD Displays
	using HD44780 chips on the Raspberry Pi Pico!
	"Copyright (c) 2021 Flo-riN (https://github.com/flo-rin/)
	
	** NOT USING I2C LCD INTERFACE, PLEASE FOLLOW @zadi15 TO PROPERLY CONNECT THE LCD TO Pico!!!
*/

/*
	8bit interface LCD display Copyright (c) 2021, zadi15 (https://github.com/zadi15/)
=*/


int LCDpins[14] = {0,1,2,3,4,5,6,7,15,16,17,16,2};

int main(){
    bi_decl(bi_program_description("Time and Date using internal Pico RealTimeClock on 16x2 8bit interface LCD Displays using HD44780 chips on the Raspberry Pi Pico!"));

    stdio_init_all();
    char datetime_buf[256];
    char *datetime_str = &datetime_buf[0];
	
	
	// TODO : compare internal RTC clock with RTC setup

    // Setting time and displaying:
	//
	//		  14:00:00 
	//		We 17 Ma 2021
    //
	
     datetime_t t = {
            .hour  = 14,
            .min   = 00,
            .sec   = 00,
            .dotw  = 3, // 0 is Sunday
            .day   = 17,
            .month = 3,
            .year  = 2021
    };

	// TODO: some sketchy things (buttons to set the clock and date) 

    // intializing RTC

    rtc_init();

    // setting time and date on internal RTC

    rtc_set_datetime(&t);

    // End RTC initialization
	
	
    // Initialize all needed pins as defined in LCDpins, set them as
    // outputs and then pull them low
 
    for(int gpio = 0; gpio < 11; gpio++){
        gpio_init(LCDpins[gpio]);
        gpio_set_dir(LCDpins[gpio], true);
        gpio_put(LCDpins[gpio], false);
    }

    //Initialize and clear the LCD, prepping it for characters / instructions
 
    LCDinit();

    while (1) {	
        LCDgoto("00");
        // reading RTC 
        rtc_get_datetime(&t);
        dt_to_str(datetime_str, sizeof(datetime_buf), &t); 
        //displaying time and date
        LCDwriteMessage(datetime_str);
        sleep_ms(350); //  yeah, it sucks, this is not an atomic clock. 
    }

 return 0;
}