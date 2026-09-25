#include <stdio.h>
#include <unistd.h>
#include <string.h>
#ifdef _WIN32
#include <direct.h>
#include <sys/stat.h>
#define mkdir(path, mode) _mkdir(path)
#else

#endif

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
                   printf("ls - List The Current Directory\n");
                  printf("cd - Change The Current Directory\n");
               printf("pwd - Show The Current Directory\n");
            printf("help - Show The Current Help Menu\n");
            printf("mkdir - Create A Directory\n");
            printf("rmdir - Remove A Directory\n");
            printf("touch - Create A File\n");
            printf("rmfile - Remove A File");
            printf("echo - echo to the Terminal.\n");
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
      else if (strcmp(terminal, "ls") == 0) {
            system("ls");
            printf("$  ");
            scanf("%s", terminal);
      }
      else if (strcmp(terminal, "cd") == 0)
      {
            char path[100];
            printf("Enter Directory Path: ");
             scanf("%s", path);
             if (chdir(path) == 0) {
                  printf("Inside Directory: %s\n", path);
                    printf("$  ");
                    scanf("%s", terminal);

             }
      }
      else if (strcmp(terminal, "pwd") == 0) {
          char cwd[1024];
           if (getcwd(cwd, sizeof(cwd)) != NULL);
            printf("%s\n", cwd);
             printf("current directory: %s\n", cwd);
            printf("$  ");
             scanf("%s", terminal);
      }
      else if (strcmp(terminal, "mkdir") == 0) {
         char dir[50];
         printf("Enter Directory Name: ");
         scanf("%49s", dir);
         if (mkdir(dir, 0777) == 0) {
            printf("Directory Created: %s\n", dir);
            printf("$  ");
            scanf("%s", terminal);
         }
         else {
            printf("Failed to create directory: %s\n", dir);
            printf("check if directory already exists\n");
            printf("or check if you have permission to create directory\n");
         printf("$  ");
         scanf("%s", terminal);

         }
      }
      else if (strcmp(terminal, "rmdir") == 0) {
          char dir[50];
          char caution [4];
          
           printf("Enter Directory Name: ");
          scanf("%49s", dir);
          printf("Are you sure you want to remove the directory? [Y/n]: ");
          scanf("%3s", caution);
          if (strcmp(caution, "Y") == 0 || strcmp (caution, "y") == 0) {
            rmdir(dir);
            printf("Directory Removed: %s\n", dir);
            printf("$  ");
            scanf("%s", terminal);

            
          }
          else if (strcmp(caution, "N") == 0 || strcmp (caution, "n") == 0)
            {
               printf("rmdir: operation cancelled\n");
               printf("$  ");
               scanf("%s", terminal);
            }
         else {
            printf("Invalid input. Please enter 'Y' or 'N'.\n");
            printf("$  ");
            scanf("%s", terminal);
         }

      }

       else if (strcmp(terminal, "touch") == 0) {
            char file[50];
            printf("Enter File Name: ");
            scanf("%49s", file);
            FILE *fp = fopen(file, "w");
            if (fp != NULL) {
                  fclose(fp);
                  printf("File Created: %s\n", file);
                  printf("$  ");
                  scanf("%s", terminal);

            }
            else { 
               printf("Failed To Create File: %s\n", file);
               printf("check if file already exists\n");
               printf("or check if you have permission to create file\n");
               printf("$  ");
               scanf("%s", terminal);
            }
         }
         else if (strcmp(terminal, "rmfile") == 0) {
            char file[50];
            char caution [4];
            printf("Enter File Name: ");
            scanf("%49s", file);
            printf("Are you sure you want to remove the file? [Y/n]: ");
            scanf("%3s", caution);
            if (strcmp(caution, "Y") == 0 || strcmp (caution, "y") == 0) {
               remove(file);
               printf("File Removed: %s\n", file);
               printf("$  ");
               scanf("%s", terminal);
            }
            else if (strcmp(caution, "N") == 0 || strcmp (caution, "n") == 0) {
               printf("rmfile: operation cancelled\n");
               printf("$  ");
               scanf("%s", terminal);
            }
            else {
               printf("Invalid input. Please enter 'Y' or 'N'.\n");
               printf("$  ");
               scanf("%s", terminal);
            }
         }
      else if (strcmp(terminal, "echo") == 0) {
         char echo[100];
        if (fgets(echo, sizeof(echo), stdin) != NULL) {
         printf("%s\n", echo);
        }
         
         
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