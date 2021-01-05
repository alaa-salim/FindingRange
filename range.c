//
// Created by Alaa Salim on 9/3/20.
//

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){

    FILE *fp ;
    double x,min,max = 0 ;
    char buffer[100];
    char *data;

    fp= fopen(argv[1], "r") ;
    if ( fp == NULL )
    {
        printf( "Unable to open file!" );
        exit(1);
    }

    //Finding length of file
    //Exits program if file is empty
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    if(size < 0)
    {
        printf("Cannot read from an empty file.");
        exit(2);
    }
    else
    {
        rewind(fp);
    }

        //Reads in numbers until EOF is detected
        while ((data = fgets(buffer, 100, fp)) != NULL)
        {
            // Ignores empty strings
            if (*data == '\n')
            {
                continue;
            }
            //Reads in number from file
            sscanf(buffer, "%lf", &x);
            //Checks if the number read in from the file is greater than max
            //If true, assigns that number to max
            if(x > max)
            {
                max = x;
            }
            //Checks if num is less than min
            if(x< min)
            {
                min =x;
            }
        }
        //Closing the file
        fclose(fp);

        //Output
        printf("min: %lf \n", min);
        printf("max: %lf \n", max);

    return 0;
}