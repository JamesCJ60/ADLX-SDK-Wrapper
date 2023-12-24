#include "SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "SDK/Include/I3DSettings.h"

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
                                return true;

                            }

                        }

                    }

                }

            }

        }
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
                                return sharpness;
                            }
                            else { return -1; }

                        }

                    }
                    else return -1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    ADLX_3DSettings int GetRSRState()
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
                                adlx_bool enabled = false;
                                rsr->IsEnabled(&enabled);
                                if (enabled)
                                {
                                    return 1;
                                }
                                else {
                                    return 0;
                                }
                            }
                            else { return -1; }

                        }

                    }
                    else return -1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    ADLX_3DSettings int SetRSR(bool isEnabled)
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
                            if (isEnabled)
                            {
                                ADLX_RESULT  res = rsr->SetEnabled(true);
                                return 1;
                            }
                            else {
                                ADLX_RESULT  res = rsr->SetEnabled(false);
                                return 0;
                            }

                        }

                    }
                    else return -1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    ADLX_3DSettings int SetAntiLag(int GPU, bool isEnabled)
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
                        // Get Anti Lag interface
                        IADLX3DAntiLagPtr anti;
                        res = d3dSettingSrv->GetAntiLag(gpuInfo, &anti);
                        if (ADLX_SUCCEEDED(res))
                        {
                            if (isEnabled)
                            {
                                ADLX_RESULT  res = anti->SetEnabled(true);
                                return 1;
                            }
                            else {
                                ADLX_RESULT  res = anti->SetEnabled(false);
                                return 0;
                            }
                        }
                        else return -1;
                    }
                    else return -1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    ADLX_3DSettings int SetBoost(int GPU, bool isEnabled, int percent)
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
                        // Get Boost interface
                        IADLX3DBoostPtr boost;
                        res = d3dSettingSrv->GetBoost(gpuInfo, &boost);
                        if (ADLX_SUCCEEDED(res))
                        {
                            if (isEnabled)
                            {
                                ADLX_RESULT  res = boost->SetEnabled(true);
                                res = boost->SetResolution(percent);
                                return 1;
                            }
                            else {
                                ADLX_RESULT  res = boost->SetEnabled(false);
                                return 0;
                            }
                        }
                        else return -1;
                    }
                    else return -1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    ADLX_3DSettings int SetChill(int GPU, bool isEnabled, int maxFPS, int minFPS)
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
                        // Get Chill interface
                        IADLX3DChillPtr chill;
                        res = d3dSettingSrv->GetChill(gpuInfo, &chill);
                        if (ADLX_SUCCEEDED(res))
                        {
                            if (isEnabled)
                            {
                                ADLX_RESULT  res = chill->SetEnabled(true);
                                res = chill->SetMaxFPS(maxFPS);
                                res = chill->SetMinFPS(minFPS);
                                return 1;
                            }
                            else {
                                ADLX_RESULT  res = chill->SetEnabled(false);
                                return 0;
                            }
                        }
                        else return -1;
                    }
                    else return -1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    ADLX_3DSettings int SetImageSharpning(int GPU, bool isEnabled, int percent)
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
                        // Get Image Sharpning interface
                        IADLX3DImageSharpeningPtr sharp;
                        res = d3dSettingSrv->GetImageSharpening(gpuInfo, &sharp);
                        if (ADLX_SUCCEEDED(res))
                        {
                            if (isEnabled)
                            {
                                ADLX_RESULT  res = sharp->SetEnabled(true);
                                res = sharp->SetSharpness(percent);
                                
                                return 1;
                            }
                            else {
                                ADLX_RESULT  res = sharp->SetEnabled(false);
                                return 0;
                            }
                        }
                        else return -1;
                    }
                    else return -1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    ADLX_3DSettings int SetFPSLimit(int GPU, bool isEnabled, int FPS)
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
                                    return 1;
                                }
                                else return 0;
                            }
                            else return 0;
                        }
                        else return -1;
                    }
                    else return -1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    ADLX_3DSettings int SetEnhancedSync(int GPU, bool isEnabled)
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
                        // Get Enhanced Sync interface
                        IADLX3DEnhancedSyncPtr sync;
                        res = d3dSettingSrv->GetEnhancedSync(gpuInfo, &sync);
                        if (ADLX_SUCCEEDED(res))
                        {
                            if (isEnabled)
                            {
                                ADLX_RESULT  res = sync->SetEnabled(true);
                                return 1;
                            }
                            else {
                                ADLX_RESULT  res = sync->SetEnabled(false);
                                return 0;
                            }
                        }
                        else return -1;
                    }
                    else return -1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
}