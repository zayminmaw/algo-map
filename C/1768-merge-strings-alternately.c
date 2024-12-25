#include <stdlib.h>

int str_len(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char * mergeAlternately(char * word1, char * word2){
    int str_len1 = str_len(word1);
    int str_len2 = str_len(word2);
    int i = 0, w1 = 0, w2 = 0;
    char *res = malloc(sizeof(char) * (str_len1 + str_len2 + 1));
    while (w1 < str_len1 || w2 < str_len2)
    {
        if (w1 < str_len1)
            res[i++] = word1[w1++];
        if (w2 < str_len2)
            res[i++] = word2[w2++];
    }
    res[i] = '\0';
    return (res);
}