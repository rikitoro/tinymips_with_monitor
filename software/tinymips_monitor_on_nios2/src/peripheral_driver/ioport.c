/*
 * ioport.c
 *
 *  Created on: 2016/08/09
 *      Author: yoshiaki
 */

#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "ioport.h"

void iport_wd(int data) {
  IOWR_ALTERA_AVALON_PIO_DATA(IPORT3_DATA_BASE, data);
}

int oport_rd() {
  return IORD_ALTERA_AVALON_PIO_DATA(OPORT3_DATA_BASE);
}

#include "ioport.h"


