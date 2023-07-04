

int		ft_arglen(char **arg)
{
	int		i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}


void 	ft_echo(char **arg)
{
	int		i;
	int		opt;

	i = 1;
	opt = 0;
	if (ft_arglen(arg) > 1)
	{
		while (arg[i] && ft_strlcmp(arg[i], "-n", 3) == 0)
		{
			opt = 1;
			i++;
		}
		while (arg[i])
		{
			ft_printf("%s", arg[i]);
			if (arg[i + 1] && arg[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (opt == 0)
		write(1, "\n", 1);
}