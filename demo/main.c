#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>
#include <linux/fb.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int main(int argc, char* args[])
{
  printf("Init Demo!\n");

  if(SDL_Init(SDL_INIT_VIDEO) != 0){
    printf("%s, failed to SDL_Init\n", __func__);
    return -1;
  }
 
  SDL_Surface* screen;
  screen = SDL_SetVideoMode(320, 240, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if(screen == NULL){
    printf("%s, failed to SDL_SetVideMode\n", __func__);
    return -1;
  }
  SDL_ShowCursor(0);

  int index=30, cnt=30;
  while(cnt--){
    switch(index){
    case 0:
      SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xff, 0x00, 0x00));
      break;
    case 1:
      SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x00, 0xff, 0x00));
      break;
    case 2:
      SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x00, 0x00, 0xff));
      break;
    }
    index+= 1;
    if(index >= 3){
      index = 0;
    }
    SDL_Flip(screen);
    SDL_Delay(100);
  }
	SDL_Quit();
  return 0;
}

