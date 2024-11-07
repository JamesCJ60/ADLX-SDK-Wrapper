#include "SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "SDK/Include/IDisplaySettings.h"
#include "SDK/Include/IDisplays.h"
#include <iostream>
#include <string>
#include "SDK/Include/I3DSettings1.h"
#include "SDK/Include/I3DSettings.h"

#define ADLX_DisplaySettings _declspec(dllexport)

extern "C" {
    using namespace adlx;
    static ADLXHelper g_ADLXHelp;

    ADLX_DisplaySettings bool HasIntegerScalingSupport1()
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
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();

                                return supported;
                            }

                        }


                    }
                }
           
            }
          
        }
      
        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings bool IsIntegerScalingEnabled1()
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
                            adlx_bool enabled = false;
                            res = displayIntegerScaling->IsEnabled(&enabled);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();

                                return enabled;
                            }
                     
                        }


                    }
                }
              
            }
           
        }
        res = g_ADLXHelp.Terminate();
        return false;

    }
    ADLX_DisplaySettings bool SetIntegerScaling1(bool isEnabled)
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
                            res = displayIntegerScaling->SetEnabled(isEnabled);

                            if (ADLX_SUCCEEDED(res)) 
                            {
                                res = g_ADLXHelp.Terminate();
                                return true;
                            }
                           
                        }


                    }
                }

            }
         
        }
    
        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
        return false;

    }

    ADLX_DisplaySettings bool HasIntegerScalingSupport2()
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
                    adlx_uint it = 1;
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
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();

                                return supported;
                            }

                        }


                    }
                }

            }

        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings bool IsIntegerScalingEnabled2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayIntegerScalingPtr displayIntegerScaling;
                        res = displayService->GetIntegerScaling(display, &displayIntegerScaling);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool enabled = false;
                            res = displayIntegerScaling->IsEnabled(&enabled);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();

                                return enabled;
                            }

                        }


                    }
                }

            }

        }
        res = g_ADLXHelp.Terminate();
        return false;

    }
    ADLX_DisplaySettings bool SetIntegerScaling2(bool isEnabled)
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayIntegerScalingPtr displayIntegerScaling;
                        res = displayService->GetIntegerScaling(display, &displayIntegerScaling);

                        if (ADLX_SUCCEEDED(res))
                        {
                            res = ADLX_FAIL;
                            res = displayIntegerScaling->SetEnabled(isEnabled);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return true;
                            }

                        }


                    }
                }

            }

        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
        return false;

    }

    ADLX_DisplaySettings bool HasGPUScalingSupport1()
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

                        IADLXDisplayGPUScalingPtr displayGPUScaling;
                        ADLX_RESULT  res = displayService->GetGPUScaling(display, &displayGPUScaling);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool supported = false;
                            res = displayGPUScaling->IsSupported(&supported);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return supported;
                            }
              
                        }

                    }
                }
               
            }
           
        }
       
        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings bool IsGPUScalingEnabled1()
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
                        IADLXDisplayGPUScalingPtr displayGPUScaling;
                        ADLX_RESULT  res = displayService->GetGPUScaling(display, &displayGPUScaling);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool enabled = false;
                            res = displayGPUScaling->IsEnabled(&enabled);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return enabled;
                            }
             
                        }

                    }
                }

            }

        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings bool SetGPUScaling1(bool isEnabled)
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
                        IADLXDisplayGPUScalingPtr displayGPUScaling;
                        ADLX_RESULT res = displayService->GetGPUScaling(display, &displayGPUScaling);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT  res = ADLX_FAIL;
                            res = displayGPUScaling->SetEnabled(isEnabled);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return true;
                            }
                        }



                    }
                }
            
            }
         
        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
        return false;


    }

    ADLX_DisplaySettings bool HasGPUScalingSupport2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {

                        IADLXDisplayGPUScalingPtr displayGPUScaling;
                        ADLX_RESULT  res = displayService->GetGPUScaling(display, &displayGPUScaling);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool supported = false;
                            res = displayGPUScaling->IsSupported(&supported);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return supported;
                            }

                        }

                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings bool IsGPUScalingEnabled2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayGPUScalingPtr displayGPUScaling;
                        ADLX_RESULT  res = displayService->GetGPUScaling(display, &displayGPUScaling);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool enabled = false;
                            res = displayGPUScaling->IsEnabled(&enabled);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return enabled;
                            }

                        }

                    }
                }

            }

        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings bool SetGPUScaling2(bool isEnabled)
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayGPUScalingPtr displayGPUScaling;
                        ADLX_RESULT res = displayService->GetGPUScaling(display, &displayGPUScaling);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT  res = ADLX_FAIL;
                            res = displayGPUScaling->SetEnabled(isEnabled);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return true;
                            }
                        }



                    }
                }

            }

        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
        return false;


    }

    ADLX_DisplaySettings bool HasScalingModeSupport1()
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
                        IADLXDisplayScalingModePtr displayScalingMode;
                        ADLX_RESULT  res = displayService->GetScalingMode(display, &displayScalingMode);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool supported = false;
                            res = displayScalingMode->IsSupported(&supported);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return supported;
                            }
                  
                        }


                    }
                }
              
            }
          
        }
      
        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings int GetScalingMode1()
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
                        IADLXDisplayScalingModePtr displayScalingMode;
                        ADLX_RESULT  res = displayService->GetScalingMode(display, &displayScalingMode);
                        if (ADLX_SUCCEEDED(res))
                        {
                            std::cout << "  === Get ScalingMode Enabled ===" << std::endl;
                            ADLX_SCALE_MODE  sm = PRESERVE_ASPECT_RATIO;
                            res = displayScalingMode->GetMode(&sm);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return sm;
                            }
                     
                        }

                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return -1;


    }
    ADLX_DisplaySettings bool SetScalingMode1(const int key)
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
                        IADLXDisplayScalingModePtr displayScalingMode;
                        ADLX_RESULT  res = displayService->GetScalingMode(display, &displayScalingMode);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT  res = ADLX_FAIL;
                            switch (key)
                            {
                                // Set scaling mode to PRESERVE_ASPECT_RATIO
                            case 0:

                                res = displayScalingMode->SetMode(PRESERVE_ASPECT_RATIO);
                                break;
                                // Set scaling mode to FULL_PANEL
                            case 1:

                                res = displayScalingMode->SetMode(FULL_PANEL);
                                break;
                                // Set scaling mode to CENTERED
                            case 2:

                                res = displayScalingMode->SetMode(CENTERED);
                                break;
                            default:
                                break;
                            }

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return true;
                            }
                        }
                        

                    }
                }
         
            }
       
        }
  
        res = g_ADLXHelp.Terminate();
        return false;


    }

    ADLX_DisplaySettings bool HasScalingModeSupport2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayScalingModePtr displayScalingMode;
                        ADLX_RESULT  res = displayService->GetScalingMode(display, &displayScalingMode);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool supported = false;
                            res = displayScalingMode->IsSupported(&supported);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return supported;
                            }

                        }


                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings int GetScalingMode2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayScalingModePtr displayScalingMode;
                        ADLX_RESULT  res = displayService->GetScalingMode(display, &displayScalingMode);
                        if (ADLX_SUCCEEDED(res))
                        {
                            std::cout << "  === Get ScalingMode Enabled ===" << std::endl;
                            ADLX_SCALE_MODE  sm = PRESERVE_ASPECT_RATIO;
                            res = displayScalingMode->GetMode(&sm);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return sm;
                            }

                        }

                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return -1;


    }
    ADLX_DisplaySettings bool SetScalingMode2(const int key)
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayScalingModePtr displayScalingMode;
                        ADLX_RESULT  res = displayService->GetScalingMode(display, &displayScalingMode);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT  res = ADLX_FAIL;
                            switch (key)
                            {
                                // Set scaling mode to PRESERVE_ASPECT_RATIO
                            case 0:

                                res = displayScalingMode->SetMode(PRESERVE_ASPECT_RATIO);
                                break;
                                // Set scaling mode to FULL_PANEL
                            case 1:

                                res = displayScalingMode->SetMode(FULL_PANEL);
                                break;
                                // Set scaling mode to CENTERED
                            case 2:

                                res = displayScalingMode->SetMode(CENTERED);
                                break;
                            default:
                                break;
                            }

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return true;
                            }
                        }


                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;


    }

    ADLX_DisplaySettings bool HasFreeSyncSupport1()
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

                        IADLXDisplayFreeSyncPtr displayFreeSync;

                        ADLX_RESULT res = displayService->GetFreeSync(display, &displayFreeSync);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayFreeSync->IsSupported(&supported);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return supported;
                            }
                        }

                    }


                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;

    }
    ADLX_DisplaySettings bool IsFreeSyncEnabled1()
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

                        IADLXDisplayFreeSyncPtr displayFreeSync;

                        res = displayService->GetFreeSync(display, &displayFreeSync);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayFreeSync->IsSupported(&supported);

                            if (ADLX_SUCCEEDED(res))
                            {
                                if (supported)
                                {
                                    adlx_bool enabled = false;

                                    res = displayFreeSync->IsEnabled(&enabled);

                                    if (ADLX_SUCCEEDED(res))
                                    {
                                        res = g_ADLXHelp.Terminate();
                                        return enabled;
                                    }

                                }

                            }


                        }

                    }

                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;


    }
    ADLX_DisplaySettings bool SetFreeSync1(bool isEnabled)
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

                        IADLXDisplayFreeSyncPtr displayFreeSync;

                        ADLX_RESULT res = displayService->GetFreeSync(display, &displayFreeSync);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayFreeSync->IsSupported(&supported);

                            if (ADLX_SUCCEEDED(res))
                            {
                                if (supported)
                                {
                                    res = ADLX_FAIL;
                                    res = displayFreeSync->SetEnabled(isEnabled);

                                    if (ADLX_SUCCEEDED(res))
                                    {
                                        res = g_ADLXHelp.Terminate();
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
 
            }
  
        }

        res = g_ADLXHelp.Terminate();
        return false;

    }

    ADLX_DisplaySettings bool HasFreeSyncSupport2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {

                        IADLXDisplayFreeSyncPtr displayFreeSync;

                        ADLX_RESULT res = displayService->GetFreeSync(display, &displayFreeSync);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayFreeSync->IsSupported(&supported);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return supported;
                            }
                        }

                    }


                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;

    }
    ADLX_DisplaySettings bool IsFreeSyncEnabled2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {

                        IADLXDisplayFreeSyncPtr displayFreeSync;

                        res = displayService->GetFreeSync(display, &displayFreeSync);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayFreeSync->IsSupported(&supported);

                            if (ADLX_SUCCEEDED(res))
                            {
                                if (supported)
                                {
                                    adlx_bool enabled = false;

                                    res = displayFreeSync->IsEnabled(&enabled);

                                    if (ADLX_SUCCEEDED(res))
                                    {
                                        res = g_ADLXHelp.Terminate();
                                        return enabled;
                                    }

                                }

                            }


                        }

                    }

                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;


    }
    ADLX_DisplaySettings bool SetFreeSync2(bool isEnabled)
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {

                        IADLXDisplayFreeSyncPtr displayFreeSync;

                        ADLX_RESULT res = displayService->GetFreeSync(display, &displayFreeSync);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayFreeSync->IsSupported(&supported);

                            if (ADLX_SUCCEEDED(res))
                            {
                                if (supported)
                                {
                                    res = ADLX_FAIL;
                                    res = displayFreeSync->SetEnabled(isEnabled);

                                    if (ADLX_SUCCEEDED(res))
                                    {
                                        res = g_ADLXHelp.Terminate();
                                        return true;
                                    }



                                }

                            }


                        }

                    }


                }
                else
                {

                }
            }
            else
            {


            }
        }
        else
        {

        }
        res = g_ADLXHelp.Terminate();
        return false;

    }

    ADLX_DisplaySettings bool HasVSRSupport1()
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
                        IADLXDisplayVSRPtr displayVSR;
                        ADLX_RESULT res = displayService->GetVirtualSuperResolution(display, &displayVSR);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayVSR->IsSupported(&supported);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return supported;
                            }
                        }
                    }
                }
            }
        }

        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings bool IsVSREnabled1()
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
                        IADLXDisplayVSRPtr displayVSR;
                        ADLX_RESULT res = displayService->GetVirtualSuperResolution(display, &displayVSR);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool enabled = false;
                            res = displayVSR->IsEnabled(&enabled);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return enabled;
                            }
      
                        }
                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;

    }
    ADLX_DisplaySettings bool SetVSRState1(bool isEnabled)
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
                        IADLXDisplayVSRPtr displayVSR;
                        ADLX_RESULT res = displayService->GetVirtualSuperResolution(display, &displayVSR);
                        if (ADLX_SUCCEEDED(res))
                        {
                            IADLXDisplayVSRPtr displayVSR;
                            ADLX_RESULT res = displayService->GetVirtualSuperResolution(display, &displayVSR);
                            if (ADLX_SUCCEEDED(res))
                            {
                                ADLX_RESULT res = ADLX_FAIL;
                                res = displayVSR->SetEnabled(isEnabled);

                                if (ADLX_SUCCEEDED(res))
                                {
                                    res = g_ADLXHelp.Terminate();
                                    return true;
                                }

                            }
 
                        }
                    }
                }

            }
        }

        res = g_ADLXHelp.Terminate();
        return false;

    }

    ADLX_DisplaySettings bool HasVSRSupport2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayVSRPtr displayVSR;
                        ADLX_RESULT res = displayService->GetVirtualSuperResolution(display, &displayVSR);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayVSR->IsSupported(&supported);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return supported;
                            }
                        }
                    }
                }
            }
        }

        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings bool IsVSREnabled2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayVSRPtr displayVSR;
                        ADLX_RESULT res = displayService->GetVirtualSuperResolution(display, &displayVSR);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool enabled = false;
                            res = displayVSR->IsEnabled(&enabled);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return enabled;
                            }

                        }
                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;

    }
    ADLX_DisplaySettings bool SetVSRState2(bool isEnabled)
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayVSRPtr displayVSR;
                        ADLX_RESULT res = displayService->GetVirtualSuperResolution(display, &displayVSR);
                        if (ADLX_SUCCEEDED(res))
                        {
                            IADLXDisplayVSRPtr displayVSR;
                            ADLX_RESULT res = displayService->GetVirtualSuperResolution(display, &displayVSR);
                            if (ADLX_SUCCEEDED(res))
                            {
                                ADLX_RESULT res = ADLX_FAIL;
                                res = displayVSR->SetEnabled(isEnabled);

                                if (ADLX_SUCCEEDED(res))
                                {
                                    res = g_ADLXHelp.Terminate();
                                    return true;
                                }

                            }

                        }
                    }
                }

            }
        }

        res = g_ADLXHelp.Terminate();
        return false;

    }

    ADLX_DisplaySettings bool HasVariBrightSupport1()
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
                        IADLXDisplayVariBrightPtr displayVariBright;
                        ADLX_RESULT  res = displayService->GetVariBright(display, &displayVariBright);
                        if (ADLX_SUCCEEDED(res))
                        {
                          
                            adlx_bool supported = false;
                            res = displayVariBright->IsSupported(&supported);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return supported;
                            }
                         
                        }

                    }
                }
            }
        }

        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings bool IsVariBrightEnabled1()
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
                        IADLXDisplayVariBrightPtr displayVariBright;
                        ADLX_RESULT  res = displayService->GetVariBright(display, &displayVariBright);
                        if (ADLX_SUCCEEDED(res))
                        {
                    
                            adlx_bool enabled = false;
                            res = displayVariBright->IsEnabled(&enabled);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return enabled;
                            }
                            
                        }


                    }
                }
             
            }
         
        }

        res = g_ADLXHelp.Terminate();
        return false;

    }
    ADLX_DisplaySettings int GetVariBrightState1()
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
                        IADLXDisplayVariBrightPtr displayVariBright;
                        ADLX_RESULT  res = displayService->GetVariBright(display, &displayVariBright);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool applied = false;

                            res = displayVariBright->IsCurrentMaximizeBrightness(&applied);
                            if (applied) 
                            {
                                res = g_ADLXHelp.Terminate();
                                return 0;
                            }

                            res = displayVariBright->IsCurrentOptimizeBrightness(&applied);
                            if (applied)
                            {
                                res = g_ADLXHelp.Terminate();
                                return 1;
                            }
                            res = displayVariBright->IsCurrentBalanced(&applied);
                            if (applied)
                            {
                                res = g_ADLXHelp.Terminate();
                                return 2;
                            }
                            res = displayVariBright->IsCurrentOptimizeBattery(&applied);
                            if (applied)
                            {
                                res = g_ADLXHelp.Terminate();
                                return 3;
                            }
                            res = displayVariBright->IsCurrentMaximizeBattery(&applied);
                            if (applied)
                            {
                                res = g_ADLXHelp.Terminate();
                                return 4;
                            }

                        }


                    }
                }

            }
        }

        res = g_ADLXHelp.Terminate();
        return -1;



    }
    ADLX_DisplaySettings bool SetVariBrightState1(const int key)
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
                        IADLXDisplayVariBrightPtr displayVariBright;
                        ADLX_RESULT  res = displayService->GetVariBright(display, &displayVariBright);

                        res = displayVariBright->SetEnabled(true);

                        if (ADLX_SUCCEEDED(res))
                        {
                            switch (key)
                            {
                            case 0:
                                res = displayVariBright->SetMaximizeBrightness();
                            
                                break;

                            case 1:
                                res = displayVariBright->SetOptimizeBrightness();
                               
                                break;

                            case 2:
                                res = displayVariBright->SetBalanced();
                       
                                break;
                            case 3:
                                res = displayVariBright->SetOptimizeBattery();
                                
                                break;

                            case 4:
                                res = displayVariBright->SetMaximizeBattery();
                            
                                break;
                            }

                            if (ADLX_SUCCEEDED(res)) 
                            {
                                res = g_ADLXHelp.Terminate();
                                return true;
                            }
                        }

                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;



    }
    ADLX_DisplaySettings bool SetVariBrightEnabled1(bool isEnabled)
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
                        IADLXDisplayVariBrightPtr displayVariBright;
                        ADLX_RESULT  res = displayService->GetVariBright(display, &displayVariBright);
                        if (ADLX_SUCCEEDED(res))
                        {
                         
                            res = displayVariBright->SetEnabled(isEnabled);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return true;
                            }
                        }

                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;



    }

    ADLX_DisplaySettings bool HasVariBrightSupport2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayVariBrightPtr displayVariBright;
                        ADLX_RESULT  res = displayService->GetVariBright(display, &displayVariBright);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool supported = false;
                            res = displayVariBright->IsSupported(&supported);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return supported;
                            }

                        }

                    }
                }
            }
        }

        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_DisplaySettings bool IsVariBrightEnabled2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayVariBrightPtr displayVariBright;
                        ADLX_RESULT  res = displayService->GetVariBright(display, &displayVariBright);
                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool enabled = false;
                            res = displayVariBright->IsEnabled(&enabled);
                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return enabled;
                            }

                        }


                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;

    }
    ADLX_DisplaySettings int GetVariBrightState2()
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayVariBrightPtr displayVariBright;
                        ADLX_RESULT  res = displayService->GetVariBright(display, &displayVariBright);
                        if (ADLX_SUCCEEDED(res))
                        {




                            adlx_bool applied = false;

                            res = displayVariBright->IsCurrentMaximizeBrightness(&applied);
                            if (applied)
                            {
                                res = g_ADLXHelp.Terminate();
                                return 0;
                            }

                            res = displayVariBright->IsCurrentOptimizeBrightness(&applied);
                            if (applied)
                            {
                                res = g_ADLXHelp.Terminate();
                                return 1;
                            }
                            res = displayVariBright->IsCurrentBalanced(&applied);
                            if (applied)
                            {
                                res = g_ADLXHelp.Terminate();
                                return 2;
                            }
                            res = displayVariBright->IsCurrentOptimizeBattery(&applied);
                            if (applied)
                            {
                                res = g_ADLXHelp.Terminate();
                                return 3;
                            }
                            res = displayVariBright->IsCurrentMaximizeBattery(&applied);
                            if (applied)
                            {
                                res = g_ADLXHelp.Terminate();
                                return 4;
                            }

                        }


                    }
                }

            }
        }

        res = g_ADLXHelp.Terminate();
        return -1;



    }
    ADLX_DisplaySettings bool SetVariBrightState2(const int key)
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayVariBrightPtr displayVariBright;
                        ADLX_RESULT  res = displayService->GetVariBright(display, &displayVariBright);

                        res = displayVariBright->SetEnabled(true);

                        if (ADLX_SUCCEEDED(res))
                        {
                            switch (key)
                            {
                            case 0:
                                res = displayVariBright->SetMaximizeBrightness();

                                break;

                            case 1:
                                res = displayVariBright->SetOptimizeBrightness();

                                break;

                            case 2:
                                res = displayVariBright->SetBalanced();

                                break;
                            case 3:
                                res = displayVariBright->SetOptimizeBattery();

                                break;

                            case 4:
                                res = displayVariBright->SetMaximizeBattery();

                                break;
                            }

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return true;
                            }
                        }

                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;



    }
    ADLX_DisplaySettings bool SetVariBrightEnabled2(bool isEnabled)
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
                    adlx_uint it = 1;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED(res))
                    {
                        IADLXDisplayVariBrightPtr displayVariBright;
                        ADLX_RESULT  res = displayService->GetVariBright(display, &displayVariBright);
                        if (ADLX_SUCCEEDED(res))
                        {

                            res = displayVariBright->SetEnabled(isEnabled);

                            if (ADLX_SUCCEEDED(res))
                            {
                                res = g_ADLXHelp.Terminate();
                                return true;
                            }
                        }

                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return false;



    }
}
