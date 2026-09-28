// Example of getchar()
// to be finish with a file we have to do: control + D -> (^ + D)
#include <stdio.h> // define EOF

void upper_to_lower(){
    int c; 
    int outC; 

    printf("\n Enter the character to conver: "); 
    c = getchar(); 
    while(c != EOF){
        // if the letter is upper we have to chnage it to lower: 
        if (c >= 'A' && c <= 'Z'){
            // changing c to lower case: 
            outC = c + ('a' - 'A'); 
        } else {
            outC = c; // just keep it as it is
        }

        putchar(outC); //tolower(c)

        c = getchar(); // read the next line.  
    }
    /**
     * This doesn't work because: 
     * getchar() reads from the same standard input stream. 
     * When the first function reaches EOF, the second function cannot simply start reading new input from that same stream.
     * You would need to reset or otherwise manage the input stream, or structure your program so that each function receives input separately.
     * This is because: Because EOF is not just a character that your program reads. It is a signal that 
     * tells the input stream that there is no more input available.
     */
}

int main (){
    int c;
    int count = 0;

    c = getchar ();
    while(c != EOF){
        /* no end-of-file yet */
        count++;
        // spaces and 'In' also counted
        c = getchar(); /* read next */
    }
    printf("# of chars: %d\n", count); 

    upper_to_lower(); 

}