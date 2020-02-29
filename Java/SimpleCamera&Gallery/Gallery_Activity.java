<<<<<<< HEAD
package com.example.a4ib2.projektkoncowynowaks;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;

import java.io.File;

public class Gallery_Activity extends AppCompatActivity {
    private LinearLayout lin_lay;
    private LinearLayout.LayoutParams lparams;
    private LinearLayout g_layH;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_gallery_);
        getSupportActionBar().hide();
        lin_lay = (LinearLayout) findViewById(R.id.g_lay);
        Bundle bundle = getIntent().getExtras();
        String wartosc = bundle.getString("key").toString();
        File file = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
        File dir = new File(file, "SzymonNowak");
        File dir_zdj = new File(dir, wartosc);
        File[] files = dir_zdj.listFiles();
        for (int i = 0; i < files.length; i++) {
            if (i % 2 == 0) {
                LinearLayout g_layH = new LinearLayout(this);
                g_layH.setOrientation(0);
            }
            lparams = new LinearLayout.LayoutParams(300, 300);

            //jesli File jest plikiem
            Log.d("KATALOOOG", files[i].toString());
            ImageView imgv1 = new ImageView(this);
            String imagepath = files[i].getPath(); // pobierz sciezke z obiektu File
            Bitmap bmp = betterImageDecode(imagepath); // funkcja decodeImage opisana jest ponizej
            imgv1.setImageBitmap(bmp); // wstawienie bitmapy do ImageView
            imgv1.setLayoutParams(lparams);
            g_layH.addView(imgv1);
            lin_lay.addView(g_layH);
        }


        ImageView imgv2 = new ImageView(this);

        //  LinearLayout lin_lay = convertView()

        lin_lay.addView(imgv2);
    }

    private Bitmap betterImageDecode(String filePath) {
        Bitmap myBitmap;
        BitmapFactory.Options options = new BitmapFactory.Options(); //opcje przekształcania bitmapy
        options.inSampleSize = 4; // zmniejszenie jakości bitmapy 4x
//
        myBitmap = BitmapFactory.decodeFile(filePath, options);
        return myBitmap;
    }
}
=======
package com.example.a4ib2.projektkoncowynowaks;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;

import java.io.File;

public class Gallery_Activity extends AppCompatActivity {
    private LinearLayout lin_lay;
    private LinearLayout.LayoutParams lparams;
    private LinearLayout g_layH;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_gallery_);
        getSupportActionBar().hide();
        lin_lay = (LinearLayout) findViewById(R.id.g_lay);
        Bundle bundle = getIntent().getExtras();
        String wartosc = bundle.getString("key").toString();
        File file = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
        File dir = new File(file, "SzymonNowak");
        File dir_zdj = new File(dir, wartosc);
        File[] files = dir_zdj.listFiles();
        for (int i = 0; i < files.length; i++) {
            if (i % 2 == 0) {
                LinearLayout g_layH = new LinearLayout(this);
                g_layH.setOrientation(0);
            }
            lparams = new LinearLayout.LayoutParams(300, 300);

            //jesli File jest plikiem
            Log.d("KATALOOOG", files[i].toString());
            ImageView imgv1 = new ImageView(this);
            String imagepath = files[i].getPath(); // pobierz sciezke z obiektu File
            Bitmap bmp = betterImageDecode(imagepath); // funkcja decodeImage opisana jest ponizej
            imgv1.setImageBitmap(bmp); // wstawienie bitmapy do ImageView
            imgv1.setLayoutParams(lparams);
            g_layH.addView(imgv1);
            lin_lay.addView(g_layH);
        }


        ImageView imgv2 = new ImageView(this);

        //  LinearLayout lin_lay = convertView()

        lin_lay.addView(imgv2);
    }

    private Bitmap betterImageDecode(String filePath) {
        Bitmap myBitmap;
        BitmapFactory.Options options = new BitmapFactory.Options(); //opcje przekształcania bitmapy
        options.inSampleSize = 4; // zmniejszenie jakości bitmapy 4x
//
        myBitmap = BitmapFactory.decodeFile(filePath, options);
        return myBitmap;
    }
}
>>>>>>> 7780897e3c05ad584d10e9aba621b7e1cc246ea4
