/*
 * monitor_command.c
 *
 *  Created on: 2016/07/20
 *      Author: yoshiaki
 */

#include "monitor_command.h"

//
int unique(const char c0, const char c1); //

MonitorCommand monitor_command(char* str) {
  //
  const int AR = unique('A','R');
  const int NR = unique('N','R');
  const int AP = unique('A','P');
  const int NP = unique('N','P');
  const int RI = unique('R','I');
  const int WI = unique('W','I');
  const int RD = unique('R','D');
  const int WD = unique('W','D');
  const int IP = unique('I','P');
  const int OP = unique('O','P');
  //
  const int command = unique(str[0], str[1]);
  if (command == AR) {
    return MONITOR_COMMAND_AR;
  } else if (command == NR) {
    return MONITOR_COMMAND_NR;
  } else if (command == AP) {
    return MONITOR_COMMAND_AP;
  } else if (command == NP) {
    return MONITOR_COMMAND_NP;
  } else if (command == RI) {
    return MONITOR_COMMAND_RI;
  } else if (command == WI) {
    return MONITOR_COMMAND_WI;
  } else if (command == RD) {
    return MONITOR_COMMAND_RD;
  } else if (command == WD) {
    return MONITOR_COMMAND_WD;
  } else if (command == IP) {
    return MONITOR_COMMAND_IP;
  } else if (command == OP) {
    return MONITOR_COMMAND_OP;
  } else {
    return MONITOR_COMMAND_ERR;
  }
}

int unique(const char c0, const char c1) {
  return (c0 << 8) + c1;
}
