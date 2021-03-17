cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(picoLCDclock)

pico_sdk_init()

add_executable(
    picoLCDclock
    main.c
    LCDops.c
    generalOps.c
    presetChars.c
	td.c
)

pico_enable_stdio_usb(picoLCDclock 1)
pico_enable_stdio_uart(picoLCDclock 1)

pico_add_extra_outputs(picoLCDclock)

target_link_libraries(picoLCDclock pico_stdlib hardware_rtc)
