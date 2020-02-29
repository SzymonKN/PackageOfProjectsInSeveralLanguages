package com.example.a4ib2.projektkoncowynowaks;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.FrameLayout;
import android.widget.GridView;
import android.hardware.Camera;
import java.io.File;
import java.util.function.Function;

public class CameraActivity extends AppCompatActivity {
    private GridView gridView2;
    private Camera camera;
    private int cameraId = -1;
    private CameraPreview _cameraPreview;
    private FrameLayout _frameLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camera);
        getSupportActionBar().hide();
        File file = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
        File dir = new File(file, "SzymonNowak");
        File[] files = dir.listFiles();
        String[] fileArray = new String[files.length];
        GridView gridView2 = (GridView) findViewById(R.id.gridView2);
        for (int i = 0; i < files.length; i++) {
            fileArray[i] = files[i].getName();
        }
        MyAr adapter = new MyAr(
                CameraActivity.this,
                R.layout.komorka2,
                fileArray
        );
        gridView2.setAdapter(adapter);

        Intent intent = new Intent(CameraActivity.this , CameraActivity2.class);
        startActivity(intent);







    }



}

