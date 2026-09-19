#ifndef __DAY13_LIB_H__
#define __DAY13_LIB_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SIZE(a) (sizeof(a)/sizeof(a[0]))

struct student3 {
    int id;
    int* score;
    char name[20];
};

struct color1 {
    unsigned int blue : 8;  // 32 bit를 준비하고, blue가 8 bit 사용
    unsigned int green : 8; // 위에서 사용하고 남은 bit 중 8bit 사용
    unsigned int red : 8;   // 위에서 사용하고 남은 bit 중 8bit 사용
};

struct color2 {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
};

struct ip {
    uint16_t version : 4;
    uint16_t IHL : 4;
    uint16_t TOS : 8;
    uint16_t Total_length;
    uint16_t Identification;
    uint16_t x : 1;
    uint16_t D : 1;
    uint16_t M : 1;
    uint16_t Fragment_Offset : 13; 
    uint8_t TTL; 
    uint8_t Protocol;
    uint16_t Header_Checksum;
    uint32_t Source_Address;
    uint32_t Destination_Address;
    uint32_t IP_Option;
};
#endif