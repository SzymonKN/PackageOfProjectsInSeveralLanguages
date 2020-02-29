package com.example.a4ib2.projektkoncowynowaks;

import android.content.Intent;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;

import java.io.File;

public class MainActivity extends AppCompatActivity {
    private ImageView albumy;
    private ImageView camera;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportActionBar().hide();
        File file = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
        if (file.exists()) {
            // zwraca tablicę plików
            File dir = new File(file, "SzymonNowak");
            dir.mkdir();
            int katalog_imienny = 0;
            for (int i = 0; i < file.listFiles().length; i++) {
                if (file.listFiles()[i].getName().equals("SzymonNowak")) {
                    katalog_imienny = i;
                    Log.e("TAG", "znaleziono na " + i);
                }
                Log.e("TAG", file.listFiles()[i].getName());
                //  }

            }
            File dirm = new File(file.listFiles()[katalog_imienny], "miejsca");
            dirm.mkdir();
            File diro = new File(file.listFiles()[katalog_imienny], "osoby");
            diro.mkdir();
            File dirr = new File(file.listFiles()[katalog_imienny], "rzeczy");
            dirr.mkdir();
        }
        albumy = (ImageView) findViewById(R.id.albumy);
        albumy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.e("kk", "OMG");
                Intent intent = new Intent(MainActivity.this, AlbumsActivity.class);
                startActivity(intent);
            }
        });
        camera = (ImageView) findViewById(R.id.camera_album);
        camera.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //  Log.e("kk", "OMG");
                Intent intent = new Intent(MainActivity.this, CameraActivity.class);
                startActivity(intent);
            }

        });


        //   Intent intent = new Intent(MainActivity.this,AlbumsActivity.class);
        // startActivity(intent);


    }
}
