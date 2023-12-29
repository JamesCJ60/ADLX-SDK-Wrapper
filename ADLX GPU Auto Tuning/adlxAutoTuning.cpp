#include "../SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "../SDK/Include/IGPUAutoTuning.h"
#include "../SDK/Include/IGPUTuning.h"
#include <string>

#define ADLX_AutoTuning _declspec(dllexport)

extern "C" {
    using namespace adlx;
    using namespace std;
    static ADLXHelper g_ADLXHelp;
    HANDLE g_ADLXEvent = nullptr;

    class GPUAutoTuningCompleteEvents : public IADLXGPUAutoTuningCompleteListener
    {
    public:
        adlx_bool ADLX_STD_CALL OnGPUAutoTuningComplete(IADLXGPUAutoTuningCompleteEvent* pGPUAutoTuningCompleteEvent)
        {
            adlx_bool change = false;
            change = pGPUAutoTuningCompleteEvent->IsUndervoltGPUCompleted();
            change = pGPUAutoTuningCompleteEvent->IsOverclockGPUCompleted();
            change = pGPUAutoTuningCompleteEvent->IsOverclockVRAMCompleted();
            SetEvent(g_ADLXEvent);
            return true;
        }
    };

    GPUAutoTuningCompleteEvents gpuAutoTuningCompleteEvents;

    ADLX_AutoTuning int SetAutoTuning(int GPU, int num)
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);

        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();

        if (ADLX_SUCCEEDED(res))
        {
            // Create event
            g_ADLXEvent = CreateEvent(NULL, TRUE, FALSE, TEXT("ADLXEvent"));

            IADLXGPUTuningServicesPtr gpuTuningService;
            res = g_ADLXHelp.GetSystemServices()->GetGPUTuningServices(&gpuTuningService);
            if (ADLX_SUCCEEDED(res))
            {
                IADLXGPUListPtr gpus;
                res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
                if (ADLX_SUCCEEDED(res))
                {
                    if (num == 0) {
                        IADLXGPUPtr oneGPU;
                        ADLX_RESULT res = gpus->At(GPU, &oneGPU);
                        if (ADLX_FAILED(res) || oneGPU == nullptr)
                        {
                            return -2;
                        }
                        adlx_bool isFactory = false;
                        res = gpuTuningService->ResetToFactory(oneGPU);
                        if (ADLX_FAILED(res))
                            return -2;
                        else
                            return 1;

                    }
                    if (num >= 1)
                    {
                        IADLXGPUPtr oneGPU;
                        // Set the first GPU auto-tuning
                        ADLX_RESULT res = gpus->At(GPU, &oneGPU);

                        if (ADLX_FAILED(res) || oneGPU == nullptr)
                        {
                            return -1;
                        }
                        adlx_bool supported = false;
                        res = gpuTuningService->IsSupportedAutoTuning(oneGPU, &supported);
                        if (ADLX_FAILED(res) || supported == false)
                        {
                            return -1;
                        }
                        IADLXInterfacePtr autoTuningIfc;
                        res = gpuTuningService->GetAutoTuning(oneGPU, &autoTuningIfc);
                        if (ADLX_FAILED(res) || autoTuningIfc == nullptr)
                        {
                            return -1;
                        }
                        IADLXGPUAutoTuningPtr autoTuning(autoTuningIfc);
                        if (autoTuning)
                        {
                            bool modeIsSupported = false;

                            if (num == 1) {
                                res = autoTuning->IsSupportedUndervoltGPU(&modeIsSupported);
                                if (!modeIsSupported) {
                                    return -1;
                                }
                                else {
                                    res = autoTuning->StartUndervoltGPU(&gpuAutoTuningCompleteEvents);
                                    WaitForSingleObject(g_ADLXEvent, 1000);
                                    ResetEvent(g_ADLXEvent);
                                    if (ADLX_SUCCEEDED(res))
                                        return 1;
                                    else
                                        return -2;
                                }
                            }
                            if (num == 2) {
                                res = autoTuning->IsSupportedOverclockGPU(&modeIsSupported);
                                if (!modeIsSupported) {
                                    return -1;
                                }
                                else {
                                    res = autoTuning->StartOverclockGPU(&gpuAutoTuningCompleteEvents);
                                    WaitForSingleObject(g_ADLXEvent, 1000);
                                    ResetEvent(g_ADLXEvent);
                                    if (ADLX_SUCCEEDED(res))
                                        return 1;
                                    else
                                        return -2;
                                }
                            }
                            if (num == 3) {
                                res = autoTuning->IsSupportedOverclockVRAM(&modeIsSupported);
                                if (!modeIsSupported) {
                                    return -1;
                                }
                                else {
                                    res = autoTuning->StartOverclockVRAM(&gpuAutoTuningCompleteEvents);
                                    WaitForSingleObject(g_ADLXEvent, 1000);
                                    ResetEvent(g_ADLXEvent);
                                    if (ADLX_SUCCEEDED(res))
                                        return 1;
                                    else
                                        return -2;
                                }
                            }
                        }
                    }
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

    ADLX_AutoTuning int GetAutoTuning(int GPU)
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);

        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();

        if (ADLX_SUCCEEDED(res))
        {
            // Create event
            g_ADLXEvent = CreateEvent(NULL, TRUE, FALSE, TEXT("ADLXEvent"));

            IADLXGPUTuningServicesPtr gpuTuningService;
            res = g_ADLXHelp.GetSystemServices()->GetGPUTuningServices(&gpuTuningService);
            if (ADLX_SUCCEEDED(res))
            {
                IADLXGPUListPtr gpus;
                res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
                if (ADLX_SUCCEEDED(res))
                {
                    IADLXGPUPtr oneGPU;
                    // Set the first GPU auto-tuning
                    ADLX_RESULT res = gpus->At(GPU, &oneGPU);
                    if (ADLX_FAILED(res) || oneGPU == nullptr)
                    {
                        return -1;
                    }

                    IADLXInterfacePtr autoTuningIfc;
                    res = gpuTuningService->GetAutoTuning(oneGPU, &autoTuningIfc);
                    if (ADLX_FAILED(res) || autoTuningIfc == nullptr)
                    {
                        return -1;
                    }

                    IADLXGPUAutoTuningPtr autoTuning(autoTuningIfc);
                    adlx_bool applied = false;
                    if (autoTuning)
                    {
                        // If ret != ADLX_OK, return default value(false).
                        applied = false;
                        res = autoTuning->IsCurrentUndervoltGPU(&applied);
                        if (applied) return 1;
                        applied = false;
                        res = autoTuning->IsCurrentOverclockGPU(&applied);
                        if (applied) return 2;
                        applied = false;
                        res = autoTuning->IsCurrentOverclockVRAM(&applied);
                        if (applied) return 3;
                        else return 0;
                    }
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

    ADLX_AutoTuning int GetFactoryStatus(int GPU)
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);

        ADLX_RESULT res = ADLX_FAIL;

        // Initialize ADLX
        res = g_ADLXHelp.Initialize();

        if (ADLX_SUCCEEDED(res))
        {
            // Create event
            g_ADLXEvent = CreateEvent(NULL, TRUE, FALSE, TEXT("ADLXEvent"));

            IADLXGPUTuningServicesPtr gpuTuningService;
            res = g_ADLXHelp.GetSystemServices()->GetGPUTuningServices(&gpuTuningService);
            if (ADLX_SUCCEEDED(res))
            {
                IADLXGPUListPtr gpus;
                res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
                if (ADLX_SUCCEEDED(res))
                {
                    IADLXGPUPtr oneGPU;

                    ADLX_RESULT res = gpus->At(GPU, &oneGPU);
                    if (ADLX_FAILED(res) || oneGPU == nullptr)
                    {
                        return -1;
                    }
                    adlx_bool isFactory = false;
                    res = gpuTuningService->IsAtFactory(oneGPU, &isFactory);
                    if (ADLX_FAILED(res))
                    {
                        return -1;
                    }
                    if (isFactory) return 1;
                    else return 0;

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