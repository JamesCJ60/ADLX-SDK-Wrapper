#include "../SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "../SDK/Include/I3DSettings.h"
#include "../SDK/Include/IDisplaySettings.h"
#include "../SDK/Include/IDisplays.h"
#include "../SDK/Include/IPerformanceMonitoring.h"

#define ADLX_Wrapper _declspec(dllexport)

extern "C" {
    using namespace adlx;
    static ADLXHelper g_ADLXHelp;

    typedef struct AdlxTelemetryData
    {
        // GPU Usage
        bool gpuUsageSupported = false;
        double gpuUsageValue;

        // GPU Core Frequency
        bool gpuClockSpeedSupported = false;
        double gpuClockSpeedValue;

        // GPU VRAM Frequency
        bool gpuVRAMClockSpeedSupported = false;
        double gpuVRAMClockSpeedValue;

        // GPU Core Temperature
        bool gpuTemperatureSupported = false;
        double gpuTemperatureValue;

        // GPU Hotspot Temperature
        bool gpuHotspotTemperatureSupported = false;
        double gpuHotspotTemperatureValue;

        // GPU Power
        bool gpuPowerSupported = false;
        double gpuPowerValue;

        // Fan Speed
        bool gpuFanSpeedSupported = false;
        double gpuFanSpeedValue;

        // VRAM Usage
        bool gpuVramSupported = false;
        double gpuVramValue;

        // GPU Voltage
        bool gpuVoltageSupported = false;
        double gpuVoltageValue;

        // GPU TBP
        bool gpuTotalBoardPowerSupported = false;
        double gpuTotalBoardPowerValue;
    };

    bool IntializeAdlx()
    {
        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();
        return ADLX_SUCCEEDED(res);
    }

    bool CloseAdlx()
    {
        ADLX_RESULT res = ADLX_FAIL;

        // Terminate ADLX
        res = g_ADLXHelp.Terminate();
        return ADLX_SUCCEEDED(res);
    }

    ADLX_Wrapper bool HasIntegerScalingSupport(int GPU)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool GetIntegerScaling(int GPU)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool SetIntegerScaling(int GPU, bool enabled)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool HasGPUScalingSupport(int GPU)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool GetGPUScaling(int GPU)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool SetGPUScaling(int GPU, bool enabled)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool HasScalingModeSupport(int GPU)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper int GetScalingMode(int GPU)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        int result = -1;

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

        return result;
    }

    ADLX_Wrapper bool SetScalingMode(int GPU, int mode)
    {
        // Define return code
        ADLX_RESULT  res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool HasRSRSupport()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool GetRSR()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool SetRSR(bool enable)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper int GetRSRSharpness()
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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

        return result;
    }

    ADLX_Wrapper bool SetRSRSharpness(int sharpness)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool GetAntiLag(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool SetAntiLag(int GPU, bool enable)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool GetBoost(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool SetBoost(int GPU, bool enable)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper int GetBoostResolution(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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

        return result;
    }

    ADLX_Wrapper bool SetBoostResolution(int GPU, int minRes)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool GetChill(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool SetChill(int GPU, bool enable)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper int GetChillMinFPS(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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

        return result;
    }

    ADLX_Wrapper bool SetChillMinFPS(int GPU, int minFPS)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper int GetChillMaxFPS(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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

        return result;
    }

    ADLX_Wrapper bool SetChillMaxFPS(int GPU, int maxFPS)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool GetImageSharpening(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper bool SetImageSharpening(int GPU, bool enable)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        bool result = false;

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

        return result;
    }

    ADLX_Wrapper int GetImageSharpeningSharpness(int GPU)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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

        return result;
    }

    ADLX_Wrapper bool SetImageSharpeningSharpness(int GPU, int sharpness)
    {
        // Define return code
        ADLX_RESULT res = ADLX_FAIL;
        int result = -1;

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

        return result;
    }

    ADLX_Wrapper bool GetTimeStamp(IADLXGPUMetricsPtr gpuMetrics)
    {
        ADLX_RESULT res = ADLX_FAIL;
        adlx_int64 timeStamp = 0;

        res = gpuMetrics->TimeStamp(&timeStamp);
        return ADLX_SUCCEEDED(res);
    }
    
    // Set GPU usage (in %)
    ADLX_Wrapper void GetGPUUsage(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, AdlxTelemetryData* telemetryData)
    {
        adlx_bool supported = false;
        // Display GPU usage support status
        ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUUsage(&supported);
        if (ADLX_SUCCEEDED(res))
        {
            telemetryData->gpuUsageSupported = supported;
            if (supported)
            {
                adlx_double usage = 0;
                res = gpuMetrics->GPUUsage(&usage);
                if (ADLX_SUCCEEDED(res))
                    telemetryData->gpuUsageValue = usage;
            }
        }
    }

    // Set GPU clock speed (in MHz)
    ADLX_Wrapper void GetGPUClockSpeed(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, AdlxTelemetryData* telemetryData)
    {
        adlx_bool supported = false;
        // Display GPU clock speed support status
        ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUClockSpeed(&supported);
        if (ADLX_SUCCEEDED(res))
        {
            telemetryData->gpuClockSpeedSupported = supported;
            if (supported)
            {
                adlx_int gpuClock = 0;
                res = gpuMetrics->GPUClockSpeed(&gpuClock);
                if (ADLX_SUCCEEDED(res))
                    telemetryData->gpuClockSpeedValue = gpuClock;
            }
        }
    }

    // Set GPU VRAM clock speed (in MHz)
    ADLX_Wrapper void GetGPUVRAMClockSpeed(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, AdlxTelemetryData* telemetryData)
    {
        adlx_bool supported = false;
        // Display the GPU VRAM clock speed support status
        ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVRAMClockSpeed(&supported);
        if (ADLX_SUCCEEDED(res))
        {
            telemetryData->gpuVRAMClockSpeedSupported = supported;
            if (supported)
            {
                adlx_int memoryClock = 0;
                res = gpuMetrics->GPUVRAMClockSpeed(&memoryClock);
                if (ADLX_SUCCEEDED(res))
                    telemetryData->gpuVRAMClockSpeedValue = memoryClock;
            }
        }
    }

    // Set GPU temperature(in °C)
    ADLX_Wrapper void GetGPUTemperature(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, AdlxTelemetryData* telemetryData)
    {
        adlx_bool supported = false;

        // Display the GPU temperature support status
        ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUTemperature(&supported);
        if (ADLX_SUCCEEDED(res))
        {
            telemetryData->gpuTemperatureSupported = supported;
            if (supported)
            {
                adlx_double temperature = 0;
                res = gpuMetrics->GPUTemperature(&temperature);
                if (ADLX_SUCCEEDED(res))
                    telemetryData->gpuTemperatureValue = temperature;
            }
        }
    }

    // Set GPU hotspot temperature(in °C)
    ADLX_Wrapper void GetGPUHotspotTemperature(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, AdlxTelemetryData* telemetryData)
    {
        adlx_bool supported = false;

        // Display GPU hotspot temperature support status
        ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUHotspotTemperature(&supported);
        if (ADLX_SUCCEEDED(res))
        {
            telemetryData->gpuHotspotTemperatureSupported = supported;
            if (supported)
            {
                adlx_double hotspotTemperature = 0;
                res = gpuMetrics->GPUHotspotTemperature(&hotspotTemperature);
                if (ADLX_SUCCEEDED(res))
                    telemetryData->gpuHotspotTemperatureValue = hotspotTemperature;
            }
        }
    }

    // Set GPU power(in W)
    ADLX_Wrapper void GetGPUPower(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, AdlxTelemetryData* telemetryData)
    {
        adlx_bool supported = false;
        // Display GPU power support status
        ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUPower(&supported);
        if (ADLX_SUCCEEDED(res))
        {
            telemetryData->gpuPowerSupported = supported;
            if (supported)
            {
                adlx_double power = 0;
                res = gpuMetrics->GPUPower(&power);
                if (ADLX_SUCCEEDED(res))
                    telemetryData->gpuPowerValue = power;
            }
        }
    }

    // Set GPU total board power(in W)
    ADLX_Wrapper void GetGPUTotalBoardPower(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, AdlxTelemetryData* telemetryData)
    {
        adlx_bool supported = false;
        // Display GPU total board power support status
        ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUTotalBoardPower(&supported);
        if (ADLX_SUCCEEDED(res))
        {
            telemetryData->gpuTotalBoardPowerSupported = supported;
            if (supported)
            {
                adlx_double power = 0;
                res = gpuMetrics->GPUTotalBoardPower(&power);
                if (ADLX_SUCCEEDED(res))
                    telemetryData->gpuTotalBoardPowerValue = power;
            }
        }
    }

    // Set GPU fan speed (in RPM)
    ADLX_Wrapper void GetGPUFanSpeed(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, AdlxTelemetryData* telemetryData)
    {
        adlx_bool supported = false;
        // Display GPU fan speed support status
        ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUFanSpeed(&supported);
        if (ADLX_SUCCEEDED(res))
        {
            telemetryData->gpuFanSpeedSupported = supported;
            if (supported)
            {
                adlx_int fanSpeed = 0;
                res = gpuMetrics->GPUFanSpeed(&fanSpeed);
                if (ADLX_SUCCEEDED(res))
                    telemetryData->gpuFanSpeedValue = fanSpeed;
            }
        }
    }

    // Set GPU VRAM (in MB)
    ADLX_Wrapper void GetGPUVRAM(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, AdlxTelemetryData* telemetryData)
    {
        adlx_bool supported = false;
        // Display GPU VRAM support status
        ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVRAM(&supported);
        if (ADLX_SUCCEEDED(res))
        {
            telemetryData->gpuVramSupported = supported;
            if (supported)
            {
                adlx_int VRAM = 0;
                res = gpuMetrics->GPUVRAM(&VRAM);
                if (ADLX_SUCCEEDED(res))
                    telemetryData->gpuVramValue = VRAM;
            }
        }
    }

    // Set GPU Voltage (in mV)
    ADLX_Wrapper void GetGPUVoltage(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, AdlxTelemetryData* telemetryData)
    {
        adlx_bool supported = false;
        // Display GPU voltage support status
        ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVoltage(&supported);
        if (ADLX_SUCCEEDED(res))
        {
            telemetryData->gpuVoltageSupported = supported;
            if (supported)
            {
                adlx_int voltage = 0;
                res = gpuMetrics->GPUVoltage(&voltage);
                if (ADLX_SUCCEEDED(res))
                    telemetryData->gpuVoltageValue = voltage;
            }
        }
    }
    
    ADLX_Wrapper bool GetAdlxTelemetry(int GPU, AdlxTelemetryData* adlxTelemetryData)
    {
        ADLX_RESULT res = ADLX_FAIL;
        bool check = false;

        // Get GPU metrics support
        IADLXGPUMetricsSupportPtr gpuMetricsSupport;
        IADLXGPUMetricsPtr gpuMetrics;
        IADLXPerformanceMonitoringServicesPtr perfMonitoringService;

        // Get GPUs
        IADLXGPUListPtr gpus;
        res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
        if (ADLX_SUCCEEDED(res) && !gpus->Empty())
        {
            // Get GPU interface
            IADLXGPUPtr gpuInfo;
            adlx_uint index = GPU;
            res = gpus->At(index, &gpuInfo);
            if (ADLX_SUCCEEDED(res))
            {
                ADLX_RESULT res1 = perfMonitoringService->GetSupportedGPUMetrics(gpuInfo, &gpuMetricsSupport);
                ADLX_RESULT res2 = perfMonitoringService->GetCurrentGPUMetrics(gpuInfo, &gpuMetrics);

                // Display timestamp and GPU metrics
                if (ADLX_SUCCEEDED(res1) && ADLX_SUCCEEDED(res2))
                {
                    GetTimeStamp(gpuMetrics);
                    GetGPUUsage(gpuMetricsSupport, gpuMetrics, adlxTelemetryData);
                    GetGPUClockSpeed(gpuMetricsSupport, gpuMetrics, adlxTelemetryData);
                    GetGPUVRAMClockSpeed(gpuMetricsSupport, gpuMetrics, adlxTelemetryData);
                    GetGPUTemperature(gpuMetricsSupport, gpuMetrics, adlxTelemetryData);
                    GetGPUHotspotTemperature(gpuMetricsSupport, gpuMetrics, adlxTelemetryData);
                    GetGPUPower(gpuMetricsSupport, gpuMetrics, adlxTelemetryData);
                    GetGPUFanSpeed(gpuMetricsSupport, gpuMetrics, adlxTelemetryData);
                    GetGPUVRAM(gpuMetricsSupport, gpuMetrics, adlxTelemetryData);
                    GetGPUVoltage(gpuMetricsSupport, gpuMetrics, adlxTelemetryData);
                    GetGPUTotalBoardPower(gpuMetricsSupport, gpuMetrics, adlxTelemetryData);

                    check = true;
                }
            }
        }

        return check;
    }
}