#include <stdio.h>
#include <string.h>

char str[100], pat[100], rep[100], ans[200];
int i, j, k, c, m, flag = 0;

void stringmatch()
{
    i = m = c = j = 0;

    while (str[c] != '\0')
    {
        if (str[m] == pat[i])
        {
            i++;
            m++;

            if (pat[i] == '\0')
            {
                flag = 1;

                for (k = 0; rep[k] != '\0'; k++, j++)
                {
                    ans[j] = rep[k];
                }

                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j++] = str[c++];
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
}

void main()
{

    printf("Enter main string: ");
    gets(str);
    printf("Enter pattern string: ");
    gets(pat);

    printf("Enter replacing string: ");
    gets(rep);

    stringmatch();

    if (flag == 1)
        printf("The resultant string is: %s\n", ans);
    else
        printf("Pattern not found.\n");

    return 0;
}
