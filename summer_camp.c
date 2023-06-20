//Sophia Hostetler
////U27264415
//Main fuction of the file

#include <stdio.h>
#include"read_line.h"
#include"request.h"

//main: Prompts the user to enter an operation code,then calls a function to perform the requested action. Repeats until the user enters the command 'q'. Prints an error message if the user enters an illegal code.

int main(void)
{
  char code;

  struct request *request_list = NULL;  
  printf("Operation Code: a for appending to the list, u for updating a request"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': request_list = append_to_list(request_list);
                break;
      case 'u': update(request_list);
                break;
      case 'p': print_list(request_list);
                break;
      case 'q': clear_list(request_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

