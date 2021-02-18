#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_STR 64
#define MAX_SONG 100

enum song_kind
  {
   ROCK,
   POP,
   JAZZ,
   HIP_HOP,
   UNKNOWN
  };

struct song
{
  char path[MAX_STR];
  char title[MAX_STR];
  char album[MAX_STR];
  char artist[MAX_STR];
  int track;
  enum song_kind kind;
};
	      
struct playlist
{
  struct song songs[MAX_SONG];
  unsigned int nb_songs;
};


int scan_song(struct song *song)
{
  struct song s = {};
  char buffer[12];
  printf("path :\n");
  if (!gets(s.path) || strlen(s.path) == 0)
    return 0;
  printf("title :\n");
  if (!gets(s.title)) {
  }  
  else printf("artist :\n");
    if (!gets(s.artist)) {
    }
  
  else printf("album :\n");
    if (!gets(s.album)) {
    }

  else printf("track's number :\n");
    if (gets(buffer)) {
    int n = atoi(buffer);
    s.track = n;
    printf("kind : \n");
    if (gets(buffer)) {
        n = atoi(buffer);
        s.kind = n;
    }
    }
  
  *song = s;
  return 1;
}

char * song_kind_to_str(enum song_kind kind)
{
  switch(kind){
  case ROCK:
    return "Rock";
  case POP:
    return "Pop";
  case JAZZ:
    return "Jazz";
  case UNKNOWN:
    return "Unknown";
  case HIP_HOP:
    return "Hip hop";
  default:
    return "INVALID_KIND";
  }
}

char * unknown_if_empty(char * element)
{
  if (element[0]==0){
    return "UNKNOWN";
  }
  return element;
}

void print_song(struct song *song)
{
  if (song->track==0){
    printf("track UNKNOWN\n");
    return;
  }
  printf("titre : %s\nartist : %s\nalbum : %s\ngenre : %s\ntrack : %d\n", unknown_if_empty(song->title), unknown_if_empty(song->artist), unknown_if_empty(song->album), unknown_if_empty(song_kind_to_str(song->kind)), song->track);
  return;
}

int nb_songs(struct playlist * playlist)
{
  return playlist->nb_songs;
}

void init_list(struct playlist * playlist)
{
  playlist->nb_songs = 0;
}

int append_song(struct playlist * playlist, struct song * song)
{
  if (playlist->nb_songs == MAX_SONG){
    return EXIT_FAILURE;
  }
  playlist->songs[playlist->nb_songs] = *song;
  playlist->nb_songs++;
  return EXIT_SUCCESS;
}

void kind_list(struct playlist * src, struct playlist * dst, enum song_kind kind)
{
  for (int i = 0 ; i <= src->nb_songs ; i++){
    if (src->songs[i]->kind==kind){
      append_song(dst, &(src->songs[i]));
    }
  }
}

int main(int argc, char *argv[])
{
    struct song some_song;
    while (scan_song(&some_song)) {
        print_song(&some_song);
    }
    return 0;
   
}
