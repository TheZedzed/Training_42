#include "ft_cat.h"

int	main(int argc,char **argv)
{
	const char	*file;
	int	fd;
	int	err;

	err = 0;
	// skip over program name
	--argc;
	++argv;

	// no arguments means stdin -- fake a "-" entry
	if (argc <= 0)
	{
		++argc;
		--argv;
		argv[0] = "-";
	}
	// loop on all input files
	for (;  argc > 0;  --argc, ++argv)
	{
		file = *argv;
		// copy stdin
		if (strcmp(file, "-") == 0)
		{
			cat_stream(0);
			continue;
		}
		// open the explicit input file
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{
			err = errno;
			fprintf(stderr, "cat: unable to open '%s' -- %s\n", file,strerror(err));
			break;
		}
		// cat the open file stream
		err = cat_stream(fd);
		// close the input file
		close(fd);
		// stop on error
		if (err)
		    break;
	}
	// regardless of the error, just return 1
	if (err)
		err = 1;
	return (err);
}
