char* longestCommonPrefix(char** strs, int strsSize) {
    char* res = strs[0];
    int i = 0;
    int j;
    while (i < strsSize)
    {
        j = 0;
        while (res[j] != '\0' && res[j] == strs[i][j])
            j++;
        res[j] = '\0';
        i++;
    }   
    return res;
}