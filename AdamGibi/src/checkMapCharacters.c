int	checkCharacter(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == '#')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (2);
	return (0);
}

int	checkMapCharacters(char **av)
{
	int p=0;
	int res;

	for (int i=0; av[i]; i++)
	{
		for (int j=0; av[i][j]; j++)
		{
			res = checkCharacter(av[i][j]);
			if (res == 2)
				p++;
			if (res == 0 || p > 1)
				return (0);
		}
	}
	return (1);
}
