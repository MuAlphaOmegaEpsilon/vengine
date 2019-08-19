// Code shorteners (never undef)
#ifndef RET_ON_ERR
#define RET_ON_ERR(fnCall) if (const VkError e = fnCall; e) return e
#endif

// Declaration shorteners
#define DEFINE_VK_HANDLE(name) struct name##_T; using name = name##_T*

// Namespace names shorteners
#define VE vengine
#define VE_AL vengine::algorithm
#define VE_HE vengine::helper
#define VE_VK vengine::vulkan

// Specifiers shorteners
#define INL inline
#define NX noexcept 
#define ND [[nodiscard]]