#include "common/common.h"

#include <Windows.h>

namespace cmn
{
std::vector<char> GetBinaryKey(const std::wstring& key, const std::wstring& name)
{
    HKEY hKey{};
    DWORD disp{};
    CHECK_RET_ERR(e, RegOpenKeyExW(HKEY_CURRENT_USER, key.c_str(), 0, KEY_READ, &hKey));
    auto kKeyGuard = scopedAction([&hKey]() { RegCloseKey(hKey); });

    std::vector<char> res(0x100);
    DWORD bytesRead = res.size();
    
    CHECK_RET_ERR(e1, RegQueryValueExW(hKey, name.c_str(), 0, 0, (BYTE*)&res[0], &bytesRead));
    res.resize(bytesRead);
    return res;
}
} // namespace cmn