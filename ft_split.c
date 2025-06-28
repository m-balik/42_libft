#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count = 0;
	int		in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, size_t len)
{
	char	*word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		word[i] = s[i];
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;
	size_t	i = 0;
	size_t	len;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			result[i++] = word_dup(s, len);
			s += len;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
