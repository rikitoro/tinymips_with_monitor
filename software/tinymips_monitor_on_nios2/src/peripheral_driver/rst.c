/*
 * reset_n.c
 *
 *  Created on: 2016/07/21
 *      Author: yoshiaki
 */

#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "rst.h"

void assert_rst() {
  IOWR_ALTERA_AVALON_PIO_DATA(RST_BASE, 1);
}
void negate_rst() {
  IOWR_ALTERA_AVALON_PIO_DATA(RST_BASE, 0);
}

