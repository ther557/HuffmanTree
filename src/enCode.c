
#include <Project.h>
#include <stdio.h>

char *MatchingString(char *s1, char *s2)
{
    char *t = (char *)malloc(strlen(s1) + strlen(s2) + 1);
    if (t == NULL)
        exit(1);
    strcpy(t, s1);
    strcat(t, s2);
    return t;
}
void enCode(HTNodep T, char *s, Code *Codep)
{
    int i = 0;
    if (T->leftChild)
        enCode(T->leftChild, MatchingString(s, "0"), Codep);
    else
    {
        Code temp = {T->letter, s};
        Codep[i] = temp;
        i++;
        return NULL;
    }
    if (T->rightChild)
        enCode(T->rightChild, MatchingString(s, "1"), Codep);
    return NULL;
}