#include <stdio.h>

int main() {
    int history[100000];
    int commands[100000];
    int numberOfCommands;
    while(scanf("%d", &numberOfCommands) && numberOfCommands!=0) {
        int arrowUp = 0;
        int historySize = 0;

        for(int i=0; i<numberOfCommands; i++){
            scanf("%d", &commands[i]);
        }
        
        for(int i=0; i<numberOfCommands; i++) {
            int commandFound = 0;
            // arrowUp++;
            for(int historyParser=historySize-1; historyParser>=0; historyParser--) {
                arrowUp++;
                if(history[historyParser] == commands[i]) {
                    commandFound = 1;
                    break;
                }
            }
            if(commandFound == 1) {
                history[historySize++] = commands[i];
                // break;
            } else {
                arrowUp += commands[i];
                history[historySize++] = commands[i];
            }
        }
        // for(int i=0; i<historySize; i++){
        //     printf("%d\n", history[i]);
        // }
        printf("%d\n", arrowUp);
    }
}