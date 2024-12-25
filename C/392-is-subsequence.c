bool isSubsequence(char* s, char* t) {
    int i = 0;
    while (t[i] != '\0')
    {
        if (*s == t[i])
        {
            s++;
        }
        i++;
    }
    return (*s == '\0');
}