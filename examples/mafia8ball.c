//an example of minimal emojiC syntax. a magic 8 ball that talks down to you like a mobster from the 70s.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    char *🤣=(NULL);
    size_t len=(0);
    ssize_t read;
    const char* 🤣🤣🤣🤣🤣🤣[35]={"fuck you. roll again.","take off your clothes and roll again.","maybe if you roll less and maybe put on a jazz record you'll get a faster answer.","i would say so, but the orientals beat me to it","if i say 'yes' will i get a manhattan that doesn't taste like yesterday's cunt juice?","yeah probably, i don't care.","i'll give you a straight answer once you bring home a straight broad to my beck and call","that baby i had off'd last week had a better chance of a future than a reply to that question.","what the hell do i look like, a magic 8 ball?","roll again, and this time don't look like a bitch when doing it","i'm busy smoking while eating a hoagie.","ask me that again, when i'm not busy throatswabbing your sister","you wouldn't understand it if i explained it to you","i'm clogging the oval office. roll again, but light a match","how about asking something that doesn't make you look like a sad little person.","when you're at church this sunday, why don't you ask the big man in the sky for a better question to ask","ziltch chance.","nada.","nope.","i've seen brain-dead kiddos at st. jude with a better chance at life than that question."
    };srand(time(NULL));printf("Enter a question or return to exit.\n");while(1){printf("\nThe Question: ");read=getline(&🤣,&len,stdin);if(read<2)break;printf("\n%s\n",🤣🤣🤣🤣🤣🤣[rand()%20]);}if(🤣)free(🤣);return(0);}
