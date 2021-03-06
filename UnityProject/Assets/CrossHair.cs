﻿using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class CrossHair : MonoBehaviour {
    public Texture2D crosshairTexture;
    public PluginLoader plugin;
    List<Vector3> _objectPositions = new List<Vector3>();
    List<Vector3> _imagePositions = new List<Vector3>();

	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void OnGUI () {
        var hh = crosshairTexture.height / 2;
        var hw = crosshairTexture.width / 2;

        var pos = Input.mousePosition;
        GUI.DrawTexture(new Rect(pos.x - hw, Screen.height - pos.y - hh, crosshairTexture.width, crosshairTexture.height), crosshairTexture);

        _imagePositions.ForEach(delegate(Vector3 position)
        {
            GL.Color(Color.black);
            GL.Begin(GL.QUADS);
            GL.Vertex3(position.x, Screen.height - position.y, 0);
            GL.Vertex3(position.x + 5, Screen.height - position.y, 0);
            GL.Vertex3(position.x + 5, Screen.height - position.y + 5, 0);
            GL.Vertex3(position.x, Screen.height - position.y + 5, 0);
            GL.End();
        });
	}

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            if (_imagePositions.Count == _objectPositions.Count)
            {
                // We have the same number of object and image positions, so we are starting a new correspondence. First is the object position
                Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
                RaycastHit hit3d;
                if (Physics.Raycast(ray, out hit3d))
                {
                    GameObject sphere = GameObject.CreatePrimitive(PrimitiveType.Sphere);
                    sphere.transform.position = hit3d.point;
                    _objectPositions.Add(hit3d.point);
                }
            }
            else
            {
                // we already have an object position, now we collect the 2D correspondence
                _imagePositions.Add(Input.mousePosition);

                if (_imagePositions.Count > 6)
                {
                    plugin.calibrateFromCorrespondences(_imagePositions, _objectPositions);
                }
            }
        }
    }
}