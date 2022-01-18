#include <iostream>

void bad_handle_example() {
    bool condition1 = false;
    bool condition2 = true;
    HANDLE handle = CreateFile(L"sample.txt",GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);
    if (handle == INVALID_HANDLE_VALUE) {
        return;
    }
    if (condition1) {
        CloseHandle(handle);
        return;
    }
    std::vector<char> buffer(1024);
    unsigned long bytesRead = 0;
    ReadFile(handle, buffer.data(), buffer.size(),&bytesRead,nullptr);
    if (condition2) {
        return;
    }
    function_that_throws();
    CloseHandle(handle);
}