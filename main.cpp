#include <windows.h>
#include <iostream>
#include "FindProcessID.h"
#include "GetBaseModuleAddress.h"
#include "spdlog/spdlog.h"
#include "FindDMAAddy.h"
#include "mem.h"
int main()
{
    bool brecoil = false;
    bool GodMode = false;
    bool InfiniteAmmo = false;
    spdlog::info("assult cube external hack started");
    DWORD processID = FindProcessID(L"ac_client.exe");
    if (processID == 0)
    {
        spdlog::error("assult cube process not found");
        return 1;
    }
    spdlog::info("assult cube process found with ID: {}", processID);

    uintptr_t baseAddress = GetBaseModuleAddress(processID, L"ac_client.exe");
    spdlog::info("Base module address found: {}", reinterpret_cast<void *>(baseAddress));

    uintptr_t localPlayerAddress = baseAddress + 0x10F4F4;
    spdlog::info("Local player address calculated: {}", reinterpret_cast<void *>(localPlayerAddress));

    HANDLE Current_Handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);

    uintptr_t healthAddress = FindDMAAddy(Current_Handle, localPlayerAddress, {0xF8});
    spdlog::info("Health address calculated: {}", reinterpret_cast<void *>(healthAddress));

    uintptr_t RecoilFunctionStart = baseAddress + 0x62020;
    uintptr_t RecoilFunctionCaller = baseAddress + 0x63786;

    uintptr_t Bullet_Decrease_function_location = baseAddress + 0x637E9;

    DWORD exit;
    while (GetExitCodeProcess(Current_Handle, &exit) && exit == STILL_ACTIVE)
    {

        if (GetAsyncKeyState(VK_F1) & 1)
        {
            brecoil = !brecoil;
            if (brecoil == true)
            {
                std::cout << "Recoil hacks on " << '\n';
                mem::NopEX((BYTE *)RecoilFunctionCaller, 10, Current_Handle);
            }
            if (brecoil == false)
            {
                std::cout << "Recoil hack off " << '\n';
                mem::PatchEX((BYTE *)RecoilFunctionCaller, (BYTE *)"\x50\x8D\x4C\x24\x1C\x51\x8B\xCE\xFF\xD2", 10, Current_Handle);
            }
        }

        if (GetAsyncKeyState(VK_F2) & 1)
        {
            GodMode = !GodMode;
            if (GodMode)
            {
                std::cout << "God mode on " << '\n';
            }
            else
            {
                std::cout << "God mode off " << '\n';
            }
        }
        if (GetAsyncKeyState(VK_F3) & 1)
        {
            InfiniteAmmo = !InfiniteAmmo;
            if (InfiniteAmmo)
            {
                std::cout << "Infinite ammo on " << '\n';
                mem::NopEX((BYTE *)Bullet_Decrease_function_location, 2, Current_Handle);
            }
            else
            {
                std::cout << "Infinite ammo off " << '\n';
                mem::PatchEX((BYTE *)Bullet_Decrease_function_location, (BYTE *)"\xFF\x0E", 2, Current_Handle);
            }
        }
        if (GodMode)
        {
            int newValue = 1337;
            mem::PatchEX((BYTE *)healthAddress, (BYTE *)&newValue, sizeof(newValue), Current_Handle);

            // we have to use virtual protect to change the memory protection of the health address to allow writing,
            // then we can write the new value to it. After that,
            // we should restore the original memory protection.
            // This is necessary because most game memory is protected against writing to prevent exactly this kind of hack.
            // *reinterpret_cast<int*>(healthAddress)=1337;
        }
    }
}
