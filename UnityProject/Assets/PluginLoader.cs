using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System;

public class PluginLoader : MonoBehaviour {
    [DllImport("UnityTexture")]
    private static extern IntPtr PrintHello();

    [DllImport("UnityTexture")]
    private static extern int PrintANumber();

    
    
    void Update () {
        // And prints 5 to the console
        var ret = PrintHello();
        var st = Marshal.PtrToStringAnsi(ret);
        print(st);

        print(PrintANumber());

        this.gameObject.renderer.enabled = false;
    }
}