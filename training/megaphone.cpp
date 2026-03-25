#include <iostream>

void	make_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = std::toupper (str[i]);
		i++;
	}
	return;
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
	}
	else
	{
		while (i < argc)
		{
			str = argv[i];
			make_upper (str);
			std::cout << str;
			i ++;
		}
		std::cout << std::endl;
	}
	return (0);
}