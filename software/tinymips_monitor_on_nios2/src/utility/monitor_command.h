/*
 * monitor_command.h
 *
 *  Created on: 2016/07/20
 *      Author: yoshiaki
 */

#ifndef MONITOR_COMMAND_H_
#define MONITOR_COMMAND_H_

typedef enum {
  MONITOR_COMMAND_ERR = -1, // error
  // reset
  MONITOR_COMMAND_AR  = 1,  // assert reset
  MONITOR_COMMAND_NR  = 2,  // negate reset
  // program mode
  MONITOR_COMMAND_AP  = 3,  // assert program mode
  MONITOR_COMMAND_NP  = 4,   // negate program mode
  // access to instruction memory
  MONITOR_COMMAND_RI  = 5,  // read imem
  MONITOR_COMMAND_WI  = 6,  // write imem
  // access to data memory
  MONITOR_COMMAND_RD  = 7,  // read ‚„mem
  MONITOR_COMMAND_WD  = 8,  // write dmem
  //
  MONITOR_COMMAND_IP  = 9,  // set iport data
  MONITOR_COMMAND_OP  = 10  // get oport data
} MonitorCommand;

MonitorCommand monitor_command(char* str);

#endif /* MONITOR_COMMAND_H_ */
