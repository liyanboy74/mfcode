#include <stdio.h>
#include "keeloq.h"

void print_key(uint8_t *key)
{
    int i;
    for(i=7;i>=0;i--)
    {
        printf("%02X ",key[i]);
    }
    printf("\n");
}

void key_minor(uint8_t *key)
{
    int i;
    for(i=0;i<8;i++)
    {
        if(key[i]==0)
        {
            key[i]=0xFF;
            continue;
        }
        key[i]--;
        break;
    }
}

int main(int argc,char **argv)
{
    int i=0;

#ifdef DEBUG
    // KEELOQ Key LSB-first
    uint8_t mf_key[]= {0xef,0xce,0xab,0x89,0x67,0x45,0x23,0x01};
#else
    uint8_t mf_key[]= {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
#endif

    uint32_t enc,ser;
    uint32_t temp;

    if(argc>=3)
    {
        sscanf(argv[1],"%X",&ser);
        sscanf(argv[2],"%X",&enc);
    }
    else
    {
        printf("Enter SER (HEX):");
        scanf("%X",&ser);
        printf("Enter 32bit HSB of KEY (HEX):");
        scanf("%X",&enc);
    }
    printf("Runing for SER=0X%X KEY(32bit HSB)=0X%X \n",ser,enc);

    while(mf_key[7]!=0)
    {
        // Test Normal Key
        temp = ser;
        temp |= 0x60000000;
        keeloq_decrypt(mf_key,&temp,KEELOQ_NROUNDS);
        if(temp==enc)break;

        // Test Secure Key
        temp = ser;
        ser &= 0x0fffffff;
        keeloq_decrypt(mf_key,&temp,KEELOQ_NROUNDS);
        if(temp==enc)break;

        if(i++%1000000==0)
        {
            printf("Trying: ");
            print_key(mf_key);
        }

        key_minor(mf_key);
    }

    if(mf_key[7]==0)
    {
        printf("Key not found\n");
        return 1;
    }

    printf("MF: ");
    print_key(mf_key);

    return 0;
}