/**
 * @date Created  on May 3, 2026
 * @author Attila Kovacs
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "novas.h"

int main(int argc, const char *argv[]) {
  novas_timespec ts = {};
  novas_eop eop = {};

  novas_debug(NOVAS_DEBUG_ON);

  if(argc > 1) {
    if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-?") == 0) {
      printf("\n");
      printf(" iers-fetch -- Obtains leap second and Earth Orientation Parameters from IERS.\n");
      printf("               (C) 2026 Attila kovacs\n\n");
      printf(" Syntax: iers-fetch [YYYY-mm-dd[[T]HH:MM:SS[.SSS]]\n\n");
      return 0;
    }

    if(novas_set_str_time(NOVAS_UTC, argv[1], 0, 0.0, &ts) < 0)
      return 1;
  }
  else {
    novas_set_current_time(0, 0.0, &ts);
  }

  if(novas_fetch_eop(novas_get_time(&ts, NOVAS_UTC), &eop) != 0)
    return 1;

  printf("  LEAP = %3d,   DUT1 = %9.6f,   XP = %9.6f,   YP = %9.6f\n", eop.leap, eop.dut1, eop.xp, eop.yp);

  return 0;
}


