#include <stdio.h>
#include <cs50.h>
#include <stdint.h>
#include <stdlib.h>
#define BLOCK 512

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // store filename
    char *infile = argv[1];

    // open an image
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    BYTE buffer[512];
    int i = 0;
    char *outfile = malloc(10);
    bool flag = false;
    FILE *outptr = NULL;

    // while not reach the end-of-file
    while(1)
    {
        // read one block at a time
        fread(buffer, 1, BLOCK, inptr);
        if (feof(inptr))
        {
            break;
        }
        // find the beginning of JEPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // already found a JPEG
            if (flag)
            {
                flag = false;
                fclose(outptr);
            }

            // start of new JPEG
            sprintf(outfile, "%03i.jpg", i);
            outptr = fopen(outfile, "w");
            if (outptr == NULL)
                {
                    fclose(outptr);
                    fprintf(stderr, "Could not create %s.\n", outfile);
                    return 3;
                }
            i++;
            // write one block at a time
            fwrite(buffer, 1, BLOCK, outptr);
            flag = true;
        }
        else
        {
            // already find a JPEG
            if (flag)
            {
                fwrite(buffer, BLOCK, 1, outptr);
            }
        }
    }
    free(outfile);
}