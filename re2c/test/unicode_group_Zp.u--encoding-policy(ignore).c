/* Generated by re2c */
#line 1 "unicode_group_Zp.u--encoding-policy(ignore).re"
#include <stdio.h>
#define YYCTYPE unsigned int
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Zp:
	
#line 12 "<stdout>"
{
	YYCTYPE yych;

	yych = *YYCURSOR;
	if (yych != 0x00002029) goto yy4;
	++YYCURSOR;
#line 11 "unicode_group_Zp.u--encoding-policy(ignore).re"
	{ goto Zp; }
#line 21 "<stdout>"
yy4:
	++YYCURSOR;
#line 12 "unicode_group_Zp.u--encoding-policy(ignore).re"
	{ return YYCURSOR == limit; }
#line 26 "<stdout>"
}
#line 13 "unicode_group_Zp.u--encoding-policy(ignore).re"

}
static const char buffer_Zp [] = "\x29\x20\x00\x00\x00\x00\x00\x00";
int main ()
{
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_Zp), reinterpret_cast<const YYCTYPE *> (buffer_Zp + sizeof (buffer_Zp) - 1)))
		printf("test 'Zp' failed\n");
}