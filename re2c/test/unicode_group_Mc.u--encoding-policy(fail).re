#include <stdio.h>
#define YYCTYPE unsigned int
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Mc:
	/*!re2c
		re2c:yyfill:enable = 0;
		Mc = [\u0903-\u0903\u093b-\u093b\u093e-\u0940\u0949-\u094c\u094e-\u094f\u0982-\u0983\u09be-\u09c0\u09c7-\u09c8\u09cb-\u09cc\u09d7-\u09d7\u0a03-\u0a03\u0a3e-\u0a40\u0a83-\u0a83\u0abe-\u0ac0\u0ac9-\u0ac9\u0acb-\u0acc\u0b02-\u0b03\u0b3e-\u0b3e\u0b40-\u0b40\u0b47-\u0b48\u0b4b-\u0b4c\u0b57-\u0b57\u0bbe-\u0bbf\u0bc1-\u0bc2\u0bc6-\u0bc8\u0bca-\u0bcc\u0bd7-\u0bd7\u0c01-\u0c03\u0c41-\u0c44\u0c82-\u0c83\u0cbe-\u0cbe\u0cc0-\u0cc4\u0cc7-\u0cc8\u0cca-\u0ccb\u0cd5-\u0cd6\u0d02-\u0d03\u0d3e-\u0d40\u0d46-\u0d48\u0d4a-\u0d4c\u0d57-\u0d57\u0d82-\u0d83\u0dcf-\u0dd1\u0dd8-\u0ddf\u0df2-\u0df3\u0f3e-\u0f3f\u0f7f-\u0f7f\u102b-\u102c\u1031-\u1031\u1038-\u1038\u103b-\u103c\u1056-\u1057\u1062-\u1064\u1067-\u106d\u1083-\u1084\u1087-\u108c\u108f-\u108f\u109a-\u109c\u17b6-\u17b6\u17be-\u17c5\u17c7-\u17c8\u1923-\u1926\u1929-\u192b\u1930-\u1931\u1933-\u1938\u19b0-\u19c0\u19c8-\u19c9\u1a19-\u1a1b\u1a55-\u1a55\u1a57-\u1a57\u1a61-\u1a61\u1a63-\u1a64\u1a6d-\u1a72\u1b04-\u1b04\u1b35-\u1b35\u1b3b-\u1b3b\u1b3d-\u1b41\u1b43-\u1b44\u1b82-\u1b82\u1ba1-\u1ba1\u1ba6-\u1ba7\u1baa-\u1baa\u1be7-\u1be7\u1bea-\u1bec\u1bee-\u1bee\u1bf2-\u1bf3\u1c24-\u1c2b\u1c34-\u1c35\u1ce1-\u1ce1\u1cf2-\u1cf2\ua823-\ua824\ua827-\ua827\ua880-\ua881\ua8b4-\ua8c3\ua952-\ua953\ua983-\ua983\ua9b4-\ua9b5\ua9ba-\ua9bb\ua9bd-\ua9c0\uaa2f-\uaa30\uaa33-\uaa34\uaa4d-\uaa4d\uaa7b-\uaa7b\uabe3-\uabe4\uabe6-\uabe7\uabe9-\uabea\uabec-\uabec\U00011000-\U00011000\U00011002-\U00011002\U00011082-\U00011082\U000110b0-\U000110b2\U000110b7-\U000110b8\U0001d165-\U0001d166\U0001d16d-\U0001d172];
		Mc { goto Mc; }
		[^] { return YYCURSOR == limit; }
	*/
}
static const char buffer_Mc [] = "\x03\x09\x00\x00\x3B\x09\x00\x00\x3E\x09\x00\x00\x3F\x09\x00\x00\x40\x09\x00\x00\x49\x09\x00\x00\x4A\x09\x00\x00\x4B\x09\x00\x00\x4C\x09\x00\x00\x4E\x09\x00\x00\x4F\x09\x00\x00\x82\x09\x00\x00\x83\x09\x00\x00\xBE\x09\x00\x00\xBF\x09\x00\x00\xC0\x09\x00\x00\xC7\x09\x00\x00\xC8\x09\x00\x00\xCB\x09\x00\x00\xCC\x09\x00\x00\xD7\x09\x00\x00\x03\x0A\x00\x00\x3E\x0A\x00\x00\x3F\x0A\x00\x00\x40\x0A\x00\x00\x83\x0A\x00\x00\xBE\x0A\x00\x00\xBF\x0A\x00\x00\xC0\x0A\x00\x00\xC9\x0A\x00\x00\xCB\x0A\x00\x00\xCC\x0A\x00\x00\x02\x0B\x00\x00\x03\x0B\x00\x00\x3E\x0B\x00\x00\x40\x0B\x00\x00\x47\x0B\x00\x00\x48\x0B\x00\x00\x4B\x0B\x00\x00\x4C\x0B\x00\x00\x57\x0B\x00\x00\xBE\x0B\x00\x00\xBF\x0B\x00\x00\xC1\x0B\x00\x00\xC2\x0B\x00\x00\xC6\x0B\x00\x00\xC7\x0B\x00\x00\xC8\x0B\x00\x00\xCA\x0B\x00\x00\xCB\x0B\x00\x00\xCC\x0B\x00\x00\xD7\x0B\x00\x00\x01\x0C\x00\x00\x02\x0C\x00\x00\x03\x0C\x00\x00\x41\x0C\x00\x00\x42\x0C\x00\x00\x43\x0C\x00\x00\x44\x0C\x00\x00\x82\x0C\x00\x00\x83\x0C\x00\x00\xBE\x0C\x00\x00\xC0\x0C\x00\x00\xC1\x0C\x00\x00\xC2\x0C\x00\x00\xC3\x0C\x00\x00\xC4\x0C\x00\x00\xC7\x0C\x00\x00\xC8\x0C\x00\x00\xCA\x0C\x00\x00\xCB\x0C\x00\x00\xD5\x0C\x00\x00\xD6\x0C\x00\x00\x02\x0D\x00\x00\x03\x0D\x00\x00\x3E\x0D\x00\x00\x3F\x0D\x00\x00\x40\x0D\x00\x00\x46\x0D\x00\x00\x47\x0D\x00\x00\x48\x0D\x00\x00\x4A\x0D\x00\x00\x4B\x0D\x00\x00\x4C\x0D\x00\x00\x57\x0D\x00\x00\x82\x0D\x00\x00\x83\x0D\x00\x00\xCF\x0D\x00\x00\xD0\x0D\x00\x00\xD1\x0D\x00\x00\xD8\x0D\x00\x00\xD9\x0D\x00\x00\xDA\x0D\x00\x00\xDB\x0D\x00\x00\xDC\x0D\x00\x00\xDD\x0D\x00\x00\xDE\x0D\x00\x00\xDF\x0D\x00\x00\xF2\x0D\x00\x00\xF3\x0D\x00\x00\x3E\x0F\x00\x00\x3F\x0F\x00\x00\x7F\x0F\x00\x00\x2B\x10\x00\x00\x2C\x10\x00\x00\x31\x10\x00\x00\x38\x10\x00\x00\x3B\x10\x00\x00\x3C\x10\x00\x00\x56\x10\x00\x00\x57\x10\x00\x00\x62\x10\x00\x00\x63\x10\x00\x00\x64\x10\x00\x00\x67\x10\x00\x00\x68\x10\x00\x00\x69\x10\x00\x00\x6A\x10\x00\x00\x6B\x10\x00\x00\x6C\x10\x00\x00\x6D\x10\x00\x00\x83\x10\x00\x00\x84\x10\x00\x00\x87\x10\x00\x00\x88\x10\x00\x00\x89\x10\x00\x00\x8A\x10\x00\x00\x8B\x10\x00\x00\x8C\x10\x00\x00\x8F\x10\x00\x00\x9A\x10\x00\x00\x9B\x10\x00\x00\x9C\x10\x00\x00\xB6\x17\x00\x00\xBE\x17\x00\x00\xBF\x17\x00\x00\xC0\x17\x00\x00\xC1\x17\x00\x00\xC2\x17\x00\x00\xC3\x17\x00\x00\xC4\x17\x00\x00\xC5\x17\x00\x00\xC7\x17\x00\x00\xC8\x17\x00\x00\x23\x19\x00\x00\x24\x19\x00\x00\x25\x19\x00\x00\x26\x19\x00\x00\x29\x19\x00\x00\x2A\x19\x00\x00\x2B\x19\x00\x00\x30\x19\x00\x00\x31\x19\x00\x00\x33\x19\x00\x00\x34\x19\x00\x00\x35\x19\x00\x00\x36\x19\x00\x00\x37\x19\x00\x00\x38\x19\x00\x00\xB0\x19\x00\x00\xB1\x19\x00\x00\xB2\x19\x00\x00\xB3\x19\x00\x00\xB4\x19\x00\x00\xB5\x19\x00\x00\xB6\x19\x00\x00\xB7\x19\x00\x00\xB8\x19\x00\x00\xB9\x19\x00\x00\xBA\x19\x00\x00\xBB\x19\x00\x00\xBC\x19\x00\x00\xBD\x19\x00\x00\xBE\x19\x00\x00\xBF\x19\x00\x00\xC0\x19\x00\x00\xC8\x19\x00\x00\xC9\x19\x00\x00\x19\x1A\x00\x00\x1A\x1A\x00\x00\x1B\x1A\x00\x00\x55\x1A\x00\x00\x57\x1A\x00\x00\x61\x1A\x00\x00\x63\x1A\x00\x00\x64\x1A\x00\x00\x6D\x1A\x00\x00\x6E\x1A\x00\x00\x6F\x1A\x00\x00\x70\x1A\x00\x00\x71\x1A\x00\x00\x72\x1A\x00\x00\x04\x1B\x00\x00\x35\x1B\x00\x00\x3B\x1B\x00\x00\x3D\x1B\x00\x00\x3E\x1B\x00\x00\x3F\x1B\x00\x00\x40\x1B\x00\x00\x41\x1B\x00\x00\x43\x1B\x00\x00\x44\x1B\x00\x00\x82\x1B\x00\x00\xA1\x1B\x00\x00\xA6\x1B\x00\x00\xA7\x1B\x00\x00\xAA\x1B\x00\x00\xE7\x1B\x00\x00\xEA\x1B\x00\x00\xEB\x1B\x00\x00\xEC\x1B\x00\x00\xEE\x1B\x00\x00\xF2\x1B\x00\x00\xF3\x1B\x00\x00\x24\x1C\x00\x00\x25\x1C\x00\x00\x26\x1C\x00\x00\x27\x1C\x00\x00\x28\x1C\x00\x00\x29\x1C\x00\x00\x2A\x1C\x00\x00\x2B\x1C\x00\x00\x34\x1C\x00\x00\x35\x1C\x00\x00\xE1\x1C\x00\x00\xF2\x1C\x00\x00\x23\xA8\x00\x00\x24\xA8\x00\x00\x27\xA8\x00\x00\x80\xA8\x00\x00\x81\xA8\x00\x00\xB4\xA8\x00\x00\xB5\xA8\x00\x00\xB6\xA8\x00\x00\xB7\xA8\x00\x00\xB8\xA8\x00\x00\xB9\xA8\x00\x00\xBA\xA8\x00\x00\xBB\xA8\x00\x00\xBC\xA8\x00\x00\xBD\xA8\x00\x00\xBE\xA8\x00\x00\xBF\xA8\x00\x00\xC0\xA8\x00\x00\xC1\xA8\x00\x00\xC2\xA8\x00\x00\xC3\xA8\x00\x00\x52\xA9\x00\x00\x53\xA9\x00\x00\x83\xA9\x00\x00\xB4\xA9\x00\x00\xB5\xA9\x00\x00\xBA\xA9\x00\x00\xBB\xA9\x00\x00\xBD\xA9\x00\x00\xBE\xA9\x00\x00\xBF\xA9\x00\x00\xC0\xA9\x00\x00\x2F\xAA\x00\x00\x30\xAA\x00\x00\x33\xAA\x00\x00\x34\xAA\x00\x00\x4D\xAA\x00\x00\x7B\xAA\x00\x00\xE3\xAB\x00\x00\xE4\xAB\x00\x00\xE6\xAB\x00\x00\xE7\xAB\x00\x00\xE9\xAB\x00\x00\xEA\xAB\x00\x00\xEC\xAB\x00\x00\x00\x10\x01\x00\x02\x10\x01\x00\x82\x10\x01\x00\xB0\x10\x01\x00\xB1\x10\x01\x00\xB2\x10\x01\x00\xB7\x10\x01\x00\xB8\x10\x01\x00\x65\xD1\x01\x00\x66\xD1\x01\x00\x6D\xD1\x01\x00\x6E\xD1\x01\x00\x6F\xD1\x01\x00\x70\xD1\x01\x00\x71\xD1\x01\x00\x72\xD1\x01\x00\x00\x00\x00\x00";
int main ()
{
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_Mc), reinterpret_cast<const YYCTYPE *> (buffer_Mc + sizeof (buffer_Mc) - 1)))
		printf("test 'Mc' failed\n");
}