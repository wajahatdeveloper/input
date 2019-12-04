#include "Common.h"

inline void zero_size(void* mem, u64 size)
{
	u8* dest = (u8*)mem;
	for (u64 i = 0; i < size; i++)
	{
		*dest++ = 0;
	}
}
