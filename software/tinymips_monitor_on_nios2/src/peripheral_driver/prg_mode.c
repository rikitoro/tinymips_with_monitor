/*
 * prg_mode.c
 *
 *  Created on: 2016/07/21
 *      Author: yoshiaki
 */

#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "prg_mode.h"

void assert_prg_mode() {
  IOWR_ALTERA_AVALON_PIO_DATA(PRG_MODE_BASE, 1);
}

void negate_prg_mode() {
  IOWR_ALTERA_AVALON_PIO_DATA(PRG_MODE_BASE, 0);
}


