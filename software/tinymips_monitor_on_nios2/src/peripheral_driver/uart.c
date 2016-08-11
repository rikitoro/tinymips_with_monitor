/*
 * uart.c
 *
 *  Created on: 2016/07/17
 *      Author: yoshiaki
 */
#include "sys/alt_stdio.h"
#include "system.h"
#include "uart.h"

int getchar() {
  int c;
  c = alt_getchar();
  //alt_putchar(c); // echo back (remove if not needed)
  return c;
}

void getstr(char* str) { // read one line, skip '_'
  int c;
  int index;

  index = 0;
  c = getchar();
  while(!(c == '\r' || c == '\n')) {
    if (c != '_') {
      str[index] = (char)c;
      index++;
    }
    c = getchar();
  }
  str[index] = '\0';
  return;
}

void putstr(const char* str) {
	alt_putstr(str);
}

void tx_str(const char* str) {
  alt_putstr(str);
}

void rx_str(char* str) {
  getstr(str);
}
