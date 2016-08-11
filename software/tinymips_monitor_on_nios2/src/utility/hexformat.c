/*
 * hexformat.c
 *
 *  Created on: 2016/07/19
 *      Author: yoshiaki
 */

#include "hexchar_int.h"

#include "hexformat.h"

int bytecount_of_hexformat(const char* hf){
  const int offset = 1;
  return hex2chars_to_int(hf[offset+0], hf[offset+1]);
}
int address_of_hexformat(const char* hf) {
  const int offset = 3;
  return hex4chars_to_int(hf[offset+0], hf[offset+1], hf[offset+2], hf[offset+3]);
}

int recordtype_of_hexformat(const char* hf) {
  const int offset = 7;
  return hex2chars_to_int(hf[offset+0], hf[offset+1]);
}

int data_of_hexformat(const char* hf, const int n) {
  const int offset = 9 + 8 * n;
  const int d3 = hex2chars_to_int(hf[offset+0], hf[offset+1]);
  const int d2 = hex2chars_to_int(hf[offset+2], hf[offset+3]);
  const int d1 = hex2chars_to_int(hf[offset+4], hf[offset+5]);
  const int d0 = hex2chars_to_int(hf[offset+6], hf[offset+7]);
  return (d3 << 24) + (d2 << 16) + (d1 << 8) + d0;
}

char checksum_of_hexformat(const char* hf) {
  const int offset = 9 + 2 * bytecount_of_hexformat(hf);
  return (char)(hex2chars_to_int(hf[offset+0], hf[offset+1]));
}
