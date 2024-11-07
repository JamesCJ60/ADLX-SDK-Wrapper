# ADLX-SDK-Wrapper
ADLX SDK Wrapper intended for C# applications


# Instructions
Add the DLLs from the release zip file into your application.
-ADLX_3DSettings.dll
-ADLX_AutoTuning.dll
-ADLX_DisplaySettings.dll
-ADLX_PerformanceMetrics.dll



# Sample in C#
```
public static class ADLX_Management
{

  #region constants and dll references
  public const string CppFunctionsDLL = @"External Resources\AMD\ADLX\ADLX_PerformanceMetrics.dll";
  public const string CppFunctionsDLL2 = @"External Resources\AMD\ADLX\ADLX_AutoTuning.dll";
  public const string CppFunctionsDLL3 = @"External Resources\AMD\ADLX\ADLX_3DSettings.dll";
  public const string CppFunctionsDLL4 = @"External Resources\AMD\ADLX\ADLX_DisplaySettings.dll";

  [DllImport(CppFunctionsDLL, CallingConvention = CallingConvention.Cdecl)] public static extern int GetFPSData();

  [DllImport(CppFunctionsDLL, CallingConvention = CallingConvention.Cdecl)] public static extern int GetGPUMetrics(int GPU, int Sensor);

  [DllImport(CppFunctionsDLL2, CallingConvention = CallingConvention.Cdecl)] public static extern int SetAutoTuning(int GPU, int num);

  [DllImport(CppFunctionsDLL2, CallingConvention = CallingConvention.Cdecl)] public static extern int GetAutoTuning(int GPU);

  [DllImport(CppFunctionsDLL2, CallingConvention = CallingConvention.Cdecl)] public static extern int GetFactoryStatus(int GPU);

  //int GPU is just the index of the GPU, default should be 0 unless you are running an egpu and want to set that, in which case it would be 1
  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetFPSLimit(int GPU, bool isEnabled, int FPS);
  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsFPSLimitEnabled(int GPU);
  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasFPSLimitSupport(int GPU);
  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool DisableFPSLimit(int GPU);

  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetRSR(bool isEnabled);
  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool GetRSRState();
  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasRSRSupport();

  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetRSRSharpness(int sharpness);
  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern int GetRSRSharpness();

  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetAFMFState(bool isEnabled);
  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool GetAFMFState();
  [DllImport(CppFunctionsDLL3, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasAFMFSupport();
  

  //if function ends 1, its for the first display! if ends in 2, second display

  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasIntegerScalingSupport1();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetIntegerScaling1(bool isEnabled);
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsIntegerScalingEnabled1();


  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasIntegerScalingSupport2();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetIntegerScaling2(bool isEnabled);
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsIntegerScalingEnabled2();

  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasGPUScalingSupport1();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetGPUScaling1(bool isEnabled);
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsGPUScalingEnabled1();

  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetGPUScaling2(bool isEnabled);
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsGPUScalingEnabled2();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasGPUScalingSupport2();

  //Scaling Mode int to mode: 0 is preserve aspect ration, 1 is full panel, 2 is center
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasScalingModeSupport1();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetScalingMode1(int key);
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern int GetScalingMode1();

  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasScalingModeSupport2();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetScalingMode2(int key);
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern int GetScalingMode2();

  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasFreeSyncSupport1();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsFreeSyncEnabled1();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern int SetFreeSync1(bool isEnabled);

  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasFreeSyncSupport2();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsFreeSyncEnabled2();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern int SetFreeSync2(bool isEnabled);


  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasVSRSupport1();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsVSREnabled1();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern int SetVSRState1(bool isEnabled);
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasVSRSupport2();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsVSREnabled2();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern int SetVSRState2(bool isEnabled);




  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasVariBrightSupport1();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsVariBrightEnabled1();
  //GetVariBrightState1 returns -1 for failed,    0 for max brightness, 1 for optimized brightness, 0 for balanced, 3 for optimized battery, 4 for max battery saver
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern int GetVariBrightState1();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetVariBrightState1(int key);
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetVariBrightEnabled1(bool isEnabled);


  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool HasVariBrightSupport2();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool IsVariBrightEnabled2();
  //GetVariBrightState1 returns -1 for failed,    0 for max brightness, 1 for optimized brightness, 0 for balanced, 3 for optimized battery, 4 for max battery saver
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern int GetVariBrightState2();
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetVariBrightState2(int key);
  [DllImport(CppFunctionsDLL4, CallingConvention = CallingConvention.Cdecl)] public static extern bool SetVariBrightEnabled2(bool isEnabled);

  #endregion
    #endregion




}
```
