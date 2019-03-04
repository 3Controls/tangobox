%{
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
%}

%token ATTR
%token VALUE
%token PULSETYPE
%token BOOLVAL
%token NL
%token BACKSLASH
%token COLON

%start Input
%%

Input:
    /* Vide */
  | Input Ligne
  ;

Ligne:
  | NL					{ }
  | Expression NL    { }
  ;

Expression:
	ATTR COLON VALUE
	{
#ifdef YACC_DBG
		printf("YACC: ATTR %s = %g\n",$1.text,$3.val);
#endif
		/**** FOCUS ****/
		if((strcasecmp($1.text,"elin/focus/kly1/current") == 0) || (strcasecmp($1.text,"elin/focus/kly1_1/current") == 0))
			thevalues.focus_klyst1[0] = $3.val;
		else if((strcasecmp($1.text,"elin/focus/kly2/current") == 0) || (strcasecmp($1.text,"elin/focus/kly1_2/current") == 0))
			thevalues.focus_klyst1[1] = $3.val;
		else if((strcasecmp($1.text,"elin/focus/kly3/current") == 0) || (strcasecmp($1.text,"elin/focus/kly1_3/current") == 0))
			thevalues.focus_klyst1[2] = $3.val;
		else if((strcasecmp($1.text,"elin/focus/kly4/current") == 0) || (strcasecmp($1.text,"elin/focus/kly2_1/current") == 0))
			thevalues.focus_klyst2[0] = $3.val;
		else if((strcasecmp($1.text,"elin/focus/kly5/current") == 0) || (strcasecmp($1.text,"elin/focus/kly2_2/current") == 0))
			thevalues.focus_klyst2[1] = $3.val;
		else if((strcasecmp($1.text,"elin/focus/kly6/current") == 0) || (strcasecmp($1.text,"elin/focus/kly2_3/current") == 0))
			thevalues.focus_klyst2[2] = $3.val;
		else if(strcasecmp($1.text,"elin/focus/b1coil/current") == 0)
			thevalues.focus_beam1[0] = $3.val;
		else if(strcasecmp($1.text,"elin/focus/b2coil/current") == 0)
			thevalues.focus_beam1[1] = $3.val;
		else if(strcasecmp($1.text,"elin/focus/buncher/current") == 0)
			thevalues.focus_beam1[2] = $3.val;
		else if(strcasecmp($1.text,"elin/focus/lens/current") == 0)
			thevalues.focus_beam1[3] = $3.val;
		else if(strcasecmp($1.text,"elin/focus/triplet/current") == 0)
			thevalues.focus_beam1[4] = $3.val;
		else if(strcasecmp($1.text,"elin/focus/sect1/current") == 0)
			thevalues.focus_beam2[0] = $3.val;
		else if(strcasecmp($1.text,"elin/focus/sect2/current") == 0)
			thevalues.focus_beam2[1] = $3.val;
		else if(strcasecmp($1.text,"elin/focus/b3coil/current") == 0)
			thevalues.focus_beam1[6] = $3.val;
		else if(strcasecmp($1.text,"elin/focus/b4coil/current") == 0)
			thevalues.focus_beam1[7] = $3.val;
		/*** STEERERS ***/
		else if(strcasecmp($1.text,"elin/steer/gh1/current") == 0)
			thevalues.steer_beam[0] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/gv1/current") == 0)
			thevalues.steer_beam[1] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/bh1/current") == 0)
			thevalues.steer_beam[2] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/bv1/current") == 0)
			thevalues.steer_beam[3] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/bh2/current") == 0)
			thevalues.steer_beam[4] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/bv2/current") == 0)
			thevalues.steer_beam[5] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/s1h1/current") == 0)
			thevalues.steer_beam[6] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/s1v1/current") == 0)
			thevalues.steer_beam[7] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/s1h2/current") == 0)
			thevalues.steer_beam[8] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/s1v2/current") == 0)
			thevalues.steer_beam[9] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/triplet/current") == 0)
			thevalues.steer_beam[10] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/s2h1/current") == 0)
			thevalues.steer_beam[11] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/s2v1/current") == 0)
			thevalues.steer_beam[12] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/s2h2/current") == 0)
			thevalues.steer_beam[13] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/s2v2/current") == 0)
			thevalues.steer_beam[14] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/chan16/current") == 0)
			thevalues.steer_beam[15] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/gh2/current") == 0)
			thevalues.steer_beam[16] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/gv2/current") == 0)
			thevalues.steer_beam[17] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/gh3/current") == 0)
			thevalues.steer_beam[18] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/gv3/current") == 0)
			thevalues.steer_beam[19] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/gh4/current") == 0)
			thevalues.steer_beam[20] = $3.val;
		else if(strcasecmp($1.text,"elin/steer/gv4/current") == 0)
			thevalues.steer_beam[21] = $3.val;

		/*** MOD HV ***/
		else if(strcasecmp($1.text,"elin/mod1/hv/highvoltage") == 0)
			thevalues.mod_hv_v[0] = $3.val;
		else if(strcasecmp($1.text,"elin/mod2/hv/highvoltage") == 0)
			thevalues.mod_hv_v[1] = $3.val;
		/*** VPFN ***/
		else if(strcasecmp($1.text,"elin/mod1/run/vpfn") == 0)
			thevalues.vpfn[0] = $3.val;
		else if(strcasecmp($1.text,"elin/mod2/run/vpfn") == 0)
			thevalues.vpfn[1] = $3.val;
		/*** Phases and Attenu ***/
		else if(strcasecmp($1.text,"elin/rf/run/bunchphase") == 0)
			thevalues.bunch_phase = $3.val;
		else if(strcasecmp($1.text,"elin/rf/run/pbunchphase") == 0)
			thevalues.pbunch_phase = $3.val;
		else if(strcasecmp($1.text,"elin/rf/run/pbunchattenu") == 0)
			thevalues.pbunch_atten = $3.val;
		else if(strcasecmp($1.text,"elin/rf/run/sect2phase") == 0)
			thevalues.section_phase = $3.val;
		/*** GUN ***/
		else if(strcasecmp($1.text,"elin/gun/aux/heatv") == 0)
			thevalues.gun_heating_v = $3.val;
		else if(strcasecmp($1.text,"elin/beam/run/gridv") == 0)
			thevalues.gun_grid_v = $3.val;
		else if(strcasecmp($1.text,"elin/beam/run/pulsev") == 0)
			thevalues.gun_pulse_v = $3.val;
		else if(strcasecmp($1.text,"elin/beam/run/pulsel") == 0)
			thevalues.gun_pulse_l = $3.val;
		else if(strcasecmp($1.text,"elin/gun/hv/highvoltage") == 0)
			thevalues.gun_hv_v = $3.val;
		/*** RF ***/
		else if(strcasecmp($1.text,"elin/rf/run/frequency") == 0)
			thevalues.frequency = $3.val;
		/*** Timers ***/
		else if(strcasecmp($1.text,"elin/rf/run/delay") == 0)
			thevalues.timer_rf = $3.val;
		else if(strcasecmp($1.text,"elin/mod1/run/delay") == 0)
			thevalues.timer_mod[0] = $3.val;
		else if(strcasecmp($1.text,"elin/mod2/run/delay") == 0)
			thevalues.timer_mod[1] = $3.val;
		else if(strcasecmp($1.text,"elin/mod1/run/delays") == 0)
			thevalues.timer_mod_s[0] = $3.val;
		else if(strcasecmp($1.text,"elin/mod2/run/delays") == 0)
			thevalues.timer_mod_s[1] = $3.val;
		else printf("ATTRIBUTE %s IGNORED !!!!!!!!!!!!\n",$1.text);
	}
	| ATTR COLON PULSETYPE
	{
#ifdef YACC_DBG
		printf("YACC: ATTRPulse %s = %s\n",$1.text,$3.text);
#endif
		if(strcasecmp($1.text,"elin/beam/run/pulsetype") == 0)
		{
			if(strcasecmp($3.text,"long") == 0)
				thevalues.short_pulse = false;
			else
				thevalues.short_pulse = true;
		}
	}
	| ATTR COLON BOOLVAL
	{
#ifdef YACC_DBG
		if($3.val == 0)
			printf("YACC: ATTRBool %s = true\n",$1.text);
		else
			printf("YACC: ATTRBool %s = false\n",$1.text);
#endif
		if(strcasecmp($1.text,"elin/beam/run/in352mhz") == 0)
		{
			if($3.val == 0)
				thevalues.r352 = false; /* false <=> DEVOPEN */
			else
				thevalues.r352 = true; /* true <=> DEVCLOSE */
		}
	}
	;

%%

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
