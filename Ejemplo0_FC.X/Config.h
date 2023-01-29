/* 
 * File:   Config.h
 * Author: HP
 *
 * Created on 29 de enero de 2023, 04:32 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#include <stdint.h>

#define FOSC 64000000UL
#define __XTAL_FREQ FOSC/4


/* SIN RETORNO - SIN ENTRADA DE PARAMETROS*/
void WriteData(void);

/* CON RETORNO - SIN ENTRADA DE PARAMETROS*/
uint8_t HTTP_Post(void);

/* SIN RETORNO - CON ENTRADA DE PARAMETROS*/


/* CON RETORNO - CON ENTRADA DE PARAMETROS*/


#endif	/* CONFIG_H */

