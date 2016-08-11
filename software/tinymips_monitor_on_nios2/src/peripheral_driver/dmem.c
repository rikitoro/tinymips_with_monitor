/*
 * dmem.c
 *
 *  Created on: 2016/07/18
 *      Author: yoshiaki
 */

#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "dmem.h"

void assert_dmem_we() {
  IOWR_ALTERA_AVALON_PIO_DATA(DMEM_WE_BASE, 1);
};

void negate_dmem_we() {
  IOWR_ALTERA_AVALON_PIO_DATA(DMEM_WE_BASE, 0);
};

void assert_dmem_clk() {
  IOWR_ALTERA_AVALON_PIO_DATA(DMEM_CLK_BASE, 1);
};

void negate_dmem_clk() {
  IOWR_ALTERA_AVALON_PIO_DATA(DMEM_CLK_BASE, 0);
};

////////
void dmem_wd(int addr, int data) {
  IOWR_ALTERA_AVALON_PIO_DATA(DMEM_ADDR_BASE, addr);
  IOWR_ALTERA_AVALON_PIO_DATA(DMEM_WD_BASE, data);
  assert_dmem_we();
  assert_dmem_clk();
  negate_dmem_clk();
  negate_dmem_we();
}

int dmem_rd(int addr) {
  IOWR_ALTERA_AVALON_PIO_DATA(DMEM_ADDR_BASE, addr);
  assert_dmem_clk();
  negate_dmem_clk();
  return IORD_ALTERA_AVALON_PIO_DATA(DMEM_RD_BASE);
}
