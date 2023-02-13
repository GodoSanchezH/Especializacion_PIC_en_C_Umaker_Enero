/* 
 * File:   TIMER.h
 * Author: gssan
 *
 * Created on 12 de febrero de 2023, 04:29 PM
 */

#ifndef TIMER_H
#define	TIMER_H

typedef enum{
    Timer_8bit=0,
    Timer_16bit
}timerMod;

void TimerInit(timerMod MT);


#endif	/* TIMER_H */

