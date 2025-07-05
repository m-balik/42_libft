#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void print_split(char **arr)
{
    if (!arr)
    {
        printf("NULL\n");
        return;
    }
    for (int i = 0; arr[i]; i++)
        printf("'%s'\n", arr[i]);
}

int main(void)
{
    char **res;

    // Test 1: Normal kullanım
    res = ft_split("hello world", ' ');
    print_split(res);
    if (res) { for (int i = 0; res[i]; i++) free(res[i]); free(res); }

    // Test 2: Sadece ayraçlardan oluşan string
    res = ft_split("     ", ' ');
    print_split(res);
    if (res) { for (int i = 0; res[i]; i++) free(res[i]); free(res); }

    // Test 3: Başında ve sonunda ayraçlar
    res = ft_split("   hello!   ", ' ');
    print_split(res);
    if (res) { for (int i = 0; res[i]; i++) free(res[i]); free(res); }

    // Test 4: NULL pointer
    res = ft_split(NULL, ' ');
    print_split(res);

    return 0;
}