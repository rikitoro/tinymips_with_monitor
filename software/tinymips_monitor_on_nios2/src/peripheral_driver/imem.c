/*
 * imem.c
 *
 *  Created on: 2016/07/17
 *      Author: yoshiaki
 */

#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "imem.h"

void assert_imem_we() {
  IOWR_ALTERA_AVALON_PIO_DATA(IMEM_WE_BASE, 1);
};

void negate_imem_we() {
  IOWR_ALTERA_AVALON_PIO_DATA(IMEM_WE_BASE, 0);
};

void assert_imem_clk() {
  IOWR_ALTERA_AVALON_PIO_DATA(IMEM_CLK_BASE, 1);
};

void negate_imem_clk() {
  IOWR_ALTERA_AVALON_PIO_DATA(IMEM_CLK_BASE, 0);
};

////////
void imem_wd(int addr, int data) {
  IOWR_ALTERA_AVALON_PIO_DATA(IMEM_ADDR_BASE, addr);
  IOWR_ALTERA_AVALON_PIO_DATA(IMEM_WD_BASE, data);
  assert_imem_we();
  assert_imem_clk();
  negate_imem_clk();
  negate_imem_we();
}

int imem_rd(int addr) {
  IOWR_ALTERA_AVALON_PIO_DATA(IMEM_ADDR_BASE, addr);
  assert_imem_clk();
  negate_imem_clk();
  return IORD_ALTERA_AVALON_PIO_DATA(IMEM_RD_BASE);
}
