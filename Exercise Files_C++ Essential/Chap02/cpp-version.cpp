// cpp-version.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

#if defined __clang__
constexpr char compiler[] = "Clang";
constexpr char version_string[] = __clang_version__;
constexpr unsigned int version_int = 0;
#elif defined _MSC_VER
constexpr char compiler[] = "Microsoft C++";
constexpr unsigned int version_int = _MSC_VER;
constexpr char version_string[] = "";
#elif defined __GNUG__
constexpr char compiler[] = "gcc";
constexpr char version_string[] = __VERSION__;
constexpr unsigned int version_int = 0;
#else
constexpr char compiler[] = "unk";
constexpr char version_string[] = "unk";
constexpr unsigned int version_int = 0;
#endif // lang

int main()
{
    if (version_int) {
        printf("%s version %d\n", compiler, version_int);
    } else {
        printf("%s version %s\n", compiler, version_string);
    }
    return 0;
}
