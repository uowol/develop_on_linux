#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

// application entry point
int main(int argc, char* argv[])
{
  int fbfd = 0; // framebuffer filedescriptor
  struct fb_var_screeninfo var_info;

  // Open the framebuffer device file for reading and writing
  fbfd = open("/dev/fb0", O_RDWR);
  if (fbfd == -1) {
    printf("Error: cannot open framebuffer device.\n");
    return(1);
  }
  printf("The framebuffer device opened.\n");

  char* fbmem = mmap(NULL, 1024 * 768 * 3, PROT_WRITE, MAP_SHARED, fbfd, 0);

  fbmem += 200 * 1024 * 3 + 100 * 3;
  for (int y = 0; y < 360; y++) {
    for (int x = 0; x < 480; x++) {
      fbmem[x * 3    ] = 255;
      fbmem[x * 3 + 1] = 0;
      fbmem[x * 3 + 2] = 0;
      }
      fbmem += 1024 * 3;
      }
  
  return 0;

}