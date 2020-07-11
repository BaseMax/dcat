# dcat

Implementation **cat** unix tools using pure **C programming language**. (Just a draft tool for Donya OS)

## Features

- Tiny code
- Good performance
- Support most features of unix `cat` tool
- Concatenation some files to one output
- Read from **STDIN**
- Depends on glibc

## Help

```
Usage: dcat [OPTION]... [FILE]...
Concatenate FILE(s) to standard output.

With no FILE, or when FILE is -, read standard input.

-l, --learn              learn and read offline documentation
-A, --show-all           equivalent to -vET
-b, --number-nonblank    number nonempty output lines, overrides -n
-e                       equivalent to -vE
-E, --show-ends          display $ at end of each line
-n, --number             number all output lines
-s, --squeeze-blank      suppress repeated empty output lines
-t                       equivalent to -vT
-T, --show-tabs          display TAB characters as ^I
-u                      (ignored)
-v, --show-nonprinting   use ^ and M- notation, except for LFD and TAB
--help     display this help and exit
--version  output version information and exit

Examples:
dcat f - g  Output f's contents, then standard input, then g's contents.
dcat        Copy standard input to standard output.

Programming by Max Base
Full documentation at: <https://github.com/basemac/dcat>
or available locally via: 'dcat --learn'
```

### Using

**max@base:~/Desktop$ ./dcat -n dcat.c**

```
option -n

Reading donya_cat.c
     1	/     1	*
     2	 * @Name: dcat: cat - Donya OS
     3	 * @Author: Max Base
     4	 * @Repository: github.com/basemax/dcat
     5	 * @Date: 2020-07-11
     6	*/
...
```

**max@base:~/Desktop$ ./dcat dcat.c**

```
Reading donya_cat.c
/*
 * @Name: dcat: cat - Donya OS
 * @Author: Max Base
 * @Repository: github.com/basemax/dcat
 * @Date: 2020-07-11
*/
...
```

### Version

```
dcat (Donya OS) 1.0
Copyright (C) 2020 Max Base.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Written by Max Base.
```

### What's cat?

cat is a standard Unix utility that reads files sequentially, writing them to standard output.

The name is derived from its function to concatenate files.

### Build and Compile

```
git clone https://github.com/BaseMax/dcat
cd dcat
gcc dcat.c -o dcat -O3
./dcat --version
```

### TODO

All features not ready:

- `-s`
- `-b`
- `-v`
- ...

I accept your contribute or help to develop this tool.

---------

# Max Base

My nickname is Max, Programming language developer, Full-stack programmer. I love computer scientists, researchers, and compilers. ([Max Base](https://maxbase.org/))

## Asrez Team

A team includes some programmer, developer, designer, researcher(s) especially Max Base.

[Asrez Team](https://www.asrez.com/)

