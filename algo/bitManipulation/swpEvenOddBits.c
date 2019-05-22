#include <stdio.h>
#include <stdint.h>

uint32_t swpBits(uint32_t val)
{
    uint32_t even = val & 0x55555555;
    uint32_t odd = val & 0xAAAAAAAA;

    even <<= 1;
    odd >>= 1;

    return (even | odd);
}

int main() {
	//code
	int tc;
	scanf("%d",&tc);
	uint32_t val;

	for(size_t itr = 0; itr < tc; ++itr)
	{
	    scanf("%u",&val);
	    val = swpBits(val);
	    printf("%u\n",val);
	}

	return 0;
}
