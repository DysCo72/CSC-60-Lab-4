/*--------------------------------------------*/
/* Lab 4                                      */
/* Figure the area of a parabola using files  */

#include <stdio.h>
#include <stdlib.h>

#define IN_FILE_NAME "lab4.dat"
#define OUT_FILE_NAME "lab4.txt"

int main(void)
{
    double length, depth, area;
    FILE *infile;
    FILE *outfile;

    infile = fopen(IN_FILE_NAME, "r");
    if (infile == NULL)
    {
        printf("Error on fopen input file\n");
        exit(EXIT_FAILURE);
    }

    outfile = fopen(OUT_FILE_NAME, "w");
    if (outfile == NULL)
    {
        printf("Error on fopen output file\n");
        exit(EXIT_FAILURE);
    }

    fprintf(outfile, "\nXXXXXX.  Lab 4. \n\n");
    fprintf(outfile, "Data on Parabolas \n\n");
    fprintf(outfile, " Length      Depth        Area   \n");
    fprintf(outfile, "--------   ---------   --------- \n");
                               
    while (	(fscanf(infile, "%lf%lf", &length, & depth)) == 2)
    {
        area = (2.0 * length * depth)/ 3.0;     // compute the area of the parabola

        // print the length, depth, and area
        fprintf(outfile, "%7.2lf    %7.2lf   %10.3lf\n",    
                length, depth, area);
    }

    fprintf(outfile, "\n\n");   //print a final empty line

    // close the two files
    fclose (infile);
    fclose (outfile);

    return EXIT_SUCCESS;
}
/*---------------------------------------------------*/
