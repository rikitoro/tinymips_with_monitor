/*
 * memory_data.c
 *
 *  Created on: 2016/07/18
 *      Author: yoshiaki
 */

#include "peripheral_driver/imem.h"
#include "peripheral_driver/dmem.h"
#include "peripheral_driver/ioport.h"
#include "utility/hexformat.h"

#include "memory_data.h"


//////////////
void write_memory_data_to_imem(const MemoryData* md) {
  const int word_count = md->bytecount / 4;
  const int start_address = md->address;
  int count = 0;

  for (count = 0; count < word_count; ++count) {
    imem_wd(start_address + 4 * count, md->data[count]);
  }
}

void read_imem_for_memory_data(MemoryData* md) {
  const int word_count = md->bytecount / 4;
  const int start_address = md->address;
  int count = 0;

  for (count = 0; count < word_count; ++count) {
    md->data[count] = imem_rd(start_address + 4 * count);
  }
}

//////////////
void write_memory_data_to_dmem(const MemoryData* md) {
  const int word_count = md->bytecount / 4;
  const int start_address = md->address;
  int count = 0;

  for (count = 0; count < word_count; ++count) {
    dmem_wd(start_address + 4 * count, md->data[count]);
  }
}

void read_dmem_for_memory_data(MemoryData* md) {
  const int word_count = md->bytecount / 4;
  const int start_address = md->address;
  int count = 0;

  for (count = 0; count < word_count; ++count) {
    md->data[count] = dmem_rd(start_address + 4 * count);
  }
}

// ioport access
void write_memory_data_to_iport_data(const MemoryData* md) {
  iport_wd(md->data[0]);
}

void read_oport_data_for_memory_data(MemoryData* md) {
  const int bytecount = 4;
  const int address = 0;

  md->bytecount = bytecount;
  md->address = address;
  md->data[0] = oport_rd();
}


//////////////

char checksum_of_memory_data(const MemoryData* md) {
  const int word_count = md->bytecount / 4;
  int count = 0;
  char sum = 0;
  sum += (char)(0xff & md->bytecount);
  sum += (char)(0x00ff & md->address);
  sum += (char)((0xff00 & md->address) >> 8);
  sum += (0xf & md->recordtype);
  for (count = 0; count < word_count; ++count) {
    sum += (char)( 0x000000ff & md->data[count]);
    sum += (char)((0x0000ff00 & md->data[count]) >> 8);
    sum += (char)((0x00ff0000 & md->data[count]) >> 16);
    sum += (char)((0xff000000 & md->data[count]) >> 24);
  }
  return (char)(0xff & (~sum + 1));
}

///////////////////

void convert_hexformat_to_memory_data(const char* hf, MemoryData* md) {
  int i;

  md->bytecount  = bytecount_of_hexformat(hf);
  md->address    = address_of_hexformat(hf);
  md->recordtype = recordtype_of_hexformat(hf);
  for (i = 0; i < md->bytecount / 4; ++i) {
    md->data[i] = data_of_hexformat(hf, i);
  }
}

void convert_memory_data_to_hexformat(const MemoryData* md, char* hf) {
  int i = 0;
  int checksum = (int)checksum_of_memory_data(md);

  hf[0] = ':';
  // bytecount
  hf[1] = hex_nth_digit(md->bytecount, 1);
  hf[2] = hex_nth_digit(md->bytecount, 0);
  // address
  hf[3] = hex_nth_digit(md->address, 3);
  hf[4] = hex_nth_digit(md->address, 2);
  hf[5] = hex_nth_digit(md->address, 1);
  hf[6] = hex_nth_digit(md->address, 0);
  // recordtype
  hf[7] = hex_nth_digit(md->recordtype, 1);
  hf[8] = hex_nth_digit(md->recordtype, 0);
  // data
  for (i = 0; i < md->bytecount / 4; ++i) {
    hf[9 + 8 * i + 0] = hex_nth_digit(md->data[i], 7);
    hf[9 + 8 * i + 1] = hex_nth_digit(md->data[i], 6);
    hf[9 + 8 * i + 2] = hex_nth_digit(md->data[i], 5);
    hf[9 + 8 * i + 3] = hex_nth_digit(md->data[i], 4);
    hf[9 + 8 * i + 4] = hex_nth_digit(md->data[i], 3);
    hf[9 + 8 * i + 5] = hex_nth_digit(md->data[i], 2);
    hf[9 + 8 * i + 6] = hex_nth_digit(md->data[i], 1);
    hf[9 + 8 * i + 7] = hex_nth_digit(md->data[i], 0);
  }
  // checksum
  hf[9 + 2 * md->bytecount + 0] = hex_nth_digit(checksum, 1);
  hf[9 + 2 * md->bytecount + 1] = hex_nth_digit(checksum, 0);
  // end
  hf[9 + 2 * md->bytecount + 2] = '\r';
  hf[9 + 2 * md->bytecount + 3] = '\n';
  hf[9 + 2 * md->bytecount + 4] = '\0';
}
