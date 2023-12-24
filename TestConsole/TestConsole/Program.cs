using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using TestConsole;

namespace CppAndCs
{
    public class Program
    {
        public static int i = 0;
        static void Main(string[] args)
        {
            while (true)
            {
                //if(i == 0)
                //{
                //    Backend.SetAutoTuning(0,0);
                //    i++;
                //}

                int isFactory = Backend.GetFactoryStatus(0);
                int autoTuning = Backend.GetAutoTuning(0);

                int fpsLimit = Backend.SetFPSLimit(0, true, 256);

                int gpuTotalPower = Backend.GetGPUMetrics(0,5);
                int fps = Backend.GetFPSData();
                int gpuHotSpot = Backend.GetGPUMetrics(0,2);
                int gpuTemp = Backend.GetGPUMetrics(0,3);
                int gpuClock = Backend.GetGPUMetrics(0,0);
                int gpuVRAMClock = Backend.GetGPUMetrics(0,1);
                int gpuPower = Backend.GetGPUMetrics(0,4);
                int gpuVRAM = Backend.GetGPUMetrics(0,6);
                int gpuUsage = Backend.GetGPUMetrics(0,7);
                int gpuVolt = Backend.GetGPUMetrics(0,8);
                int gpuFan = Backend.GetGPUMetrics(0,9);

                Console.WriteLine();
                Console.WriteLine($"==================================");
                Console.WriteLine($"AMD Device Library eXtra GPU Info:");
                Console.WriteLine($"==================================");
                Console.WriteLine();


                if (fps == -2) Console.WriteLine($"FPS: Not Supported (use fullscreen if using windowed!)");
                else Console.WriteLine($"FPS: {fps}");

                Console.WriteLine();

                if (isFactory == -2 || isFactory == -1) Console.WriteLine($"Factory Status: Not Supported");
                else Console.WriteLine($"Factory Status: {isFactory}");

                if (autoTuning == -2 || autoTuning == -1) Console.WriteLine($"Auto Tuning Status: Not Supported");
                else Console.WriteLine($"Auto Tuning Status: {autoTuning}");

                Console.WriteLine();

                if (gpuHotSpot == -2) Console.WriteLine($"GPU Hotspot: Not Supported");
                else Console.WriteLine($"GPU Hotspot: {gpuHotSpot} °C");
                
                if (gpuTemp == -2) Console.WriteLine($"GPU Temp: Not Supported");
                else Console.WriteLine($"GPU Temp: {gpuTemp} °C");

                if (gpuUsage == -2) Console.WriteLine($"GPU Usage: Not Supported");
                else Console.WriteLine($"GPU Usage: {gpuUsage} %");

                if (gpuClock == -2) Console.WriteLine($"GPU Clock: Not Supported");
                else Console.WriteLine($"GPU Clock: {gpuClock} MHz");

                if (gpuVRAMClock == -2) Console.WriteLine($"GPU VRAM Clock: Not Supported");
                else Console.WriteLine($"GPU VRAM Clock: {gpuVRAMClock} MHz");

                if (gpuVRAM == -2) Console.WriteLine($"GPU VRAM: Not Supported");
                else Console.WriteLine($"GPU VRAM: {gpuVRAM} MB");

                if (gpuFan == -2) Console.WriteLine($"GPU Fan Speed: Not Supported");
                else Console.WriteLine($"GPU Fan Speed: {gpuFan} RPM");

                if (gpuVolt == -2) Console.WriteLine($"GPU Voltage: Not Supported");
                else Console.WriteLine($"GPU Voltage: {gpuVolt} V");

                if (gpuPower == -2) Console.WriteLine($"GPU Power: Not Supported");
                else Console.WriteLine($"GPU Power: {gpuPower} W");

                if (gpuTotalPower == -2) Console.WriteLine($"GPU Board Power: Not Supported");
                else Console.WriteLine($"GPU VRAM Clock: {gpuTotalPower} W");

                Thread.Sleep(2000);
            }
        }
    }
}
