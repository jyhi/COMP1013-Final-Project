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

/**
 * Buffer sizes limited.
 */
#define BUFSIZE 512

/**
 * Definitions for main_menu's return value.
 *
 * These values are also used for menu display.
 * @see STR
 */
#define MAIN_MENU_GRADE   1 //< User chooses to grade.
#define MAIN_MENU_INQUIRE 2 //< User chooses to inquire.
#define MAIN_MENU_SORT    3 //< User chooses to sort.
#define MAIN_MENU_QUIT    4 //< User chooses to quit.

/**
 * Display the main menu, and ask for user input as choice of action.
 *
 * @return User choice, defined in constants.
 * @see MAIN_MENU_GRADE, MAIN_MENU_INQUIRE, MAIN_MENU_SORT, MAIN_MENU_QUIT
 */
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
