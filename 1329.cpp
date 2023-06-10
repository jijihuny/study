#include <iostream>

using namespace std;


uint8_t cmp(char * first, char* flast, char* second, char* slast){
    while(1){
        if(first!=0)first++;
        if(second!=0)second++;
        if(first!=0 && second!=0)break;
    }//setting MSB to a leading nonzero bit.

    short int flen = flast - first, slen = slast - second;

    if(flen>slen)return 0;
    else if(flen<slen)return 1;
    else{
        for(;first==flast;first++, second++){
            if (first>second)return 0;
            else if(first<second)return 1;
        }
        return 2;
    }
}

char* min(char *)