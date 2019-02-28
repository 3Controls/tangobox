/*static char RcsId[] = " $Header: /segfs/tango/cvsroot/cppserver/machine/linac/LinacSequencer/global.h,v 1.23 2010/06/17 11:31:03 vedder Exp $"; */
struct doublestr
{
	double val;
	char text[100];
};

#define YYSTYPE struct doublestr
extern YYSTYPE yylval;

#ifndef YY_NULL
#define YY_NULL 0
#endif



