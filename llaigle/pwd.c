


void		ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
		ft_printf("%s\n", cwd);
    else
        perror("Pwd");
}