#include "../SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "../SDK/Include/I3DSettings.h"

#define ADLX_3DSettings _declspec(dllexport)

extern "C" {
    using namespace adlx;
    static ADLXHelper g_ADLXHelp;

    ADLX_3DSettings bool HasRSRSupport()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                        result = supported;
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_3DSettings bool GetRSR()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

    ADLX_3DSettings bool SetRSR(bool enable)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            ADLX_RESULT res = rsr->SetEnabled(enable);
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

    ADLX_3DSettings int GetRSRSharpness()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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
                            adlx_int currentSharpness;
                            rsr->GetSharpness(&currentSharpness);
                            result = currentSharpness;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_3DSettings bool SetRSRSharpness(int sharpness)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            ADLX_RESULT adlx_result = rsr->SetSharpness(sharpness);
                            result = ADLX_SUCCEEDED(adlx_result);
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_3DSettings bool GetAntiLag(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            adlx_bool enabled = false;
                            anti->IsEnabled(&enabled);
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

    ADLX_3DSettings bool SetAntiLag(int GPU, bool enable)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            ADLX_RESULT res = anti->SetEnabled(enable);
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

    ADLX_3DSettings bool GetBoost(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            adlx_bool isEnabled = false;
                            boost->IsEnabled(&isEnabled);
                            result = isEnabled;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_3DSettings bool SetBoost(int GPU, bool enable)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            ADLX_RESULT res = boost->SetEnabled(enable);
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

    ADLX_3DSettings int GetBoostResolution(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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
                            adlx_int currentMinRes;
                            boost->GetResolution(&currentMinRes);
                            result = currentMinRes;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_3DSettings bool SetBoostResolution(int GPU, int minRes)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            ADLX_RESULT res = boost->SetResolution(minRes);
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

    ADLX_3DSettings bool GetChill(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            adlx_bool isEnabled;
                            chill->IsEnabled(&isEnabled);
                            result = isEnabled;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_3DSettings bool SetChill(int GPU, bool enable)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            ADLX_RESULT res = chill->SetEnabled(enable);
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

    ADLX_3DSettings int GetChillMinFPS(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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
                            adlx_int currentMinFPS;
                            chill->GetMinFPS(&currentMinFPS);
                            result = currentMinFPS;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_3DSettings bool SetChillMinFPS(int GPU, int minFPS)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            ADLX_RESULT res = chill->SetMinFPS(minFPS);
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

    ADLX_3DSettings int GetChillMaxFPS(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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
                            adlx_int currentMaxFPS;
                            chill->GetMaxFPS(&currentMaxFPS);
                            result = currentMaxFPS;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_3DSettings bool SetChillMaxFPS(int GPU, int maxFPS)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                            ADLX_RESULT res = chill->SetMaxFPS(maxFPS);
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

    ADLX_3DSettings bool GetImageSharpening(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                        // Get Image Sharpening interface
                        IADLX3DImageSharpeningPtr sharp;
                        res = d3dSettingSrv->GetImageSharpening(gpuInfo, &sharp);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_bool isEnabled;
                            sharp->IsEnabled(&isEnabled);
                            result = isEnabled;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_3DSettings bool SetImageSharpening(int GPU, bool enable)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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
                        // Get Image Sharpening interface
                        IADLX3DImageSharpeningPtr sharp;
                        res = d3dSettingSrv->GetImageSharpening(gpuInfo, &sharp);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT res = sharp->SetEnabled(enable);
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

    ADLX_3DSettings int GetImageSharpeningSharpness(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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
                        // Get Image Sharpening interface
                        IADLX3DImageSharpeningPtr sharp;
                        res = d3dSettingSrv->GetImageSharpening(gpuInfo, &sharp);
                        if (ADLX_SUCCEEDED(res))
                        {
                            adlx_int currentMaxFPS;
                            sharp->GetSharpness(&currentMaxFPS);
                            result = currentMaxFPS;
                        }
                    }
                }
            }

            // terminate ADLX
            g_ADLXHelp.Terminate();
        }

        return result;
    }

    ADLX_3DSettings bool SetImageSharpeningSharpness(int GPU, int sharpness)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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
                        // Get Image Sharpening interface
                        IADLX3DImageSharpeningPtr sharp;
                        res = d3dSettingSrv->GetImageSharpening(gpuInfo, &sharp);
                        if (ADLX_SUCCEEDED(res))
                        {
                            ADLX_RESULT res = sharp->SetSharpness(sharpness);
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