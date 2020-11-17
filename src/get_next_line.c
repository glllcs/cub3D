#include "mapping.h"

static void		ft_strfree(char **str)
{
	if (str == 0)
		return ;
	if (*str)
		free(*str);
	*str = 0;
}

/*
 * Allocate *line and copies to that everything in *resto until i_break
 * Copies everything after i_break into a new string temp
 * Deallocate the oldest resto
 * Copies to &resto the new string temp
 * Returns (-1) if error, (0) if EOF and (1) if not EOF
*/
static int		ft_strcut(char **resto, char **line, int i_break)
{
	char	*temp;
	int		i;

	if (!(*line = malloc(sizeof(char) * (i_break + 1))))
		return (-1);
	ft_strlcpy(*line, *resto, i_break + 1);
	if (ft_strlen(*resto) - i_break != 0)
	{
		if (!(temp = malloc(sizeof(char) * (ft_strlen(*resto) - i_break))))
			return (-1);
		i_break++;
		i = 0;
		while ((*resto)[i_break])
		{
			temp[i] = (*resto)[i_break];
			i_break++;
			i++;
		}
		temp[i] = '\0';
		ft_strlcpy(*resto, temp, ft_strlen(*resto));
		ft_strfree(&temp);
		return (1);
	}
	ft_strfree(resto);
	return (0);
}

/*
 * Returns the position of a '\n' (or of the '\0' if there are no more to read in the file)
*/
static int		ft_new_line(const char *str, int ret)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (ret == 0)
		return (i);
	return (-1);
}

/*
 * Allocates a new string concat for concatenation of resto and temp
 * Deallocates the oldest resto
 * Returns the string concat
*/
static char		*ft_strconcat(char *str1, char *str2)
{
	int		len;
	char	*concat;
	int		cont;

	cont = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	if (!(concat = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str1[cont])
	{
		concat[cont] = str1[cont];
		cont++;
	}
	while (*str2)
	{
		concat[cont] = *str2;
		cont++;
		str2++;
	}
	concat[cont] = '\0';
	if (str1)
		ft_strfree(&str1);
	return (concat);
}

int				get_next_line(int fd, char **line)
{
	char		temp[BUFFER_SIZE + 1];
	int			ret;
	static char	*resto[OPEN_MAX];
	int			i;

	if (line == 0 || fd < 0 || BUFFER_SIZE < 1 || read(fd, temp, 0) < 0)
		return (-1);
	ret = read(fd, temp, BUFFER_SIZE);
	temp[ret] = '\0';
	if (!resto[fd])
		resto[fd] = ft_strdup(temp);
	else if (temp[0] != '\0')
		resto[fd] = ft_strconcat(resto[fd], temp);
	if ((i = ft_new_line(resto[fd], ret)) != -1)
		return (ft_strcut(&resto[fd], line, i));
	return (get_next_line(fd, line));
}
