/*
 * This provides simple bussy loop sleep functionality, these functions are not
 * 100% correct and can't be used incrementally for example for clock loop but
 * are precise enough to be used as wait loop for hardware initalization and
 * because of set_crystal_speed() are independent from crystal.
 *
 */

#ifndef __SLEEP_H__
#define __SLEEP_H__

/* To be sure to have uint16_t */
#include <stdint.h>

/*
 * Sleep for time in seconds. Maximal time
 * is 256 seconds.
 */
void sleep_s(uint8_t time);

/*
 * Sleeps for time miliseconds. Maximal time is
 * about 2^16/10^3 = aprox. 65 seconds.
 */
void sleep_ms(uint16_t time);

/*
 * Sleeps for time in micro seconds.
 */
void sleep_us(uint16_t time);


#endif /* __SLEEP_H__ */
