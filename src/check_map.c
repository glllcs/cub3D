int	check_map(char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j] != '\0')
	{


int	count_lines(char *map)
{
	int	i;
	int	j;
	int	posit;

	i = -1;
	j = 0;
	posit = 0;
	while (map[++i][j] != '\0')
	{
		j = -1;
		while (map[i][++j] != '\n')
		{
			if (map[i][j] == START_POSIT)
				posit++;
		}
	}
	if (posit < 1)
		return (-1);
	if (posit > 1)
		return (-2);
	return (i);
}

int	read_file(t_map 
