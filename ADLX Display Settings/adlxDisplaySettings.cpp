#include "../SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "../SDK/Include/IDisplaySettings.h"
#include "../SDK/Include/IDisplays.h"

#define ADLX_DisplaySettings _declspec(dllexport)

extern "C" {
    using namespace adlx;
    static ADLXHelper g_ADLXHelp;

    ADLX_DisplaySettings bool HasIntegerScalingSupport(int GPU)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get display service
            IADLXDisplayServicesPtr displayService;
            res = g_ADLXHelp.GetSystemServices()->GetDisplaysServices(&displayService);
            if (ADLX_SUCCEEDED(res))
            {
                // Get display list
                IADLXDisplayListPtr displayList;
                res = displayService->GetDisplays(&displayList);
                if (ADLX_SUCCEEDED(res))
                {
                    // Inspect for the first display in the list
                    adlx_uint index = GPU;
                    IADLXDisplayPtr display;
                    res = displayList->At(index, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayIntegerScalingPtr displayIntegerScaling;
                        res = displayService->GetIntegerScaling(display, &displayIntegerScaling);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            displayIntegerScaling->IsSupported(&supported);
                            result = supported;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_DisplaySettings bool GetIntegerScaling(int GPU)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get display service
            IADLXDisplayServicesPtr displayService;
            res = g_ADLXHelp.GetSystemServices()->GetDisplaysServices(&displayService);
            if (ADLX_SUCCEEDED(res))
            {
                // Get display list
                IADLXDisplayListPtr displayList;
                res = displayService->GetDisplays(&displayList);
                if (ADLX_SUCCEEDED(res))
                {
                    // Inspect for the first display in the list
                    adlx_uint index = GPU;
                    IADLXDisplayPtr display;
                    res = displayList->At(index, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayIntegerScalingPtr displayIntegerScaling;
                        res = displayService->GetIntegerScaling(display, &displayIntegerScaling);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool enabled = false;
                            res = displayIntegerScaling->IsEnabled(&enabled);
                            return enabled;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_DisplaySettings bool SetIntegerScaling(int GPU, bool enabled)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get display service
            IADLXDisplayServicesPtr displayService;
            res = g_ADLXHelp.GetSystemServices()->GetDisplaysServices(&displayService);
            if (ADLX_SUCCEEDED(res))
            {
                // Get display list
                IADLXDisplayListPtr displayList;
                res = displayService->GetDisplays(&displayList);
                if (ADLX_SUCCEEDED(res))
                {
                    // Inspect for the first display in the list
                    adlx_uint index = GPU;
                    IADLXDisplayPtr display;
                    res = displayList->At(index, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayIntegerScalingPtr displayIntegerScaling;
                        res = displayService->GetIntegerScaling(display, &displayIntegerScaling);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT res = displayIntegerScaling->SetEnabled(enabled);
                            result = ADLX_SUCCEEDED(res);
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }
}