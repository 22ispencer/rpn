#include <notcurses/nckeys.h>
#include <notcurses/notcurses.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  struct notcurses *nc = notcurses_init(NULL, NULL);
  if (nc == NULL) {
    printf("unable to initialize notcurses");
    return 1;
  }

  unsigned int y;

  struct ncplane *stdplane = notcurses_stddim_yx(nc, &y, NULL);

  ncinput input;
  for (;;) {
    notcurses_get(nc, NULL, &input);
    if (input.evtype == NCTYPE_PRESS) {
      if (input.id == NCKEY_RETURN) {
        ncplane_cursor_move_yx(stdplane, input.y + 1, 0);
      } else {
        ncplane_putstr(stdplane, input.utf8);
      }
    }
    notcurses_render(nc);
  }

  notcurses_stop(nc);
  return 0;
}
