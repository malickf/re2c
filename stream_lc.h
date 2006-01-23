/*
 Author: Marcus Boerger <helly@users.sourceforge.net>
*/

/* $Id$ */

#ifndef _stream_lc_h
#define _stream_lc_h

#include <iosfwd>
#include <fstream>
#include <assert.h>

namespace re2c
{

template<class _E>
class basic_null_streambuf
	: public std::basic_streambuf<_E>
{
public:
	basic_null_streambuf()
		: std::basic_streambuf<_E>()
	{
	}	
};

typedef basic_null_streambuf<char> null_streambuf;

template<class _E>
class basic_null_stream
	: public std::basic_ostream<_E>
{
public:
	basic_null_stream()
		: std::basic_ostream<_E>(&null_buf)
	{
	}

	basic_null_stream& put(_E)
	{
		// nothing to do
		return *this;
	}
	
	basic_null_stream& write(const _E *, std::streamsize)
	{
		// nothing to do
		return *this;
	}

protected:
	basic_null_streambuf<_E>  null_buf;
};

typedef basic_null_stream<char> null_stream;

class line_number
{
public:
	virtual ~line_number()
	{
	}

	virtual uint get_line() const = 0;
};

template<class _E, class _Tr = std::char_traits<_E> >
class basic_filebuf_lc
	: public std::basic_streambuf<_E, _Tr>
	, public line_number
{
public:
	typedef std::basic_streambuf<_E, _Tr> _Mybase;
	typedef basic_filebuf_lc<_E, _Tr> _Myt;
	typedef _E char_type;
	typedef _Tr traits_type;
	typedef typename _Tr::int_type int_type;
	typedef typename _Tr::pos_type pos_type;
	typedef typename _Tr::off_type off_type;

	basic_filebuf_lc(FILE *_fp = 0)
		: _Mybase()
		, fp(_fp)
		, must_close(false)
		, oline(1)
	{
	}

	virtual ~basic_filebuf_lc()
	{
		sync();
		if (must_close)
		{
			close();
		}
	}

	uint get_line() const
	{
		return oline + 1;
	}

	bool is_open() const
	{
		return fp != 0;
	}

	_Myt* open(const char *filename, std::ios_base::openmode mode = std::ios_base::out)
	{
		if (fp != 0)
		{
			return 0;
		}
		const char * fmode = (mode & std::ios_base::out)
		                   ? "w"
		                   : "r";
		if ((fp = fopen(filename, fmode)) == 0)
		{
			return 0;
		}

		must_close = true;
		return this;
	}

	_Myt* open(FILE * _fp)
	{
		if (fp != 0)
		{
			return 0;
		}
		fp = _fp;
		must_close = false;
		return this;
	}

	_Myt* close()
	{
		sync();

		if (fp == 0 || fclose(fp) != 0)
		{
			fp = 0;
			return 0;
		}
		else
		{
			fp = 0;
			return this;
		}
	}

protected:

	virtual int_type overflow(int_type c = _Tr::eof())
	{
		if (c == '\n')
		{
			++oline;
		}
		if (_Tr::eq_int_type(_Tr::eof(), c))
		{
			return _Tr::not_eof(c);
		}
		else
		{
			buffer += _Tr::to_char_type(c);
			return c;
		}
	}

	virtual int_type pbackfail(int_type c = _Tr::eof())
	{
		c = 0;
		assert(0);
		return 0;
	}

	virtual int_type underflow()
	{
		assert(0);
		return 0;
	}

	virtual int_type uflow()
	{
		assert(0);
		return 0;
	}

	virtual pos_type seekoff(off_type, std::ios_base::seekdir,
		std::ios_base::openmode = (std::ios_base::openmode)(std::ios_base::in | std::ios_base::out))
	{
		assert(0);
		return pos_type(~0);
	}

	virtual pos_type seekpos(pos_type,
		std::ios_base::openmode = (std::ios_base::openmode)(std::ios_base::in | std::ios_base::out))
	{
		assert(0);
		return pos_type(~0);
	}

	virtual _Mybase * setbuf(_E *, std::streamsize)
	{
		assert(0);
		return this;
	}

	virtual int sync()
	{
		fwrite(buffer.c_str(), sizeof(_E), buffer.length(), fp);
		buffer.clear();
		return fp == 0
			|| _Tr::eq_int_type(_Tr::eof(), overflow())
			|| 0 <= fflush(fp) ? 0 : -1;
	}

	virtual void imbue(const std::locale&)
	{
		assert(0);
	}

	std::streamsize xsputn(const _E *buf, std::streamsize cnt)
	{
		fwrite(buffer.c_str(), sizeof(_E), buffer.length(), fp);
		buffer.clear();
		oline += std::count(buf, buf + cnt, '\n');
		return fwrite(buf, sizeof(_E), cnt, fp);
	}

private:

	FILE * fp;
	bool   must_close;
	uint   oline;
	std::basic_string<_E, _Tr> buffer;
};

typedef basic_filebuf_lc<char> filebuf_lc;

template<class _E, class _Tr = std::char_traits<_E> >
class basic_ofstream_lc
	: public std::basic_ostream<_E, _Tr>
	, public line_number
{
public:
	typedef std::basic_ios<    _E, _Tr> _Myios;
	typedef std::basic_ostream<_E, _Tr> _Mybase;
	typedef basic_ofstream_lc< _E, _Tr> _Myt;
	typedef basic_filebuf_lc<  _E, _Tr> _Mybuf;

	basic_ofstream_lc()
		: _Mybase(&mybuf)  
	{
	}

	virtual ~basic_ofstream_lc()
	{
	}

	bool is_open() const
	{
		return mybuf.is_open();
	}

	void open(const char * filename, std::ios_base::openmode mode = std::ios_base::out)
	{
		if ((mode & std::ios_base::out) == 0 || mybuf.open(filename, mode) == 0)
		{
			_Myios::setstate(std::ios_base::failbit);
		}
	}
	
	void open(FILE *fp)
	{
		if (mybuf.open(fp) == 0)
		{
			_Myios::setstate(std::ios_base::failbit);
		}
	}
	
	void close()
	{
		if (mybuf.close() == 0)
		{
			_Myios::setstate(std::ios_base::failbit);
		}
	}
	
	uint get_line() const
	{
		return mybuf.get_line();
	}

protected:
	mutable _Mybuf mybuf;
};

typedef basic_ofstream_lc<char> ofstream_lc;

class file_info
{
public:

	static std::string escape(const std::string& _str)
	{
		std::string str(_str);
		size_t l = str.length();
		for (size_t p = 0; p < l; ++p)
		{
			if (str[p] == '\\')
			{
				str.insert(++p, "\\");
				++l;
			}
		}
		return str;
	}

	file_info()
		: ln(NULL)
	{
	}

	file_info(const std::string& _fname, const line_number* _ln, bool _escape = true)
		: fname(_escape ? escape(_fname) : _fname)
		, ln(_ln)
	{
	}

	file_info(const file_info& oth, const line_number* _ln = NULL)
		: fname(oth.fname)
		, ln(_ln)
	{
	}

	file_info& operator = (const file_info& oth)
	{
		new (this) file_info(oth.fname, oth.ln, false);
		return *this;
	}

	const std::string  fname;
	const line_number* ln;
};

std::ostream& operator << (std::ostream& o, const file_info& li);

} // end namespace re2c

#endif /* _stream_lc_h */