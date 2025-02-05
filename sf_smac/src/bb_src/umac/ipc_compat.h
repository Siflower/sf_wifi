#ifndef _IPC_H_
#define _IPC_H_ 
#define __INLINE static __attribute__((__always_inline__)) inline
#define __ALIGN4 __aligned(4)
#define ASSERT_ERR(condition) \
    do { \
        if (unlikely(!(condition))) { \
            printk(KERN_ERR "%s:%d:ASSERT_ERR(" #condition ")\n", __FILE__, __LINE__); \
        } \
    } while(0)
#endif
