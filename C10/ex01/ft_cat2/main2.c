int	cat_stream(int fd)
{
	int	rlen;
	int	wlen;
	char	*cur;
	char	buf[29 * 1024];

/*NOTE: the buffer size can be _any_ length, but 64KB is optimal for many
**filesystem files or devices
*/
	while (1)
	{
		// read a chunk of input
		rlen = read(fd, buf, sizeof(buf));
		// end of file
		if (rlen == 0)
			break;
		// error <<
		if (rlen < 0)
		{
			ft_putstr(basename(argv[0]));
			ft_putstr(": ");
			ft_putstr(argv);
			ft_putstr(": ");
			ft_putstr(strerror(errno));
			ft_putstr("\n");
			break;
		}
/*write out all data read in current chunk -- loop until all data
**read in this chunk has been output, even if it could _not_ be
**output in a single write call, advancing the pointer into the
**buffer [and shortening the remaining length]
*/
		cur = buf;
		for (;  rlen > 0;  rlen -= wlen, cur += wlen)
		{
			wlen = write(1, cur, rlen);
			// handle error
			if (wlen < 0)
			{
				err = errno;
				fprintf(stderr,"cat_stream: write error -- %s\n", strerror(err));
				break;
		    	}
		}
	}

	// restore errno after fprintf so caller can use it [if desired]
	if (err)
		errno = err;
	return (err);
}
