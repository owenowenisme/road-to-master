#include <stdio.h>
#include <math.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};

char layers[4] = {'C', 'M', 'Y', 'K'};

void print_C(unsigned int mask[][MAX_SIZE]);
void print_M(unsigned int mask[][MAX_SIZE]);
void print_Y(unsigned int mask[][MAX_SIZE]);
void print_K(unsigned int mask[][MAX_SIZE]);
void CMYK_to_RGB();

int main()
{
    // Get the dimension of the image.
    scanf("%u %u", &W, &H);

    // Declare the mask for single ink color.
    unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

    // For each layer, do the following:
    for (int layer = 0; layer < 4; ++layer)
    {
        // Get color mask.
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                scanf("%u", &mask[i][j]);
            }
        }

        // Print a layer of that color to the paper.
        switch (layers[layer])
        {
            case 'C': print_C(mask); break;
            case 'M': print_M(mask); break;
            case 'Y': print_Y(mask); break;
            case 'K': print_K(mask); break;
        }
    }

    // Convert CMYK color to RGB color.
    CMYK_to_RGB();

    // Show the final result.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            printf("#%06x ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void print_C(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; ++i)
    {

        for (int j = 0; j < W; ++j)
        {   
            image[i][j]=((100-mask[i][j]))*256*256;
            //printf("#%06x ", image[i][j]);
        }
        
    }
}

void print_M(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; ++i)
    {

        for (int j = 0; j < W; ++j)
        {   
            image[i][j]+=(100-mask[i][j])*256;
            //printf("#%06x ", image[i][j]);
        }
        
    }
}


void print_Y(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; ++i)
    {

        for (int j = 0; j < W; ++j)
        {   
            image[i][j]+=(100-mask[i][j]);
            //printf("#%06x ", image[i][j]);
        }
        
    }
}

void print_K(unsigned int mask[][MAX_SIZE])
{int tmp;
   for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {  
            for(int)
           tmp=image[i][j];
           lround((tmp%256)*(100-mask[i][j])*0.01*2.55);
           
        }
        
    } 
}

void CMYK_to_RGB()
{   
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {   
           
        }
        
    }
}

// #59176d #7e3f87 #4d3217 #b2ae44 #9fa60e 
// #5d4101 #064136 #2a2f44 #584657 #3a0114 
// #0b0101 #6e2a3f #141107 #041317 #8d51c3 
// #0f1e34 #838d1b #98808a #cf52cc #a4023b 
// #a900cc #561891 #995f70 #372b1a #a38948 

