#ifndef COREDEFINITIONSDEFINED
#define COREDEFINITIONSDEFINED

//to know what to do with dll export
#ifdef BUILD_DLL
#define XENGINE_API __declspec(dllexport)
#else
#define XENGINE_API __declspec(dllimport)
#endif

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)



#endif