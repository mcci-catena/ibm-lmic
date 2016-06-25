/*******************************************************************************
 * Copyright (c) 2014-2015 IBM Corporation.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    IBM Zurich Research Lab - initial API, implementation and documentation
 *******************************************************************************/

#include "oslmic.h"
#include "stm32l1xx.h"

// GPIO by port number (A=0, B=1, ..)
#define GPIOx(no) ((GPIO_TypeDef*) (GPIOA_BASE + (no)*(GPIOB_BASE-GPIOA_BASE)))

// GPIOCFG macros
#define GPIOCFG_AF_MASK        0x000F
#define GPIOCFG_MODE_SHIFT      4
#define GPIOCFG_MODE_MASK      (3<<GPIOCFG_MODE_SHIFT)
#define GPIOCFG_MODE_INP       (0<<GPIOCFG_MODE_SHIFT)
#define GPIOCFG_MODE_OUT       (1<<GPIOCFG_MODE_SHIFT)
#define GPIOCFG_MODE_ALT       (2<<GPIOCFG_MODE_SHIFT)
#define GPIOCFG_MODE_ANA       (3<<GPIOCFG_MODE_SHIFT)
#define GPIOCFG_OSPEED_SHIFT    6
#define GPIOCFG_OSPEED_MASK    (3<<GPIOCFG_OSPEED_SHIFT)
#define GPIOCFG_OSPEED_400kHz  (0<<GPIOCFG_OSPEED_SHIFT)
#define GPIOCFG_OSPEED_2MHz    (1<<GPIOCFG_OSPEED_SHIFT)
#define GPIOCFG_OSPEED_10MHz   (2<<GPIOCFG_OSPEED_SHIFT)
#define GPIOCFG_OSPEED_40MHz   (3<<GPIOCFG_OSPEED_SHIFT)
#define GPIOCFG_OTYPE_SHIFT     8
#define GPIOCFG_OTYPE_MASK     (1<<GPIOCFG_OTYPE_SHIFT)
#define GPIOCFG_OTYPE_PUPD     (0<<GPIOCFG_OTYPE_SHIFT)
#define GPIOCFG_OTYPE_OPEN     (1<<GPIOCFG_OTYPE_SHIFT)
#define GPIOCFG_PUPD_SHIFT      9
#define GPIOCFG_PUPD_MASK      (3<<GPIOCFG_PUPD_SHIFT)
#define GPIOCFG_PUPD_NONE      (0<<GPIOCFG_PUPD_SHIFT)
#define GPIOCFG_PUPD_PUP       (1<<GPIOCFG_PUPD_SHIFT)
#define GPIOCFG_PUPD_PDN       (2<<GPIOCFG_PUPD_SHIFT)
#define GPIOCFG_PUPD_RFU       (3<<GPIOCFG_PUPD_SHIFT)

// IRQ triggers (same values as in Moterunner!)
#define GPIO_IRQ_MASK          0x38
#define GPIO_IRQ_FALLING       0x20
#define GPIO_IRQ_RISING        0x28
#define GPIO_IRQ_CHANGE        0x30

// configure operation mode of GPIO pin
void hw_cfg_pin (GPIO_TypeDef* gpioport, u1_t pin, u2_t gpiocfg);

// set state of GPIO output pin
void hw_set_pin (GPIO_TypeDef* gpioport, u1_t pin, u1_t state);

// configure given line as external interrupt source (EXTI handler)
void hw_cfg_extirq (u1_t portidx, u1_t pin, u1_t irqcfg);
