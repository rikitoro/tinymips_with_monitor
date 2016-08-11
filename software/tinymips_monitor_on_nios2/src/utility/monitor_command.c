/*
 * monitor_command.c
 *
 *  Created on: 2016/07/20
 *      Author: yoshiaki
 */

#include "monitor_command.h"

//
int unique(const char c0, const char c1, const char c2, const char c3); //

MonitorCommand monitor_command(char* str) {
  //
  const int ASRS = unique('A','S','R','S');
  const int NGRS = unique('N','G','R','S');
  const int ASPM = unique('A','S','P','M');
  const int NGPM = unique('N','G','P','M');
  const int RDIM = unique('R','D','I','M');
  const int WRIM = unique('W','R','I','M');
  const int RDDM = unique('R','D','D','M');
  const int WRDM = unique('W','R','D','M');
  const int STIP = unique('S','T','I','P');
  const int GTOP = unique('G','T','O','P');
  //
  const int command = unique(str[0], str[1], str[2], str[3]);
  if (command == ASRS) {
    return MONITOR_COMMAND_ASRS;
  } else if (command == NGRS) {
    return MONITOR_COMMAND_NGRS;
  } else if (command == ASPM) {
    return MONITOR_COMMAND_ASPM;
  } else if (command == NGPM) {
    return MONITOR_COMMAND_NGPM;
  } else if (command == RDIM) {
    return MONITOR_COMMAND_RDIM;
  } else if (command == WRIM) {
    return MONITOR_COMMAND_WRIM;
  } else if (command == RDDM) {
    return MONITOR_COMMAND_RDDM;
  } else if (command == WRDM) {
    return MONITOR_COMMAND_WRDM;
  } else if (command == STIP) {
    return MONITOR_COMMAND_STIP;
  } else if (command == GTOP) {
    return MONITOR_COMMAND_GTOP;
  } else {
    return MONITOR_COMMAND_ERR;
  }
}

int unique(const char c0, const char c1, const char c2, const char c3) {
  return (c0 << 24) + (c1 << 16) + (c2 << 8) + c3;
}
