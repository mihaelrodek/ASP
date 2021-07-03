//najvece slovo po ASCII
#include <bits/stdc++.h>

char najveceSlovo(char *niz)
{
    if (niz == '\0')
        return '\0';
    char max = najveceSlovo(niz++);
    char trenutni = niz[0];
    if (trenutni > max)
        max = trenutni;
    return max;
};

int main()
{
}