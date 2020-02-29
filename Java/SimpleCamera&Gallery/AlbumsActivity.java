package com.example.a4ib2.projektkoncowynowaks;

import android.content.Intent;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.GridView;

import org.w3c.dom.Text;

import java.io.File;

public class AlbumsActivity extends AppCompatActivity {
    private GridView gridView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_albums_activity);
        getSupportActionBar().hide();
        gridView = (GridView) findViewById(R.id.gridView);
        File file = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
        File dir = new File(file, "SzymonNowak");
        File[] files = dir.listFiles();
        final String[] fileArray = new String[files.length];
        for (int i = 0; i < files.length; i++) {
            fileArray[i] = files[i].getName();
        }
        Log.e("KATALOG", "" + files.length);

        //String[] array = new String[]{"a","b","c"};
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(
                AlbumsActivity.this,     // Context
                R.layout.komorka,     // nazwa pliku xml naszej komórki
                R.id.komorka1,         // id pola txt w komórce
                fileArray);         // tablica przechowująca dane


        gridView.setOnItemClickListener(new AdapterView.OnItemClickListener() {

            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                //test
                Log.d("TAG", "index = " + i);
                Log.e("ZAWARTOSC ", fileArray[i] );
                Intent intent = new Intent(AlbumsActivity.this, Gallery_Activity.class);
                intent.putExtra("key", fileArray[i]);
                startActivity(intent);
            }
        });
        gridView.setAdapter(adapter);

    }
}
