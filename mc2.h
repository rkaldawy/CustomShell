//Remy Kaldawy and Malika Nurbekova

#ifndef HELPER_H
#define HELPER_H

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

typedef struct {
  char* name;
  char* SIDEBAR_COLOR;
  char* TITLE_COLOR;
  char* VERSION_COLOR;
  char* INT_OPTION_COLOR;
  char* CHAR_OPTION_COLOR;
  char* COMMAND_NAME_COLOR;
  char* COMMAND_DESC_COLOR;
} Color_Profile;

Color_Profile* PROFILE_LIST;
int CLR_PRFL = 0;
int CLR_PRFL_CNT = 0;

/*
char* SIDEBAR_COLOR = KNRM;
char* TITLE_COLOR = KNRM;
char* VERSION_COLOR = KNRM;
char* INT_OPTION_COLOR = KNRM;
char* CHAR_OPTION_COLOR = KNRM;
char* COMMAND_NAME_COLOR = KNRM;
char* COMMAND_DESC_COLOR = KNRM;
*/

//define a command struct
typedef struct {
  char* name;
  char* desc;
  //used for preset commands
  char* path;
  //the info field is used when user inputs info
  char** info;
  int flag;    // 0 if its the foreground process, 1 if its the background process
} Command;

//the command list and the pointer to the end of the array is initialized
Command* COMMAND_LIST;
Command* ARRAY_END;

//same for the character commands
Command* CHAR_COMMAND_LIST;
Command* CHAR_ARRAY_END;

//the max commands allowed is 20
const int MAX_COMMANDS = 20;

//we actively count the number of commands in each list of commands
int COMMAND_COUNT = 3;
const int CHAR_COMMAND_COUNT = 4;

//we typedef the process struct beforehand because it self references in its fields
typedef struct Process Process;

//the process struct has a PID, a struct time that tells when it started, and pointers
//to previous and next values
struct Process{
  int PID;
  struct timeval start;
  Process* prev;
  Process* next;
};

//we create the linked list variable and a pointer to its stub
Process* PROCESS_LIST;
Process* LAST_PROCESS;
int PROCESS_COUNT = 0;

#endif
