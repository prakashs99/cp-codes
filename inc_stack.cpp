#include<sys/resource.h>
#define inc_stack const rlim_t kStackSize = 64*1024*1024; struct rlimit rl; rl.rlim_cur = kStackSize; setrlimit(RLIMIT_STACK, &rl);

