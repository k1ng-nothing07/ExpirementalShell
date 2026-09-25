#include <stdio.h>
#include <unistd.h>
#include <string.h>

 int main() {
      char terminal[100];


   printf("Welcome to the terminal.\n\n");
    sleep(1);


    printf("$  ");
      scanf("%s", terminal);

         while (1) {
     if  (strcmp(terminal, "exit") == 0) {
          printf("exiting the terminal...\n");
           return 0;
        }
      else if (strcmp(terminal, "clear") == 0) {
          printf("\033[2J\033[1;1H");
       printf("$  ");
      scanf("%s", terminal);
      }
      else if (strcmp(terminal, "help") == 0) {
            printf("Available commands:\n");
               printf("exit - Exit The Shell\n");
                  printf("clear - Clear The Shell\n");
               printf("pwd - Show The Current Directory\n");
            printf("help - Show The Current Help Menu\n");
         printf("$  ");
      scanf("%s", terminal);
         
      }
      
      else if  (strcmp(terminal, "pwd") == 0) {
          char cwd[1024];
           if (getcwd(cwd, sizeof(cwd)) != NULL);
            printf("%s\n", cwd);
             printf("current directory: %s\n", cwd);
            printf("$  ");
             scanf("%s", terminal);

      } 
        else {
         printf("bash: %s: command not found.\n", terminal);
         printf("$  ");
         scanf("%s", terminal);
        }
      }
   return 0;
 }