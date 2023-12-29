#include "../SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "../SDK/Include/IPerformanceMonitoring.h"

#define ADLX_PerformanceMetrics _declspec(dllexport)

extern "C" {
    using namespace adlx;
    static ADLXHelper g_ADLXHelp;
    static const signed char g_degree = 248;

    ADLX_PerformanceMetrics int GetFPSData()
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);

        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();

        if (ADLX_SUCCEEDED(res))
        {
            // Get Performance Monitoring services
            IADLXPerformanceMonitoringServicesPtr perfMonitoringServices;
            ADLX_RESULT res = g_ADLXHelp.GetSystemServices()->GetPerformanceMonitoringServices(&perfMonitoringServices);
            if (ADLX_SUCCEEDED(res))
            {
                // Accumulate and display current metrics
                IADLXFPSPtr oneFPS;

                // Get current FPS metrics
                ADLX_RESULT res = perfMonitoringServices->GetCurrentFPS(&oneFPS);
                if (ADLX_SUCCEEDED(res))
                {
                    adlx_int fpsData = 0;
                    res = oneFPS->FPS(&fpsData);
                    if (ADLX_SUCCEEDED(res))
                        return fpsData;
                    else if (res == ADLX_NOT_SUPPORTED) {

                        return -2;
                    }
                }
            }
            else
                return -1;
        }
        else
            return -1;

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
    }

    ADLX_PerformanceMetrics int GetGPUMetrics(int GPU, int Sensor)
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);

        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();

        if (ADLX_SUCCEEDED(res))
        {
            // Get Performance Monitoring services
            IADLXPerformanceMonitoringServicesPtr perfMonitoringService;
            ADLX_RESULT res = g_ADLXHelp.GetSystemServices()->GetPerformanceMonitoringServices(&perfMonitoringService);
            if (ADLX_SUCCEEDED(res))
            {
                IADLXGPUListPtr gpus;
                // Get GPU list
                res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
                if (ADLX_SUCCEEDED(res))
                {
                    // Use the first GPU in the list
                    IADLXGPUPtr oneGPU;
                    res = gpus->At(GPU, &oneGPU);
                    if (ADLX_SUCCEEDED(res))
                    {
                        // Get system metrics support
                        IADLXSystemMetricsSupportPtr systemMetricsSupport;
                        ADLX_RESULT res2 = perfMonitoringService->GetSupportedSystemMetrics(&systemMetricsSupport);
                        // Get GPU metrics support
                        IADLXGPUMetricsSupportPtr gpuMetricsSupport;
                        res2 = perfMonitoringService->GetSupportedGPUMetrics(oneGPU, &gpuMetricsSupport);

                        

                        // accumulate data and show the current metrics
                        IADLXAllMetricsPtr allMetrics;
                        IADLXSystemMetricsPtr systemMetrics;
                        IADLXGPUMetricsPtr gpuMetrics;

                        ADLX_RESULT res1 = perfMonitoringService->GetCurrentAllMetrics(&allMetrics);

                        // Get current GPU metrics
                        res1 = allMetrics->GetGPUMetrics(oneGPU, &gpuMetrics);
                        if (ADLX_SUCCEEDED(res1))
                        {
                            if (Sensor == 0) {
                                adlx_bool supported = false;
                                // Display GPU clock speed support status
                                ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUClockSpeed(&supported);
                                if (ADLX_SUCCEEDED(res))
                                {
                                    if (supported)
                                    {
                                        adlx_int gpuClock = 0;
                                        res = gpuMetrics->GPUClockSpeed(&gpuClock);
                                        if (ADLX_SUCCEEDED(res)) return gpuClock;
                                        else return - 2;
                                    }
                                    else return -2;
                                }
                            }
                            else if (Sensor == 1) {
                                adlx_bool supported = false;
                                // Display GPU VRAM clock speed support status
                                ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVRAMClockSpeed(&supported);
                                if (ADLX_SUCCEEDED(res))
                                {
                                    if (supported)
                                    {
                                        adlx_int gpuVRAMClock = 0;
                                        res = gpuMetrics->GPUVRAMClockSpeed(&gpuVRAMClock);
                                        if (ADLX_SUCCEEDED(res)) return gpuVRAMClock;
                                        else return -2;
                                    }
                                    else return -2;
                                }
                            }
                            else if (Sensor == 2) {
                                adlx_bool supported = false;
                                // Display GPU Hotspot support status
                                ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUHotspotTemperature(&supported);
                                if (ADLX_SUCCEEDED(res))
                                {
                                    if (supported)
                                    {
                                        adlx_double gpuHotSpot = 0;
                                        res = gpuMetrics->GPUHotspotTemperature(&gpuHotSpot);
                                        if (ADLX_SUCCEEDED(res)) return (int)gpuHotSpot;
                                        else return -2;
                                    }
                                    else return -2;
                                }
                            }
                            else if (Sensor == 3) {
                                adlx_bool supported = false;
                                // Display GPU temp support status
                                ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUTemperature(&supported);
                                if (ADLX_SUCCEEDED(res))
                                {
                                    if (supported)
                                    {
                                        adlx_double gpuTemp = 0;
                                        res = gpuMetrics->GPUTemperature(&gpuTemp);
                                        if (ADLX_SUCCEEDED(res)) return (int)gpuTemp;
                                        else return -2;
                                    }
                                    else return -2;
                                }
                            }
                            else if (Sensor == 4) {
                                adlx_bool supported = false;
                                // Display GPU power support status
                                ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUPower(&supported);
                                if (ADLX_SUCCEEDED(res))
                                {
                                    if (supported)
                                    {
                                        adlx_double gpuPower = 0;
                                        res = gpuMetrics->GPUPower(&gpuPower);
                                        if (ADLX_SUCCEEDED(res)) return (int)gpuPower;
                                        else return -2;
                                    }
                                    else return -2;
                                }
                            }
                            else if (Sensor == 5) {
                                adlx_bool supported = false;
                                // Display GPU total power support status
                                ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUTotalBoardPower(&supported);
                                if (ADLX_SUCCEEDED(res))
                                {
                                    if (supported)
                                    {
                                        adlx_double gpuTotalPower = 0;
                                        res = gpuMetrics->GPUTotalBoardPower(&gpuTotalPower);
                                        if (ADLX_SUCCEEDED(res)) return (int)gpuTotalPower;
                                        else return -2;
                                    }
                                    else return -2;
                                }
                            }
                            else if (Sensor == 6) {
                                adlx_bool supported = false;
                                // Display GPU VRAM support status
                                ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVRAM(&supported);
                                if (ADLX_SUCCEEDED(res))
                                {
                                    if (supported)
                                    {
                                        adlx_int gpuVRAMUsage = 0;
                                        res = gpuMetrics->GPUVRAM(&gpuVRAMUsage);
                                        if (ADLX_SUCCEEDED(res)) return gpuVRAMUsage;
                                        else return -2;
                                    }
                                    else return -2;
                                }
                            }
                            else if (Sensor == 7) {
                                adlx_bool supported = false;
                                // Display GPU usage support status
                                ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUUsage(&supported);
                                if (ADLX_SUCCEEDED(res))
                                {
                                    if (supported)
                                    {
                                        adlx_double gpuUsage = 0;
                                        res = gpuMetrics->GPUUsage(&gpuUsage);
                                        if (ADLX_SUCCEEDED(res)) return (int)gpuUsage;
                                        else return -2;
                                    }
                                    else return -2;
                                }
                            }
                            else if (Sensor == 8) {
                            adlx_bool supported = false;
                            // Display GPU voltage support status
                            ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVoltage(&supported);
                            if (ADLX_SUCCEEDED(res))
                            {
                                if (supported)
                                {
                                    adlx_int gpuVolt = 0;
                                    res = gpuMetrics->GPUVoltage(&gpuVolt);
                                    if (ADLX_SUCCEEDED(res)) return gpuVolt;
                                    else return -2;
                                }
                                else return -2;
                            }
                            }
                            else if (Sensor == 9) {
                            adlx_bool supported = false;
                            // Display GPU fan speed support status
                            ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUFanSpeed(&supported);
                            if (ADLX_SUCCEEDED(res))
                            {
                                if (supported)
                                {
                                    adlx_int gpuFan = 0;
                                    res = gpuMetrics->GPUFanSpeed(&gpuFan);
                                    if (ADLX_SUCCEEDED(res)) return gpuFan;
                                    else return -2;
                                }
                                else return -2;
                            }
                            }
                        }
                        else return -1;
                    }
                    else
                        return -1;
                }
                else
                    return -1;
            }
            else
                 return -1;
        }
        else
            return -1;

        // Destroy ADLX
        res = g_ADLXHelp.Terminate();
    }
}