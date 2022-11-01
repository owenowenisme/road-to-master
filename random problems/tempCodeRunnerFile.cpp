void print_C(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; ++i)
    {

        for (int j = 0; j < W; ++j)
        {   
            image[i][j]=lround((100-mask[i][j])*255*0.01)*256*256;
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
            image[i][j]+=lround((100-mask[i][j])*255*0.01)*256;
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
            image[i][j]+=lround((100-mask[i][j])*255*0.01);
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
           tmp=image[i][j];
           float black=((100-mask[i][j])*0.01);
           //printf("%d ", black);
           image[i][j]=lround((tmp%256)*(100-mask[i][j])*0.01);
           tmp/=256;
           image[i][j]+=lround((tmp%256)*(100-mask[i][j])*0.01)*256;
           tmp/=256;
           image[i][j]+=lround((tmp%256)*(100-mask[i][j])*0.01)*256*256;
           tmp/=256;
            printf("#%06x ", image[i][j]);
        }
        
    }
}

void CMYK_to_RGB()
{   int temp;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            
            
        }
        
    }
}