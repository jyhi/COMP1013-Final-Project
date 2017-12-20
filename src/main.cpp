/**
 * @file main.cpp
 * @version 0.1
 * @author
 *
 * This file contains entry codes of the whole program.
 */

#include <stdio.h>

#include "grade.hpp"
#include "inquire.hpp"
#include "sort.hpp"
#include "utils.hpp"

#define BUFSIZE 512

#define MAIN_MENU_GRADE   0
#define MAIN_MENU_INQUIRE 1
#define MAIN_MENU_SORT    2
#define MAIN_MENU_QUIT    3

static int main_menu (void) {
  static const char *main_menu_text =
    "\n"
    "===== Student Grading System =====\n"
    "\n"
    "Choose an option to start:\n"
    "\n"
    STR(MAIN_MENU_GRADE)   ". Grade\n"
    STR(MAIN_MENU_INQUIRE) ". Inquire\n"
    STR(MAIN_MENU_SORT)    ". Sort\n"
    STR(MAIN_MENU_QUIT)    ". Quit\n"
    "\n"
    "Your option: ";           // Menu text to be displayed to user
  char linebuf[BUFSIZE] = {0}; // Buffer to receive user input
  int choice = 0;              // Choice of user
  int r = 0;                   // Return values (for checking)

  printf (main_menu_text);
  if (!fgets (linebuf, BUFSIZE, stdin)) {
    puts ("Receive nothing, expect an option listed above. Exiting.");
    return MAIN_MENU_QUIT;
  }

  // Parse user input
  r = sscanf (linebuf, "%d", &choice);
  if (r != 1) {
    puts ("Encounter invalid input, expect an option listed above. Exiting.");
    return MAIN_MENU_QUIT;
  }

  if (choice < 1 || choice > 4) {
    printf ("Choice %d is invalid, expect an option listed above. Exiting.\n", choice);
    return MAIN_MENU_QUIT;
  }

  return choice;
}

int main (void) {
  // Display the main menu and choose what to do.
  switch (main_menu ()) {
    case MAIN_MENU_GRADE:
      grade ();
      break;
    case MAIN_MENU_INQUIRE:
      inquire ();
      break;
    case MAIN_MENU_SORT:
      sort ();
      break;
    case MAIN_MENU_QUIT: // fall through
    default:
      break;
  }

  return 0;
}
