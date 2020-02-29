<<<<<<< HEAD
package com.example.a4ib2.projektkoncowynowaks;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.TextView;


public class MyAr extends ArrayAdapter {

    private String[] array;
    private Context _context;

    public MyAr(Context context, int resource, String[] objects) {

        super(context, resource, objects);
        array = objects;
        _context = context;
    }
    //

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        //inflater - klasa konwertująca xml na kod javy
        LayoutInflater inflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        convertView = inflater.inflate(R.layout.komorka2, null);
        //szukam kontrolki w layoucie

        TextView tv1 = (TextView) convertView.findViewById(R.id.tv1);
        tv1.setText(array[position]);
        //
        ImageView iv1 = (ImageView) convertView.findViewById(R.id.iv1);
        iv1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });

        Button bt1 = (Button) convertView.findViewById(R.id.bt1);
        bt1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // klik w button
            }
        });

        return convertView;
    }
}
=======
package com.example.a4ib2.projektkoncowynowaks;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.TextView;


public class MyAr extends ArrayAdapter {

    private String[] array;
    private Context _context;

    public MyAr(Context context, int resource, String[] objects) {

        super(context, resource, objects);
        array = objects;
        _context = context;
    }
    //

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        //inflater - klasa konwertująca xml na kod javy
        LayoutInflater inflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        convertView = inflater.inflate(R.layout.komorka2, null);
        //szukam kontrolki w layoucie

        TextView tv1 = (TextView) convertView.findViewById(R.id.tv1);
        tv1.setText(array[position]);
        //
        ImageView iv1 = (ImageView) convertView.findViewById(R.id.iv1);
        iv1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });

        Button bt1 = (Button) convertView.findViewById(R.id.bt1);
        bt1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // klik w button
            }
        });

        return convertView;
    }
}
>>>>>>> 7780897e3c05ad584d10e9aba621b7e1cc246ea4
