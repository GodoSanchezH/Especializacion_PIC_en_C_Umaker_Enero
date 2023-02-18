/* 
 * File:   Interrupt.h
 * Author: gssan
 *
 * Created on 5 de febrero de 2023, 04:57 PM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

void Interrupt_Config(void);
void __interrupt(irq(IRQ_INT0),base(0x400),high_priority) HP_ISR(void);
void __interrupt(irq(IRQ_INT1),base(0x400),low_priority) DEFAULT_ISR(void);

#endif	/* INTERRUPT_H */

