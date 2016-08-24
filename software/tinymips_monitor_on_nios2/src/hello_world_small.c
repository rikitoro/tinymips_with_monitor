/* 
 * "Small Hello World" example. 
 * 
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example 
 * designs. It requires a STDOUT  device in your system's hardware. 
 *
 * The purpose of this example is to demonstrate the smallest possible Hello 
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard 
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete 
 * description.
 * 
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION 
 *      This removes software exception handling, which means that you cannot 
 *      run code compiled for Nios II cpu with a hardware multiplier on a core 
 *      without a the multiply unit. Check the Nios II Software Developers 
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks  
 *      support for buffering, file IO, floating point and getch(), etc. 
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program 
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */

#include "sys/alt_stdio.h"
// drivers
#include "peripheral_driver/imem.h"
#include "peripheral_driver/uart.h"
#include "peripheral_driver/rst.h"
#include "peripheral_driver/prg_mode.h"
// utility
#include "utility/monitor_command.h"
// data
#include "memory_data.h"

const char* EOF = ":00000001FF\r\n";

///
void do_AR();
void do_NR();
void do_AP();
void do_NP();
void do_RI(const char* hf);
void do_WI(const char* hf);
void do_RD(const char* hf);
void do_WD(const char* hf);
void do_IP(const char* hf);
void do_OP(const char* hf);

///
void pp_memory_data(const MemoryData* md);
///

int main()
{ 
  char r_msg[600];

  tx_str(EOF);

  while (1) {
    rx_str(r_msg);

    switch (monitor_command(r_msg)) {
      case MONITOR_COMMAND_AR:  // assert reset
        do_AR();          break;
      case MONITOR_COMMAND_NR:  // negate reset
        do_NR();          break;
      case MONITOR_COMMAND_AP:  // assert programming mode
        do_AP();          break;
      case MONITOR_COMMAND_NP:  // negate programming mode
        do_NP();          break;
      case MONITOR_COMMAND_RI:  // read instruction memory
        do_RI(&r_msg[2]); break;
      case MONITOR_COMMAND_WI:  // write instruction memory
        do_WI(&r_msg[2]); break;
      case MONITOR_COMMAND_RD:  // read data memory
        do_RD(&r_msg[2]); break;
      case MONITOR_COMMAND_WD:  // write data memory
        do_WD(&r_msg[2]); break;
      case MONITOR_COMMAND_IP:  // set iport data
        do_IP(&r_msg[2]); break;
      case MONITOR_COMMAND_OP:  // get oport data
        do_OP(&r_msg[2]); break;
      default:
        break;
    }
  }
}

///////////////////

void do_AR() {
  assert_rst();
  tx_str(EOF);
}

void do_NR() {
  negate_rst();
  tx_str(EOF);
}

void do_AP() {
  assert_prg_mode();
  tx_str(EOF);
}

void do_NP() {
  negate_prg_mode();
  tx_str(EOF);
}

void do_RI(const char* hf) {
  MemoryData md;
  char s_msg[522];

  convert_shorthexformat_to_memory_data(hf, &md);
  read_imem_for_memory_data(&md);
  convert_memory_data_to_hexformat(&md, s_msg);
  tx_str(s_msg);
}

void do_WI(const char* hf) {
  MemoryData md;

  convert_hexformat_to_memory_data(hf, &md);
  write_memory_data_to_imem(&md);
  tx_str(EOF);
}

void do_RD(const char* hf) {
  MemoryData md;
  char s_msg[522];

  convert_shorthexformat_to_memory_data(hf, &md);
  read_dmem_for_memory_data(&md);
  convert_memory_data_to_hexformat(&md, s_msg);
  tx_str(s_msg);
}

void do_WD(const char* hf) {
  MemoryData md;

  convert_hexformat_to_memory_data(hf, &md);
  write_memory_data_to_dmem(&md);
  tx_str(EOF);
}

void do_IP(const char* hf) {
  MemoryData md;
  convert_hexformat_to_memory_data(hf, &md);
  write_memory_data_to_iport_data(&md);
  tx_str(EOF);
}

void do_OP(const char* hf) {
  MemoryData md;
  char s_msg[522];
  convert_shorthexformat_to_memory_data(hf, &md);
  read_oport_data_for_memory_data(&md);
  convert_memory_data_to_hexformat(&md, s_msg);
  tx_str(s_msg);
}

//////////////////

void pp_memory_data(const MemoryData* md) {
  int i = 0;

  alt_printf("bytecount  = %x\r\n", md->bytecount);
  alt_printf("address    = %x\r\n", md->address);
  alt_printf("recordtype = %x\r\n", md->recordtype);
  for ( i = 0; i < md->bytecount / 4; ++i) {
    alt_printf("%x : %x\r\n", md->address + i * 4, md->data[i]);
  }
}
