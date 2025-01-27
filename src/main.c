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

  char message[] = "Hello, World!";

  ncplane_putstr_aligned(stdplane, y / 2, NCALIGN_CENTER, message);

  notcurses_render(nc);
  sleep(5);

  notcurses_stop(nc);
  return 0;
}
