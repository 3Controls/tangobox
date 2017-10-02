%{
/*static char RcsId[] = " $Header: ";*/
#include "global.h"
#include "LinacFileReader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static char * strToLower(char * str)
{
	unsigned int i;
	if(str == NULL)
		return NULL;
	for(i=0;i<strlen(str);i++)
	{
		str[i]=tolower(str[i]);
	}
	return str;
}
%}


%a 5000
%o 5000

blancs		[ \t]+
comment		#.*$
attr			.*"/".*"/".*"/".*"->__"[vV][aA][lL][uU][eE]
prop			.*"/".*"/".*"->"[^"__"].*
Value			[0-9.-]+
pulsetype	[lL][oO][nN][gG]|[sS][hH][oO][rR][tT]
boolval		[tT][rR][uU][eE]|[fF][aA][lL][sS][eE]

%%

{blancs}			{/* ignore */}
{comment}		{/* ignore */}
{prop}	{ 		
#ifdef LEX_DBG
	printf("LEX:Property : %s\n",yytext);
#endif
					/* ignore */}
{attr} 			{  
						/* suppress the suffix "->__value"*/
						yytext[yyleng-9] = '\0';
#ifdef LEX_DBG
						printf("LEX:ATTR !! %s\n",yytext);
#endif
						strncpy(yylval.text,strToLower(yytext),99);
						return ATTR; }
{Value}	{	
#ifdef LEX_DBG
				printf("LEX:VALUE !! %s\n",yytext);
#endif
				yylval.val = strtod(yytext,NULL);
				return VALUE; }
{pulsetype}	{ 	
#ifdef LEX_DBG
					printf("LEX:pulsetype %s\n",yytext);
#endif
					strncpy(yylval.text,strToLower(yytext),99);
					return PULSETYPE; }
{boolval}	{	
#ifdef LEX_DBG
					printf("LEX:boolval %s\n",yytext);
#endif
					strncpy(yylval.text,strToLower(yytext),99);
					if(strcmp(yylval.text,"true") == 0)
						yylval.val = 1;
					else
						yylval.val = 0;
					return BOOLVAL;
				}
"\n"	{return NL;}
":"	{return COLON; }
"\\"	{return BACKSLASH;}
