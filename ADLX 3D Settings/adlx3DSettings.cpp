#include "SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "SDK/Include/I3DSettings.h"
#include "SDK/Include/I3DSettings1.h"

#define ADLX_3DSettings _declspec(dllexport)

extern "C" {
    using namespace adlx;
    static ADLXHelper g_ADLXHelp;

    ADLX_3DSettings bool SetRSRSharpness(int sharpness)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get 3DSettings service
            IADLX3DSettingsServicesPtr d3dSettingSrv;
            res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
            if (ADLX_SUCCEEDED(res))
            {

                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    if (ADLX_SUCCEEDED(res))
                    {
                        // Get RadeonSuperResolution interface
                        IADLX3DRadeonSuperResolutionPtr rsr;
                        res = d3dSettingSrv->GetRadeonSuperResolution(&rsr);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            rsr->IsSupported(&supported);

                            if (supported)
                            {
                                rsr->SetSharpness(sharpness);
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
    ADLX_3DSettings int GetRSRSharpness()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get 3DSettings service
            IADLX3DSettingsServicesPtr d3dSettingSrv;
            res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
            if (ADLX_SUCCEEDED(res))
            {

                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    if (ADLX_SUCCEEDED(res))
                    {
                        // Get RadeonSuperResolution interface
                        IADLX3DRadeonSuperResolutionPtr rsr;
                        res = d3dSettingSrv->GetRadeonSuperResolution(&rsr);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            rsr->IsSupported(&supported);

                            if (supported)
                            {
                                adlx_int sharpness;
                                ADLX_IntRange  sharpnessRange;
                                rsr->GetSharpness(&sharpness);

                                if (ADLX_SUCCEEDED(res))
                                {
                                    res = g_ADLXHelp.Terminate();
                                    return sharpness;
                                }

                            }
                           
                        }

                    }
                }

            }

        }

        res = g_ADLXHelp.Terminate();
        return -1;
    }
    ADLX_3DSettings bool HasRSRSupport()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get 3DSettings service
            IADLX3DSettingsServicesPtr d3dSettingSrv;
            res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
            if (ADLX_SUCCEEDED(res))
            {

                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    // Get RadeonSuperResolution interface
                    IADLX3DRadeonSuperResolutionPtr rsr;
                    res = d3dSettingSrv->GetRadeonSuperResolution(&rsr);
                    if (ADLX_SUCCEEDED(res))
                    {
                        adlx_bool supported = false;
                        rsr->IsSupported(&supported);

                        if (ADLX_SUCCEEDED(res))
                        {
                            res = g_ADLXHelp.Terminate();
                            return supported;
                        }


                    }


                }

            }

        }
        res = g_ADLXHelp.Terminate();
        return false;
    }
    ADLX_3DSettings bool GetRSRState()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get 3DSettings service
            IADLX3DSettingsServicesPtr d3dSettingSrv;
            res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
            if (ADLX_SUCCEEDED(res))
            {

                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    // Get RadeonSuperResolution interface
                    IADLX3DRadeonSuperResolutionPtr rsr;
                    res = d3dSettingSrv->GetRadeonSuperResolution(&rsr);
                    if (ADLX_SUCCEEDED(res))
                    {
                        adlx_bool supported = false;
                        rsr->IsSupported(&supported);

                        if (supported)
                        {
                            adlx_bool enabled = false;
                            rsr->IsEnabled(&enabled);
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
    ADLX_3DSettings bool SetRSR(bool isEnabled)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get 3DSettings service
            IADLX3DSettingsServicesPtr d3dSettingSrv;
            res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
            if (ADLX_SUCCEEDED(res))
            {

                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    if (ADLX_SUCCEEDED(res))
                    {
                        // Get RadeonSuperResolution interface
                        IADLX3DRadeonSuperResolutionPtr rsr;
                        res = d3dSettingSrv->GetRadeonSuperResolution(&rsr);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT  res = rsr->SetEnabled(isEnabled);
                          
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
    ADLX_3DSettings bool MadeByProjectSBC()
    {
        return true;
    }

    ADLX_3DSettings bool HasFPSLimitSupport(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get GPUs
            IADLXGPUListPtr gpus;
            res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
            if (ADLX_SUCCEEDED(res) && !gpus->Empty())
            {
                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    // Get GPU interface
                    IADLXGPUPtr gpuInfo;
                    adlx_uint index = GPU;
                    res = gpus->At(index, &gpuInfo);
                    if (ADLX_SUCCEEDED(res))
                    {
                        // Get FRTC interface
                        IADLX3DFrameRateTargetControlPtr frtc;
                        res = d3dSettingSrv->GetFrameRateTargetControl(gpuInfo, &frtc);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool supported = false;
                            ADLX_RESULT  res = frtc->IsSupported(&supported);



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
    ADLX_3DSettings bool IsFPSLimitEnabled(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get GPUs
            IADLXGPUListPtr gpus;
            res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
            if (ADLX_SUCCEEDED(res) && !gpus->Empty())
            {
                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    // Get GPU interface
                    IADLXGPUPtr gpuInfo;
                    adlx_uint index = GPU;
                    res = gpus->At(index, &gpuInfo);
                    if (ADLX_SUCCEEDED(res))
                    {
                        // Get FRTC interface
                        IADLX3DFrameRateTargetControlPtr frtc;
                        res = d3dSettingSrv->GetFrameRateTargetControl(gpuInfo, &frtc);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool enabled = false;
                            ADLX_RESULT  res = frtc->IsEnabled(&enabled);



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
    ADLX_3DSettings bool SetFPSLimit(int GPU, bool isEnabled, int FPS)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get GPUs
            IADLXGPUListPtr gpus;
            res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
            if (ADLX_SUCCEEDED(res) && !gpus->Empty())
            {
                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    // Get GPU interface
                    IADLXGPUPtr gpuInfo;
                    adlx_uint index = GPU;
                    res = gpus->At(index, &gpuInfo);
                    if (ADLX_SUCCEEDED(res))
                    {
                        // Get FRTC interface
                        IADLX3DFrameRateTargetControlPtr frtc;
                        res = d3dSettingSrv->GetFrameRateTargetControl(gpuInfo, &frtc);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT res = frtc->SetEnabled(isEnabled == true);

                            if (isEnabled == true && ADLX_SUCCEEDED(res))
                            {
                                adlx_int fps = FPS;
                                ADLX_IntRange range = { 0 };
                                frtc->GetFPSRange(&range);
                                if (fps >= range.minValue && fps <= range.maxValue)
                                {
                                    res = frtc->SetFPS(fps);
                                    if (ADLX_SUCCEEDED(res))
                                    {
                                        return true;
                                    }
                                }
                                
                            }
                           
                        }
                       
                    }
               
                }

            }

        }
        return false;
    }
    ADLX_3DSettings bool DisableFPSLimit(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get GPUs
            IADLXGPUListPtr gpus;
            res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
            if (ADLX_SUCCEEDED(res) && !gpus->Empty())
            {
                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    // Get GPU interface
                    IADLXGPUPtr gpuInfo;
                    adlx_uint index = GPU;
                    res = gpus->At(index, &gpuInfo);
                    if (ADLX_SUCCEEDED(res))
                    {
                        // Get FRTC interface
                        IADLX3DFrameRateTargetControlPtr frtc;
                        res = d3dSettingSrv->GetFrameRateTargetControl(gpuInfo, &frtc);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT res = frtc->SetEnabled(false);

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


    ADLX_3DSettings bool HasAFMFSupport()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get 3DSettings service
            IADLX3DSettingsServicesPtr d3dSettingSrv;
            res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
            if (ADLX_SUCCEEDED(res))
            {

                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    // Get 3DSettings service
                    IADLX3DSettingsServices1Ptr d3dSettingSrv1(d3dSettingSrv);

                    if (NULL != d3dSettingSrv1)
                    {

                        // Get AFMF interface
                        IADLX3DAMDFluidMotionFramesPtr d3dAFMF;
                        res = d3dSettingSrv1->GetAMDFluidMotionFrames(&d3dAFMF);


                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool supported = false;
                            ADLX_RESULT res = d3dAFMF->IsSupported(&supported);
                            if (ADLX_SUCCEEDED(res))
                            {
                                return supported;
                               
                            }
                        }

                    }
                  
                }

            }

        }
        return false;
    }
    ADLX_3DSettings bool GetAFMFState()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get 3DSettings service
            IADLX3DSettingsServicesPtr d3dSettingSrv;
            res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
            if (ADLX_SUCCEEDED(res))
            {

                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    // Get 3DSettings service
                    IADLX3DSettingsServices1Ptr d3dSettingSrv1(d3dSettingSrv);

                    if (NULL != d3dSettingSrv1)
                    {

                        // Get AFMF interface
                        IADLX3DAMDFluidMotionFramesPtr d3dAFMF;
                        res = d3dSettingSrv1->GetAMDFluidMotionFrames(&d3dAFMF);


                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool supported = false;
                            ADLX_RESULT res = d3dAFMF->IsSupported(&supported);
                            if (ADLX_SUCCEEDED(res))
                            {
                                if (supported)
                                {

                                    adlx_bool enabled = false;
                                    ADLX_RESULT res = d3dAFMF->IsEnabled(&enabled);

                                    if (ADLX_SUCCEEDED(res))
                                    {

                                        return enabled;

                                    }

                                }
                            }
                           
                        }

                    }

                }

            }

        }
        return false;
    }
    ADLX_3DSettings bool SetAFMFState(bool isEnabled)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        if (ADLX_SUCCEEDED(res))
        {
            // Get 3DSettings service
            IADLX3DSettingsServicesPtr d3dSettingSrv;
            res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
            if (ADLX_SUCCEEDED(res))
            {

                // Get 3DSettings service
                IADLX3DSettingsServicesPtr d3dSettingSrv;
                res = g_ADLXHelp.GetSystemServices()->Get3DSettingsServices(&d3dSettingSrv);
                if (ADLX_SUCCEEDED(res))
                {
                    // Get 3DSettings service
                    IADLX3DSettingsServices1Ptr d3dSettingSrv1(d3dSettingSrv);

                    if (NULL != d3dSettingSrv1)
                    {

                        // Get AFMF interface
                        IADLX3DAMDFluidMotionFramesPtr d3dAFMF;
                        res = d3dSettingSrv1->GetAMDFluidMotionFrames(&d3dAFMF);


                        if (ADLX_SUCCEEDED(res))
                        {

                            adlx_bool supported = false;
                            ADLX_RESULT res = d3dAFMF->IsSupported(&supported);

                            if (ADLX_SUCCEEDED(res))
                            {
                                if (supported)
                                {
                                    if (isEnabled) 
                                    {
                                        ADLX_RESULT res = d3dAFMF->SetEnabled(1);
                                    }
                                    else {
                                        ADLX_RESULT res = d3dAFMF->SetEnabled(0);
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

            }

        }
        res = g_ADLXHelp.Terminate();
        return false;
    }

}
