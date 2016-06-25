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

// intialize debug library
void debug_init (void);

// set LED state
void debug_led (u1_t val);

// write character to USART
void debug_char (u1_t c);

// write byte as two hex digits to USART
void debug_hex (u1_t b);

// write buffer as hex dump to USART
void debug_buf (const u1_t* buf, u2_t len);

// write 32-bit integer as eight hex digits to USART
void debug_uint (u4_t v);

// write nul-terminated string to USART
void debug_str (const u1_t* str);

// write LMiC event name to USART
void debug_event (int ev);

// write label and 32-bit value as hex to USART
void debug_val (const u1_t* label, u4_t val);
