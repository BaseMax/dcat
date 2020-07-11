# dcat

Implementation **cat** unix tools using pure **C programming language**. (Just a draft tool for Donya OS)

## Features

- Tiny code
- Good performance
- Depends on glibc
- Support most features of unix cat tool
- Concatenation some files to one output
- Read from **STDIN**

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
cat f - g  Output f's contents, then standard input, then g's contents.
cat        Copy standard input to standard output.

Programming by Max Base
Full documentation at: <https://github.com/basemac/dcat>
or available locally via: 'dcat --learn'
```

### What's cat?

cat is a standard Unix utility that reads files sequentially, writing them to standard output.

The name is derived from its function to concatenate files.

### TODO

- `-s`
- `-b`
- `-v``

---------

# Max Base

My nickname is Max, Programming language developer, Full-stack programmer. I love computer scientists, researchers, and compilers. ([Max Base](https://maxbase.org/))

## Asrez Team

A team includes some programmer, developer, designer, researcher(s) especially Max Base.

[Asrez Team](https://www.asrez.com/)

