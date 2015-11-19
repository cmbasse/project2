#define FNV_32_prime 16777619
#define FNV_32_offset 2166136261

unsigned int FNV(const void *bytes, int len);

int myhash(const void *bytes, int len, int array_length);