<<<<<<< HEAD
package com.example.a4ib2.projektkoncowynowaks;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.hardware.Camera;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.FrameLayout;

import java.util.ArrayList;

public class CameraActivity2 extends AppCompatActivity {

    private Camera camera;
    private int cameraId = -1;
    private CameraPreview cameraPreview;
    private FrameLayout frameLayout;
    private Camera.Parameters camParams;
    private Button balans_bieli;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camera2);
        initCamera();
        initPreview();
        camParams = camera.getParameters();

        balans_bieli = (Button) findViewById(R.id.balans);
        balans_bieli.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder alert = new AlertDialog.Builder(CameraActivity2.this);
                alert.setTitle("Wybierz");

                String[] opcje = {"tanie", "średnie", "drogie"};
                ArrayList<String> lista = new ArrayList<String>();
                for(int i=0;i< camParams.getSupportedWhiteBalance().size();i++){
                    lista.add(camParams.getSupportedWhiteBalance().toString());
                }

                String[] tab = new String[camParams.getSupportedWhiteBalance().size()];
                for(int i=0;i< camParams.getSupportedWhiteBalance().size();i++){
                   tab[i] = camParams.getSupportedWhiteBalance().get(i).toString();
                }


                camParams.getSupportedWhiteBalance();
                alert.setItems(tab, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
// wyswietl opcje[which]);
                        camParams.setWhiteBalance(camParams.getSupportedWhiteBalance().get(which));
                        camera.setParameters(camParams);

                    }
                });
                alert.show();

            }
        }
        );
    }






    @Override
    protected void onPause() {
        super.onPause();
        if (camera != null) {
            camera.stopPreview();
//linijka nieudokumentowana w API, bez niej jest crash przy wznawiamiu kamery
            cameraPreview.getHolder().removeCallback(cameraPreview);
            camera.release();
            camera = null;
        }


    }


    @Override
    protected void onResume() {
        super.onResume();
        if (camera == null) {
//zainicjalizuj kamerę
            //od nowa
            initCamera();
            initPreview();
        }
    }

    public int initCamera() {
        boolean cam = getPackageManager().hasSystemFeature(PackageManager.FEATURE_CAMERA);
        if (!cam) {
// uwaga - brak kamery
        } else {
// wykorzystanie danych zwróconych przez kolejną funkcję getCameraId
            cameraId = getCameraId();
// jest jakaś kamera!
            if (cameraId < 0) {
// brak kamery z przodu!
            } else if (cameraId >= 0) {
                camera = Camera.open(cameraId);
            }
        }
        return cameraId;
    }

    public void initPreview() {
        cameraPreview = new CameraPreview(CameraActivity2.this, camera);
        frameLayout = (FrameLayout) findViewById(R.id.frameLayout1);
        frameLayout.addView(cameraPreview);

    }


    public int getCameraId() {

        int cid = 0;
        int camerasCount = Camera.getNumberOfCameras(); // gdy więcej niż jedna kamera
        for (int i = 0; i < camerasCount; i++) {
            Camera.CameraInfo cameraInfo = new Camera.CameraInfo();
            Camera.getCameraInfo(i, cameraInfo);
            if (cameraInfo.facing == Camera.CameraInfo.CAMERA_FACING_BACK) {
                cid = i;
            }
    /*
if (cameraInfo.facing == CameraInfo.CAMERA_FACING_FRONT) {
cid = i;
}
	*/
        }
        return cid;
    }


}
=======
package com.example.a4ib2.projektkoncowynowaks;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.hardware.Camera;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.FrameLayout;

import java.util.ArrayList;

public class CameraActivity2 extends AppCompatActivity {

    private Camera camera;
    private int cameraId = -1;
    private CameraPreview cameraPreview;
    private FrameLayout frameLayout;
    private Camera.Parameters camParams;
    private Button balans_bieli;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camera2);
        initCamera();
        initPreview();
        camParams = camera.getParameters();

        balans_bieli = (Button) findViewById(R.id.balans);
        balans_bieli.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder alert = new AlertDialog.Builder(CameraActivity2.this);
                alert.setTitle("Wybierz");

                String[] opcje = {"tanie", "średnie", "drogie"};
                ArrayList<String> lista = new ArrayList<String>();
                for(int i=0;i< camParams.getSupportedWhiteBalance().size();i++){
                    lista.add(camParams.getSupportedWhiteBalance().toString());
                }

                String[] tab = new String[camParams.getSupportedWhiteBalance().size()];
                for(int i=0;i< camParams.getSupportedWhiteBalance().size();i++){
                   tab[i] = camParams.getSupportedWhiteBalance().get(i).toString();
                }


                camParams.getSupportedWhiteBalance();
                alert.setItems(tab, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
// wyswietl opcje[which]);
                        camParams.setWhiteBalance(camParams.getSupportedWhiteBalance().get(which));
                        camera.setParameters(camParams);

                    }
                });
                alert.show();

            }
        }
        );
    }






    @Override
    protected void onPause() {
        super.onPause();
        if (camera != null) {
            camera.stopPreview();
//linijka nieudokumentowana w API, bez niej jest crash przy wznawiamiu kamery
            cameraPreview.getHolder().removeCallback(cameraPreview);
            camera.release();
            camera = null;
        }


    }


    @Override
    protected void onResume() {
        super.onResume();
        if (camera == null) {
//zainicjalizuj kamerę
            //od nowa
            initCamera();
            initPreview();
        }
    }

    public int initCamera() {
        boolean cam = getPackageManager().hasSystemFeature(PackageManager.FEATURE_CAMERA);
        if (!cam) {
// uwaga - brak kamery
        } else {
// wykorzystanie danych zwróconych przez kolejną funkcję getCameraId
            cameraId = getCameraId();
// jest jakaś kamera!
            if (cameraId < 0) {
// brak kamery z przodu!
            } else if (cameraId >= 0) {
                camera = Camera.open(cameraId);
            }
        }
        return cameraId;
    }

    public void initPreview() {
        cameraPreview = new CameraPreview(CameraActivity2.this, camera);
        frameLayout = (FrameLayout) findViewById(R.id.frameLayout1);
        frameLayout.addView(cameraPreview);

    }


    public int getCameraId() {

        int cid = 0;
        int camerasCount = Camera.getNumberOfCameras(); // gdy więcej niż jedna kamera
        for (int i = 0; i < camerasCount; i++) {
            Camera.CameraInfo cameraInfo = new Camera.CameraInfo();
            Camera.getCameraInfo(i, cameraInfo);
            if (cameraInfo.facing == Camera.CameraInfo.CAMERA_FACING_BACK) {
                cid = i;
            }
    /*
if (cameraInfo.facing == CameraInfo.CAMERA_FACING_FRONT) {
cid = i;
}
	*/
        }
        return cid;
    }


}
>>>>>>> 7780897e3c05ad584d10e9aba621b7e1cc246ea4
