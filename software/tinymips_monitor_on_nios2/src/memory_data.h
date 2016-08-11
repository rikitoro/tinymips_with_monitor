/*
 * memory_data.h
 *
 *  Created on: 2016/07/18
 *      Author: yoshiaki
 */

#ifndef MEMORY_DATA_H_
#define MEMORY_DATA_H_

typedef enum{
  DATA_TYPE = 0,
  EOF_TYPE = 1
} RecordType;

typedef struct {
  int bytecount; // = 0x00, 0x04, 0x08, ... , 0xfc
  int address; // = 0x0000, 0x0004, 0x0008, ...
  RecordType recordtype;
  int data[0x3f]; // maximun bytecount/ 4 [byte] = 0xfc / 4 = 0x3f
} MemoryData;

// imem access
void write_memory_data_to_imem(const MemoryData* md);
void read_imem_for_memory_data(MemoryData* md);

// dmem access
void write_memory_data_to_dmem(const MemoryData* md);
void read_dmem_for_memory_data(MemoryData* md);

// ioport access
void write_memory_data_to_iport_data(const MemoryData* md);
void read_oport_data_for_memory_data(MemoryData* md);

// hex format string <-> memory_data
void convert_hexformat_to_memory_data(const char* hf, MemoryData* md);
void convert_memory_data_to_hexformat(const MemoryData* md, char* hf);

//
char checksum_of_memory_data(const MemoryData* md);

#endif /* MEMORY_DATA_H_ */
