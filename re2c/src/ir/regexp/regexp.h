#ifndef _RE2C_IR_REGEXP_REGEXP_
#define _RE2C_IR_REGEXP_REGEXP_

#include "src/util/c99_stdint.h"
#include <iosfwd>
#include <set>
#include <vector>

#include "src/util/free_list.h"
#include "src/util/forbid_copy.h"

namespace re2c
{

struct nfa_state_t;
struct nfa_t;

typedef std::vector<uint32_t> charset_t;

class RegExp
{
public:
	static free_list <RegExp *> vFreeList;

	/*
	 * There're several different cases when the same regexp
	 * can be used multiple times:
	 * 	1) named definitions, e.g. digit = [0-9];
	 * 	2) counted repetition, e.g. "a"{3}, "a"{3,}, "a"{3,5}
	 * 	3) multiple DFA's sharing the same regexp , e.g. <c1, c2> "abc" { }
	 * 	4) common suffixes, e.g. suffix [\x80-\xBF] in UTF-8 ranges
	 * In cases 1-3, regexp must be recompiled each time it's reused.
	 * In case 4, regexp should be compiled only once, and instructions
	 * should be shared in order to reduce space.
	 *
	 * Note: if regexp must always be recompiled, it doesn't imply that
	 * parts of this regexp must always be recompiled. It only forces
	 * the compilation function to traverse the regexp after compilation
	 * and reset compilation cache for each sub-regexp. E.g., for a regexp
	 * [^]{3} in UTF-8 mode, each of sub-regexps [^] will have common suffix
	 * [\x80-\xBF] factored out, but they won't share instructions.
	 */
	nfa_state_t *ins_cache; /* if non-NULL, points to compiled instructions */
	enum InsAccess
	{
		SHARED,
		PRIVATE
	} ins_access;

	inline RegExp ()
		: ins_cache (NULL)
		, ins_access (SHARED)
	{
		vFreeList.insert (this);
	}
	inline virtual ~RegExp ()
	{
		vFreeList.erase (this);
	}
	virtual void split (std::set<uint32_t> &) = 0;
	virtual uint32_t calc_size() const = 0;
	virtual uint32_t fixedLength ();
	virtual nfa_state_t *compile(nfa_t &nfa, nfa_state_t *n) = 0;
	virtual void decompile () = 0;
	virtual void display (std::ostream &) const = 0;
	friend std::ostream & operator << (std::ostream & o, const RegExp & re);

	FORBID_COPY (RegExp);
};

RegExp * doAlt (RegExp * e1, RegExp * e2);
RegExp * mkAlt (RegExp * e1, RegExp * e2);
RegExp * doCat (RegExp * e1, RegExp * e2);
RegExp * repeat (RegExp * e, uint32_t n);
RegExp * repeat_from_to (RegExp * e, uint32_t n, uint32_t m);
RegExp * repeat_from (RegExp * e, uint32_t n);

} // end namespace re2c

#endif // _RE2C_IR_REGEXP_REGEXP_
