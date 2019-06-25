#include <stdio.h>
#include <stdlib.h>

/* lbf
 * Simple brainfuck interpreter with interactive mode.
 * Skips every non-brainfuck character.
 *
 * author: László Ádám
 * version: 1.0
 * e-mail: adam.laszlo.91@gmail.com
 * web: http://eve-hci001.atw.hu/
 *
 * december 8, 2014
 */

// get character without enter
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

char getCharacter(){
	char c = getchar();
	clean_stdin();
	return c;
}

// interpret
int interpret(int* char_index, char* char_array, char* tape, int* tape_pointer, int* tape_size, int file_size){
    switch(char_array[*char_index]){
    case '.':
        // print the actual data
        printf("%c", tape[*tape_pointer]);
        break;
    case '+':
        // inc data
        tape[*tape_pointer]++;
        break;
    case '-':
        // dec data
        tape[*tape_pointer]--;
        break;
    case ',':
        // store new input
        tape[*tape_pointer] = getCharacter();
        break;
    case '<':
        // move left
        (*tape_pointer)--;
        if (*tape_pointer < 0){
            printf("\nerror: left end exceeded at %d. character.\n", *tape_pointer+1);
            return 1;
        }
        break;
    case '>':
        // move right
        (*tape_pointer)++;
        if (*tape_pointer == *tape_size){
            // increase tape length
            (*tape_size)++;
            tape = (char*)realloc(tape, (*tape_size)*sizeof(char));
            tape[*tape_pointer] = 0;
        }
        break;
    case ']':
        // jump back to the bracket's pair if the actual data is nonzero
        if (tape[*tape_pointer] != 0){
            int bracket_counter = 1;
            while (bracket_counter != 0) {
                (*char_index)--;
                if (*char_index < 0){
                    printf("\nerror: not maching left bracket\n");
                    return 1;
                }
                if (char_array[*char_index] == ']')
                    bracket_counter++;
                if (char_array[*char_index] == '[')
                    bracket_counter--;
            }
            (*char_index)--;
        }
        break;
    case '[':
        // jump forward to the bracket's pair if the actual data is zero
        if (tape[*tape_pointer] == 0){
            int bracket_counter = 1;
            while (bracket_counter != 0) {
                (*char_index)++;
                if (*char_index == file_size){
                    printf("\nerror: not maching right bracket\n");
                    return 1;
                }
                if (char_array[*char_index] == '[')
                    bracket_counter++;
                if (char_array[*char_index] == ']')
                    bracket_counter--;
            }
        }
        break;
    default:
        // skip character
        break;
    }
    return 0;
}

// offline mode
void offline_mode(char path[]){
    FILE *file = NULL;
    char *char_array;
    char *tape;
    int tape_size = 1, tape_pointer = 0;
    int i, file_size;

    // open file
    file = fopen(path, "r");
    if (file == NULL){
        printf("error: cannot open input file.");
        return;
    }
    printf("lbf - OFFLINE MODE\n\n");
    // set file size (number of ascii characters)
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    // get the data into the array
    char_array = (char*)malloc(file_size*sizeof(char));
    for (i = 0; i < file_size; i++){
        char_array[i] = fgetc(file);
    }
	if (file != NULL){
		fclose(file);
		file = NULL;
	}
    // start interpreting
    tape = (char*)malloc(sizeof(char));
    tape[0] = 0;
    for (i = 0; i < file_size; i++){
        if(interpret(&i, char_array, tape, &tape_pointer, &tape_size, file_size))
            return;
    }
    printf("\n\nfile length: %d.\n", file_size);
    printf("tape length: %d.\n", tape_size);
    free(char_array);
    free(tape);
    return;
}

// interactive mode
void interactive_mode(){
	printf("lbf - INTERACTIVE MODE\n\n");
    char char_array[500];
    char *tape = (char*)malloc(sizeof(char));
    tape[0] = 0;
    int tape_size = 1, tape_pointer = 0;
    int file_size;
    int i;
    // typing
    while(1){
        // print current tape
        printf("\ntape\n: ");
        for (i = 0; i < tape_size; i++){
            printf("[%c]", tape[i]);
            if (i == tape_pointer){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
        printf("> ");
        scanf("%s", char_array);
        clean_stdin();
        i=0;
        while(1){
            if (char_array[i] == '\0'){
                file_size = i+1;
                break;
            }
            i++;
        }
        // exit on q
        if (file_size == 2 && char_array[0] == 'q'){
            exit(0);
        }
        for (i=0; i < file_size; i++){
            interpret(&i, char_array, tape, &tape_pointer, &tape_size, file_size);
        }
    }
}

// main
/*int main(int argc, char *argv[]){
    if (argc == 1){
        // if there's no argument, start interactive mode
        interactive_mode();
    }else if (argc == 2){
        // it must be the input file
        offline_mode(argv[1]);
        return 0;
    }else{
        printf("error: too many arguments.");
        return 0;
    }
}*/
