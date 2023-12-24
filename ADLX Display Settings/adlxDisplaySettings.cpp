#include "SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "SDK/Include/IDisplaySettings.h"
#include "SDK/Include/IDisplays.h"

#define ADLX_DisplaySettings _declspec(dllexport)

extern "C" {
    using namespace adlx;
    static ADLXHelper g_ADLXHelp;

    ADLX_DisplaySettings bool HasIntegerScalingSupport()
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;

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
                    adlx_uint it = 0;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayIntegerScalingPtr displayIntegerScaling;
                        res = displayService->GetIntegerScaling(display, &displayIntegerScaling);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayIntegerScaling->IsSupported(&supported);
                            return supported;
                        }


                    }
                }
                else
                {

                }
            }
            else
            {
                // Destroy ADLX
                res = g_ADLXHelp.Terminate();

            }
        }
        else
        {

        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();

    }

    ADLX_DisplaySettings bool IsIntegerScalingEnabled()
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;

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
                    adlx_uint it = 0;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayIntegerScalingPtr displayIntegerScaling;
                        res = displayService->GetIntegerScaling(display, &displayIntegerScaling);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayIntegerScaling->IsSupported(&supported);
                            return supported;
                        }


                    }
                }
                else
                {

                }
            }
            else
            {
                // Destroy ADLX
                res = g_ADLXHelp.Terminate();

            }
        }
        else
        {

        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();

    }
    ADLX_DisplaySettings int SetIntegerScaling(const int key)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;

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
                    adlx_uint it = 0;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayIntegerScalingPtr displayIntegerScaling;
                        res = displayService->GetIntegerScaling(display, &displayIntegerScaling);

                        if (ADLX_SUCCEEDED(res))
                        {
                            res = ADLX_FAIL;
                            switch (key)
                            {
                                // Set integer scaling disabled
                            case 0:

                                res = displayIntegerScaling->SetEnabled(false);
                                break;
                                // Set integer scaling enabled
                            case 1:

                                res = displayIntegerScaling->SetEnabled(true);
                                break;
                            default:
                                break;
                            }
                            return res;
                        }


                    }
                }
                else
                {

                }
            }
            else
            {
                // Destroy ADLX
                res = g_ADLXHelp.Terminate();

            }
        }
        else
        {

        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();

    }
}