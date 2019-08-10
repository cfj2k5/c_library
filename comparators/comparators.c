#include <string.h>

/*
    cmp_func_lexographic_sort
    Checks if string a comes before string b in non-descending order, lexographically.
    Returns:
        -1 for b before a
        0  for the same
        1  for a before b
 */
int cmp_func_lexographic_sort(const char* a, const char* b){
    int compare = strcmp(a,b);
    if(compare < 0){
        /* String in a comes before b */
        return 1;
    }else if(compare > 0){
        /* String in b comes before a */
        return -1;
    }
    return 0;
}

/*
    cmp_func_lexographic_sort_reverse
    Checks if string b comes before string a in non-ascending order, lexographically.
    Returns:
        -1 for a before b
        0  for the same
        1  for b before a
 */
int cmp_func_lexographic_sort_reverse(const char* a, const char* b){
    int compare = strcmp(a,b);

    if(compare < 0){
        /* String in b comes before a */
        return -1;
    }else if(compare > 0){
        /* String in a comes before b */
        return 1;
    }
    return 0;
}

/*
    cmp_func_number_of_distinct_characters
    Checks two strings for the number of distinct characters.
    Returns:
        1  for a has less distinct characters than b
        -1  for a has more distinct characters than b
        If both strings compare equally, then the lexographically 
          first string decision is returned
 */
int cmp_func_number_of_distinct_characters(const char* a, const char* b){
    int i,j;
    int distCntA = 0;
    int distCntB = 0;
    unsigned int charFound = 0; // maps characters found
    //ASCII a is dec 97 (hex 0x61) and z is dec 122 (hex 0x7a)

    for(i = 0; i < strlen(a); i++){
        if( (charFound & (0x1 << ((unsigned int)a[i] - 97))) == 0x0){
            charFound |= (0x1 << ((unsigned int)a[i] - 97));
            distCntA++;
        }
    }
    charFound = 0; //reset character found map
    for(i = 0; i < strlen(b); i++){
        if( (charFound & (0x1 << ((int)b[i] - 97))) == 0x0){
            charFound |= (0x1 << ((int)b[i] - 97));
            distCntB++;
        }
    }

    if(distCntA < distCntB){
        return 1;
    }else if(distCntB < distCntA){
        return -1;
    }
    return cmp_func_lexographic_sort(a, b);
}

/*
    cmp_func_length
    Checks two strings for the character length. Checks if the first
    string is shorter than the second.
    Returns:
        -1 for b has less characters than a
        1  for b has more characters than a
        If both strings compare equally, then the lexographically 
          first string decision is returned
 */
int cmp_func_length(const char* a, const char* b){
    int lenA = strlen(a);
    int lenB = strlen(b);
    if(lenA < lenB){
        return 1;
    }else if(lenA > lenB){
        return -1;
    }
    return cmp_func_lexographic_sort(a,b);
}