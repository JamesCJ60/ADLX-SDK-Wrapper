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

    ADLX_DisplaySettings bool HasGPUScalingSupport(int GPU)
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
                        IADLXDisplayGPUScalingPtr gpuScaling;
                        res = displayService->GetGPUScaling(display, &gpuScaling);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            gpuScaling->IsSupported(&supported);
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

    ADLX_DisplaySettings bool GetGPUScaling(int GPU)
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
                        IADLXDisplayGPUScalingPtr gpuScaling;
                        res = displayService->GetGPUScaling(display, &gpuScaling);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool enabled = false;
                            res = gpuScaling->IsEnabled(&enabled);
                            result = enabled;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_DisplaySettings bool SetGPUScaling(int GPU, bool enabled)
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
                        IADLXDisplayGPUScalingPtr gpuScaling;
                        res = displayService->GetGPUScaling(display, &gpuScaling);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT res = gpuScaling->SetEnabled(enabled);
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

    ADLX_DisplaySettings bool HasScalingModeSupport(int GPU)
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
                        IADLXDisplayScalingModePtr scalingMode;
                        res = displayService->GetScalingMode(display, &scalingMode);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            scalingMode->IsSupported(&supported);
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

    ADLX_DisplaySettings int GetScalingMode(int GPU)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        int result = -1;

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
                        IADLXDisplayScalingModePtr scalingMode;
                        res = displayService->GetScalingMode(display, &scalingMode);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_SCALE_MODE scaleMode;
                            res = scalingMode->GetMode(&scaleMode);
                            result = scaleMode;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_DisplaySettings bool SetScalingMode(int GPU, int mode)
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
                        IADLXDisplayScalingModePtr scalingMode;
                        res = displayService->GetScalingMode(display, &scalingMode);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT res = scalingMode->SetMode((ADLX_SCALE_MODE)mode);
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