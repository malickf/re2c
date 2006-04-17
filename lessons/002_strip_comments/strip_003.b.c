/* Generated by re2c */
#line 1 "strip_003.b.re"
/* re2c lesson 002_strip_comments, strip_003.b, (c) M. Boerger 2006 */
#line 29 "strip_003.b.re"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define YYMAXFILL 4
#define	BSIZE	128

#if BSIZE < YYMAXFILL
# error BSIZE must be greater YYMAXFILL
#endif

#define	YYCTYPE		char
#define	YYCURSOR	s.cur
#define	YYLIMIT		s.lim
#define YYMARKER	s.mrk
#define YYCTXMARKER s.ctx
#define	YYFILL(n)	{ if ((res = fill(&s, n)) >= 0) break; }

typedef struct Scanner
{
	FILE		*fp;
	char		*cur, *tok, *lim, *eof, *ctx, *mrk;
	char 		buffer[BSIZE];
} Scanner;

int fill(Scanner *s, int len)
{
	if (!len)
	{
		s->tok = s->cur = s->lim = s->mrk = s->buffer;
		s->eof = 0;
	}
	if (!s->eof)
	{
		int got, cnt = s->tok - s->buffer;

		if (cnt > 0)
		{
			memcpy(s->buffer, s->tok, s->lim - s->tok);
			s->tok -= cnt;
			s->cur -= cnt;
			s->lim -= cnt;
			s->mrk -= cnt;
			s->ctx -= cnt;
		}
		cnt = BSIZE - cnt;
		if ((got = fread(s->lim, 1, cnt, s->fp)) != cnt)
		{
			s->eof = &s->lim[got];
		}
		s->lim += got;
	}
	else if (s->cur + len > s->eof)
	{
		return 0; /* not enough input data */
	}
	return -1;
}

void echo(Scanner *s)
{
	fwrite(s->tok, 1, s->cur - s->tok, stdout);
}

int scan(FILE *fp)
{
	int  res = 0;
	int  nlcomment = 0;
    Scanner s;

	if (!fp)
	{
		return 1; /* no file was opened */
	}

    s.fp = fp;
	
	fill(&s, 0);

	for(;;)
	{
		s.tok = s.cur;
		{

#line 91 "<stdout>"
			{
				YYCTYPE yych;

				if((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
				yych = *YYCURSOR;
				if(yych <= 0x0C) {
					if(yych == 0x0A) goto yy5;
					goto yy6;
				} else {
					if(yych <= 0x0D) goto yy4;
					if(yych != '/') goto yy6;
				}
				++YYCURSOR;
				if((yych = *YYCURSOR) == '*') goto yy12;
				if(yych == '/') goto yy14;
yy3:
#line 122 "strip_003.b.re"
				{ fputc(*s.tok, stdout); continue; }
#line 110 "<stdout>"
yy4:
				yych = *(YYMARKER = ++YYCURSOR);
				if(yych == 0x0A) goto yy11;
				goto yy3;
yy5:
				YYCTXMARKER = YYCURSOR + 1;
				yych = *(YYMARKER = ++YYCURSOR);
				if(yych == '/') goto yy7;
				goto yy3;
yy6:
				yych = *++YYCURSOR;
				goto yy3;
yy7:
				yych = *++YYCURSOR;
				if(yych == '*') goto yy9;
yy8:
				YYCURSOR = YYMARKER;
				goto yy3;
yy9:
				++YYCURSOR;
				YYCURSOR = YYCTXMARKER;
#line 120 "strip_003.b.re"
				{ echo(&s); nlcomment = 1; continue; }
#line 134 "<stdout>"
yy11:
				YYCTXMARKER = YYCURSOR + 1;
				yych = *++YYCURSOR;
				if(yych == '/') goto yy7;
				goto yy8;
yy12:
				++YYCURSOR;
#line 121 "strip_003.b.re"
				{ goto comment; }
#line 144 "<stdout>"
yy14:
				++YYCURSOR;
#line 119 "strip_003.b.re"
				{ goto cppcomment; }
#line 149 "<stdout>"
			}
		}
#line 123 "strip_003.b.re"

comment:
		s.tok = s.cur;
		{

#line 158 "<stdout>"
			{
				YYCTYPE yych;
				if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
				yych = *YYCURSOR;
				if(yych != '*') goto yy20;
				++YYCURSOR;
				if((yych = *YYCURSOR) == '/') goto yy21;
yy19:
#line 128 "strip_003.b.re"
				{ goto comment; }
#line 169 "<stdout>"
yy20:
				yych = *++YYCURSOR;
				goto yy19;
yy21:
				++YYCURSOR;
#line 127 "strip_003.b.re"
				{ goto commentws; }
#line 177 "<stdout>"
			}
		}
#line 129 "strip_003.b.re"

commentws:
		s.tok = s.cur;
		{

#line 186 "<stdout>"
			{
				YYCTYPE yych;
				if((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
				yych = *YYCURSOR;
				if(yych <= 0x0D) {
					if(yych <= 0x09) {
						if(yych <= 0x08) goto yy32;
						goto yy31;
					} else {
						if(yych <= 0x0A) goto yy27;
						if(yych <= 0x0C) goto yy32;
					}
				} else {
					if(yych <= ' ') {
						if(yych <= 0x1F) goto yy32;
						goto yy31;
					} else {
						if(yych == '/') goto yy29;
						goto yy32;
					}
				}
				++YYCURSOR;
				if((yych = *YYCURSOR) == 0x0A) goto yy37;
yy26:
#line 142 "strip_003.b.re"
				{ goto commentws; }
#line 213 "<stdout>"
yy27:
				yych = *(YYMARKER = ++YYCURSOR);
				if(yych == '/') goto yy35;
yy28:
#line 134 "strip_003.b.re"
				{
				if (!nlcomment)
				{
					echo(&s);
				}
				nlcomment = 0;
				continue;
			}
#line 227 "<stdout>"
yy29:
				++YYCURSOR;
				if((yych = *YYCURSOR) == '*') goto yy33;
yy30:
#line 143 "strip_003.b.re"
				{ echo(&s); nlcomment = 0; continue; }
#line 234 "<stdout>"
yy31:
				yych = *++YYCURSOR;
				goto yy26;
yy32:
				yych = *++YYCURSOR;
				goto yy30;
yy33:
				++YYCURSOR;
#line 133 "strip_003.b.re"
				{ goto comment; }
#line 245 "<stdout>"
yy35:
				yych = *++YYCURSOR;
				if(yych == '*') goto yy33;
				YYCURSOR = YYMARKER;
				goto yy28;
yy37:
				yych = *(YYMARKER = ++YYCURSOR);
				if(yych == '/') goto yy35;
				goto yy28;
			}
		}
#line 144 "strip_003.b.re"

cppcomment:
		s.tok = s.cur;
		{

#line 263 "<stdout>"
			{
				YYCTYPE yych;
				if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
				yych = *YYCURSOR;
				if(yych == 0x0A) goto yy42;
				if(yych != 0x0D) goto yy44;
				++YYCURSOR;
				if((yych = *YYCURSOR) == 0x0A) goto yy45;
yy41:
#line 149 "strip_003.b.re"
				{ goto cppcomment; }
#line 275 "<stdout>"
yy42:
				++YYCURSOR;
yy43:
#line 148 "strip_003.b.re"
				{ echo(&s); continue; }
#line 281 "<stdout>"
yy44:
				yych = *++YYCURSOR;
				goto yy41;
yy45:
				++YYCURSOR;
				yych = *YYCURSOR;
				goto yy43;
			}
		}
#line 150 "strip_003.b.re"

	}

	if (fp != stdin)
	{
		fclose(fp); /* close only if not stdin */
	}
	return res; /* return result */
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		return scan(!strcmp(argv[1], "-") ? stdin : fopen(argv[1], "r"));
	}
	else
	{
		fprintf(stderr, "%s <expr>\n", argv[0]);
		return 1;
	}
}