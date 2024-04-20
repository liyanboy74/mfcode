#include <stdio.h>
#include "keeloq.h"

uint32_t gen_normal_key(uint64_t mf_key,uint32_t seed)
{
    static uint32_t temp,enc;

    seed &= 0x0fffffff;// mask out function codes 

    temp = seed;
    temp |= 0x20000000;
    keeloq_decrypt(&mf_key,&enc, &temp, KEELOQ_NROUNDS);

    return enc;
}

int main(int argc,char **argv)
{
    uint64_t key= {0xffffffffffffffff};
    uint32_t enc,ser;
    uint32_t g,i;

    if(argc>=3)
    {
        sscanf(argv[1],"%X",&ser);
        sscanf(argv[2],"%X",&enc);
    }
    else
    {
        printf("Enter SER (HEX):");
        scanf("%X",&ser);
        printf("Enter 32bit LSB of KEY (HEX):");
        scanf("%X",&enc);
    }

    printf("Runing for SER=0X%X KEY(LSB)=0X%X \n",ser,enc);

    while(key)
    {
        g=gen_normal_key(key,ser);

        if(g==enc)break;
        if(key%1000000==0)
        {
            printf("Try %X%X \n",(uint32_t)(key>>32),(uint32_t)key);
        }
        key--;
    }

    printf("MF: %X%X \n",(uint32_t)(key>>32),(uint32_t)key);

    return 0;
}