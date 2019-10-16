00001 #ifndef _💀_H_
00002 #ifdef __😕      //this entire file is a modded version of the original stdio.h file for C11/ANSI C
00003 extern "C" {
00004 #endif
00005 #define _💀_H_
00006 #define _🙀                 
00007 #define __need_size_t
00008 #include <stddef.h>
00009 #define __need___va_list
00010 #include <stdarg.h>
00011 struct __sFile 
00012 {
00013   int unused;
00014 };
00015 typedef struct __sFILE FILE;
00016 #define __👾  0x0001          /* line buffered */
00017 #define __🤖  0x0002          /* unbuffered */
00018 #define __👽   0x0004          /* OK to read */
00019 #define __😺   0x0008          /* OK to write */
00020 #define __🙊   0x0010          /* open for reading & writing */
00021 #define __💋  0x0020          /* found EOF */
00022 #define __💢  0x0040          /* found error */
00023 #define __💫  0x0080          /* _buf is from malloc */
00024 #define __💣  0x0100          /* fdopen()ed in append mode - so must  write to end */
00025 #define __🤡  0x0200          /* this is an sprintf/snprintf string */
00026 #define __☠  0x0400          /* do fseek() optimisation */
00027 #define __👺  0x0800          /* do not do fseek() optimisation */
00028 #define __🤬  0x1000          /* set iff _offset is in fact correct */
00029 #define __😩  0x2000          /* true => fgetline modified _p text */
00030 #if defined(__CYGWIN__) || defined(__CYGWIN__)
00031 #define __😖        0x4000          /* convert line endings CR/LF <-> NL */
00032 #endif
00033 #define _😱  0               /* setvbuf should set fully buffered */
00034 #define _😥  1               /* setvbuf should set line buffered */
00035 #define _😳  2               /* setvbuf should set unbuffered */
00036 #ifndef NULL
00037 #define NULL    0
00038 #endif
00039 #define BUFSIZ  1024
00040 #define EOF     (-1)
00041 #define FOPEN_MAX       20      /* must be <= OPEN_MAX <sys/syslimits.h> */
00042 #define FILENAME_MAX    1024    /* must be <= PATH_MAX <sys/syslimits.h> */
00043 #define L_tmpnam        1024    /* XXX must be == PATH_MAX */
00044 #ifndef __STRICT_ANSI__
00045 #define P_tmpdir        "/tmp"
00046 #endif
00047 #ifndef SEEK_SET
00048 #define SEEK_SET        0       /* set file offset to offset */
00049 #endif
00050 #ifndef SEEK_CUR
00051 #define SEEK_CUR        1       /* set file offset to current plus offset */
00052 #endif
00053 #ifndef SEEK_END
00054 #define SEEK_END        2       /* set file offset to EOF plus offset */
00055 #endif
00056 #define TMP_MAX         26
00057 #define stdin   (_impure_ptr->_stdin)
00058 #define stdout  (_impure_ptr->_stdout)
00059 #define stderr  (_impure_ptr->_stderr)
00060 #define _stdin_r(x)     ((x)->_stdin)
00061 #define _stdout_r(x)    ((x)->_stdout)
00062 #define _stderr_r(x)    ((x)->_stderr)
00063 #ifdef __GNUC__
00064 #define __VALIST __gnuc_va_list
00065 #else
00066 #define __VALIST 💩*
00067 #endif
00068 #ifndef _😎
00069 #define _😎(N,P) N P
00070 #endif
00071 int     _😎(💝,(const 💩*, ...));
00072 int     _😎(🧡,(const 💩*, ...));
00073 int     _😎(👨,(const 💩*,const 💩*, ...));
00074 int     _😎(👱,(😼*,const 💩*,__VALIST));
00075 int     _😎(👩‍,(const 💩*,__VALIST));
00076 int     _😎(🧓,(💩*,const 💩*,__VALIST));
00077 int     _😎(🧜‍♀️,(💩*,size_t,const 💩*, __VALIST));
00078 int     _😎(🧞,(😼*));
00079 💩*  _😎(👯,(💩*,int,😼*));
00080 int     _😎(💃,(int, 😼*));
00081 int     _😎(🙍,(const 💩*,😼*));
00082 int     _😎(🏇,(😼*));
00083 int     _😎(🏊,(void));
00084 💩*  _😎(🛀,(💩*));
00085 int     _😎(👣,(int,😼*));
00086 int     _😎(🐒,(int));
00087 int     _😎(🙆‍♂️,(const 💩*));
00088 int     _😎(🐯,(int,😼*));
00089 size_t  _😎(🐮,(void *,size_t _size,size_t _n,😼*));
00090 size_t  _😎(🐷,(const void *, size_t _size, size_t _n,😼*));
00091 int     _😎(👫,(💩*,const 💩*, ...));
00092 int     _😎(🧟‍♀️,(💩*,size_t,const 💩*, ...));
00093 #ifdef __😕
00094 }
00095 #endif
00096 #endif
