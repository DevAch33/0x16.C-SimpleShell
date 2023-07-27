/**
 *_puts - prints an input string
 *@st: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *st)
{
	int i = 0;

	if (!st)
		return;
	while (str[i] != '\0')
	{
		_putchar(st[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
