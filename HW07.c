//HW07 grep! Hi alive!
#include <stdio.h>

/* The main program */
int main(int argc, char *argv[])
{
    FILE *fp;

    char pattern[20];
    int count_pattern = 0;

    switch (argc){
        case 2:
            //[PATTERN]
            for (count_pattern = 0; argv[1][count_pattern] != '\0'; count_pattern++){
                pattern[count_pattern] = argv[1][count_pattern];
            }
            //[FILE]
            fp = stdin;
            break;
        case 3:
            // Ð•NÐ»Ð¸ argv[1][0] == '-', Ð·Ð?Ð°N‡Ð¸N‚ ÐzÐµN€Ð?N‹Ða ÐzÐ°N€Ð°ÐLÐµN‚N€ NTN‚Ðl [OPTIONS]
            if(argv[1][0] == '-') {
                //[OPTIONS]
                //options = argv[1][1];

                //[PATTERN]
                for (count_pattern = 0; argv[2][count_pattern] != '\0'; count_pattern++){
                    pattern[count_pattern] = argv[2][count_pattern];
                }

                //[FILE]
                fp = stdin;
            }
            else{
                //[PATTERN]
                for (count_pattern = 0; argv[1][count_pattern] != '\0'; count_pattern++)
                    pattern[count_pattern] = argv[1][count_pattern];

                //[FILE]
                if((fp = fopen(argv[2], "r")) == NULL){
                    // exit(1);
                }
            }
            break;
        case 4:
            //[OPTIONS]
            //options = argv[1][1];

            //[PATTERN]
            for (count_pattern = 0; argv[2][count_pattern] != '\0'; count_pattern++){
                pattern[count_pattern] = argv[2][count_pattern];
            }

            //[FILE]
            if((fp = fopen(argv[2], "r")) == NULL){
                // exit(1);
            }
            break;
        default:
            fp = stdin;
            break;
    }


    char *estr = NULL;
    char buf_string[512];
    //char options;
    int found_number = 0;
    int count_string = 0;
    int number_string = 0;

    while (1)
    {
        // Ð§N‚ÐµÐ?Ð¸Ðµ ÐlÐ´Ð?ÐlÐa NN‚N€ÐlÐsÐ¸  Ð¸Ð· N„Ð°ÐaÐ»Ð°
        estr = fgets (buf_string,sizeof(buf_string),fp);

        // Ð”Ð»Ð¸Ð?Ð° NN‚N€ÐlÐsÐ¸
        count_string = 0;
        while(buf_string[count_string] != '\0')
            count_string++;

        // ÐšÐlÐ»Ð¸N‡ÐµNN‚Ð?Ðl NN‚N€ÐlÐs
        number_string++;


        if (estr == NULL)
        {

            if ( feof (fp) != 0)
            {

                break;
            }
            else
            {

                break;
            }
        }

        int i = 0, ii = 0;
        for(; i < count_string; i++) {
            if(buf_string[i] == pattern[ii]){
                ii++;
                if(count_pattern == ii){
                    printf("%s", buf_string);
                    found_number++;
                    break;
                }
            }
            else{
                ii = 0;
            }
        }
    }

    fclose(fp);

    if(found_number == 0)
        return 1;

    return 0;

