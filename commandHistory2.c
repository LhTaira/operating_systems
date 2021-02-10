#include <stdio.h>
#include <stdlib.h>


int main() {
    int numberOfCommands;
    int commands[200000];
    int history[200000];
    while(scanf("%d", &numberOfCommands) && numberOfCommands!=0) {
        int biggestCommand = 0;
        int arrowUp = 0;

        for(int i=0; i<numberOfCommands; i++){
            scanf("%d", &commands[i]);
            if(commands[i] > biggestCommand) {
                biggestCommand = commands[i];
            }
        }
        for(int i=biggestCommand; i>=0; i--) {
            history[i] = biggestCommand - i;
        }

        // for(int i=1; i<=biggestCommand; i++) {
        //     history[i-1] = i;
        // }


        for(int i=0; i<numberOfCommands; i++) {
            int historyPlace = biggestCommand - 1;
            arrowUp++;
            while(history[historyPlace] != commands[i]) {
                historyPlace--;
                arrowUp++;
            }
            history[biggestCommand++] = commands[i];
        }
        printf("%d\n", arrowUp);

        // for(int i=0; i<biggestCommand; i++) {
        //     printf("%d\n", history[i]);
        // }
    }

}