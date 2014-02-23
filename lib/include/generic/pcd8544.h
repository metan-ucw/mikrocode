/*****************************************************************************
 * This file is part of Mikrocode library.                                   *
 *                                                                           *
 * Mikrocode project is free software; you can redistribute it and/or        *
 * modify it under the terms of the GNU Lesser General Public                *
 * License as published by the Free Software Foundation; either              *
 * version 2.1 of the License, or (at your option) any later version.        *
 *                                                                           *
 * Mikrocode is distributed in the hope that it will be useful,              *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Lesser General Public License for more details.                           *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public          *
 * License along with Mikrocode; if not, write to the Free Software          *
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,                        *
 * Boston, MA  02110-1301  USA                                               *
 *                                                                           *
 * Copyright (C) 2009-2014 Cyril Hrubis <metan@ucw.cz>                       *
 *                                                                           *
 *****************************************************************************/

 /*

   Nokia 5110 (pcd8544) LCD driver. See pcd8544.c for details.

  */

#ifndef __PCD8544_H__
#define __PCD8544_H__

#include <stdint.h>

/* Power down the the chip */
#define PCD8544_POWER_DOWN    0x24
/* Horizontal vs vertical addressing */
#define PCD8544_ADDRESS_VERT  0x22
#define PCD8544_ADDRESS_EXT_CMD 0x21
#define PCD8544_ADDRESS_BASIC_CMD 0x20

/* Basic commands */

#define PCD8544_CMD_BLANK      0x08
#define PCD8544_CMD_NORM_MODE  0x0c
#define PCD8544_CMD_INV_MODE   0x0d
#define PCD8544_CMD_SET_Y(y) (0x20 | (y & 0x07))
#define PCD8544_CMD_SET_X(x) (0x40 | (x & 0x3f))

/* Extended Commands */

/* Temperature compenstation 0 - 3 */
#define PCD8544_CMD_TEPM_CTL(tc) (0x04 | (tc & 0x03))
/* Sets Bias system */
#define PCD8544_CMD_BIAS(bs) (0x10 | (bs & 0x07))
/* Sets V_OP register 7 bit constrast */
#define PCD8544_CMD_VOP(vop) (0x80 | (vop & 0x7f))

/*
 * Resets display controller.
 */
void pcd8544_reset(void);

/*
 * Initialize I/O and display, must be called first
 */
void pcd8544_init(void);

/*
 * Clears the display with data byte.
 */
void pcd8544_clear(uint8_t data);

/*
 * Writes cmd to the display controllers
 */
void pcd8544_cmd(uint8_t cmd);

/*
 * Writes bytes of the data to the screen
 */
void pcd8544_write(uint8_t data);

#endif /* __PCD8544_H__ */
