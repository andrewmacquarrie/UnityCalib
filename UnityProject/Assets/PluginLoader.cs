using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System;
using System.Collections.Generic;

public class PluginLoader : MonoBehaviour {
    [DllImport("UnityTexture")]
    private static extern IntPtr PrintHello();

    [DllImport("UnityTexture")]
    private static extern int PrintANumber();

    [DllImport("UnityTexture")]
    private static extern double fillSomeArrayData([In, Out] double[] imagePoints, [In, Out] double[] objectPoints, int resultVertCount, [In, Out] double[] res);

    void Update () {
        // And prints 5 to the console
  //      var ret = PrintHello();
 //       var st = Marshal.PtrToStringAnsi(ret);
//        print(st);


        //this.gameObject.renderer.enabled = false;
    }

    public void calibrateFromCorrespondences(List<Vector3> _imagePositions, List<Vector3> _objectPositions)
    {
        double[] imagePositions = flatten(_imagePositions);
        double[] objectPositions = flatten(_objectPositions);

        double[] resultingArray = new double[9];
        double added = fillSomeArrayData(imagePositions, objectPositions, _imagePositions.Count, resultingArray);

        Debug.Log(added);
        for (int r = 0; r < 9; ++r)
        {
           // Debug.Log(resultingArray[r]);
        }
    }

    private double[] flatten(List<Vector3> _imagePositions)
    {
        int size = _imagePositions.Count * 3;
        double[] imageArray = new double[size];
        for (int r = 0; r < _imagePositions.Count; ++r)
        {
            imageArray[r * 3] = _imagePositions[r].x;
            imageArray[r * 3 + 1] = _imagePositions[r].y;
            imageArray[r * 3 + 2] = _imagePositions[r].z;
        }
        return imageArray;
    }
}