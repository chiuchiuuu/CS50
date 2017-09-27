/**
 * Resizes a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize int infile outfile\n");
        return 1;
    }

    // remember resize int
    int n = atoi(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }



    // creating new bitmap
    BITMAPFILEHEADER newBf = bf;
    BITMAPINFOHEADER newBi = bi;
    newBi.biWidth *= n;
    newBi.biHeight *= n;

    // determine new padding for scanlines
    int newPadding = (4 - (newBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // modify outfile header info
    newBi.biSizeImage = ((sizeof(RGBTRIPLE) * newBi.biWidth) + newPadding) * abs(newBi.biHeight);
    newBf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + newBi.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&newBf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&newBi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines (for each row)
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // resize in column
        for (int k = 0; k < n; k++)
        {
            // determine old padding for scanlines
            int oldPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

            // send pointer back to the start of scan line
            fseek(inptr, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) +
            (bi.biWidth*sizeof(RGBTRIPLE) + oldPadding) * i , SEEK_SET);

            // iterate over pixels in scanline (for each column)
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // resize in row
                for (int l = 0; l < n; l++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // then add new padding back (to demonstrate how) (outfile)
            for (int m = 0; m < newPadding; m++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
