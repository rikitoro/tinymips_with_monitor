/*
 * dmem.h
 *
 *  Created on: 2016/07/17
 *      Author: yoshiaki
 */

#ifndef DMEM_H_
#define DMEM_H_

void assert_dmen_clk();
void negate_dmem_clk();
void assert_dmen_we();
void negate_dmem_we();
int  dmem_rd(int addr);
void dmem_wd(int addr, int data);

#endif /* DMEM_H_ */
