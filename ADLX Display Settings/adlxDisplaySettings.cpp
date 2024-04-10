#include "SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "SDK/Include/IDisplaySettings.h"
#include "SDK/Include/IDisplays.h"
#include <iostream>
#include <string>
#define ADLX_DisplaySettings _declspec(dllexport)

extern "C" {
    using namespace adlx;
    static ADLXHelper g_ADLXHelp;

    ADLX_DisplaySettings bool HasIntegerScalingSupport1()
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL ;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED (res))
        {
            // Get display service
            IADLXDisplayServicesPtr displayService;
            res = g_ADLXHelp.GetSystemServices()->GetDisplaysServices(&displayService);
            if (ADLX_SUCCEEDED (res))
            {
                // Get display list
                IADLXDisplayListPtr displayList;
                res = displayService->GetDisplays(&displayList);
                if (ADLX_SUCCEEDED  (res))
                {
                    // Inspect for the first display in the list
                    adlx_uint it = 0;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED (res))
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
                res = g_ADLXHelp.Terminate ();
              
            }
        }
        else
        {
           
        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
      
    }
    ADLX_DisplaySettings bool IsIntegerScalingEnabled1()
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL ;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED (res))
        {
            // Get display service
            IADLXDisplayServicesPtr displayService;
            res = g_ADLXHelp.GetSystemServices()->GetDisplaysServices(&displayService);
            if (ADLX_SUCCEEDED (res))
            {
                // Get display list
                IADLXDisplayListPtr displayList;
                res = displayService->GetDisplays(&displayList);
                if (ADLX_SUCCEEDED  (res))
                {
                    // Inspect for the first display in the list
                    adlx_uint it = 0;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED (res))
                    {
                        IADLXDisplayIntegerScalingPtr displayIntegerScaling;
                        res = displayService->GetIntegerScaling(display, &displayIntegerScaling);

                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            res = displayIntegerScaling->IsEnabled(&supported);
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
                res = g_ADLXHelp.Terminate ();
              
            }
        }
        else
        {
           
        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
      
    }
    ADLX_DisplaySettings int SetIntegerScaling1(const int key)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL ;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED (res))
        {
            // Get display service
            IADLXDisplayServicesPtr displayService;
            res = g_ADLXHelp.GetSystemServices()->GetDisplaysServices(&displayService);
            if (ADLX_SUCCEEDED (res))
            {
                // Get display list
                IADLXDisplayListPtr displayList;
                res = displayService->GetDisplays(&displayList);
                if (ADLX_SUCCEEDED  (res))
                {
                    // Inspect for the first display in the list
                    adlx_uint it = 0;
                    IADLXDisplayPtr display;
                    res = displayList->At(it, &display);
                    if (ADLX_SUCCEEDED (res))
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
                res = g_ADLXHelp.Terminate ();
              
            }
        }
        else
        {
           
        }

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
      
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
                            adlx_bool supported = false;
                            res = displayIntegerScaling->IsEnabled(&supported);
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
    ADLX_DisplaySettings int SetIntegerScaling2(const int key)
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


            }
        }
        else
        {

        }

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
                            return enabled;
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
    ADLX_DisplaySettings int SetGPUScaling1(const int key)
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
                            switch (key)
                            {
                                // Set GPUScaling disabled
                            case 0:
                               
                                res = displayGPUScaling->SetEnabled(false);
                                break;
                                // Set GPUScaling enabled
                            case 1:
                         
                                res = displayGPUScaling->SetEnabled(true);
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
              

            }
        }
        else
        {

        }


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


            }
        }
        else
        {

        }

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
                            return enabled;
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
    ADLX_DisplaySettings int SetGPUScaling2(const int key)
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
                            switch (key)
                            {
                                // Set GPUScaling disabled
                            case 0:

                                res = displayGPUScaling->SetEnabled(false);
                                break;
                                // Set GPUScaling enabled
                            case 1:

                                res = displayGPUScaling->SetEnabled(true);
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


            }
        }
        else
        {

        }


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
                

            }
        }
        else
        {

        }

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
                            return sm;
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

      

    }
    ADLX_DisplaySettings int SetScalingMode1(const int key)
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
                           
                        }
                        return res;

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


            }
        }
        else
        {

        }

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
                            return sm;
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



    }
    ADLX_DisplaySettings int SetScalingMode2(const int key)
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

                        }
                        return res;

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
                                return supported;
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
                                        return enabled;
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

        return false;

      
    }
    ADLX_DisplaySettings bool SetFreeSync1(const int key)
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
                                    switch (key)
                                    {
                                        // Set freesync disabled
                                    case 0:

                                        res = displayFreeSync->SetEnabled(false);
                                        return true;
                                        break;
                                        // Set freesync enabled
                                    case 1:

                                        res = displayFreeSync->SetEnabled(true);
                                        return true;
                                        break;
                                    default:
                                        break;
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
                                return supported;
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
                                        return enabled;
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

        return false;


    }
    ADLX_DisplaySettings bool SetFreeSync2(const int key)
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
                                    switch (key)
                                    {
                                        // Set freesync disabled
                                    case 0:

                                        res = displayFreeSync->SetEnabled(false);
                                        return true;
                                        break;
                                        // Set freesync enabled
                                    case 1:

                                        res = displayFreeSync->SetEnabled(true);
                                        return true;
                                        break;
                                    default:
                                        break;
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

        return false;

    }
}
