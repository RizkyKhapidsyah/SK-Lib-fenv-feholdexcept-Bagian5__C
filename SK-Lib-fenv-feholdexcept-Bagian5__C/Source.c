// pragma_directive_fenv_access_x86.cpp
// compile with: /O2 /arch:IA32
// processor: x86

/*  Source by Microsoft 
    Modified For Learn by Rizky Khapidsyah */

#include <stdio.h>
#include <float.h>
#include <errno.h>
#include <conio.h>

#pragma fenv_access (on)

int main() {
    double z, b = 0.1, t = 0.1;
    unsigned int currentControl;
    errno_t err;

    err = _controlfp_s(&currentControl, _PC_24, _MCW_PC);

    if (err != 0) {
        printf_s("The function _controlfp_s failed!\n");
        return -1;
    }
    
    z = b * t;
    
    printf_s("out=%.15e\n", z);

    _getch();
    return 0;
}