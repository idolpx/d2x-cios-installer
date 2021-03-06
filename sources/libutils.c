#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdarg.h>
#include <string.h>
#include "libstring.h"
#include "libutils.h"
unsigned int printBreakLines(const char chBreakChar,size_t intMaxLineSize,const char *strFormatTextLine,...) {
static char strTextBuffer[1024];
unsigned int varout=0;
char *strBreakTextLine;
char *chCurrentOffset;
va_list pArguments;
    va_start(pArguments,strFormatTextLine);
    vsnprintf(strTextBuffer,sizeof(strTextBuffer),strFormatTextLine,pArguments);
    va_end(pArguments);
    chCurrentOffset=&strTextBuffer[0];
    while (strlen(chCurrentOffset)) {
        if ((strBreakTextLine=getBreakString(chCurrentOffset,chBreakChar,intMaxLineSize))==NULL) {
            chCurrentOffset=&strTextBuffer[strlen(strTextBuffer)];
        }
        else {
            printf("%s%s",(varout)?"\n":"",strBreakTextLine);
            chCurrentOffset=chCurrentOffset+strlen(strBreakTextLine);
            if (*chCurrentOffset==chBreakChar) {
                chCurrentOffset=chCurrentOffset+1;
            }
            varout++;
            free(strBreakTextLine);
            strBreakTextLine=NULL;
        }
    }
    return varout;
}
int patchBytesData(u8 *chBytesData,u32 lngPatchOffset,u8 *chOriginalBytes,u8 *chNewBytes,u32 lngPatchBytesCount) {
int varout=memcmp(&chBytesData[lngPatchOffset],chOriginalBytes,lngPatchBytesCount);
    if (!varout) {
		memcpy(&chBytesData[lngPatchOffset],chNewBytes,lngPatchBytesCount);
	}
	return varout;
}
void permutePointers(void *varValue1,void *varValue2) {
void *varTemp;
    varTemp=varValue1;
    varValue1=varValue2;
    varValue2=varTemp;
}
void printRepeatString(unsigned int intRepeatsCount,const char *strFormatValue,...) {
static char strTextBuffer[1024];
va_list pArguments;
    va_start(pArguments,strFormatValue);
    vsnprintf(strTextBuffer,sizeof(strTextBuffer),strFormatValue,pArguments);
    va_end(pArguments);
    while (intRepeatsCount) {
        intRepeatsCount--;
        printf("%s",strTextBuffer);
    }
}
char *getFormattedString(const char *strFormatString,...) {
static char strFormattedString[1024];
va_list pArguments;
    va_start(pArguments,strFormatString);
    vsnprintf(strFormattedString,sizeof(strFormattedString),strFormatString,pArguments);
    va_end(pArguments);
    return getCloneString(strFormattedString);
}
