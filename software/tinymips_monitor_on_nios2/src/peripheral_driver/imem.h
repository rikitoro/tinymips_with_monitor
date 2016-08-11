/*
 * imem.h
 *
 *  Created on: 2016/07/17
 *      Author: yoshiaki
 */

#ifndef IMEM_H_
#define IMEM_H_

void assert_imen_clk();
void negate_imem_clk();
void assert_imen_we();
void negate_imem_we();
int  imem_rd(int addr);
void imem_wd(int addr, int data);

#endif /* IMEM_H_ */
