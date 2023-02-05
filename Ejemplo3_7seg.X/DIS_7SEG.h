/* 
 * File:   7SEG.h
 * Author: gssan
 *
 * Created on 5 de febrero de 2023, 03:56 PM
 */

#ifndef DIS_7SEG_H
#define	DIS_7SEG_H

#include <stdint.h>

typedef struct{

    uint8_t a;//RA3
    uint8_t b;//RA4
    uint8_t c;//RE2
    uint8_t d;//RC7
    uint8_t e;//RD0
    uint8_t f;//RD1
    uint8_t g;//RD2

}Display7Seg;

void Write_Display7seg(Display7Seg *D7S,uint8_t val);
void Reset_Display7seg(void);
#endif	/* DIS_7SEG_H */

