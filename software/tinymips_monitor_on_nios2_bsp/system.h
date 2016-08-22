/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_processor' in SOPC Builder design 'monitor'
 * SOPC Builder design path: ../../monitor.sopcinfo
 *
 * Generated: Mon Aug 22 14:12:40 JST 2016
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00000820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x10
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00008020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x10
#define ALT_CPU_NAME "nios2_processor"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00008000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00000820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x10
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00008020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x10
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00008000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_UART
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x500
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/uart"
#define ALT_STDIN_BASE 0x400
#define ALT_STDIN_DEV uart
#define ALT_STDIN_IS_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_uart"
#define ALT_STDOUT "/dev/uart"
#define ALT_STDOUT_BASE 0x400
#define ALT_STDOUT_DEV uart
#define ALT_STDOUT_IS_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_uart"
#define ALT_SYSTEM_NAME "monitor"


/*
 * dmem_addr configuration
 *
 */

#define ALT_MODULE_CLASS_dmem_addr altera_avalon_pio
#define DMEM_ADDR_BASE 0x120
#define DMEM_ADDR_BIT_CLEARING_EDGE_REGISTER 0
#define DMEM_ADDR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DMEM_ADDR_CAPTURE 0
#define DMEM_ADDR_DATA_WIDTH 32
#define DMEM_ADDR_DO_TEST_BENCH_WIRING 0
#define DMEM_ADDR_DRIVEN_SIM_VALUE 0
#define DMEM_ADDR_EDGE_TYPE "NONE"
#define DMEM_ADDR_FREQ 50000000
#define DMEM_ADDR_HAS_IN 0
#define DMEM_ADDR_HAS_OUT 1
#define DMEM_ADDR_HAS_TRI 0
#define DMEM_ADDR_IRQ -1
#define DMEM_ADDR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMEM_ADDR_IRQ_TYPE "NONE"
#define DMEM_ADDR_NAME "/dev/dmem_addr"
#define DMEM_ADDR_RESET_VALUE 0
#define DMEM_ADDR_SPAN 16
#define DMEM_ADDR_TYPE "altera_avalon_pio"


/*
 * dmem_clk configuration
 *
 */

#define ALT_MODULE_CLASS_dmem_clk altera_avalon_pio
#define DMEM_CLK_BASE 0x110
#define DMEM_CLK_BIT_CLEARING_EDGE_REGISTER 0
#define DMEM_CLK_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DMEM_CLK_CAPTURE 0
#define DMEM_CLK_DATA_WIDTH 1
#define DMEM_CLK_DO_TEST_BENCH_WIRING 0
#define DMEM_CLK_DRIVEN_SIM_VALUE 0
#define DMEM_CLK_EDGE_TYPE "NONE"
#define DMEM_CLK_FREQ 50000000
#define DMEM_CLK_HAS_IN 0
#define DMEM_CLK_HAS_OUT 1
#define DMEM_CLK_HAS_TRI 0
#define DMEM_CLK_IRQ -1
#define DMEM_CLK_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMEM_CLK_IRQ_TYPE "NONE"
#define DMEM_CLK_NAME "/dev/dmem_clk"
#define DMEM_CLK_RESET_VALUE 0
#define DMEM_CLK_SPAN 16
#define DMEM_CLK_TYPE "altera_avalon_pio"


/*
 * dmem_rd configuration
 *
 */

#define ALT_MODULE_CLASS_dmem_rd altera_avalon_pio
#define DMEM_RD_BASE 0x130
#define DMEM_RD_BIT_CLEARING_EDGE_REGISTER 0
#define DMEM_RD_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DMEM_RD_CAPTURE 0
#define DMEM_RD_DATA_WIDTH 32
#define DMEM_RD_DO_TEST_BENCH_WIRING 0
#define DMEM_RD_DRIVEN_SIM_VALUE 0
#define DMEM_RD_EDGE_TYPE "NONE"
#define DMEM_RD_FREQ 50000000
#define DMEM_RD_HAS_IN 1
#define DMEM_RD_HAS_OUT 0
#define DMEM_RD_HAS_TRI 0
#define DMEM_RD_IRQ -1
#define DMEM_RD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMEM_RD_IRQ_TYPE "NONE"
#define DMEM_RD_NAME "/dev/dmem_rd"
#define DMEM_RD_RESET_VALUE 0
#define DMEM_RD_SPAN 16
#define DMEM_RD_TYPE "altera_avalon_pio"


/*
 * dmem_wd configuration
 *
 */

#define ALT_MODULE_CLASS_dmem_wd altera_avalon_pio
#define DMEM_WD_BASE 0x140
#define DMEM_WD_BIT_CLEARING_EDGE_REGISTER 0
#define DMEM_WD_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DMEM_WD_CAPTURE 0
#define DMEM_WD_DATA_WIDTH 32
#define DMEM_WD_DO_TEST_BENCH_WIRING 0
#define DMEM_WD_DRIVEN_SIM_VALUE 0
#define DMEM_WD_EDGE_TYPE "NONE"
#define DMEM_WD_FREQ 50000000
#define DMEM_WD_HAS_IN 0
#define DMEM_WD_HAS_OUT 1
#define DMEM_WD_HAS_TRI 0
#define DMEM_WD_IRQ -1
#define DMEM_WD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMEM_WD_IRQ_TYPE "NONE"
#define DMEM_WD_NAME "/dev/dmem_wd"
#define DMEM_WD_RESET_VALUE 0
#define DMEM_WD_SPAN 16
#define DMEM_WD_TYPE "altera_avalon_pio"


/*
 * dmem_we configuration
 *
 */

#define ALT_MODULE_CLASS_dmem_we altera_avalon_pio
#define DMEM_WE_BASE 0x100
#define DMEM_WE_BIT_CLEARING_EDGE_REGISTER 0
#define DMEM_WE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DMEM_WE_CAPTURE 0
#define DMEM_WE_DATA_WIDTH 1
#define DMEM_WE_DO_TEST_BENCH_WIRING 0
#define DMEM_WE_DRIVEN_SIM_VALUE 0
#define DMEM_WE_EDGE_TYPE "NONE"
#define DMEM_WE_FREQ 50000000
#define DMEM_WE_HAS_IN 0
#define DMEM_WE_HAS_OUT 1
#define DMEM_WE_HAS_TRI 0
#define DMEM_WE_IRQ -1
#define DMEM_WE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMEM_WE_IRQ_TYPE "NONE"
#define DMEM_WE_NAME "/dev/dmem_we"
#define DMEM_WE_RESET_VALUE 0
#define DMEM_WE_SPAN 16
#define DMEM_WE_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * imem_addr configuration
 *
 */

#define ALT_MODULE_CLASS_imem_addr altera_avalon_pio
#define IMEM_ADDR_BASE 0x20
#define IMEM_ADDR_BIT_CLEARING_EDGE_REGISTER 0
#define IMEM_ADDR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IMEM_ADDR_CAPTURE 0
#define IMEM_ADDR_DATA_WIDTH 32
#define IMEM_ADDR_DO_TEST_BENCH_WIRING 0
#define IMEM_ADDR_DRIVEN_SIM_VALUE 0
#define IMEM_ADDR_EDGE_TYPE "NONE"
#define IMEM_ADDR_FREQ 50000000
#define IMEM_ADDR_HAS_IN 0
#define IMEM_ADDR_HAS_OUT 1
#define IMEM_ADDR_HAS_TRI 0
#define IMEM_ADDR_IRQ -1
#define IMEM_ADDR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define IMEM_ADDR_IRQ_TYPE "NONE"
#define IMEM_ADDR_NAME "/dev/imem_addr"
#define IMEM_ADDR_RESET_VALUE 0
#define IMEM_ADDR_SPAN 16
#define IMEM_ADDR_TYPE "altera_avalon_pio"


/*
 * imem_clk configuration
 *
 */

#define ALT_MODULE_CLASS_imem_clk altera_avalon_pio
#define IMEM_CLK_BASE 0x10
#define IMEM_CLK_BIT_CLEARING_EDGE_REGISTER 0
#define IMEM_CLK_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IMEM_CLK_CAPTURE 0
#define IMEM_CLK_DATA_WIDTH 1
#define IMEM_CLK_DO_TEST_BENCH_WIRING 0
#define IMEM_CLK_DRIVEN_SIM_VALUE 0
#define IMEM_CLK_EDGE_TYPE "NONE"
#define IMEM_CLK_FREQ 50000000
#define IMEM_CLK_HAS_IN 0
#define IMEM_CLK_HAS_OUT 1
#define IMEM_CLK_HAS_TRI 0
#define IMEM_CLK_IRQ -1
#define IMEM_CLK_IRQ_INTERRUPT_CONTROLLER_ID -1
#define IMEM_CLK_IRQ_TYPE "NONE"
#define IMEM_CLK_NAME "/dev/imem_clk"
#define IMEM_CLK_RESET_VALUE 0
#define IMEM_CLK_SPAN 16
#define IMEM_CLK_TYPE "altera_avalon_pio"


/*
 * imem_rd configuration
 *
 */

#define ALT_MODULE_CLASS_imem_rd altera_avalon_pio
#define IMEM_RD_BASE 0x30
#define IMEM_RD_BIT_CLEARING_EDGE_REGISTER 0
#define IMEM_RD_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IMEM_RD_CAPTURE 0
#define IMEM_RD_DATA_WIDTH 32
#define IMEM_RD_DO_TEST_BENCH_WIRING 0
#define IMEM_RD_DRIVEN_SIM_VALUE 0
#define IMEM_RD_EDGE_TYPE "NONE"
#define IMEM_RD_FREQ 50000000
#define IMEM_RD_HAS_IN 1
#define IMEM_RD_HAS_OUT 0
#define IMEM_RD_HAS_TRI 0
#define IMEM_RD_IRQ -1
#define IMEM_RD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define IMEM_RD_IRQ_TYPE "NONE"
#define IMEM_RD_NAME "/dev/imem_rd"
#define IMEM_RD_RESET_VALUE 0
#define IMEM_RD_SPAN 16
#define IMEM_RD_TYPE "altera_avalon_pio"


/*
 * imem_wd configuration
 *
 */

#define ALT_MODULE_CLASS_imem_wd altera_avalon_pio
#define IMEM_WD_BASE 0x40
#define IMEM_WD_BIT_CLEARING_EDGE_REGISTER 0
#define IMEM_WD_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IMEM_WD_CAPTURE 0
#define IMEM_WD_DATA_WIDTH 32
#define IMEM_WD_DO_TEST_BENCH_WIRING 0
#define IMEM_WD_DRIVEN_SIM_VALUE 0
#define IMEM_WD_EDGE_TYPE "NONE"
#define IMEM_WD_FREQ 50000000
#define IMEM_WD_HAS_IN 0
#define IMEM_WD_HAS_OUT 1
#define IMEM_WD_HAS_TRI 0
#define IMEM_WD_IRQ -1
#define IMEM_WD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define IMEM_WD_IRQ_TYPE "NONE"
#define IMEM_WD_NAME "/dev/imem_wd"
#define IMEM_WD_RESET_VALUE 0
#define IMEM_WD_SPAN 16
#define IMEM_WD_TYPE "altera_avalon_pio"


/*
 * imem_we configuration
 *
 */

#define ALT_MODULE_CLASS_imem_we altera_avalon_pio
#define IMEM_WE_BASE 0x0
#define IMEM_WE_BIT_CLEARING_EDGE_REGISTER 0
#define IMEM_WE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IMEM_WE_CAPTURE 0
#define IMEM_WE_DATA_WIDTH 1
#define IMEM_WE_DO_TEST_BENCH_WIRING 0
#define IMEM_WE_DRIVEN_SIM_VALUE 0
#define IMEM_WE_EDGE_TYPE "NONE"
#define IMEM_WE_FREQ 50000000
#define IMEM_WE_HAS_IN 0
#define IMEM_WE_HAS_OUT 1
#define IMEM_WE_HAS_TRI 0
#define IMEM_WE_IRQ -1
#define IMEM_WE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define IMEM_WE_IRQ_TYPE "NONE"
#define IMEM_WE_NAME "/dev/imem_we"
#define IMEM_WE_RESET_VALUE 0
#define IMEM_WE_SPAN 16
#define IMEM_WE_TYPE "altera_avalon_pio"


/*
 * iport3_data configuration
 *
 */

#define ALT_MODULE_CLASS_iport3_data altera_avalon_pio
#define IPORT3_DATA_BASE 0x300
#define IPORT3_DATA_BIT_CLEARING_EDGE_REGISTER 0
#define IPORT3_DATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IPORT3_DATA_CAPTURE 0
#define IPORT3_DATA_DATA_WIDTH 32
#define IPORT3_DATA_DO_TEST_BENCH_WIRING 0
#define IPORT3_DATA_DRIVEN_SIM_VALUE 0
#define IPORT3_DATA_EDGE_TYPE "NONE"
#define IPORT3_DATA_FREQ 50000000
#define IPORT3_DATA_HAS_IN 0
#define IPORT3_DATA_HAS_OUT 1
#define IPORT3_DATA_HAS_TRI 0
#define IPORT3_DATA_IRQ -1
#define IPORT3_DATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define IPORT3_DATA_IRQ_TYPE "NONE"
#define IPORT3_DATA_NAME "/dev/iport3_data"
#define IPORT3_DATA_RESET_VALUE 0
#define IPORT3_DATA_SPAN 16
#define IPORT3_DATA_TYPE "altera_avalon_pio"


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x500
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * onchip_memory configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory altera_avalon_onchip_memory2
#define ONCHIP_MEMORY_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY_BASE 0x8000
#define ONCHIP_MEMORY_CONTENTS_INFO ""
#define ONCHIP_MEMORY_DUAL_PORT 0
#define ONCHIP_MEMORY_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY_INIT_CONTENTS_FILE "monitor_onchip_memory"
#define ONCHIP_MEMORY_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY_IRQ -1
#define ONCHIP_MEMORY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY_NAME "/dev/onchip_memory"
#define ONCHIP_MEMORY_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY_SIZE_VALUE 8192
#define ONCHIP_MEMORY_SPAN 8192
#define ONCHIP_MEMORY_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY_WRITABLE 1


/*
 * oport3_data configuration
 *
 */

#define ALT_MODULE_CLASS_oport3_data altera_avalon_pio
#define OPORT3_DATA_BASE 0x310
#define OPORT3_DATA_BIT_CLEARING_EDGE_REGISTER 0
#define OPORT3_DATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define OPORT3_DATA_CAPTURE 0
#define OPORT3_DATA_DATA_WIDTH 32
#define OPORT3_DATA_DO_TEST_BENCH_WIRING 0
#define OPORT3_DATA_DRIVEN_SIM_VALUE 0
#define OPORT3_DATA_EDGE_TYPE "NONE"
#define OPORT3_DATA_FREQ 50000000
#define OPORT3_DATA_HAS_IN 1
#define OPORT3_DATA_HAS_OUT 0
#define OPORT3_DATA_HAS_TRI 0
#define OPORT3_DATA_IRQ -1
#define OPORT3_DATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define OPORT3_DATA_IRQ_TYPE "NONE"
#define OPORT3_DATA_NAME "/dev/oport3_data"
#define OPORT3_DATA_RESET_VALUE 0
#define OPORT3_DATA_SPAN 16
#define OPORT3_DATA_TYPE "altera_avalon_pio"


/*
 * prg_mode configuration
 *
 */

#define ALT_MODULE_CLASS_prg_mode altera_avalon_pio
#define PRG_MODE_BASE 0x200
#define PRG_MODE_BIT_CLEARING_EDGE_REGISTER 0
#define PRG_MODE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PRG_MODE_CAPTURE 0
#define PRG_MODE_DATA_WIDTH 1
#define PRG_MODE_DO_TEST_BENCH_WIRING 0
#define PRG_MODE_DRIVEN_SIM_VALUE 0
#define PRG_MODE_EDGE_TYPE "NONE"
#define PRG_MODE_FREQ 50000000
#define PRG_MODE_HAS_IN 0
#define PRG_MODE_HAS_OUT 1
#define PRG_MODE_HAS_TRI 0
#define PRG_MODE_IRQ -1
#define PRG_MODE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PRG_MODE_IRQ_TYPE "NONE"
#define PRG_MODE_NAME "/dev/prg_mode"
#define PRG_MODE_RESET_VALUE 0
#define PRG_MODE_SPAN 16
#define PRG_MODE_TYPE "altera_avalon_pio"


/*
 * rst configuration
 *
 */

#define ALT_MODULE_CLASS_rst altera_avalon_pio
#define RST_BASE 0x210
#define RST_BIT_CLEARING_EDGE_REGISTER 0
#define RST_BIT_MODIFYING_OUTPUT_REGISTER 0
#define RST_CAPTURE 0
#define RST_DATA_WIDTH 1
#define RST_DO_TEST_BENCH_WIRING 0
#define RST_DRIVEN_SIM_VALUE 0
#define RST_EDGE_TYPE "NONE"
#define RST_FREQ 50000000
#define RST_HAS_IN 0
#define RST_HAS_OUT 1
#define RST_HAS_TRI 0
#define RST_IRQ -1
#define RST_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RST_IRQ_TYPE "NONE"
#define RST_NAME "/dev/rst"
#define RST_RESET_VALUE 0
#define RST_SPAN 16
#define RST_TYPE "altera_avalon_pio"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x510
#define SYSID_QSYS_0_ID 4660
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1471841518
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * uart configuration
 *
 */

#define ALT_MODULE_CLASS_uart altera_avalon_uart
#define UART_BASE 0x400
#define UART_BAUD 9600
#define UART_DATA_BITS 8
#define UART_FIXED_BAUD 1
#define UART_FREQ 50000000
#define UART_IRQ 1
#define UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_NAME "/dev/uart"
#define UART_PARITY 'N'
#define UART_SIM_CHAR_STREAM ""
#define UART_SIM_TRUE_BAUD 0
#define UART_SPAN 32
#define UART_STOP_BITS 1
#define UART_SYNC_REG_DEPTH 2
#define UART_TYPE "altera_avalon_uart"
#define UART_USE_CTS_RTS 0
#define UART_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
