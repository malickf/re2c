#ifndef _RE2C_IR_NFA_NFA_
#define _RE2C_IR_NFA_NFA_

#include "src/util/c99_stdint.h"
#include <vector>
#include <set>

#include "src/util/forbid_copy.h"

namespace re2c
{

struct Range;
struct RegExp;
struct RuleOp;

struct nfa_state_t
{
	enum type_t
	{
		ALT,
//		CHR,
		RAN,
		CTX,
		FIN
	} type;
	union
	{
		struct
		{
			nfa_state_t *out1;
			nfa_state_t *out2;
		} alt;
//		struct
//		{
//			nfa_state_t *out;
//			uint32_t chr;
//		} chr;
		struct
		{
			nfa_state_t *out;
			Range *ran;
		} ran;
		struct
		{
			nfa_state_t *out;
		} ctx;
		struct
		{
			RuleOp *rule;
		} fin;
	} value;
	bool mark;

	void alt(nfa_state_t *s1, nfa_state_t *s2)
	{
		type = ALT;
		value.alt.out1 = s1;
		value.alt.out2 = s2;
		mark = false;
	}
//	void chr(nfa_state_t *s, uint32_t c)
//	{
//		type = CHR;
//		value.chr.out = s;
//		value.chr.chr = c;
//		mark = false;
//	}
	void ran(nfa_state_t *s, Range *r)
	{
		type = RAN;
		value.ran.out = s;
		value.ran.ran = r;
		mark = false;
	}
	void ctx(nfa_state_t *s)
	{
		type = CTX;
		value.ctx.out = s;
		mark = false;
	}
	void fin(RuleOp *r)
	{
		type = FIN;
		value.fin.rule = r;
		mark = false;
	}
};

struct nfa_t
{
	const uint32_t max_size;
	uint32_t size;
	nfa_state_t *states;
	nfa_state_t *root;

	nfa_t(RegExp *re);
	~nfa_t();

	FORBID_COPY(nfa_t);
};

} // namespace re2c

#endif // _RE2C_IR_NFA_NFA_
