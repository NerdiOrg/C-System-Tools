#include <windows.h>
int main() {

    SHELLEXECUTEINFO execInfo = {0};
    execInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    execInfo.fMask = SEE_MASK_DEFAULT;
    execInfo.hwnd = NULL;
    execInfo.lpVerb = "runas";  // request elevated perms
    execInfo.lpFile = "pkg\\run.exe"; 
    execInfo.lpParameters = "";  // parameters
    execInfo.nShow = SW_SHOWNORMAL;

    if(!ShellExecuteEx(&execInfo)) {
        DWORD dwStatus = GetLastError();
        // Handle the error
    }
    return 0;
}
