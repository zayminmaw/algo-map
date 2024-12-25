#define SIZE 7

typedef struct KeyValue {
    char key;
    int value;
} KeyValue;

KeyValue rton[SIZE] = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int getValue(char k)
{
    int i = 0;
    while (i < SIZE)
    {
        if (rton[i].key == k)
            return (rton[i].value);
        i++;
    }
    return -1;
}

int romanToInt(char* s) {
    int i = 0;
    int total = 0;
    while (s[i] != '\0')
    {
        if (s[i + 1] != '\0' && getValue(s[i + 1]) > getValue(s[i]))
        {
            total -= getValue(s[i]);
            i++;
            continue;
        }
        total += getValue(s[i]);
        i++;
    }
    return (total);
}