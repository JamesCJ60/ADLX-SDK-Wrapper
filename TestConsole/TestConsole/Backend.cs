using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace TestConsole
{
    internal class Backend
    {
        public const string perfMetrics = @"ADLX_PerformanceMetrics.dll";
        public const string autoTuning = @"ADLX_AutoTuning.dll";
        public const string graphSettings = @"ADLX_3DSettings.dll";

        [DllImport(perfMetrics, CallingConvention = CallingConvention.Cdecl)] public static extern int GetFPSData();
        
        [DllImport(perfMetrics, CallingConvention = CallingConvention.Cdecl)] public static extern int GetGPUMetrics(int GPU, int Sensor);

        [DllImport(autoTuning, CallingConvention = CallingConvention.Cdecl)] public static extern int SetAutoTuning(int GPU, int num);

        [DllImport(autoTuning, CallingConvention = CallingConvention.Cdecl)] public static extern int GetAutoTuning(int GPU);

        [DllImport(autoTuning, CallingConvention = CallingConvention.Cdecl)] public static extern int GetFactoryStatus(int GPU);

        [DllImport(graphSettings, CallingConvention = CallingConvention.Cdecl)] public static extern int SetFPSLimit(int GPU, bool isEnabled, int FPS);
    }
}
