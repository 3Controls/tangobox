#ifndef lint
static char const 
yyrcsid[] = "$FreeBSD: src/usr.bin/yacc/skeleton.c,v 1.28 2000/01/17 02:04:06 bde Exp $";
#endif
#include <stdlib.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
static int yygrowstack();
#define YYPREFIX "yy"
#line 2 "LinacFileReader.y"
/*static char RcsId[] = " $Header: /segfs/tango/cvsroot/cppserver/machine/linac/LinacSequencer/LinacFileReader.y,v 1.23 2010/06/17 11:31:03 vedder Exp $ ";*/
#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "LinacStructure.h"

static Values thevalues;
int doLex(char *filename);
extern FILE *yyin,*yyout;
void yyerror(const char *);
int yywrap(void);
extern int yylex(void);
extern int yyparse(void);

/*#define YACC_DBG*/
#line 35 "y.tab.c"
#define YYERRCODE 256
#define ATTR 257
#define VALUE 258
#define PULSETYPE 259
#define BOOLVAL 260
#define NL 261
#define BACKSLASH 262
#define COLON 263
const short yylhs[] = {                                        -1,
    0,    0,    1,    1,    1,    2,    2,    2,
};
const short yylen[] = {                                         2,
    0,    2,    0,    1,    2,    3,    3,    3,
};
const short yydefred[] = {                                      1,
    0,    0,    4,    2,    0,    0,    5,    6,    7,    8,
};
const short yydgoto[] = {                                       1,
    4,    5,
};
const short yysindex[] = {                                      0,
 -257, -262,    0,    0, -259, -253,    0,    0,    0,    0,
};
const short yyrindex[] = {                                      0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
const short yygindex[] = {                                      0,
    0,    0,
};
#define YYTABLESIZE 7
const short yytable[] = {                                       2,
    6,    7,    3,    3,    8,    9,   10,
};
const short yycheck[] = {                                     257,
  263,  261,    0,  261,  258,  259,  260,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 263
#if YYDEBUG
const char * const yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ATTR","VALUE","PULSETYPE",
"BOOLVAL","NL","BACKSLASH","COLON",
};
const char * const yyrule[] = {
"$accept : Input",
"Input :",
"Input : Input Ligne",
"Ligne :",
"Ligne : NL",
"Ligne : Expression NL",
"Expression : ATTR COLON VALUE",
"Expression : ATTR COLON PULSETYPE",
"Expression : ATTR COLON BOOLVAL",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#if YYDEBUG
#include <stdio.h>
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
int yystacksize;
#line 203 "LinacFileReader.y"

void yyerror(const char *s)
{
	fprintf(stderr,"%s\n",s);
}

int yywrap(void)
{
#ifdef YACC_DBG
	printf("End of input\n");
#endif
	return 1;
}

Values * getValFromFile(const char * filename,Values defaultVal)
{
#ifdef YACC_DBG
	printf("# LinacFileReader\n");
	printf("# Parsing file ...\n");
#endif
	if(filename == NULL)
	{
		printf("LinacFileReader.y::getValFromFile: filename = NULL\n");
		yyin = fdopen(0,"r");
	}
	else
	{
#ifdef YACC_DBG
		printf("LinacFileReader.y::getValFromFile: filename = %s\n",filename);
#else
	/* to prevent lex from printing all not recognised characters */
		yyout = fopen("/dev/null","r");
#endif
		yyin = fopen(filename,"r");
	}
	/* initialize default Values */
	thevalues = defaultVal;
   if(yyparse()!=0)
		return NULL;
	fclose(yyin);
#ifdef YACC_DBG
	printf("LinacFileReader.y::getValFromFile exiting ...\n");
#endif
	return &thevalues;
}
#line 176 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack()
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    i = yyssp - yyss;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss);
    if (newss == NULL)
        return -1;
    yyss = newss;
    yyssp = newss + i;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs);
    if (newvs == NULL)
        return -1;
    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

#ifndef YYPARSE_PARAM
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG void
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif	/* ANSI-C/C++ */
#else	/* YYPARSE_PARAM */
#ifndef YYPARSE_PARAM_TYPE
#define YYPARSE_PARAM_TYPE void *
#endif
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG YYPARSE_PARAM_TYPE YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL YYPARSE_PARAM_TYPE YYPARSE_PARAM;
#endif	/* ANSI-C/C++ */
#endif	/* ! YYPARSE_PARAM */

int
yyparse (YYPARSE_PARAM_ARG)
    YYPARSE_PARAM_DECL
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate])) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#if defined(lint) || defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(lint) || defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 4:
#line 38 "LinacFileReader.y"
{ }
break;
case 5:
#line 39 "LinacFileReader.y"
{ }
break;
case 6:
#line 44 "LinacFileReader.y"
{
#ifdef YACC_DBG
		printf("YACC: ATTR %s = %g\n",yyvsp[-2].text,yyvsp[0].val);
#endif
		/**** FOCUS ****/
		if((strcasecmp(yyvsp[-2].text,"elin/focus/kly1/current") == 0) || (strcasecmp(yyvsp[-2].text,"elin/focus/kly1_1/current") == 0))
			thevalues.focus_klyst1[0] = yyvsp[0].val;
		else if((strcasecmp(yyvsp[-2].text,"elin/focus/kly2/current") == 0) || (strcasecmp(yyvsp[-2].text,"elin/focus/kly1_2/current") == 0))
			thevalues.focus_klyst1[1] = yyvsp[0].val;
		else if((strcasecmp(yyvsp[-2].text,"elin/focus/kly3/current") == 0) || (strcasecmp(yyvsp[-2].text,"elin/focus/kly1_3/current") == 0))
			thevalues.focus_klyst1[2] = yyvsp[0].val;
		else if((strcasecmp(yyvsp[-2].text,"elin/focus/kly4/current") == 0) || (strcasecmp(yyvsp[-2].text,"elin/focus/kly2_1/current") == 0))
			thevalues.focus_klyst2[0] = yyvsp[0].val;
		else if((strcasecmp(yyvsp[-2].text,"elin/focus/kly5/current") == 0) || (strcasecmp(yyvsp[-2].text,"elin/focus/kly2_2/current") == 0))
			thevalues.focus_klyst2[1] = yyvsp[0].val;
		else if((strcasecmp(yyvsp[-2].text,"elin/focus/kly6/current") == 0) || (strcasecmp(yyvsp[-2].text,"elin/focus/kly2_3/current") == 0))
			thevalues.focus_klyst2[2] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/focus/b1coil/current") == 0)
			thevalues.focus_beam1[0] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/focus/b2coil/current") == 0)
			thevalues.focus_beam1[1] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/focus/buncher/current") == 0)
			thevalues.focus_beam1[2] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/focus/lens/current") == 0)
			thevalues.focus_beam1[3] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/focus/triplet/current") == 0)
			thevalues.focus_beam1[4] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/focus/sect1/current") == 0)
			thevalues.focus_beam2[0] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/focus/sect2/current") == 0)
			thevalues.focus_beam2[1] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/focus/b3coil/current") == 0)
			thevalues.focus_beam1[6] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/focus/b4coil/current") == 0)
			thevalues.focus_beam1[7] = yyvsp[0].val;
		/*** STEERERS ***/
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/gh1/current") == 0)
			thevalues.steer_beam[0] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/gv1/current") == 0)
			thevalues.steer_beam[1] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/bh1/current") == 0)
			thevalues.steer_beam[2] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/bv1/current") == 0)
			thevalues.steer_beam[3] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/bh2/current") == 0)
			thevalues.steer_beam[4] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/bv2/current") == 0)
			thevalues.steer_beam[5] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/s1h1/current") == 0)
			thevalues.steer_beam[6] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/s1v1/current") == 0)
			thevalues.steer_beam[7] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/s1h2/current") == 0)
			thevalues.steer_beam[8] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/s1v2/current") == 0)
			thevalues.steer_beam[9] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/triplet/current") == 0)
			thevalues.steer_beam[10] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/s2h1/current") == 0)
			thevalues.steer_beam[11] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/s2v1/current") == 0)
			thevalues.steer_beam[12] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/s2h2/current") == 0)
			thevalues.steer_beam[13] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/s2v2/current") == 0)
			thevalues.steer_beam[14] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/chan16/current") == 0)
			thevalues.steer_beam[15] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/gh2/current") == 0)
			thevalues.steer_beam[16] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/gv2/current") == 0)
			thevalues.steer_beam[17] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/gh3/current") == 0)
			thevalues.steer_beam[18] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/gv3/current") == 0)
			thevalues.steer_beam[19] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/gh4/current") == 0)
			thevalues.steer_beam[20] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/steer/gv4/current") == 0)
			thevalues.steer_beam[21] = yyvsp[0].val;

		/*** MOD HV ***/
		else if(strcasecmp(yyvsp[-2].text,"elin/mod1/hv/highvoltage") == 0)
			thevalues.mod_hv_v[0] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/mod2/hv/highvoltage") == 0)
			thevalues.mod_hv_v[1] = yyvsp[0].val;
		/*** VPFN ***/
		else if(strcasecmp(yyvsp[-2].text,"elin/mod1/run/vpfn") == 0)
			thevalues.vpfn[0] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/mod2/run/vpfn") == 0)
			thevalues.vpfn[1] = yyvsp[0].val;
		/*** Phases and Attenu ***/
		else if(strcasecmp(yyvsp[-2].text,"elin/rf/run/bunchphase") == 0)
			thevalues.bunch_phase = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/rf/run/pbunchphase") == 0)
			thevalues.pbunch_phase = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/rf/run/pbunchattenu") == 0)
			thevalues.pbunch_atten = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/rf/run/sect2phase") == 0)
			thevalues.section_phase = yyvsp[0].val;
		/*** GUN ***/
		else if(strcasecmp(yyvsp[-2].text,"elin/gun/aux/heatv") == 0)
			thevalues.gun_heating_v = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/beam/run/gridv") == 0)
			thevalues.gun_grid_v = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/beam/run/pulsev") == 0)
			thevalues.gun_pulse_v = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/beam/run/pulsel") == 0)
			thevalues.gun_pulse_l = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/gun/hv/highvoltage") == 0)
			thevalues.gun_hv_v = yyvsp[0].val;
		/*** RF ***/
		else if(strcasecmp(yyvsp[-2].text,"elin/rf/run/frequency") == 0)
			thevalues.frequency = yyvsp[0].val;
		/*** Timers ***/
		else if(strcasecmp(yyvsp[-2].text,"elin/rf/run/delay") == 0)
			thevalues.timer_rf = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/mod1/run/delay") == 0)
			thevalues.timer_mod[0] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/mod2/run/delay") == 0)
			thevalues.timer_mod[1] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/mod1/run/delays") == 0)
			thevalues.timer_mod_s[0] = yyvsp[0].val;
		else if(strcasecmp(yyvsp[-2].text,"elin/mod2/run/delays") == 0)
			thevalues.timer_mod_s[1] = yyvsp[0].val;
		else printf("ATTRIBUTE %s IGNORED !!!!!!!!!!!!\n",yyvsp[-2].text);
	}
break;
case 7:
#line 172 "LinacFileReader.y"
{
#ifdef YACC_DBG
		printf("YACC: ATTRPulse %s = %s\n",yyvsp[-2].text,yyvsp[0].text);
#endif
		if(strcasecmp(yyvsp[-2].text,"elin/beam/run/pulsetype") == 0)
		{
			if(strcasecmp(yyvsp[0].text,"long") == 0)
				thevalues.short_pulse = false;
			else
				thevalues.short_pulse = true;
		}
	}
break;
case 8:
#line 185 "LinacFileReader.y"
{
#ifdef YACC_DBG
		if(yyvsp[0].val == 0)
			printf("YACC: ATTRBool %s = true\n",yyvsp[-2].text);
		else
			printf("YACC: ATTRBool %s = false\n",yyvsp[-2].text);
#endif
		if(strcasecmp(yyvsp[-2].text,"elin/beam/run/in352mhz") == 0)
		{
			if(yyvsp[0].val == 0)
				thevalues.r352 = false; /* false <=> DEVOPEN */
			else
				thevalues.r352 = true; /* true <=> DEVCLOSE */
		}
	}
break;
#line 542 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
