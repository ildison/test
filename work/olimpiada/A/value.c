 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>

char		*gnl()
{
	char	*str;
	char	buf[2];

	str = (char *)malloc(sizeof(char) * 10);
	*str = '\0';
	*(buf + 1) = '\0';
	while (read(0, buf, 1) && *buf != '\n')
		strcat(str, buf);
	return (str);
}

void		euro(int *n, int e)
{
	int		face_value = 5;
	int		val;


	val = (e * face_value);
	*n -= val;
}

void		dollar(int *n, int d)
{
	int		face_value = 1;
	int		val;

	val = (d * face_value);
	*n -= val;
}

void		change(int *n, int d, int e)
{
	while (*n >= d || *n >= (e * 5))
	{
		if (!(*n % d))
			dollar(n, d);
		else if (!(*n % (e * 5)))
			euro(n, e);
		else if (!((*n - d) % d) || !((*n - d) % (e * 5)))
			dollar(n, d);
		else if (!((*n - e * 5) % (e * 5)) || !((*n - e * 5) % (e * 5)))
			euro(n, e);
		else if (*n > (d + (e * 5)) && (!((*n - e * 5 - d) % e) || !((*n - e * 5 -d) % e)))
		{
			dollar(n, d);
			euro(n, e);
		}
		else if (d < (e * 5))
			dollar(n, d);
		else
			euro(n, e);
	}
}

int			main()
{
	int		n;
	int		d;
	int		e;

	n = atoi(gnl());
	d = atoi(gnl());
	e = atoi(gnl());
	change(&n, d, e);
	printf("%d\n", n);
	return (0);
}