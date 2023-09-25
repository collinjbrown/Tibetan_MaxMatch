#include "scrubber.h"

#include <iostream>

std::wstring Scrub(std::wstring in, bool keepSpaces)
{
	std::wstring out;
	wchar_t lastChar = L' ';

	for (int i = 0; i < in.size(); i++)
	{
		int val = (int)in[i];

		// We'll see if this actually works.
		if (val == 32 || val == (int)L'།' || (val >= (int)L'༠' && val < (int)L'྾'))
		{
			if (val == 32 && lastChar == L' ' ||
				val == 32 && lastChar == L'\n') continue;
			if (val == 32 && !keepSpaces) continue;

			out += in[i];
			lastChar = in[i];
			if (val == (int)L'།')
			{
				out += L'\n';
				lastChar = L'\n';
			}
		}
	}

	return out;
}