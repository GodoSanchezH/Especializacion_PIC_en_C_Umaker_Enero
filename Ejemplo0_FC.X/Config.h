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
void HMI_WRITE_DATA(int *ID,char *string,uint8_t X_pos,uint8_t Y_pos);

/* CON RETORNO - CON ENTRADA DE PARAMETROS*/
float PID_Calculo(float *Planta,float ref,float feedback);

#endif	/* CONFIG_H */

