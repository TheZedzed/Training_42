/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:26:24 by alex              #+#    #+#             */
/*   Updated: 2020/07/11 16:26:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int
cat_stream(int fd)
{
    ssize_t rlen;
    ssize_t wlen;
    int err = 0;
    char *cur;
    char buf[64 * 1024];

    // NOTE: the buffer size can be _any_ length, but 64KB is optimal for many
    // filesystem files or devices

    while (1) {
        // read a chunk of input
        rlen = read(fd,buf,sizeof(buf));

        // end of file
        if (rlen == 0)
            break;

        // error
        if (rlen < 0) {
            err = errno;
            fprintf(stderr,"cat_stream: read error -- %s\n",strerror(err));
            break;
        }

        // write out all data read in current chunk -- loop until all data
        // read in this chunk has been output, even if it could _not_ be
        // output in a single write call, advancing the pointer into the
        // buffer [and shortening the remaining length]
        cur = buf;
        for (;  rlen > 0;  rlen -= wlen, cur += wlen) {
            wlen = write(1,cur,rlen);

            // handle error
            if (wlen < 0) {
                err = errno;
                fprintf(stderr,"cat_stream: write error -- %s\n",strerror(err));
                break;
            }
        }
    }

    // restore errno after fprintf so caller can use it [if desired]
    if (err)
        errno = err;

    return err;
}

int
main(int argc,char **argv)
{
    const char *file;
    int fd;
    int err = 0;

    // skip over program name
    --argc;
    ++argv;

    // no arguments means stdin -- fake a "-" entry
    if (argc <= 0) {
        ++argc;
        --argv;
        argv[0] = "-";
    }

    // loop on all input files
    for (;  argc > 0;  --argc, ++argv) {
        file = *argv;

        // copy stdin
        if (strcmp(file,"-") == 0) {
            cat_stream(0);
            continue;
        }

        // open the explicit input file
        fd = open(file,O_RDONLY);
        if (fd < 0) {
            err = errno;
            fprintf(stderr,"cat: unable to open '%s' -- %s\n",
                file,strerror(err));
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

    return err;
}
